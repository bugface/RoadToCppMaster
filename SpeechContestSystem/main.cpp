#include "SysManage.hpp"

using namespace std;

int main() {
    SysManage sys;
    int choice;

//    sys.printMap();

    while (true) {
        sys.showMenu();
        cin >> choice;

        switch (choice) {
            case 0:
                sys.exitSystem();
                break;
            case 1:  //start
                sys.startSpeechContest();
                break;
            case 2: // check history
//                sys.loadRecords();
                sys.showHistory();
                break;
            case 3: // clean
                sys.cleanRecord();
                break;
            default: // refresh
                system("clear");
                break;
        }
    }
}
