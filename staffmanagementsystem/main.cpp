#include <iostream>
#include "string"
#include "./src/manager.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
using namespace std;

int main() {
    managersys msys;
    int flag = 0;

    while (true) {
        msys.showMenu();
        printf("Input you command:\n");
        cin >> flag;

        switch (flag) {
            case 0:
                managersys::systemExit();
                break;
            case 1:
                msys.addStaff();
                break;
            case 2:
                msys.showStaffInfo();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                printf("invalid command, please re-input");
                break;

        }
    }
}

#pragma clang diagnostic pop