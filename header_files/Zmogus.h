#pragma once

#include <iostream>
#include <string>

using std::string;

/**
 * @class Zmogus
 * @brief Abstrakti bazinė klasė bendram žmogaus aprašymui
 * 
 * Ši klasė nuo v1.5 versijos aprašo bendrą žmogaus duomenis (vardas, pavardė).
 * Yra abstrakti - jos objektų kurti negalima, tik iš jos išvestines klases.
 * 
 * Paveldi iš šios klasės: Studentas
 */
class Zmogus {
protected:
	string vardas_;
	string pavarde_;

	/**
	 * @brief Pagalbinis metodas žmogaus duomenims paskaičiuoti
	 * Abstraktus metodas - turi būti implementuotas išvestinėse klasėse
	 */
	virtual void paskaiciuoti() = 0;

public:
	/**
	 * @brief Parametrizuotas konstruktorius
	 * @param v Žmogaus vardas
	 * @param p Žmogaus pavardė
	 */
	Zmogus(const string& v, const string& p)
		: vardas_(v), pavarde_(p) {}

	/**
	 * @brief Parametrizuotas konstruktorius su numatytosiomis reikšmėmis
	 */
	Zmogus() : vardas_("Asmuo"), pavarde_("Asmenys") {}

	/**
	 * @brief Virtualus destruktorius - reikalingas polimorfizmui
	 */
	virtual ~Zmogus() {}

	// ===== GETTERS =====
	/**
	 * @return Žmogaus vardą
	 */
	inline string getVardas() const { return vardas_; }

	/**
	 * @return Žmogaus pavardę
	 */
	inline string getPavarde() const { return pavarde_; }

	// ===== SETTERS =====
	/**
	 * @brief Nustato žmogaus vardą
	 */
	inline void setVardas(const string& v) { vardas_ = v; }

	/**
	 * @brief Nustato žmogaus pavardę
	 */
	inline void setPavarde(const string& p) { pavarde_ = p; }

	// ===== ABSTRAKTUS METODAS =====
	/**
	 * @brief Grąžina žmogaus informaciją
	 * Šis metodas turi būti implementuotas visose išvestinėse klasėse
	 */
	virtual string getInfo() const = 0;

	// ===== I/O OPERATORIAI (friend functions) =====
	/**
	 * @brief Išvesties operatorius - spausdina žmogaus duomenis
	 */
	friend std::ostream& operator<<(std::ostream& os, const Zmogus& z);
};
