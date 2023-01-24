#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"
#include "Profesor.h"
#include "Seminarski.h"
using namespace std;

inline int meni() {
    cout << "1. Unos studenta\n";
    cout << "2. Unos profesora\n";
    cout << "3. Ispis svih studenata\n";
    cout << "4. Ispis svih profesora\n";
    cout << "5. Kreiranje seminarskog rada\n";
    cout << "6. Ispis podataka o seminarskim radovima\n";
    cout << "7. Ispis studenata sa seminarskim radom kod odredenog profesora\n";
    cout << "0. Izlaz\n\nIzbor: ";

    int pom;
    do {
        cin >> pom;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (pom < 0 || pom > 7);
    cin.ignore();
    return pom;
}

int main() {
    vector<Student> studenti;
    vector<Profesor> profesori;
    vector<Seminarski> seminarskiRadovi;

    int izbor;
    while ((izbor = meni())) {
        switch (izbor) {
        case 1: {
            Student s;
            cin >> s;
            for (const auto& student : studenti) if (student.brIndeksa == s.brIndeksa) {
                cout << "Student s unesenim brojem indeksa vec postoji!\n";
                break;
            }
            studenti.push_back(s);
            cout << "Podaci o studentu uneseni!\n";
            break;
        }
        case 2: {
            Profesor p;
            cin >> p;
            for (const auto& profesor : profesori) if (profesor.id == p.id) {
                cout << "Profesor s unesenim ID-em vec postoji!\n";
                break;
            }
            profesori.push_back(p);
            cout << "Podaci o profesoru uneseni!\n";
            break;
        }
        case 3: {
            if (studenti.empty()) {
                cout << "Nema unesenih studenata!\n";
                break;
            }
            for (const auto& s : studenti) cout << s;
            break;
        }
        case 4: {
            if (profesori.empty()) {
                cout << "Nema unesenih profesora!\n";
                break;
            }
            for (const auto& p : profesori) cout << p;
            break;
        }
        case 5: {
            if (studenti.empty() || profesori.empty()) {
                cout << "Mora biti unesen barem jedan student i profesor!\n";
                break;
            }
            Seminarski s;
            cout << "Unos podataka o seminarskom radu:\n";
            cin >> s;
            bool studentPronaden = false;
            for (const auto& st : studenti) {
                if (st.brIndeksa == s.studentIndeks) {
                    studentPronaden = true;
                    break;
                }
            }
            if (!studentPronaden) {
                cout << "Ne postoji student s unesenim brojem indeksa!\n";
                break;
            }

            if (find_if(profesori.begin(), profesori.end(), [&s](Profesor& p) {
                return p.id == s.profesorId;
                }) == profesori.end()) {
                cout << "Ne postoji profesor s unesenim id-em!\n";
                break;
            }

            if (find_if(seminarskiRadovi.begin(), seminarskiRadovi.end(), [&s](Seminarski& si) {
                return si.studentIndeks == s.studentIndeks;
                }) != seminarskiRadovi.end()) {
                cout << "Student vec ima prijavljen seminarski rad!\n";
                break;
            }

            seminarskiRadovi.push_back(s);
            cout << "Podaci o seminarskom radu uneseni!\n";
            break;
        }
        case 6: {
            if (seminarskiRadovi.empty()) {
                cout << "Nema unesenih seminarskih radova!\n";
                break;
            }
            for (const auto& seminarski : seminarskiRadovi) {
                Profesor p = *find_if(profesori.begin(), profesori.end(), [&seminarski](Profesor& p) {
                    return p.id == seminarski.profesorId;
                    });
                Student s = *find_if(studenti.begin(), studenti.end(), [&seminarski](Student& s) {
                    return s.brIndeksa == seminarski.studentIndeks;
                    });
                cout << seminarski.naziv << " - " << p.ime << " " << p.prezime << " - " << s.ime << " " << s.prezime << std::endl;
            }
            break;
        }
        case 7: {
            if (profesori.empty()) {
                cout << "Nema unesenih profesora!\n";
                break;
            }
            int profesorId;
            cout << "Unesite ID profesora za pretragu: ";
            cin >> profesorId;
            for (const auto& seminarski : seminarskiRadovi) if (seminarski.profesorId == profesorId)
                cout << *find_if(studenti.begin(), studenti.end(), [&seminarski](Student& s) {
                return s.brIndeksa == seminarski.studentIndeks;
                    });
            break;
        }
        default: {
            cout << "Pogresan izbor!\n";
            break;
        }
        }
    }
    return 0;
}