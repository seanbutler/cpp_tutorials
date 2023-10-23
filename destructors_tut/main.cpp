//
//  main.cpp
//  Constructors and Destructors
//

//
// see also https://www.interviewsansar.com/cplusplus-virtual-destructor-and-use-of-virtual-destructor/
//

#include <iostream>

class Core {
public:
    Core()          {std::cout << "Core constructor" << std::endl;}
    virtual ~Core() {std::cout << "Core destructor" << std::endl;};
};

class Base : public Core {
public:
    Base(): Core() { std::cout << "Base constructor" << std::endl; }
    virtual ~Base() { std::cout << "Base destructor" << std::endl; }
};


class Other : public Core {
public:
    Other(): Core() { std::cout << "Other constructor" << std::endl; }
    virtual ~Other() { std::cout << "Other destructor" << std::endl; }
};

class Derived : public Base, Other {
public:
    Derived(std::string L ) : label(L) { std::cout << "Derived constructor " << label << std::endl; }
    virtual ~Derived() { std::cout << "Derived destructor " << label << std::endl; }

    std::string label;

};


void function(){

    std::cout << "--- function is called" << std::endl;

    Derived d2("function stack");

    Derived *d3 = new Derived("function heap");
    free(d3);

    std::cout << "--- function returns" << std::endl;
}

// Derived d1("outside stack");


int main(int argc, const char * argv[])
{
    std::cout << "--- main is called" << std::endl;

    Derived d2("main stack");

    // function();
    // Derived *d3 = new Derived("main heap");
    // free(d3);

    std::cout << "--- main returns" << std::endl;
}

