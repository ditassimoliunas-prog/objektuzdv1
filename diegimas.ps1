# ========== ObjektinisUzdavinys v2.0 - Diegimas (Windows) ==========
# Šis skriptas automatizuoja projektą kompiliavimą, testavimą ir dokumentacijos generavimą
#
# Naudojimas:
#   .\diegimas.ps1
#   .\diegimas.ps1 -Stage build
#   .\diegimas.ps1 -Stage test
#   .\diegimas.ps1 -Stage docs
#   .\diegimas.ps1 -Stage clean

param(
	[ValidateSet("all", "build", "test", "docs", "run", "clean")]
	[string]$Stage = "all"
)

# ========== PAGALBINĖS FUNKCIJOS ==========

function Write-Header {
	param([string]$Message)
	Write-Host ""
	Write-Host "========================================" -ForegroundColor Cyan
	Write-Host "  $Message" -ForegroundColor Cyan
	Write-Host "========================================" -ForegroundColor Cyan
	Write-Host ""
}

function Write-Success {
	param([string]$Message)
	Write-Host "[✓ OK]     $Message" -ForegroundColor Green
}

function Write-Error {
	param([string]$Message)
	Write-Host "[✗ KLAIDA] $Message" -ForegroundColor Red
}

function Write-Info {
	param([string]$Message)
	Write-Host "[i INFO]   $Message" -ForegroundColor Yellow
}

# ========== KONFIGŪRACIJA ==========

$BuildDir = "build"
$DocsDir = "dokumentacija"
$CMake = "cmake"

# Patikrinkime, ar CMake yra suinstaliuota
if (-not (Get-Command $CMake -ErrorAction SilentlyContinue)) {
	Write-Error "CMake nsuinstaliuotas! Parsisiųskite iš https://cmake.org/download/"
	exit 1
}

Write-Header "ObjektinisUzdavinys v2.0 - Diegimas"

# ========== BUILD TIKSLAS ==========

function Build-Project {
	Write-Info "Konfigūruojame CMake..."
	if (-not (Test-Path $BuildDir)) {
		New-Item -ItemType Directory -Path $BuildDir | Out-Null
		Write-Success "Sukurtas $BuildDir direktorija"
	}

	Push-Location $BuildDir
	& $CMake -G "Visual Studio 16 2019" ..
	if ($LASTEXITCODE -ne 0) {
		Write-Error "CMake konfigūracija nepavyko!"
		Pop-Location
		exit 1
	}
	Pop-Location
	Write-Success "CMake konfigūracija sėkminga"

	Write-Info "Kompiliuojame projektą..."
	& $CMake --build $BuildDir --config Release
	if ($LASTEXITCODE -ne 0) {
		Write-Error "Kompiliavimas nepavyko!"
		exit 1
	}
	Write-Success "Kompiliavimas sėkmingas!"
}

# ========== TESTŲ TIKSLAS ==========

function Run-Tests {
	Write-Info "Vykdome unit testus..."
	$TestExe = "$BuildDir\Release\test_programa.exe"

	if (-not (Test-Path $TestExe)) {
		Write-Error "Test programa nerasta! Pirmiausia vykdykite: .\diegimas.ps1 -Stage build"
		exit 1
	}

	& $TestExe
	if ($LASTEXITCODE -ne 0) {
		Write-Error "Kai kurie testai nepavyko!"
		exit 1
	}
	Write-Success "Visi testai priimti!"
}

# ========== DOKUMENTACIJOS TIKSLAS ==========

function Generate-Docs {
	Write-Info "Sugeneruojame Doxygen dokumentaciją..."

	$DoxygenCmd = Get-Command doxygen -ErrorAction SilentlyContinue
	if (-not $DoxygenCmd) {
		Write-Error "Doxygen nsuinstaliuotas!"
		Write-Info "Parsisiųskite iš: https://www.doxygen.nl/download.html"
		exit 1
	}

	& doxygen Doxyfile
	if ($LASTEXITCODE -ne 0) {
		Write-Error "Doxygen dokumentacijos generavimas nepavyko!"
		exit 1
	}
	Write-Success "Dokumentacija sugeneruota!"
	Write-Info "HTML: $DocsDir\html\index.html"
	Write-Info "LaTeX: $DocsDir\latex\refman.pdf"
}

# ========== PALEIDIMO TIKSLAS ==========

function Run-Program {
	Write-Info "Paleidžiame pagrindinę programą..."
	$ProgExe = "$BuildDir\Release\programa.exe"

	if (-not (Test-Path $ProgExe)) {
		Write-Error "Programa nerasta! Pirmiausia vykdykite: .\diegimas.ps1 -Stage build"
		exit 1
	}

	& $ProgExe
}

# ========== VALYMO TIKSLAS ==========

function Clean-Build {
	Write-Info "Išvalome build direktorijų..."
	if (Test-Path $BuildDir) {
		Remove-Item -Recurse -Force $BuildDir
		Write-Success "Build direktorija išvalyta!"
	} else {
		Write-Info "Build direktorija neegzistuoja"
	}
}

# ========== HELP TIKSLAS ==========

function Show-Help {
	Write-Header "Diegimas - Pagalba"
	Write-Host "Naudojimas: .\diegimas.ps1 -Stage <Stage>" -ForegroundColor White
	Write-Host ""
	Write-Host "Turimi etapai:" -ForegroundColor White
	Write-Host "  all     - Viskas (clean, build, test, docs)" -ForegroundColor Gray
	Write-Host "  build   - Tik kompiliavimas" -ForegroundColor Gray
	Write-Host "  test    - Tik testai (reikalingas build)" -ForegroundColor Gray
	Write-Host "  docs    - Tik dokumentacija" -ForegroundColor Gray
	Write-Host "  run     - Paleisti programą" -ForegroundColor Gray
	Write-Host "  clean   - Išvalyti build" -ForegroundColor Gray
	Write-Host ""
	Write-Host "Pavyzdžiai:" -ForegroundColor White
	Write-Host "  .\diegimas.ps1                    # Viskas" -ForegroundColor Gray
	Write-Host "  .\diegimas.ps1 -Stage build       # Tik build" -ForegroundColor Gray
	Write-Host "  .\diegimas.ps1 -Stage test        # Tik testai" -ForegroundColor Gray
	Write-Host ""
}

# ========== PAGRINDINĖ LOGIKA ==========

switch ($Stage) {
	"all" {
		Clean-Build
		Build-Project
		Run-Tests
		Generate-Docs
		Write-Header "✓ PILNAS DIEGIMAS SĖKMINGAS!"
		Write-Host "Tolimi žingsniai:" -ForegroundColor White
		Write-Host "  1. Paleisti programą: .\diegimas.ps1 -Stage run" -ForegroundColor Gray
		Write-Host "  2. Peržiūrėti dokumentaciją: $DocsDir\html\index.html" -ForegroundColor Gray
		Write-Host ""
	}
	"build" {
		Build-Project
	}
	"test" {
		Run-Tests
	}
	"docs" {
		Generate-Docs
	}
	"run" {
		Run-Program
	}
	"clean" {
		Clean-Build
	}
	default {
		Show-Help
	}
}

Write-Host ""
