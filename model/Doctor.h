//
// Created by Kacper on 15.11.2019.
//

#ifndef DATABASE_DOCTOR_H
#define DATABASE_DOCTOR_H

#include <string>
#include <vector>

#include "Patient.h"

using std::string;

class Doctor : public Person {

private:

    string specialization;
    string hospital;
    string mail;
    int phoneNumber;
    int ID;
    int howManyPatients;
    std::vector<Patient> opinions;

public:
    Doctor(const string &name, const string &secondName, const string &hospital, const string &mail, int phoneNumber,
           int id, int howManyPatients);

    const string &getHospital() const;

    const string &getMail() const;

    int getPhoneNumber() const;

    int getId() const;

    int getHowManyPatients() const;

    const string &getSpecialization() const;

    const std::vector<Patient> &getOpinions() const;

    void addOpinion();

    const string toString();

};


#endif //DATABASE_DOCTOR_H
