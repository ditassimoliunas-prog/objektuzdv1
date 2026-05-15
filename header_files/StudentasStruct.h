#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

struct StudentasStruct {
	string vardas;
	string pavarde;
	vector<int> paz;
	int egz;
	double rez;
	double med;

	// Numatytasis konstruktorius
	StudentasStruct() : vardas("A"), pavarde("BB"), egz(0), rez(0.0), med(0.0) {}

	// Parametrizuotas konstruktorius
	StudentasStruct(string v, string p, int e) : vardas(v), pavarde(p), egz(e), rez(0.0), med(0.0) {}

	// Destruktorius
	~StudentasStruct() {
		paz.clear();
	}

	// Getters
	inline string getVardas() const { return vardas; }
	inline string getPavarde() const { return pavarde; }
	inline const vector<int>& getPaz() const { return paz; }
	inline vector<int>& getPaz() { return paz; }
	inline int getEgz() const { return egz; }
	inline double getRez() const { return rez; }
	inline double getMed() const { return med; }

	// Setters
	inline void setVardas(const string& v) { vardas = v; }
	inline void setPavarde(const string& p) { pavarde = p; }
	inline void setEgz(int e) { egz = e; }
	inline void setRez(double r) { rez = r; }
	inline void setMed(double m) { med = m; }

	// Metodai pazymiams
	inline void addPaz(int p) { paz.push_back(p); }
	inline void clearPaz() { paz.clear(); }
	inline void reservePaz(size_t n) { paz.reserve(n); }
	inline bool isPazEmpty() const { return paz.empty(); }
	inline void setPaz(const vector<int>& p) { paz = p; }
};