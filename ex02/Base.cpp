#include "Base.hpp"

Base *generate(void)
{
    int nb = 0;

    srand(time(NULL));
    nb = rand() % 100;
    if (nb >= 0 && nb <= 33)
        return new A();
    else if (nb > 33 && nb <= 66)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer = A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer = B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer = C" << std::endl;
}

void identify(Base &p)
{
    try 
    {
        Base &a = dynamic_cast<A&>(p); 
        (void)a;
        std::cout << "Reference = A" << std::endl;
    }
    catch(std::exception &e) {}

    try 
    {
        Base &b = dynamic_cast<B&>(p); 
        (void)b;
        std::cout << "Reference = B" << std::endl;
    }
    catch(std::exception &e) {} 
   
    try 
    {
        Base &c = dynamic_cast<C&>(p); 
        (void)c;
        std::cout << "Reference = C" << std::endl;
    }
    catch(std::exception &e) {}
}