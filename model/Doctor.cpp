//
// Created by Kacper on 15.11.2019.
//

#include "Doctor.h"
#include <iostream>

using namespace std;

const string &Doctor::getHospital() const {
    return hospital;
}

const string &Doctor::getMail() const {
    return mail;
}

int Doctor::getPhoneNumber() const {
    return phoneNumber;
}

int Doctor::getId() const {
    return ID;
}

int Doctor::getHowManyPatients() const {
    return howManyPatients;
}

Doctor::Doctor(const string &name, const string &secondName, const string &hospital, const string &mail,
               int phoneNumber, int id, int howManyPatients) : Person(name,
                                                                      secondName),
                                                               hospital(hospital),
                                                               mail(mail),
                                                               phoneNumber(
                                                                       phoneNumber),
                                                               ID(id),
                                                               howManyPatients(
                                                                       howManyPatients) {}

const vector<Patient> &Doctor::getOpinions() const {
    return opinions;
}


void Doctor::addOpinion() {
    string name;
    string secondName;
    string opinion;

    cout << "Imie" << endl;
    cin >> name;

    cout << "Nazwisko" << endl;
    cin >> secondName;

    getchar();

    cout << "Co sadzisz o danym lekarzu?" << endl;
    getline(cin, opinion);

    Patient patient(name, secondName, opinion);
    Doctor::opinions.push_back(patient);

}

const string &Doctor::getSpecialization() const {
    return specialization;
}

const string Doctor::toString() {
    const string result = Doctor::mail;
    return result;
}

