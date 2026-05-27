## v2.0 relisas: Unit Testai ir Doxygen Dokumentacija

### Unit Testai (v2.0)

#### Rule of Five Metodai (pagrindiniai):

| Testas # | Metodas | Aprašas |
|----------|---------|---------|
| 1 | Default konstruktorius | Numatytosios reikšmės |
| 2 | Parametrizuotas konstruktorius | Duomenų inicializavimas |
| 3 | Copy konstruktorius | Deep copy operacija |
| 4 | Copy assignment | Duomenų kopijavimas |
| 5 | Move konstruktorius | Išteklių perėmimas |
| 6 | Move assignment | Laikino objekto išteklių perėmimas |
| 7 | Destruktorius | Tinkamas išteklių atlaisvinimas (RAII) |

#### Papildomi Testai (v2.0):

| Testas # | Aprašas |
|----------|---------|
| 8-10 | I/O operatoriai (`operator<<`, `operator>>`) |
| 11-13 | Getters/Setters ir vektoriaus operacijos |
| 14 | Copy vs Move semantika palyginimas |
| 15 | Rule of Five lankstumo testas su vektoriumi |
| 16-17 | Self-assignment saugumas (Copy ir Move) |
| 18 | Assignment operator chaining |
| 19 | Deep copy - vektoriaus duomenų saugumas |
| 20 | Move efficiency - memory optimizacija |

### Testų Vykdymas

**Linux/macOS:**
```bash
cd build
./test_programa
```

**Windows:**
```powershell
cd build
.\Release\test_programa.exe
```
### Doxygen Dokumentacija (v2.0 nauja!)

Dokumentacija sugeneruojama iš source kodo komentarų:

**Sugeneruoti dokumentaciją:**
```bash
doxygen Doxyfile
```

**Rezultatai:**
- `dokumentacija/html/index.html` - HTML dokumentacija
- `dokumentacija/latex/refman.pdf` - PDF dokumentacija

---

## Diegimo Instrukcija

### Sistemos Reikalavimai

- **CMake** ≥ 3.10
- **C++17** kompiliatorius (MSVC, GCC, Clang)
- **Doxygen** (parsisiuntimas: https://www.doxygen.nl/download.html)
- **LaTeX/TeX Live** (PDF generavimui)

### 1. Klonuojame repoziciją

```bash
git clone https://github.com/ditassimoliunas-prog/objektuzdv1.git
cd objektuzdv1
git checkout v2.0
```

### 2. Konfigūruojame CMake

**Linux/macOS:**
```bash
mkdir build
cd build
cmake ..
```

**Windows (MSVC):**
```powershell
mkdir build
cd build
cmake -G "Visual Studio 16 2019" ..
```

### 3. Kompiliuojame projektą

**Linux/macOS:**
```bash
cmake --build .
```

**Windows:**
```powershell
cmake --build . --config Release
```

### 4. Vykdome testus

**Linux/macOS:**
```bash
./test_programa
```

**Windows:**
```powershell
.\Release\test_programa.exe
```

### 5. Sugeneruojame Doxygen dokumentaciją

```bash
cd ..  # Grįžtame į projekto šaknį
doxygen Doxyfile
```

---

## Naudojimosi Instrukcija

### Pagrindinės Programos Paleidimas

**Linux/macOS:**
```bash
./build/programa
```

**Windows:**
```powershell
.\build\Release\programa.exe
```

### Programos Meniu

| Opciją | Veikimas |
|--------|----------|
| 1 | Rankininis įvedimas (vardas, pavardė, 5 pažymiai, egzaminas) |
| 2 | Generuoti tik pažymius |
| 3 | Generuoti visus duomenis automatiškai |
| 4 | Nuskaityti iš failo |
| 5 | Sukurti testavimo failus |
| 6 | Atlikti spartos analizę |
| 7 | Baigti darbą |

## Projekto Failų Struktūra

```
objektuzdv1/
├── CMakeLists.txt              # Build konfigūracija
├── Doxyfile                    # Doxygen konfigūracija (v2.0)
├── README.md                   # Šis failas
├── .gitignore                  # Git taisyklės
│
├── header_files/               # Klasių aprašymai
│   ├── Zmogus.h               # Abstrakti bazė
│   ├── Studentas.h            # Studentas klasė
│   ├── mat_funkcijos.h
│   ├── menu.h
│   └── ...
│
├── extra_cpp/                  # Implementacijos
│   ├── Zmogus.cpp
│   ├── Studentas.cpp
│   ├── mat_funkcijos.cpp
│   └── ...
│
├── objekt1uzd.cpp             # Pagrindinė programa
├── test_studentas.cpp         # Unit testai (v2.0 išplėsti)
│
├── dokumentacija/             # Sugeneruota Doxygen (v2.0)
│   ├── html/
│   └── latex/
│
└── build/                      # CMake build direktorija (git ignored)
```

---

## Klaidų Sprendimas

### Klaida: "CMake not found"
```bash
# Instaliuoti CMake
# Windows: https://cmake.org/download/
# Linux: sudo apt install cmake
# macOS: brew install cmake
```

### Klaida: "C++ compiler not found"
```bash
# Windows: Instaliuoti Visual Studio Build Tools
# Linux: sudo apt install build-essential
# macOS: xcode-select --install
```

### Klaida: "Doxygen not found"
```bash
# Parsisiųsti iš https://www.doxygen.nl/download.html
# Arba: brew install doxygen (macOS)
```

---

<img width="424" height="722" alt="Screenshot 2026-05-24 171304" src="https://github.com/user-attachments/assets/378556d4-baec-41be-ba2b-20b1401cf511" />
<img width="835" height="689" alt="Screenshot 2026-05-24 171330" src="https://github.com/user-attachments/assets/8f343a65-4895-40bf-aa0c-5da988354cf1" />
<img width="459" height="383" alt="Screenshot 2026-05-24 171440" src="https://github.com/user-attachments/assets/452b239b-0c8e-47ff-bfcb-115a8902081d" />







