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
                if (msys.deleteStaffById()) {
                    printf("delete success!\n");
                } else {
                    printf("delete failed.\n");
                }
                break;
            case 4:
                msys.findStaff();
                break;
            case 5:
                if (msys.modifyStaffById()) {
                    printf("modify success!\n");
                } else {
                    printf("modify failed.\n");
                }
                break;
            case 6:
                msys.cleanup();
                break;
            case 7:
                msys.sortStaff();
                break;
            default:
                printf("invalid command, please re-input");
                break;

        }
    }
}

#pragma clang diagnostic pop