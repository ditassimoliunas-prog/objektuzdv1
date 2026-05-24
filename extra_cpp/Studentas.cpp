#include "../header_files/Studentas.h"
#include "../header_files/mat_funkcijos.h"
#include <iostream>

using std::istream;

// Nuskaitymas is srauto konstruktoriuje
Studentas::Studentas(std::istream& is) : Zmogus(), egz_(0), rez_(0.0), med_(0.0) {
    readStudent(is);
}

// ===== RULE OF FIVE =====

// Destruktorius
Studentas::~Studentas() {
    paz_.clear();
}

// Copy konstruktorius
Studentas::Studentas(const Studentas& other)
    : Zmogus(other.vardas_, other.pavarde_), paz_(other.paz_),
      egz_(other.egz_), rez_(other.rez_), med_(other.med_) {
}

// Copy assignment operator
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        setVardas(other.getVardas());
        setPavarde(other.getPavarde());
        paz_ = other.paz_;
        egz_ = other.egz_;
        rez_ = other.rez_;
        med_ = other.med_;
    }
    return *this;
}

// Move konstruktorius
Studentas::Studentas(Studentas&& other) noexcept
    : Zmogus(std::move(other.vardas_), std::move(other.pavarde_)),
      paz_(std::move(other.paz_)), egz_(other.egz_), rez_(other.rez_),
      med_(other.med_) {
    other.setEgz(0);
    other.setRez(0.0);
    other.setMed(0.0);
    other.paz_.clear();
}

// Move assignment operator
Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        paz_.clear();
        setVardas(std::move(other.vardas_));
        setPavarde(std::move(other.pavarde_));
        paz_ = std::move(other.paz_);
        egz_ = other.egz_;
        rez_ = other.rez_;
        med_ = other.med_;
        other.setEgz(0);
        other.setRez(0.0);
        other.setMed(0.0);
        other.paz_.clear();
    }
    return *this;
}

// Implementacija abstraktaus metodo iš Zmogus
string Studentas::getInfo() const {
    return getVardas() + " " + getPavarde();
}

// Privati pagalbine funkcija
void Studentas::paskaiciuotiGalutinius() {
    if (!paz_.empty()) {
        double vid = vidurkis(paz_);
        double med = mediana(paz_);
        rez_ = galutinisBalas(vid, egz_);
        med_ = galutinisBalas(med, egz_);
    } else {
        rez_ = egz_ * 0.6;
        med_ = egz_ * 0.6;
    }
}

// Implementacija abstraktaus metodo paskaiciuoti() iš Zmogus
void Studentas::paskaiciuoti() {
    paskaiciuotiGalutinius();
}

// Duomenu nuskaitymas ir apskaiciavimas
std::istream& Studentas::readStudent(std::istream& is) {
    string vardas, pavarde;
    is >> vardas >> pavarde;
    if (!is) return is;
    setVardas(vardas);
    setPavarde(pavarde);
    paz_.clear();
    int p;
    for (int i = 0; i < 5; i++) {
        is >> p;
        paz_.push_back(p);
    }
    is >> egz_;
    paskaiciuotiGalutinius();
    return is;
}

// ===== I/O OPERATORIAI =====

// Išvesties operatorius
std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << "Vardas: " << s.getVardas() << " | Pavarde: " << s.getPavarde() << " | ";
    os << "Egzaminas: " << s.egz_ << " | Vidurkis rezultatas: " << s.rez_ << " | ";
    os << "Mediana rezultatas: " << s.med_ << " | Pazymiai: ";

    if (!s.paz_.empty()) {
        for (int paz : s.paz_) {
            os << paz << " ";
        }
    } else {
        os << "(nera)";
    }

    return os;
}

// ?vesties operatorius - nuskaito student? iš srauto
std::istream& operator>>(std::istream& is, Studentas& s) {
    return s.readStudent(is);
}

// ===== LYGINIMO FUNKCIJOS =====

bool comparePagalVarda(const Studentas& a, const Studentas& b) {
    return a.getVardas() < b.getVardas();
}

bool comparePagalPavarde(const Studentas& a, const Studentas& b) {
    return a.getPavarde() < b.getPavarde();
}

bool comparePagalReza(const Studentas& a, const Studentas& b) {
    return a.getRez() < b.getRez();
}

bool comparePagalMeda(const Studentas& a, const Studentas& b) {
    return a.getMed() < b.getMed();
}
