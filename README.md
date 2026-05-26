## v1.5 relisas: Abstrakti Klasė Žmogus ir Paveldėjimas

### Apžvalga

v1.5 versijoje projektas perrašytas su objektinio programavimo paveldėjimo principais. Sukurta abstrakti bazinė klasė `Žmogus`, iš kurios paveldima `Studentas` klasė. Žmogus klasė yra abstrakti - jos objektų kurti negalima, tik iš jos išvestinių klasių.

### Klasių Hierarchija

Bazinė abstrakti klasė `Žmogus` saugo bendrus žmogaus atributus (vardas, pavardė) ir apibrėžia abstrakčius metodus `getInfo()` ir `paskaiciuoti()`. Iš jos paveldi `Studentas` klasė, kuri implementuoja šiuos abstrakčius metodus ir prideda savus duomenis (pažymiai, egzaminas, galutinius rezultatus).

### Abstrakti Klasė Žmogus

| Funkcionalumas | Aprašas |
|----------------|---------|
| **Bazinės savybės** | vardas_, pavarde_ (protected - prieinamos tik išvestinėms klasėms) |
| **Virtualus destruktorius** | Reikalingas tinkamam polimorfizmui |
| **Abstraktūs metodai** | getInfo(), paskaiciuoti() - turi būti implementuoti išvestinėse klasėse |
| **Getters/Setters** | getVardas(), getPavarde(), setVardas(), setPavarde() |
| **Objektų kūrimas** | **NEGALIMA** kurti Žmogus objektų tiesiai |

### Studentas Klasė (Išvestinė iš Žmogus)

`Studentas` yra išvestinė klasė, kuri paveldi iš `Žmogus`. Ji implementuoja abstrakčius metodus ir prideda savus duomenis bei funkcionalumą.

| Metodas | Tikslas | Statusas |
|---------|---------|----------|
| **Destruktorius** | Atlaisvina išteklius | Implementuotas |
| **Copy konstruktorius** | Kuria objekto kopiją (deep copy) | Implementuotas |
| **Copy assignment** | Priskyrimo operatorius kopijuoti | Implementuotas |
| **Move konstruktorius** | Perima išteklius iš laikino objekto | Implementuotas |
| **Move assignment** | Priskyrimo operatorius perkelti | Implementuotas |
| **getInfo()** | Grąžina vardą ir pavardę (abstraktaus metodo realizacija) | Implementuotas |
| **paskaiciuoti()** | Skaičiuoja galutinius rezultatus (abstraktaus metodo realizacija) | Implementuotas |

### I/O Operatoriai (iš v1.2, išlaikyti)

| Operatorius | Funkcija |
|-------------|----------|
| **operator<<** | Išveda studento duomenis (vardas, pavardė, egzaminas, rezultatai, pažymiai) |
| **operator>>** | Nuskaitomas duomenis iš srauto (vardas, pavardė, 5 pažymiai, egzaminas) |

### Programa - Meniu (iš v1.2, išlaikytas)

| Opciją | Veikimas |
|--------|----------|
| 1 | Rankininis įvedimas (vardas, pavardė, 5 pažymiai, egzaminas) |
| 2 | Generuoti tik pažymius |
| 3 | Generuoti visus duomenis automatiškai |
| 4 | Nuskaityti iš failo |
| 5 | Sukurti testavimo failus |
| 6 | Atlikti spartos analizę |
| 7 | Baigti darbą |

### v1.5 Pokyčiai vs v1.2

| Elementas | v1.2 | v1.5 |
|-----------|------|------|
| **Klasių skaičius** | 1 (tik Studentas) | 2 (Žmogus + Studentas) |
| **Paveldėjimas** | Nėra | Studentas paveldi iš Žmogaus |
| **Abstrakti klasė** | Ne | Žmogus - abstrakti bazė |
| **Žmogaus savybės** | Tiesiai Studentas klasėje | Perkeltos į Žmogus bazę |
| **Rule of Five** | Implementuota | Išlaikyta |
| **I/O operatoriai** | Yra | Išlaikyti |
| **Veikimo logika** | Tokia pati | Identiška |
| **Testai** | Veikia | Visi veikia nepakeisti |

### Testai (iš v1.2, visi veikia v1.5)

Visi v1.2 versijoje parašyti testai veikia ir v1.5 versijoje be jokių pakeitimų:

| # | Aprašymas | Statusas |
|---|-----------|----------|
| 1-2 | Default ir parametrizuotas konstruktoriai | Veikia |
| 3-4 | Copy konstruktorius ir assignment | Veikia |
| 5-6 | Move konstruktorius ir assignment | Veikia |
| 7 | Destruktorius (RAII) | Veikia |
| 8-10 | I/O operatoriai ir round-trip testas | Veikia |
| 11-13 | Getters/setters, vector operacijos | Veikia |

### Veikimo Principas

Programos logika išlieka ta pati kaip v1.2:

1. Vartotojas pasirenka iš meniu (rankinis įvedimas, automatinė, iš failo, etc.)
2. Nuskaito arba generuoja studentų duomenis
3. Skaičiuoja galutinius rezultatus (vidurkis ir mediana)
4. Rūšiuoja studentus pagal vardą, pavardę arba rezultatą
5. Išveda rezultatus į ekraną arba failą

**Svarbu:** Nuo v1.5 versijos, žmogaus savybės (vardas, pavardė) saugomos Žmogus bazinėje klasėje, o Studentas jas paveldi. Tai leidžia ateityje kurti kitas išvestines klases iš Žmogaus (pvz. Dėstytojas, Administratorius).

---

## v2.0 relisas: Unit Testai ir Doxygen Dokumentacija

### v2.0 Novacijos

v2.0 versija papildo v1.5 su akademiniais reikalavimais:

| Komponentas | v1.5 | v2.0 |
|-------------|------|------|
| **Unit Testai** | Ne | ✅ 20 testų su Rule of Five |
| **Doxygen Dokumentacija** | Ne | ✅ HTML ir PDF |
| **CMake Build** | Bazinė | ✅ Su test target |
| **Repo Tvarkymas** | Dalinai | ✅ Švari, be IDE failų |
| **README Instrukcijos** | Nėra | ✅ Diegimas, paleidimas, testai |

### Unit Testai (v2.0 nauja!)

Parašyti **20 testų** naudojant `assert()` ir custom testavimo sistemą:

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

**Sėkmingo vykdymo rezultatas:**
```
============================================================
  STUDENTAS KLASES VISOS METODU TESTAI
  RULE OF FIVE DEMONTRACIJA
============================================================
[PRIIMTAS] Vardas inicijuotas i 'A'
[PRIIMTAS] Pavarde inicijuota i 'BB'
...
[PRIIMTAS] Pazymiai pridedami teisingai

============================================================
TESTO REZULTATAI:
Priimti testai: 87
Nepriimti testai: 0
============================================================

VISI TESTAI PRIIMTI! Sveikiname su Rule of Five demontracija!
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

### Naudojimosi Pavyzdys

```
====== PAGRINDINIS MENIU ======
1 - Rankininis ivedimas
2 - Generuoti pažymius
3 - Generuoti visus duomenis
4 - Nuskaityti iš failo
5 - Sukurti testavimo failus
6 - Atlikti spartos analiz
7 - Baigti darb
Pasirinkite: 3
Kiek studentų generuoti? 5
Studentai sugeneruoti!
```

---

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







