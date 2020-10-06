#include <iostream>                     //Second part

void func1(int &z){
    int* a = new int(z);
}

class cl1 {
public:
    cl1(const int &alpha) {                    //No RAII class
        *a = alpha;
    }
    ~cl1() {
    }

    int* a = new int;
};

class cl2 {
public:
    cl2(const int &alpha) {                    //RAII class
        *a = alpha;
    }
    ~cl2() {
        delete a;
        a = 0;
    }

    int* a = new int;
};

int main() {
    int n = 43;


    func1(n);                       //Memory leakage


    cl1 *a = new cl1(n);            //Memory leakage
    delete a;

    cl2* b = new cl2(n);            //No memory leakage
    delete b;


    return 0;
}