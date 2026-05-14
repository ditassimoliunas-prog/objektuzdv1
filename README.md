## v1.2 relisas: Rule of Five ir I/O Operatoriai

### Apžvalga

v1.2 versijoje implementuoti **Rule of Five** principai (destruktorius, copy/move konstruktoriai, copy/move assignment operatoriai) ir **I/O operatoriai** Studentas klasei. Rule of Five yra C++ šablonas, kuris užtikrina tinkamą atmintis valdymą, duomenų kopijimą ir perkėlimą. Studentas klasė naudoja STL konteinerius (string, vector), todėl atmintis valdymas yra automatinis, bet metodai yra pilnai implementuoti dėl geros praktikos ir ateities panaudojimo, jei klasė būtų modifikuota naudoti raw pointerius.

### Rule of Five Metodai

| Metodas | Tikslas |
|---------|---------|
| **Destruktorius** | Atlaisvinusios išteklius |
| **Copy konstruktorius** | Kuria objekto kopiją (deep copy) |
| **Copy assignment** | Priskyrimo operatorius kopijuoti |
| **Move konstruktorius** | Perima išteklius iš laikino objekto |
| **Move assignment** | Priskyrimo operatorius perkelti išteklius |

### I/O Operatoriai

| Operatorius | Funkcija |
|-------------|----------|
| **operator<<** | Išveda studento duomenis (vardas, pavardė, egzaminas, rezultatai, pažymiai) |
| **operator>>** | Nuskaitomas duomenis iš srauto (vardas, pavardė, 5 pažymiai, egzaminas) |

### Programa - Meniu

| Opciją | Veikimas |
|--------|----------|
| 1 | Rankinė ivedis (vardas, pavardė, 5 pažymiai, egzaminas) |
| 2 | Generuoti tik pažymius |
| 3 | Generuoti visus duomenis automatiskai |
| 4 | Nuskaityti iš failo |
| 5 | Sukurti testavimo failus |
| 6 | Atlikti spartos analizę |
| 7 | Baigti darbą |

### Duomenų Ivedis ir Isvedimas

**Rankinė ivedis:** Vartotojas įveda vardą, pavardę, 5 pažymius (1-10) ir egzaminą (1-100)

**Automatinė ivedis:** Duomenys generuojami atsitiktinai

**Ivedis iš failo:** Failas turi formatą `vardas pavarde paz paz paz paz paz egzaminas` (viena eilutė = vienas studentas)

**Isvedimas į ekraną:** `Vardas: X | Pavarde: Y | Egzaminas: Z | Vidurkis: W | Mediana: V | Pazymiai: ...`

**Isvedimas į failą:** Duomenys išsaugomi tokiu pat formatu kaip ekrane

### Testai

| # | Aprašymas |
|---|-----------|
| 1-2 | Default ir parametrizuotas konstruktoriai |
| 3-4 | Copy konstruktorius ir assignment |
| 5-6 | Move konstruktorius ir assignment |
| 7 | Destruktorius (RAII) |
| 8-10 | I/O operatoriai ir round-trip testas |
| 11-13 | Getters/setters, vector operacijos |

### v1.2 Versijos Pakeitimai

- COMMIT #1: Rule of Five deklaracijos
- COMMIT #2: Copy/Move operatorių implementacija
- COMMIT #3: I/O operatoriai
- COMMIT #4: Testai (13 testų)
- COMMIT #5: README dokumentacija

---

## v1.1 relisas: `struct` vs `class` ir Kompiliatoriaus optimizacijos

### 1. `struct` ir `class` spartos palyginimas
Lyginamas `struct` ir `class` realizacijų greitis naudojant programos spartos analizę. 
*Testavimo parametrai: `std::vector` konteineris, 3-oji (algoritmų bibliotekos) skaidymo strategija, Release build (O2 optimizacija).*

| Įrašų skaičius | `struct` laikas (s) | `class` laikas (s) |
| -------------- | ------------------- | ------------------ |
| **100000**     | 0.55363 s           | 0.46851 s          |
| **1000000**    | 4.78121 s           | 4.57017 s          |

*Išvada:*

### 2. Eksperimentinė analizė pagal kompiliatoriaus optimizavimo lygį
*Testavimo parametrai: `class` realizacija, `std::vector` konteineris, 3 strategija, 1 000 000 duomenų failas.* Naudojamas MSVC kompiliatorius (Visual Studio).

| Optimizavimo lygis (Flag)           | `.exe` failo dydis (KB) | Vykdymo laikas (s) |
| ----------------------------------- | ----------------------- | ------------------ |
| **O1** (`/O1` - size optimization)  | [įrašyti dydį] KB       | [įrašyti laiką] s  |
| **O2** (`/O2` - speed optimization) | [įrašyti dydį] KB       | [įrašyti laiką] s  |
| **O3** (`/Ox` - full optimization)  | [įrašyti dydį] KB       | [įrašyti laiką] s  |

*Išvada:* [Trumpi pastebėjimai, kaip keitėsi programos `.exe` failo dydis ir apdorojimo laikas didinant optimizacijos lygius.]
