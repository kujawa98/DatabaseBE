//
// Created by Kacper on 21.11.2019.
//

#include "Patient.h"

const string &Patient::getOpinion() const {
    return opinion;
}

Patient::Patient(const string &name, const string &secondName, const string &opinion) : Person(name, secondName),
                                                                                        opinion(opinion) {}
