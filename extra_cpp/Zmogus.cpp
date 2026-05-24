#include "../header_files/Zmogus.h"
#include <iostream>

using std::ostream;

/**
 * @brief Išvesties operatorius - spausdina žmogaus pagrindinius duomenis
 * @param os Išvesties srautas
 * @param z Žmogaus objektas
 * @return Išvesties srautas
 */
std::ostream& operator<<(std::ostream& os, const Zmogus& z) {
	os << "Vardas: " << z.vardas_ << " | Pavarde: " << z.pavarde_;
	return os;
}
