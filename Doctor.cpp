//
// Created by Kacper on 15.11.2019.
//

#include "Doctor.h"
#include <iostream>
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

const std::vector<Person> &Doctor::getOpinions() const {
    return opinions;
}

void Doctor::setMail(const string &mail) {
    Doctor::mail = mail;
}

void Doctor::addOpinion(){
    Person person("Stanislaw", "Skrillex");
    Doctor::opinions.push_back(person);
}

