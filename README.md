## v1.1 relisas: `struct` vs `class` ir Kompiliatoriaus optimizacijos

### 1. `struct` ir `class` spartos palyginimas
Lyginamas `struct` ir `class` realizacijų greitis naudojant programos spartos analizę. 
*Testavimo parametrai: `std::vector` konteineris, 3-oji (algoritmų bibliotekos) skaidymo strategija, Release build (O2 optimizacija).*

| Įrašų skaičius | `struct` laikas (s) | `class` laikas (s) |
| -------------- | ------------------- | ------------------ |
| **100000**     | 0.35412 s           | 0.35281 s          |
| **1000000**    | 3.19561 s           | 3.18656 s          |

*Išvada:* `Class` ir `Struct` realizacijų laikai po atidžios testacijos pasirodė lygūs arba vienas į kitą įeinantys paklaidų ribose. Nors objektinis programavimas (per klasės „Getters/Setters“ interfeisus bei papildomus konstruktorius) dažnai asocijuojamas su potencialiomis laiko sąnaudomis, C++ kompiliatorių optimizacijos ir modernūs „inline“ metodai sulygina šiuos tipus iki vientiso greičio. Abiejų duomenų struktūrų atminties pralaidumas su optimizuotais „std::make_move_iterator“ yra praktiškai identiškas.

### 2. Eksperimentinė analizė pagal kompiliatoriaus optimizavimo lygį
*Testavimo parametrai: `class` realizacija, `std::vector` konteineris, 3 strategija, 1 000 000 duomenų failas.* Naudojamas MSVC kompiliatorius (Visual Studio).

| Optimizavimo lygis (Flag)           | `.exe` failo dydis (KB) | Vykdymo laikas (s) |
| ----------------------------------- | ----------------------- | ------------------ |
| **O1** (`/O1` - size optimization)  | 387.5 KB                | 3.49308 s          |
| **O2** (`/O2` - speed optimization) | 472.0 KB                | 3.18656 s          |
| **O3** (`/O3` - full optimization)  | 523.5 KB                | 10.51777 s         | 

*Išvada:* Tyrimo rezultatai lygiai atspindi kiekvieno optimizavimo „flag'o“ teorinę paskirtį:
- **/O1 (dydžio optimizavimas):** Pateikė mažiausią vykdomąjį failą (387.5 KB). Greitis liko artimas geriausiam kompromisui (3.49s).
- **/O2 (greičio optimizavimas):** Akivaizdžiai geriausias kompromisas. Failas išpūstas truputį (472 KB), tačiau pasiektas maksimaliausias vykdymo greitis (3.18s).
- **/O3 (arba Linux/GCC palaikomas standartas):** Smagiai išsipučia failo dydis (523 KB) ir greitis katastrofiškai krenta iki 10 sekundžių. Tai vyksta dėl perdėtų „Function inlining“ ir „Loop unrolling“ procesų, kada mašininio instrukcijų kodo kiekis perlipa tiesioginį CPU Cache atminties dydį ir tampa našumo smukdymu (CPU cache miss penalty), nuolatos ieškant blokų gilesnėje atminties architektūroje.
