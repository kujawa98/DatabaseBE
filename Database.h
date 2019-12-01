//
// Created by Kacper on 21.11.2019.
//

#ifndef DATABASE_DATABASE_H
#define DATABASE_DATABASE_H

#include "model/Doctor.h"
#include <map>

class Database {
private:
    std::vector<Doctor> doctors;
    int latestID = 0;

    void addDoctor();

    void deleteDoctor();

    void editDoctorsData();

    std::multimap<int, Doctor> searchDoctor();

    std::vector<Doctor> searchSpecialistMinQueue();

    std::vector<string> tokenizeSearch(string &search);

    void printOptions();

    void printDoctors(std::vector<Doctor> doctors);

    void printData();

public:
    void runDatabase();

};


#endif //DATABASE_DATABASE_H
