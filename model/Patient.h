//
// Created by Kacper on 21.11.2019.
//

#ifndef DATABASE_PATIENT_H
#define DATABASE_PATIENT_H

#include <string>
#include "Person.h"
using std::string;

class Patient : public Person{
private:
    string opinion;
public:

    Patient(const string &name, const string &secondName, const string &opinion);

    const string &getOpinion() const;
};


#endif //DATABASE_PATIENT_H
