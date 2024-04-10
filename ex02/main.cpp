
#include "Fixed.hpp"

int main(void)
{
    Fixed a(4);
    Fixed c(3);
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << b << std::endl;

    std::cout << a << std::endl; 
    std::cout << ++a << std::endl; //operator++(void)
    std::cout << a << std::endl;
    std::cout << a++ << std::endl; //operator++(int)

    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl;

    std::cout << Fixed::max(a, c) << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}
