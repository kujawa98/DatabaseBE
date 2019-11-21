//
// Created by Kacper on 21.11.2019.
//

#ifndef DATABASE_DATABASE_H
#define DATABASE_DATABASE_H

#include <unordered_map>
#include "model/Doctor.h"

class Database {
private:
    std::unordered_multimap<string, Doctor> map;
};


#endif //DATABASE_DATABASE_H
