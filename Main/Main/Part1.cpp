#include <iostream>                     //First part
#include <string>
#include <vector>
#include <stdexcept>      
#include <bitset>
#include <typeinfo> 
#include <new>
#include <exception>




class cl1 {
    virtual void member() {}
};

class cl2 : cl1 {
};

class MyException {                                              //user exp

public:
    MyException(const std::string& msg) : msg_(msg) {}
    ~MyException() {}

    std::string getMessage() const { return(msg_); }
private:
    std::string msg_;
};

int main() {
    
    int n;                                                       //out_of_range
    std::string s1("alpha");
    std::string s2("beta");
    std::cin >> n;
      
        try {
            if (n > s2.size())
                throw - 1;
        }       
        catch (int) {
            std::cout << "out_of_range";
            return 0;
        };  
    s1.append(s2, n, 2);
    std::cout << s1 << std::endl;



    std::vector<int> v1;                                         //lenght_error
    std::cin >> n;
    try {        
        v1.resize(v1.size() + n);
        if (v1.size() > v1.max_size())
            throw - 1;
    }
    catch (...) {
        std::cout << "lenght_error";
    }
    

    
                                                               //invalid_argument

    try {                                       
        std::bitset<5> bs1(std::string("9848011223"));
    }
    catch (...) {
        std::cout << "invalid_argument";
    }

                                                               //bad_cast
    try {
        cl1 gfg;
        cl2& rd= dynamic_cast<cl2&>(gfg);
    }

    catch (...) {
        std::cout << "bad_cast";
    }
                                                               //bad_alloc
    try {
        while (true) {
            new int[999999999999999999ul];
        }
    }
    catch (...) {
        std::cout << "bad_alloc";
    }

                                                                //user exp
    try {

        throw (MyException("alpha"));
    }
    catch (MyException& e) {
        std::cout << "Пользовательское исключение: " << e.getMessage() << std::endl;
    }























   return 0;
}

