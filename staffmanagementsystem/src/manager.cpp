//Created by Yang,Xi on 7/4/22.

#include "iostream"
#include "manager.h"

using namespace std;

void managersys::_init() {
    // force re-init fields to default
    this->numStaff = 0;
    this->staffArray = nullptr;
    this->isFileEmpty = true;
}

managersys::managersys() {
    ifstream ifs;
    filesystem::path fp = filesystem::current_path().parent_path() / FILENAME;
    printf("try to load data from: %s", fp.string().c_str());
    ifs.open(fp.string(), ios::in);

    //file not exist
    if (! ifs.is_open()) {
        printf("%s file is not exist.\n", FILENAME);
        this->_init();
        ifs.close();
        return;
    }

    //file exist but empty
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        printf("%s file is empty.\n", FILENAME);
        this->_init();
        ifs.close();
        return;
    }

    // if file exist and not empty
    this->_getStaffNum();
    // init staff array
    this->staffArray = new staff*[this->numStaff];
    this->_initStaffArray();
//    for (int i=0; i<this->numStaff; ++i) {
//        this->staffArray[i]->showInfo();
//        cout << endl;
//    }
}

managersys::~managersys() {
    for(int i=0; i<this->numStaff; ++i) {
        delete this->staffArray[i];
        this->staffArray[i]= nullptr;
    }

    delete[] this->staffArray;
    this->staffArray = nullptr;
}

void managersys::showMenu() {
    printf("1. add user\n");
    printf("2. show users\n");
    printf("3. delete user\n");
    printf("4. search user\n");
    printf("5. modify user\n");
    printf("6. clean up\n");
    printf("7. sort by\n");
    printf("0. exist\n");
}

void managersys::systemExit() {
    printf("welcome to use again, exit!\n");
    system("pause");
    exit(0);
}

void managersys::addStaff() {
    printf ("how many you want to add?\n");
    int addNum;
    cin >> addNum;

    if (addNum > 0) {
        int newSize = this->numStaff + addNum;
        auto ** newSpace = new staff * [newSize];
        if (this->staffArray != nullptr) {
            for (int i=0; i<this->numStaff; ++i) {
                newSpace[i] = this->staffArray[i];
            }
        }

        for (int i=0; i<addNum; ++i) {
            cout << "input " << i << "th staff information" << endl;
            int sid;
            string name;
            int dept_id;

            cin >> sid;
            cin >> name;
            cin >> dept_id;
            
            staff * newStaff;
            switch (dept_id) {
                case 1:
                    newStaff = new worker(sid, name, dept_id);
                    break;
                case 2:
                    newStaff = new manager(sid, name, dept_id);
                    break;
                case 3:
                    newStaff = new boss(sid, name, dept_id);
                    break;
                default:
                    cout << "not valid dept id (1-3), we default to 1" << endl;
                    newStaff = new worker(sid, name, 1);
                    break;
            }
            newSpace[this->numStaff + i] = newStaff;
        }
        // release old space for just array
        // all old array elements are reference in the new array so we do not delete
        delete[] this->staffArray;
        this->staffArray = newSpace;
        this->numStaff = newSize;
    }else {
        printf("input must be integer > 0\n");
    }

    saveToFile();
}

void managersys::saveToFile() {
    ofstream ofs;
    filesystem::path fp = filesystem::current_path().parent_path() / FILENAME;
    ofs.open(fp.string(), ios::out);

    for (int i=0; i<this->numStaff; ++i) {
//        ofs << this->staffArray[i]->getStaffID() << " " << this->staffArray[i]->getStaffName()
//        << " " << this->staffArray[i]->getDeptID() << endl;
        char buff[128];
        snprintf(buff, 128, "%d %s %d\n",
                 this->staffArray[i]->getStaffID(),
                 this->staffArray[i]->getStaffName().c_str(),
                 this->staffArray[i]->getDeptID()
                 );
        string s = string(buff);
        ofs.write(s.c_str(), (long) size(s));
    }

    ofs.close();
}

void managersys::_getStaffNum() {
    ifstream ifs;
    filesystem::path fp = filesystem::current_path().parent_path() / FILENAME;
    ifs.open(fp.string(), ios::in);

    int sid;
    string name;
    int dept_id;

    int num = 0;
    while(ifs >> sid && ifs >> name && ifs >> dept_id) {
        num++;
    }
    this->numStaff = num;

    ifs.close();
}

void managersys::_initStaffArray() {
    fstream ifs;
    filesystem::path fp = filesystem::current_path().parent_path() / FILENAME;
    ifs.open(fp.string(), ios::in);

    int sid;
    string name;
    int dept_id;
    staff * s;

    int index = 0;
    while(ifs >> sid && ifs >> name && ifs >> dept_id) {
        if (dept_id == 1) {
            s = new worker(sid, name, dept_id);
        } else if (dept_id == 2) {
            s = new manager(sid, name, dept_id);
        } else if (dept_id == 3) {
            s = new boss(sid, name, dept_id);
        } else {
            s = new worker(sid, name, 1);
        }

        this->staffArray[index] = s;
        ++index;
    }

    ifs.close();
}

void managersys::showStaffInfo() {
    if (this->isFileEmpty) {
        printf("no records yet\n");
    } else {
        for (int i=0; i<this->numStaff; ++i) {
            this->staffArray[i]->showInfo();
            cout << endl;
        }
    }
}

int managersys::_findById(int sid) {
    int index = -1;

    for(int i=0; i<this->numStaff; ++i) {
        if(this->staffArray[i]->getStaffID() == sid) {
            index = i;
            break;
        }
    }

    return index;
}

bool managersys::deleteStaffById() {
    if(this->isFileEmpty) {
        printf("No staff in system\n");
        return false;
    }

    printf("input the id of the staff you want to delete\n");
    int sid;
    cin >> sid;

    int index = this->_findById(sid);

    if (index == -1) {
        printf("staff you want to delete is not exist\n");
        return false;
    } else {
        for (int i=index; i<(this->numStaff-1); ++i) {
            this->staffArray[i] = this->staffArray[i+1];
        }
        this->numStaff--;
        // sync with file
        this->saveToFile();

        return true;
    }
}

bool managersys::modifyStaffById() {
    if(this->isFileEmpty) {
        printf("No staff in system\n");
        return false;
    }

    printf("input the id of the staff you want to modify\n");
    int sid;
    cin >> sid;

    int index = this->_findById(sid);

    if (index == -1) {
        printf("staff you want to modify is not exist\n");
        return false;
    } else {
        printf("the current information for staff for modification:\n");
        this->staffArray[index]->showInfo();
        printf("input the new information (new name and new dept ID):\n");

        sid = this->staffArray[index]->getStaffID();
        string name;
        int dept_id;

        cin >> name;
        cin >> dept_id;

        staff * newStaff;
        switch (dept_id) {
            case 1:
                newStaff = new worker(sid, name, dept_id);
                break;
            case 2:
                newStaff = new manager(sid, name, dept_id);
                break;
            case 3:
                newStaff = new boss(sid, name, dept_id);
                break;
            default:
                cout << "not valid dept id (1-3), we default to 1" << endl;
                newStaff = new worker(sid, name, 1);
                break;
        }

        delete this->staffArray[index];
        this->staffArray[index] = newStaff;
        // sync with file
        this->saveToFile();
        return true;
    }
}

void managersys::_findByName(string &name) {
    bool flag = true;
    for (int i=0; i>this->numStaff; ++i) {
        if (this->staffArray[i]->getStaffName() == name) {
            printf("find a staff matched:\n");
            this->staffArray[i]->showInfo();
            cout << endl;
            flag = false;
        }
    }

    if (flag)  printf("No staff in system\n");
}

void managersys::findStaff() {
    if (this->isFileEmpty) {
        printf("No staff in system\n");
        return;
    }

    printf("search by id = 1; search by name =2");

    int search_method;
    cin >> search_method;

    if (search_method == 1) {
        printf("input id you want to search:\n");
        int search_id;
        cin >> search_id;
        int index = this->_findById(search_id);
        if(index == -1) {
            printf("staff with id : %d you want to delete is not exist\n", search_id);
        } else {
            this->staffArray[index]->showInfo();
        }
    } else {
        printf("input staff name for search:\n");
        string search_name;
        cin >> search_name;
        this->_findByName(search_name);
    }
}

void managersys::sortStaff() {
    if (this->isFileEmpty) {
        printf("No staff in system\n");
        return;
    }

    cout << "select sort method: 1. ascending; 2. descending" << endl;
    int method;
    cin >> method;

    for (int i=0; i<this->numStaff; ++i) {
        int minOrmax = i;
        for (int j=(i+1); j<this->numStaff; ++j) {
            if (method == 1) {
                if (this->staffArray[minOrmax]->getStaffID() > this->staffArray[j]->getStaffID()) {
                    minOrmax = j;
                }
            } else {
                if (this->staffArray[minOrmax]->getStaffID() < this->staffArray[j]->getStaffID()) {
                    minOrmax = j;
                }
            }
        }

        if(i != minOrmax) {
            swap(this->staffArray[i], this->staffArray[minOrmax]);
        }
    }

    this->saveToFile();

    cout << "sort done." << endl;
    this->showStaffInfo();
}

void managersys::cleanup() {
    if (this->isFileEmpty) {
        printf("No staff in system\n");
        return;
    }

    filesystem::path fp = filesystem::current_path().parent_path() / FILENAME;

    // overwrite file with empty
    ofstream ofs(fp.string(), ios::out);
    ofs.close();

    if (this->numStaff > 0) {
        for (int i=0; i<this->numStaff; ++i) {
            delete this->staffArray[i];
            this->staffArray[i] = nullptr;
        }

        delete[] this->staffArray;
        this->staffArray = nullptr;
        this->numStaff = 0;
        this->isFileEmpty = true;
    }

    cout << "all data clean up." << endl;
}