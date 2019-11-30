//
// Created by Kacper on 21.11.2019.
//

#ifndef DATABASE_PERSON_H
#define DATABASE_PERSON_H


#include <string>

class Person {

private:
    std::string name;
    std::string secondName;

public:
    Person(const std::string &name, const std::string &secondName);

    const std::string &getName() const;

    const std::string &getSecondName() const;

    void setName(const std::string &name);

    void setSecondName(const std::string &secondName);
};


#endif //DATABASE_PERSON_H
