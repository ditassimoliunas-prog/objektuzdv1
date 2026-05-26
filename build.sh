#!/bin/bash

# ========== ObjektinisUzdavinys v2.0 - Diegimas (Linux/macOS) ==========
# Šis skriptas automatizuoja projektą kompiliavimą, testavimą ir dokumentacijos generavimą
#
# Naudojimas:
#   ./build.sh
#   ./build.sh build
#   ./build.sh test
#   ./build.sh docs
#   ./build.sh clean

set -e  # Išeiti jei kuri nors komanda nepavyksta

# ========== SPALVOS ==========
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# ========== PAGALBINĖS FUNKCIJOS ==========

print_header() {
	echo ""
	echo -e "${CYAN}========================================${NC}"
	echo -e "${CYAN}  $1${NC}"
	echo -e "${CYAN}========================================${NC}"
	echo ""
}

print_success() {
	echo -e "${GREEN}[✓ OK]     $1${NC}"
}

print_error() {
	echo -e "${RED}[✗ KLAIDA] $1${NC}"
}

print_info() {
	echo -e "${YELLOW}[i INFO]   $1${NC}"
}

# ========== KONFIGŪRACIJA ==========

BUILD_DIR="build"
DOCS_DIR="dokumentacija"

# Patikrinkime, ar CMake yra suinstaliuota
if ! command -v cmake &> /dev/null; then
	print_error "CMake nsuinstaliuotas!"
	echo "Linux: sudo apt install cmake"
	echo "macOS: brew install cmake"
	exit 1
fi

print_header "ObjektinisUzdavinys v2.0 - Diegimas"

# ========== BUILD TIKSLAS ==========

build_project() {
	print_info "Konfigūruojame CMake..."
	mkdir -p $BUILD_DIR
	cd $BUILD_DIR
	cmake ..
	if [ $? -ne 0 ]; then
		print_error "CMake konfigūracija nepavyko!"
		exit 1
	fi
	cd ..
	print_success "CMake konfigūracija sėkminga"

	print_info "Kompiliuojame projektą..."
	cmake --build $BUILD_DIR
	if [ $? -ne 0 ]; then
		print_error "Kompiliavimas nepavyko!"
		exit 1
	fi
	print_success "Kompiliavimas sėkmingas!"
}

# ========== TESTŲ TIKSLAS ==========

run_tests() {
	print_info "Vykdome unit testus..."

	if [ ! -f "$BUILD_DIR/test_programa" ]; then
		print_error "Test programa nerasta! Pirmiausia vykdykite: ./build.sh build"
		exit 1
	fi

	$BUILD_DIR/test_programa
	if [ $? -ne 0 ]; then
		print_error "Kai kurie testai nepavyko!"
		exit 1
	fi
	print_success "Visi testai priimti!"
}

# ========== DOKUMENTACIJOS TIKSLAS ==========

generate_docs() {
	print_info "Sugeneruojame Doxygen dokumentaciją..."

	if ! command -v doxygen &> /dev/null; then
		print_error "Doxygen nsuinstaliuotas!"
		echo "Linux: sudo apt install doxygen"
		echo "macOS: brew install doxygen"
		exit 1
	fi

	doxygen Doxyfile
	if [ $? -ne 0 ]; then
		print_error "Doxygen dokumentacijos generavimas nepavyko!"
		exit 1
	fi
	print_success "Dokumentacija sugeneruota!"
	print_info "HTML: $DOCS_DIR/html/index.html"
	print_info "LaTeX: $DOCS_DIR/latex/refman.pdf"
}

# ========== PALEIDIMO TIKSLAS ==========

run_program() {
	print_info "Paleidžiame pagrindinę programą..."

	if [ ! -f "$BUILD_DIR/programa" ]; then
		print_error "Programa nerasta! Pirmiausia vykdykite: ./build.sh build"
		exit 1
	fi

	$BUILD_DIR/programa
}

# ========== VALYMO TIKSLAS ==========

clean_build() {
	print_info "Išvalome build direktorijų..."
	if [ -d "$BUILD_DIR" ]; then
		rm -rf $BUILD_DIR
		print_success "Build direktorija išvalyta!"
	else
		print_info "Build direktorija neegzistuoja"
	fi
}

# ========== HELP TIKSLAS ==========

show_help() {
	print_header "Diegimas - Pagalba"
	echo "Naudojimas: ./build.sh [STAGE]"
	echo ""
	echo "Turimi etapai:"
	echo "  all      Viskas (clean, build, test, docs)"
	echo "  build    Tik kompiliavimas"
	echo "  test     Tik testai (reikalingas build)"
	echo "  docs     Tik dokumentacija"
	echo "  run      Paleisti programą"
	echo "  clean    Išvalyti build"
	echo "  help     Rodyti šią pagalbą"
	echo ""
	echo "Pavyzdžiai:"
	echo "  ./build.sh          # Viskas"
	echo "  ./build.sh build    # Tik build"
	echo "  ./build.sh test     # Tik testai"
	echo ""
}

# ========== PAGRINDINĖ LOGIKA ==========

STAGE=${1:-all}

case $STAGE in
	all)
		clean_build
		build_project
		run_tests
		generate_docs
		print_header "✓ PILNAS DIEGIMAS SĖKMINGAS!"
		echo "Tolimi žingsniai:"
		echo "  1. Paleisti programą: ./build.sh run"
		echo "  2. Peržiūrėti dokumentaciją: open $DOCS_DIR/html/index.html"
		echo ""
		;;
	build)
		build_project
		;;
	test)
		run_tests
		;;
	docs)
		generate_docs
		;;
	run)
		run_program
		;;
	clean)
		clean_build
		;;
	help)
		show_help
		;;
	*)
		show_help
		;;
esac

echo ""
