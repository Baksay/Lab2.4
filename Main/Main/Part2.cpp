#include <iostream>                     //втора€ часть

void func1(int &z){
    int* a = new int(z);
}

class cl1 {
public:
    cl1(const int &alpha) {                    // ласс без RAII
        *a = alpha;
    }
    ~cl1() {
    }

    int* a = new int;
};

class cl2 {
public:
    cl2(const int &alpha) {                    // ласс с RAII
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


    func1(n);                       //”течка п€м€ти из-за выхода из области видимости


    cl1 *a = new cl1(n);            //ѕроисходит утечка пам€ти из-за выхода из зоны видимости
    delete a;

    cl2* b = new cl2(n);            //Ќе происходит утечка пам€ти из-за выхода из зоны видимости
    delete b;


    return 0;
}