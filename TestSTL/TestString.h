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
    cout << s <<endl;
    //string = &string
    s1 = s;
    cout << s1 <<endl;
    // string = char
    s = 'a';
    cout << s <<endl;
    //string . assign (char*)
    s.assign("assign");
    cout << s <<endl;
    //string.assign(char *, n)
    //n is the first n char from char *
    s.assign("hello world", 5);
    cout << s <<endl;
    s.assign(s1);
    cout << s <<endl;
    s.assign(10, 'a');
    cout << s <<endl;
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
    s.append(s3, 2 , 3); //append llo
    cout << s << endl;
}


#endif //TESTSTL_TESTSTRING_H
