#include <fstream>
#include "util.hpp"
#include "globalFile.h"

int main() {
    int select = 0;

    while (true) {
        showMainMenu();
        cin >> select;
        switch (select) {
            case 1:
                login(1, STUDENT_FILE);
                break;
            case 2:
                login(2, TEACHER_FILE);
                break;
            case 3:
                login(3, ADMIN_FILE);
                break;
            case 0:
                goto SYSEXIT;
            default:
                cout << "Use 1,2,3,0..." << endl;
                break;
        }
    }

    SYSEXIT:
    sysExit();
    return 0;
}