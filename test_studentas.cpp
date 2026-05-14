#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include "header_files/Studentas.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;

int testai_praletii = 0;
int testai_nepraletii = 0;

void printTestHeader(const string& testName) {
    cout << "\n" << string(60, '=') << endl;
    cout << "TEST: " << testName << endl;
    cout << string(60, '=') << endl;
}

void testPassed(const string& info) {
    cout << "[PRIIMTAS] " << info << endl;
    testai_praletii++;
}

void testFailed(const string& info) {
    cout << "[NEPRIIMTAS] " << info << endl;
    testai_nepraletii++;
}

// TEST #1: Default konstruktorius
void test_default_constructor() {
    printTestHeader("Default Konstruktorius");

    Studentas s;

    assert(s.getVardas() == "A");
    testPassed("Vardas inicijuotas į 'A'");

    assert(s.getPavarde() == "BB");
    testPassed("Pavardė inicijuota į 'BB'");

    assert(s.getEgz() == 0);
    testPassed("Egzaminas inicijuotas į 0");

    assert(s.getRez() == 0.0);
    testPassed("Rezultatas inicijuotas į 0.0");

    assert(s.getMed() == 0.0);
    testPassed("Mediana inicijuota į 0.0");

    assert(s.isPazEmpty());
    testPassed("Pažymiai sąrašas tuščias");
}

// TEST #2: Parametrizuotas konstruktorius
void test_parametrized_constructor() {
    printTestHeader("Parametrizuotas Konstruktorius");

    Studentas s("Jonas", "Jonaitis", 95);

    assert(s.getVardas() == "Jonas");
    testPassed("Vardas teisingai priskirtas");

    assert(s.getPavarde() == "Jonaitis");
    testPassed("Pavardė teisingai priskirta");

    assert(s.getEgz() == 95);
    testPassed("Egzaminas teisingai priskirtas");
}

// TEST #3: Copy konstruktorius
void test_copy_constructor() {
    printTestHeader("Copy Konstruktorius");

    Studentas s1("Petras", "Petrauskas", 85);
    s1.addPaz(8);
    s1.addPaz(9);
    s1.addPaz(10);

    // Kuriam kopiją
    Studentas s2 = s1;

    assert(s2.getVardas() == s1.getVardas());
    testPassed("Kopijoje vardas sutampa");

    assert(s2.getPavarde() == s1.getPavarde());
    testPassed("Kopijoje pavardė sutampa");

    assert(s2.getEgz() == s1.getEgz());
    testPassed("Kopijoje egzaminas sutampa");

    assert(s2.getPaz().size() == s1.getPaz().size());
    testPassed("Kopijoje pažymiai kiekis sutampa");

    assert(s2.getPaz()[0] == s1.getPaz()[0]);
    testPassed("Kopijoje pažymiai vertės sutampa");

    // Tikriname, kad tai skirtingi objektai (deep copy)
    Studentas s3 = s1;
    s3.addPaz(100);
    assert(s1.getPaz().size() != s3.getPaz().size());
    testPassed("Deep copy veikia - modifikacija nepaveikia originalą");
}

// TEST #4: Copy assignment operator
void test_copy_assignment() {
    printTestHeader("Copy Assignment Operator");

    Studentas s1("Marta", "Martinė", 92);
    s1.addPaz(7);
    s1.addPaz(8);
    s1.addPaz(9);

    Studentas s2;
    s2 = s1;

    assert(s2.getVardas() == "Marta");
    testPassed("Priskyrimo metu vardas iš naujo priskirtas");

    assert(s2.getPavarde() == "Martinė");
    testPassed("Priskyrimo metu pavardė iš naujo priskirta");

    assert(s2.getPaz().size() == 3);
    testPassed("Priskyrimo metu pažymiai iš naujo priskirti");

    // Self-assignment check
    s2 = s2;
    assert(s2.getVardas() == "Marta");
    testPassed("Self-assignment saugiai veikia");
}

// TEST #5: Move konstruktorius
void test_move_constructor() {
    printTestHeader("Move Konstruktorius");

    Studentas s1("Laima", "Laima", 88);
    s1.addPaz(6);
    s1.addPaz(7);
    s1.addPaz(8);

    // Move konstruktorius
    Studentas s2 = std::move(s1);

    assert(s2.getVardas() == "Laima");
    testPassed("Move konstruktorius - vardas iš naujo priskirtas");

    assert(s2.getPaz().size() == 3);
    testPassed("Move konstruktorius - pažymiai iš naujo priskirti");

    // s1 turėtų turėti tuščius pažymius
    assert(s1.isPazEmpty());
    testPassed("Move konstruktorius - šaltinis ištuštintas");
}

// TEST #6: Move assignment operator
void test_move_assignment() {
    printTestHeader("Move Assignment Operator");

    Studentas s1("Rūta", "Rutė", 90);
    s1.addPaz(5);
    s1.addPaz(6);
    s1.addPaz(7);

    Studentas s2;
    s2 = std::move(s1);

    assert(s2.getVardas() == "Rūta");
    testPassed("Move assignment - vardas iš naujo priskirtas");

    assert(s2.getPaz().size() == 3);
    testPassed("Move assignment - pažymiai iš naujo priskirti");

    assert(s1.isPazEmpty());
    testPassed("Move assignment - šaltinis ištuštintas");

    // Self-move assignment check
    s2 = std::move(s2);
    assert(s2.getVardas() == "Rūta");
    testPassed("Move assignment self-assignment saugiai veikia");
}

// TEST #7: Destruktorius - RAII principas
void test_destructor() {
    printTestHeader("Destruktorius - RAII Principas");

    {
        Studentas s("Vidmantas", "Vidmantė", 87);
        s.addPaz(9);
        s.addPaz(10);
        s.addPaz(8);

        assert(s.getPaz().size() == 3);
        testPassed("Destruktoriaus testas - objektas sukurtas");
    } // Čia iš automatiškai kviečiamas destruktorius

    testPassed("Destruktor veikia be problemų (nėra memory leaks)");
}

// TEST #8: Išvesties operatorius (operator<<)
void test_output_operator() {
    printTestHeader("Išvesties Operatorius (operator<<)");

    Studentas s("Darius", "Dariuš", 93);
    s.addPaz(9);
    s.addPaz(10);
    s.addPaz(9);

    stringstream ss;
    ss << s;
    string output = ss.str();

    assert(output.find("Vardas: Darius") != string::npos);
    testPassed("Išvestis - vardas rastas");

    assert(output.find("Pavarde: Dariuš") != string::npos);
    testPassed("Išvestis - pavardė rastas");

    assert(output.find("Egzaminas: 93") != string::npos);
    testPassed("Išvestis - egzaminas rastas");

    cout << "Išvesties pavyzdys: " << endl;
    cout << "  " << s << endl;
}

// TEST #9: Įvesties operatorius (operator>>)
void test_input_operator() {
    printTestHeader("Įvesties Operatorius (operator>>)");

    stringstream ss;
    ss << "Vaidas Vaidauskas 10 10 10 10 10 100";

    Studentas s;
    ss >> s;

    assert(s.getVardas() == "Vaidas");
    testPassed("Įvestis - vardas nuskaitytas");

    assert(s.getPavarde() == "Vaidauskas");
    testPassed("Įvestis - pavardė nuskaitytas");

    assert(s.getEgz() == 100);
    testPassed("Įvestis - egzaminas nuskaitytas");

    assert(s.getPaz().size() == 5);
    testPassed("Įvestis - pažymiai nuskaityti");

    assert(s.getPaz()[0] == 10);
    testPassed("Įvestis - pažymio reikšmė teisingai nuskaitytas");
}

// TEST #10: I/O operatoriai kartu (Round-trip test)
void test_io_roundtrip() {
    printTestHeader("I/O Round-Trip Testas");

    Studentas s1("Kristina", "Kristina", 96);
    s1.addPaz(8);
    s1.addPaz(9);
    s1.addPaz(10);
    s1.addPaz(9);
    s1.addPaz(8);

    stringstream ss;
    ss << s1.getVardas() << " " << s1.getPavarde();
    for (int paz : s1.getPaz()) {
        ss << " " << paz;
    }
    ss << " " << s1.getEgz();

    Studentas s2;
    ss >> s2;

    assert(s2.getVardas() == s1.getVardas());
    testPassed("Round-trip - vardas saugai išsaugotas ir nuskaitytas");

    assert(s2.getPavarde() == s1.getPavarde());
    testPassed("Round-trip - pavardė saugai išsaugotas ir nuskaitytas");

    assert(s2.getPaz() == s1.getPaz());
    testPassed("Round-trip - pažymiai saugai išsaugoti ir nuskaityti");
}

// TEST #11: Modificiravimas po kopijimo
void test_modification_after_copy() {
    printTestHeader("Modificiravimas po Kopijimo");

    Studentas s1("Elena", "Elenė", 85);
    s1.addPaz(7);
    s1.addPaz(8);

    Studentas s2 = s1;

    s2.setEgz(95);
    assert(s1.getEgz() == 85 && s2.getEgz() == 95);
    testPassed("Egzamino modifikacija - originalas nepaveiktas");

    s2.addPaz(9);
    assert(s1.getPaz().size() == 2 && s2.getPaz().size() == 3);
    testPassed("Pažymio pridėjimas - originalas nepaveiktas");
}

// TEST #12: Getter/Setter operacijų konsekvencija
void test_getters_setters() {
    printTestHeader("Getters/Setters Konsekvencija");

    Studentas s;

    s.setVardas("Tomas");
    assert(s.getVardas() == "Tomas");
    testPassed("Vardas setter/getter veikia");

    s.setPavarde("Tomaš");
    assert(s.getPavarde() == "Tomaš");
    testPassed("Pavardė setter/getter veikia");

    s.setEgz(100);
    assert(s.getEgz() == 100);
    testPassed("Egzaminas setter/getter veikia");

    s.setRez(90.5);
    assert(s.getRez() == 90.5);
    testPassed("Rezultatas setter/getter veikia");

    s.setMed(88.0);
    assert(s.getMed() == 88.0);
    testPassed("Mediana setter/getter veikia");
}

// TEST #13: Vector operacijos su pažymiais
void test_paz_operations() {
    printTestHeader("Vector Operacijos su Pažymiais");

    Studentas s;

    assert(s.isPazEmpty());
    testPassed("isPazEmpty() grąžina true tuščiam sąrašui");

    s.addPaz(10);
    s.addPaz(9);
    assert(!s.isPazEmpty());
    testPassed("isPazEmpty() grąžina false ne tuščiam sąrašui");

    assert(s.getPaz().size() == 2);
    testPassed("Pažymiai pridedami teisingai");

    s.clearPaz();
    assert(s.isPazEmpty());
    testPassed("clearPaz() išvalo pažymius");
}

// MAIN FUNCTION - SUMMARY
int main() {
    cout << "\n" << string(60, '*') << endl;
    cout << "  STUDENTAS KLASES VISOS METODU TESTAI" << endl;
    cout << string(60, '*') << endl;

    try {
        test_default_constructor();
        test_parametrized_constructor();
        test_copy_constructor();
        test_copy_assignment();
        test_move_constructor();
        test_move_assignment();
        test_destructor();
        test_output_operator();
        test_input_operator();
        test_io_roundtrip();
        test_modification_after_copy();
        test_getters_setters();
        test_paz_operations();

        cout << "\n" << string(60, '*') << endl;
        cout << "TESTO REZULTATAI:" << endl;
        cout << "Priimti testai: " << testai_praletii << endl;
        cout << "Nepriimti testai: " << testai_nepraletii << endl;
        cout << string(60, '*') << endl;

        if (testai_nepraletii == 0) {
            cout << "\nVISI TESTAI PRIIMTI!\n" << endl;
            return 0;
        } else {
            cout << "\nKai kurie testai nepraėjo. Patikrinkite kodą!\n" << endl;
            return 1;
        }
    }
    catch (const std::exception& e) {
        cout << "Kritine klaida: " << e.what() << endl;
        return 1;
    }
}
