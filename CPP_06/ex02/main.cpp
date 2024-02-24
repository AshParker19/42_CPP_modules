#include "Utils.hpp"

int main()
{
    {
        srand(time(NULL));
        Base *base = generate();
        identify(base);
        identify(*base);
    }
    std::cout << std::endl;
    {
        Wrong *w = new Wrong;
        Base *base = w;
        identify(base);
        identify(*base);
    //TODO: check memory leaks
    }
}