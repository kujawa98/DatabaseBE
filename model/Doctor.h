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
    string phoneNumber;
    string ID;
    int howManyPatients;
    std::vector<Patient> opinions;

public:
    Doctor(const string &name, const string &secondName, const string &specialization, const string &hospital,
           const string &mail, const string &phoneNumber, const string &id, int howManyPatients);

    const string &getSpecialization() const;

    const string &getHospital() const;

    const string &getMail() const;

    const string &getPhoneNumber() const;

    const string &getId() const;

    int getHowManyPatients() const;

    const std::vector<Patient> &getOpinions() const;

    void addOpinion();

    const string toString();

    void setSpecialization(const string &specialization);

    void setHospital(const string &hospital);

    void setMail(const string &mail);

    void setPhoneNumber(const string &phoneNumber);

    void setHowManyPatients(int howManyPatients);

};


#endif //DATABASE_DOCTOR_H
