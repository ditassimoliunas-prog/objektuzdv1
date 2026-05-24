## v1.5 relisas: Abstrakti Klasė Žmogus ir Paveldėjimas

### Apžvalga

v1.5 versijoje projektas perrašytas su objektinio programavimo paveldėjimo principais. Sukurta abstrakti bazinė klasė `Žmogus`, iš kurios paveldi `Studentas` klasė. Žmogus klasė yra abstrakti - jos objektų kurti negalima, tik iš jos išvestinių klasių.

### Klasių Hierarchija

Bazinė abstrakti klasė `Žmogus` saugo bendrus žmogaus atributus (vardas, pavardė) ir apibrėžia abstraktus metodus `getInfo()` ir `paskaiciuoti()`. Iš jos paveldi `Studentas` klasė, kuri implementuoja šiuos abstraktus metodus ir prideda savus duomenis (pažymiai, egzaminas, galutinius rezultatus).

### Abstrakti Klasė Žmogus

| Funkcionalumas | Aprašas |
|----------------|---------|
| **Bazinės savybės** | vardas_, pavarde_ (protected - prieinamos tik išvestinėms klasėms) |
| **Virtualus destruktorius** | Reikalingas tinkamam polimorfizmui |
| **Abstraktūs metodai** | getInfo(), paskaiciuoti() - turi būti implementuoti išvestinėse klasėse |
| **Getters/Setters** | getVardas(), getPavarde(), setVardas(), setPavarde() |
| **Objektų kūrimas** | **NEGALIMA** kurti Žmogus objektų tiesiai |

### Studentas Klasė (Išvestinė iš Žmogus)

`Studentas` yra išvestinė klasė, kuri paveldi iš `Žmogus`. Ji implementuoja abstraktus metodus ir prideda savus duomenis bei funkcionalumą.

| Metodas | Tikslas | Statusas |
|---------|---------|----------|
| **Destruktorius** | Atlaisvinusios išteklius | Implementuotas |
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
| 1 | Rankinė ivedis (vardas, pavardė, 5 pažymiai, egzaminas) |
| 2 | Generuoti tik pažymius |
| 3 | Generuoti visus duomenis automatiskai |
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
| **Veikimo logika** | Tokia pati | Identiska |
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

1. Vartotojas pasirenka iš meniu (rankinė ivedis, automatinė, iš failo, etc.)
2. Nuskaito arba generuoja studentų duomenis
3. Skaičiuoja galutinius rezultatus (vidurkis ir mediana)
4. Rūšiuoja studentus pagal vardą, pavardę arba rezultatą
5. Išveda rezultatus į ekraną arba failą

**Svarbu:** Nuo v1.5 versijos, žmogaus savybės (vardas, pavardė) saugomos Žmogus bazinėje klasėje, o Studentas jas paveldi. Tai leidžia ateityje kurti kitas išvestines klases iš Žmogaus (pvz. Dėstytojas, Administratorius).

<img width="437" height="734" alt="image" src="https://github.com/user-attachments/assets/e71d41ea-3766-4f6b-a89f-10bd49b48f55" />

<img width="917" height="729" alt="image" src="https://github.com/user-attachments/assets/0d84eae5-1925-43e6-9843-b34291d9ad27" />

<img width="550" height="394" alt="image" src="https://github.com/user-attachments/assets/d950c503-e1ff-4e3d-8e4a-8bf03867e352" />




