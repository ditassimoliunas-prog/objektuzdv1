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
    // Nustatiname kitą objektą į validią, tuščią būseną
    other.egz_ = 0;
    other.rez_ = 0.0;
    other.med_ = 0.0;
    other.paz_.clear();  // Užtikrinti, kad vektorius yra tuščias
}

// Move assignment operator
Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        // Išvalome savo esamus duomenis
        paz_.clear();

        // Perkėlime duomenis iš other
        vardas_ = std::move(other.vardas_);
        pavarde_ = std::move(other.pavarde_);
        paz_ = std::move(other.paz_);
        egz_ = other.egz_;
        rez_ = other.rez_;
        med_ = other.med_;

        // Nustatiname other objektą į validią, tuščią būseną
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

// ===== I/O OPERATORIAI =====

// Išvesties operatorius - išspausdina student? ? sraut?
std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << "Vardas: " << s.vardas_ << " | Pavarde: " << s.pavarde_ << " | ";
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
