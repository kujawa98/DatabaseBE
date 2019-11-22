//
// Created by Kacper on 21.11.2019.
//

#include "Database.h"

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

void Database::runDatabase() {
    char option;
    cout << "Witaj w bazie danych! Co chcesz zrobic?" << endl;
    while (option != 'q') {
        printOptions();
        option = getch();
        getchar();
        switch (option) {
            case 'a':
                addDoctor();
                printDoctors();
                break;
            case 'e':
                editDoctorsData();
                break;
            case 'd':
                deleteDoctor();
                break;
            case 'q':
                cout << "Wyjscie z bazy" << endl;
                break;
            default:
                cout << "Nieznana opcja" << endl;
                break;
        }
    }
}

std::vector<Doctor> Database::searchDoctor() {
    return std::vector<Doctor>();
}

std::vector<Doctor> Database::searchSpecialist() {
    return std::vector<Doctor>();
}

void Database::addDoctor() {
    string name, secondName, hostpital, mail, specialization;
    int phoneNumber, ID, howManyPatients;
    cout << "Imie lekarza:"<<setw(10);
    cin >> name;


    cout << "Nazwisko lekarza: " << setw(10);
    cin >> secondName;


    cout << "Specjalizacja lekarza: " << setw(10);
    cin >> specialization;


    cout << "Osrodek: " << setw(10);
    cin >> hostpital;


    cout << "Mail lekarza: " << setw(10);

    cin >> mail;


    cout << "Numer telefonu lekarza: " << setw(10);
    cin >> phoneNumber;

    cout << "Ilosc pacjentow lekarza: " << setw(10);
    cin >> howManyPatients;


    ID = latestID++;
    Doctor doctor(name, secondName, hostpital, mail, phoneNumber, ID, howManyPatients, specialization);
    doctors.push_back(doctor);
}

void Database::deleteDoctor() {
    cout << "Kogo chcesz usunac z bazy? Wybierz odpowiednia opcje" << endl;
    printDoctors();
    int deletedDoctorIndex;
    cin >> deletedDoctorIndex;
    doctors.erase(doctors.begin() + deletedDoctorIndex - 1);
}

void Database::editDoctorsData() {

}

void Database::printDoctors() {
    for (int i = 0; i < doctors.size(); i++) {
        cout << i + 1 << " " << doctors[i].toString() << endl;
    }
    cout << endl;
}

void Database::printOptions() {
    cout << "1. Dodanie lekarza do bazy - wybierz 'a'" << endl;
    cout << "2. Wyjscie z bazy - wybierz 'q'" << endl;
    cout << "3. Usuniecie lekarza z bazy - wybierz 'd'" << endl;
    cout << "4. Edytowanie danych lekarza - wybierz 'e'" << endl;
}
