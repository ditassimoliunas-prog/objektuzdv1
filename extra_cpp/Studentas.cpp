#include "../header_files/Studentas.h"
#include "../header_files/mat_funkcijos.h"
#include <iostream>

using std::istream;

// Nuskaitymas is srauto konstruktoriuje
Studentas::Studentas(std::istream& is) : egz_(0), rez_(0.0), med_(0.0) {
    readStudent(is);
}

// ===== RULE OF FIVE IMPLEMENTACIJA =====

// Destruktorius
Studentas::~Studentas() {
    paz_.clear();
}

// Copy konstruktorius
Studentas::Studentas(const Studentas& other)
    : vardas_(other.vardas_), pavarde_(other.pavarde_), paz_(other.paz_),
      egz_(other.egz_), rez_(other.rez_), med_(other.med_) {
}

// Copy assignment operator
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        paz_ = other.paz_;
        egz_ = other.egz_;
        rez_ = other.rez_;
        med_ = other.med_;
    }
    return *this;
}

// Move konstruktorius
Studentas::Studentas(Studentas&& other) noexcept
    : vardas_(std::move(other.vardas_)), pavarde_(std::move(other.pavarde_)),
      paz_(std::move(other.paz_)), egz_(other.egz_), rez_(other.rez_),
      med_(other.med_) {
    other.egz_ = 0;
    other.rez_ = 0.0;
    other.med_ = 0.0;
}

// Move assignment operator
Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        paz_.clear();
        vardas_ = std::move(other.vardas_);
        pavarde_ = std::move(other.pavarde_);
        paz_ = std::move(other.paz_);
        egz_ = other.egz_;
        rez_ = other.rez_;
        med_ = other.med_;
        other.egz_ = 0;
        other.rez_ = 0.0;
        other.med_ = 0.0;
        other.paz_.clear();
    }
    return *this;
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

// Duomenu nuskaitymas ir apskaiciavimas
std::istream& Studentas::readStudent(std::istream& is) {
    is >> vardas_ >> pavarde_;
    if (!is) return is;
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
