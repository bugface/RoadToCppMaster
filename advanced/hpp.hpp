#include <iostream>
#include <string>

using namespace std;

template <class T>
class splitfile {
public:
    T t;

    splitfile(T t);

    void show();
};

template <class T>
splitfile<T>::splitfile(T t) {
    cout << "implement in hpp" << endl;
    this->t = t;
}

template <class E>
void splitfile<E>::show() {
    cout << "show implement in hpp" << endl;
    cout << this->t << endl;
}