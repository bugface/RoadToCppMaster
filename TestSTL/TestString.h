//
// Created by alex on 7/14/22.
//

#ifndef TESTSTL_TESTSTRING_H
#define TESTSTL_TESTSTRING_H


#include <iostream>
#include <string>

using namespace std;

void testString1() {
    string s1;

    const char *s = "hello world!";
    string s2(s);
    cout << s2 << endl;

    string s3(s2);
    cout << s3 << endl;

    string s4(6, 'c');
    cout << s4 << endl;
}

void testString2() {
    string s;
    string s1;
    //string = char *
    s = "hello world";
    cout << s << endl;
    //string = &string
    s1 = s;
    cout << s1 << endl;
    // string = char
    s = 'a';
    cout << s << endl;
    //string . assign (char*)
    s.assign("assign");
    cout << s << endl;
    //string.assign(char *, n)
    //n is the first n char from char *
    s.assign("hello world", 5);
    cout << s << endl;
    s.assign(s1);
    cout << s << endl;
    s.assign(10, 'a');
    cout << s << endl;
}

void testString3() {
    string s = "test";
    s += " test 1";
    cout << s << endl;

    s += 'a';
    cout << s << endl;

    string s2 = " this is s2";
    s += s2;
    cout << s << endl;

    s.append(s2);
    cout << s << endl;

    s.append(s2, 8);
    cout << s << endl;

    string s3 = "hello";
    s.append(s3, 2, 3); //append llo
    cout << s << endl;
}

void testStringFind() {
    //find search from left to right
    int idx;
    string s = "abc efg hij ef";
    idx = s.find("ef", 0);
    cout << idx << endl; // 4

    idx = s.find("cb", 0);
    cout << idx << endl; //-1

    // rfind search from right to left
    idx = s.rfind("ef");
    cout << idx << endl; // 12

    //replace
    s.replace(idx, 1, "xy"); // pos: from where; n: replace how many char; s: replacement
    cout << s << endl;
    s.replace(0, 5, "hello"); // pos: from where; n: replace how many char; s: replacement
    cout << s << endl;
    s.replace(0, 1, "xxoo"); // pos: from where; n: replace how many char; s: replacement
    cout << s << endl;
}

void testStringCompare() {
    string s1 = "hello";
    string s2 = "wello";
    string s3 = "hello";
    string s4 = "aello";
    string s5 = "helloa";
    string s6 = "hellox";
    char *s7 = "hello";
    string s8 = "well";

    cout << s1.compare(s2) << endl; // s1 < s2 -1
    cout << s1.compare(s3) << endl; // s1 == s3 0
    cout << s1.compare(s4) << endl; // s3 > s4 1
    cout << s1.compare(s5) << endl; //-1 longer string is larger
    cout << s1.compare(s6) << endl; //-1
    cout << s1.compare(s7) << endl; //0
    cout << s1.compare(s8) << endl; //-1

    // string compare mainly used to check if two strings are he same
    // compare which is larger or smaller is meanless for most cases
    // so we want check == 0 or != 0 for most cases
}

void tsetGetCharFromString() {
    string s1 = "hello";

    for (int i = 0; i < s1.size(); ++i) {
        cout << s1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < s1.size(); ++i) {
        cout << s1.at(i) << " ";
    }
    cout << endl;

    for (auto c: s1) {
        cout << c << " ";
    }
    cout << endl;

    // since string is &
    // you can modify each char at index
    s1[0] = 'a';
    cout << s1 << endl;

    //get substring
    string sub1 = s1.substr(0, 3);
    cout << sub1 << endl;
    sub1 = s1.substr(4, 3);
    cout << sub1 << endl;

    // test email
    string email = "this_is_test@gmail.com";
    int idx = email.find('@');
    string ename = email.substr(0, idx);
    string eaddr = email.substr(idx + 1, 20);
    cout << ename << " @ " << eaddr << endl;
}

void testInsertDeleteString() {
    string s1 = "hello";

    //insert
    s1.insert(1, "xx");
    cout << s1 << endl;
    string s2 = "world";
    s1.insert(7, s2);
    cout << s1 << endl;

    //delete
    s1.erase(1, 2);
    cout << s1 << endl;
}

#endif //TESTSTL_TESTSTRING_H
