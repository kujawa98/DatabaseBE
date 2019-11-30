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

void Person::setName(const std::string &name) {
    Person::name = name;
}

void Person::setSecondName(const std::string &secondName) {
    Person::secondName = secondName;
}
