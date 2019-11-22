#include <iostream>
#include "model/Doctor.h"

using namespace std;

#include "Database.h"
int main() {
    Database doctorsDatabase;
    doctorsDatabase.runDatabase();

    return 0;
}