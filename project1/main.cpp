#include <iostream>
#include <stdio.h>
#include "string"
#include "func.h"

using namespace std;

int main() {
    int flag = 1;

    Book book;
    book.current_size = 0;

    while (flag) {
        showManu();
        printf("input your command:");
        cin >> flag;
        printf("\n");

        if (! cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            flag = 10;
        }

        switch (flag) {
            case 0:
                printf("system exit. Bye.");
                break;
            case 1:
                addUser(&book);
                break;
            case 2:
                showUser(&book);
                break;
            case 3:
                deleteUser(&book);
                break;
            case 4:
                searchUser(&book);
                break;
            case 5:
                updateUser(&book);
                break;
            case 6:
                cleanUp(&book);
                break;
            default:
                printf("invalid command (0-6).\n");
        }

        //clean console
        system("clear");
    }

    return 0;
}
