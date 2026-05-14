#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Studentas {
private:
    string vardas_;
    string pavarde_;
    vector<int> paz_;
    int egz_;
    double rez_;
    double med_;

    // Privatus helperis perstatymui, jei norėsime
    void paskaiciuotiGalutinius();

public:
    // Numatytasis konstruktorius
    Studentas() : vardas_("A"), pavarde_("BB"), egz_(0), rez_(0.0), med_(0.0) {}

    // Parametrizuotas konstruktorius
    Studentas(string v, string p, int e) : vardas_(v), pavarde_(p), egz_(e), rez_(0.0), med_(0.0) {}

    // Konstruktorius su nuskaitymu is srauto
    Studentas(std::istream& is);

    // ===== RULE OF FIVE =====
    // Destruktorius
    ~Studentas();

    // Copy konstruktorius
    Studentas(const Studentas& other);

    // Copy assignment operator
    Studentas& operator=(const Studentas& other);

    // Move konstruktorius
    Studentas(Studentas&& other) noexcept;

    // Move assignment operator
    Studentas& operator=(Studentas&& other) noexcept;

    // Getters
    inline string getVardas() const { return vardas_; }
    inline string getPavarde() const { return pavarde_; }
    inline const vector<int>& getPaz() const { return paz_; }
    inline vector<int>& getPaz() { return paz_; }
    inline int getEgz() const { return egz_; }
    inline double getRez() const { return rez_; }
    inline double getMed() const { return med_; }

    // Setters
    inline void setVardas(const string& v) { vardas_ = v; }
    inline void setPavarde(const string& p) { pavarde_ = p; }
    inline void setEgz(int e) { egz_ = e; }
    inline void setRez(double r) { rez_ = r; }
    inline void setMed(double m) { med_ = m; }

    // Methods for pazymiai
    inline void addPaz(int p) { paz_.push_back(p); }
    inline void clearPaz() { paz_.clear(); }
    inline void reservePaz(size_t n) { paz_.reserve(n); }
    inline bool isPazEmpty() const { return paz_.empty(); }
    inline void setPaz(const vector<int>& p) { paz_ = p; }

    // Skaitymas ir skaičiavimas
    std::istream& readStudent(std::istream& is);

    // ===== I/O OPERATORIAI =====
    // Išvesties operatorius (friend)
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);

    // Įvesties operatorius (friend)
    friend std::istream& operator>>(std::istream& is, Studentas& s);
};

// Ne klasės narės, bet su klase tiesiogiai susijusios lyginimo funkcijos
bool comparePagalVarda(const Studentas& a, const Studentas& b);
bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalReza(const Studentas& a, const Studentas& b);
bool comparePagalMeda(const Studentas& a, const Studentas& b);

