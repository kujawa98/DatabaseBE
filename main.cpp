#include <iostream>
#include "Doctor.h"

using namespace std;

int main() {

    Doctor doctor("Jakub", "Urbański", "Kopernik Gdańsk", "jss@Xd", 12345789, 669669, 12);
    cout << doctor.getHospital() << endl;

    for (int j = 0; j < 4; ++j) {
        doctor.addOpinion();
    }

    for (int i = 0; i < doctor.getOpinions().size(); ++i) {
        cout << doctor.getOpinions()[i].getName() << ' ' << doctor.getOpinions()[i].getSecondName() << endl;
    }
    return 0;
}