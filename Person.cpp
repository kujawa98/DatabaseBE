//
// Created by Kacper on 21.11.2019.
//

#include "Person.h"

const std::string &Person::getName() const {
    return name;
}

const std::string &Person::getSecondName() const {
    return secondName;
}

Person::Person(const std::string &name, const std::string &secondName) : name(name), secondName(secondName) {}
