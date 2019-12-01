//
// Created by Kacper on 21.11.2019.
//

#include "Database.h"

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

void Database::runDatabase() {
    char option;
    cout << "Witaj w bazie danych! Co chcesz zrobic?" << endl;
    while (option != 'q') {
        printOptions();
        option = getchar();
        getchar();
        switch (option) {
            case 'a':
                addDoctor();
                break;
            case 'e':
                editDoctorsData();
                break;
            case 'd':
                deleteDoctor();
                break;
            case 's':
                cout << "Szukaj doktora" << endl;
                searchDoctor();
                break;
            case 'p':
                cout << "Szukaj specjalisty z najmniejsza kolejka" << endl;
                printDoctors(searchSpecialistMinQueue());
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

std::multimap<int, Doctor> Database::searchDoctor() {
    std::multimap<int, Doctor> highestMatch;
    string searchString;
    //getchar();
    getline(cin, searchString);
    std::vector<string> tokens = tokenizeSearch(searchString);
    for (int i = 0; i < doctors.size(); i++) {
        int match = 0;
        for (size_t j = 0; j < tokens.size(); j++) {
            if (doctors[i].toString().find(tokens[j]) != string::npos) {
                match++;
            }
        }
        highestMatch.insert(pair<int, Doctor>(match, doctors[i]));
        std::multimap<int, Doctor>::iterator itr;
        for (itr = highestMatch.begin(); itr != highestMatch.end(); ++itr) {
            cout << itr->first << ' ' << (itr->second).toString() << endl;
        }
    }

    return highestMatch;
}

std::vector<Doctor> Database::searchSpecialistMinQueue() {
    std::vector<Doctor> minQueueDoctors;
    if (!doctors.size()) {
        cout << "Baza jest pusta" << endl;
        return minQueueDoctors;
    }
    size_t minQueueIndex = 0;
    string specialization;
    cout << "Jakiego specjalisty poszukujesz: " << endl;
    cin >> specialization;
    getchar();
    for (size_t i = 0; i < doctors.size(); ++i) {
        if (specialization.compare(doctors[i].getSpecialization()) == 0) {
            if (doctors[minQueueIndex].getHowManyPatients() >= doctors[i].getHowManyPatients()) {
                minQueueIndex = i;
                minQueueDoctors.insert(minQueueDoctors.begin(), doctors[minQueueIndex]);
            }
        }
    }
    return minQueueDoctors;
}

void Database::addDoctor() {
    string name, secondName, hostpital, mail, specialization;
    string phoneNumber, ID;
    int howManyPatients;
    cout << "Imie lekarza:" << endl;
    cin >> name;


    cout << "Nazwisko lekarza: " << endl;
    cin >> secondName;


    cout << "Specjalizacja lekarza: " << endl;
    cin >> specialization;


    cout << "Osrodek: " << endl;
    cin >> hostpital;


    cout << "Mail lekarza: " << endl;

    cin >> mail;


    cout << "Numer telefonu lekarza: " << endl;
    cin >> phoneNumber;

    cout << "Ilosc pacjentow lekarza: " << endl;
    cin >> howManyPatients;

    getchar();
    ID = latestID++;
    Doctor doctor(name, secondName, specialization, hostpital, mail, phoneNumber, ID, howManyPatients);
    doctors.push_back(doctor);
}

void Database::deleteDoctor() {
    if (!doctors.empty()) {
        cout << "Kogo chcesz usunac z bazy? Wybierz odpowiednia opcje" << endl;
        printDoctors(doctors);
        int deletedDoctorIndex;
        cin >> deletedDoctorIndex;
        getchar();
        if (deletedDoctorIndex > doctors.size()) {
            return;
        }
        doctors.erase(doctors.begin() + deletedDoctorIndex - 1);
    } else {
        cout << "W bazie nia ma zadnego lekarza" << endl;
    }

}

void Database::editDoctorsData() {
    if (!doctors.empty()) {
        cout << "Czyje dane chcesz edytować? Wybierz odpowiednia opcje" << endl;
        printDoctors(doctors);
        int doctorToeditIndex;
        cin >> doctorToeditIndex;
        if (doctorToeditIndex > doctors.size()) {
            return;
        }
        cout << "Ktora dana chcesz edytowac?" << endl;
        printData();
        int option;
        cin >> option;
        switch (option) {
            case 1: {
                string name;
                cout << "Podaj nowe imie" << endl;
                cin >> name;
                doctors[doctorToeditIndex - 1].setName(name);
                break;
            }
            case 2: {
                string secondName;
                cin >> secondName;
                doctors[doctorToeditIndex - 1].setSecondName(secondName);
                break;
            }
            case 3: {
                string specialization;
                cin >> specialization;
                doctors[doctorToeditIndex - 1].setSpecialization(specialization);
                break;
            }
            case 4: {
                string hospital;
                cin >> hospital;
                doctors[doctorToeditIndex - 1].setHospital(hospital);
                break;
            }
            case 5: {
                string mail;
                cin >> mail;
                doctors[doctorToeditIndex - 1].setMail(mail);
                break;
            }
            case 6: {
                int patients;
                cin >> patients;
                doctors[doctorToeditIndex - 1].setHowManyPatients(patients);
                break;
            }
            case 7: {
                string phoneNumber;
                cin >> phoneNumber;
                doctors[doctorToeditIndex - 1].setPhoneNumber(phoneNumber);
                break;
            }
        }
        getchar();
        printDoctors(doctors);
    } else {
        cout << "W bazie nia ma zadnego lekarza" << endl;
    }
}

void Database::printDoctors(std::vector<Doctor> doctors) {
    for (size_t i = 0; i < doctors.size(); i++) {
        cout << i + 1 << " " << doctors[i].toString() << endl;
    }
    cout << endl;
}

void Database::printData() {
    cout << "1. Imie" << endl;
    cout << "2. Nazwisko" << endl;
    cout << "3. Specjalizacja" << endl;
    cout << "4. Placowka" << endl;
    cout << "5. Mail" << endl;
    cout << "6. Ilosc pacjentow" << endl;
    cout << "7. Numer telefonu" << endl;
}

void Database::printOptions() {
    cout << "Dodanie lekarza do bazy - wybierz 'a'" << endl;
    cout << "Wyjscie z bazy - wybierz 'q'" << endl;
    cout << "Usuniecie lekarza z bazy - wybierz 'd'" << endl;
    cout << "Edytowanie danych lekarza - wybierz 'e'" << endl;
}

std::vector<string> Database::tokenizeSearch(string &search) {
    std::vector<string> tokens;
    size_t lastSpace = 0;
    for (size_t i = 0; i < search.size(); ++i) {
        if (search[i] == ' ') {
            tokens.push_back(search.substr(lastSpace, i));
            lastSpace = i + 1;
        }
    }
    tokens.push_back(search.substr(lastSpace, search.npos));

    return tokens;
}
