//
// Created by Kacper on 15.11.2019.
//

#include "Doctor.h"
#include <iostream>

using namespace std;


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


const string Doctor::toString() {
    string result =
            Doctor::getName() + ' ' + Doctor::getSecondName() + ' ' + Doctor::specialization + ' ' + Doctor::hospital;
    for (int i = 0; i < result.length(); i++) {
        result[i] = std::tolower(result[i]);
    }
    return result;
}


//Settery
void Doctor::setSpecialization(const string &specialization) {
    Doctor::specialization = specialization;
}

void Doctor::setHospital(const string &hospital) {
    Doctor::hospital = hospital;
}

void Doctor::setMail(const string &mail) {
    Doctor::mail = mail;
}

void Doctor::setPhoneNumber(const string &phoneNumber) {
    Doctor::phoneNumber = phoneNumber;
}

void Doctor::setHowManyPatients(int howManyPatients) {
    Doctor::howManyPatients = howManyPatients;
}


//Gettery
const string &Doctor::getSpecialization() const {
    return specialization;
}

const string &Doctor::getHospital() const {
    return hospital;
}

const string &Doctor::getMail() const {
    return mail;
}

const string &Doctor::getPhoneNumber() const {
    return phoneNumber;
}

const string &Doctor::getId() const {
    return ID;
}

int Doctor::getHowManyPatients() const {
    return howManyPatients;
}

const vector<Patient> &Doctor::getOpinions() const {
    return opinions;
}

Doctor::Doctor(const string &name, const string &secondName, const string &specialization, const string &hospital,
               const string &mail, const string &phoneNumber, const string &id, int howManyPatients) : Person(name,
                                                                                                              secondName),
                                                                                                       specialization(
                                                                                                               specialization),
                                                                                                       hospital(
                                                                                                               hospital),
                                                                                                       mail(mail),
                                                                                                       phoneNumber(
                                                                                                               phoneNumber),
                                                                                                       ID(id),
                                                                                                       howManyPatients(
                                                                                                               howManyPatients) {}

