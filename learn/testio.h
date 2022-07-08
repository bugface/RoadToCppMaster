//
// Created by Yang,Xi on 7/3/22.
//

#ifndef LEARN_TESTIO_H
#define LEARN_TESTIO_H
#include "iostream"
#include "string"
#include "fstream"
#include <filesystem>

using namespace std;


class testio {
public:
    ofstream * ofs = nullptr;
    ifstream * ifs = nullptr;

    ~testio() {
        delete ofs;
        ofs = nullptr;

        delete ifs;
        ifs = nullptr;
    }

    void write(const string& filename, const string& text) {
        ofs = new ofstream;
        ofs->open(filename, ios::out);
//        * ofs << text << endl;
//        char buf[1024] = {0};
        ofs->write(text.c_str(), 1024);
        ofs->clear();
        ofs->close();
    }

    void read(const string& filename) {
        ifs = new ifstream;
        ifs->open(filename, ios::in);
        if (! ifs->is_open()) {
            printf("failed open file: %s\n", filename.c_str());
            return;
        }

        char buf[1024] = {0};

        while(ifs->getline(buf, sizeof(buf))) {
            printf("from file: %s\n", buf);
        }

//        string buf;
//        while(getline(* ifs, buf)) {
//            printf("from file: %s\n", buf.c_str());
//        }

        ifs->close();
    }
};

class Person1 {
public:
    char name[64];
    int age;
};


void testFileIo() {
    testio tio;
    string content = "alex is a superstart\nhis grade is 100\nhe is qualified.";
    filesystem::path fp = filesystem::current_path().parent_path() / "test.txt";
    tio.write(fp.string(), content);
    tio.read(fp.string());

    ofstream ofs(filesystem::current_path().parent_path() / "test_bin.bin", ios::out | ios::binary);
    Person1 p1 = {"alex", 18};
    ofs.write((const char *) &p1, sizeof(p1));
    ofs.close();

    ifstream ifs(filesystem::current_path().parent_path() / "test_bin.bin", ios::in | ios::binary);
    if (! ifs.is_open()) {
        cout << "read failed" << endl;
        return;
    }
    Person1 p2;
    ifs.read((char *) &p2, sizeof(p2));
    printf("read bin: %s, %d \n", p2.name, p2.age);
    ifs.close();
}


#endif //LEARN_TESTIO_H
