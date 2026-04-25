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
