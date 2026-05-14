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

<img width="437" height="734" alt="image" src="https://github.com/user-attachments/assets/e71d41ea-3766-4f6b-a89f-10bd49b48f55" />

<img width="917" height="729" alt="image" src="https://github.com/user-attachments/assets/0d84eae5-1925-43e6-9843-b34291d9ad27" />

<img width="550" height="394" alt="image" src="https://github.com/user-attachments/assets/d950c503-e1ff-4e3d-8e4a-8bf03867e352" />




