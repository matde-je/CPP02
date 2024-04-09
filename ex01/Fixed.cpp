#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point_value = 0;
    return ;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator = (const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed_point_value = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->fixed_point_value);
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called"<< std::endl;
    fixed_point_value = i << fractional_bits;
}

Fixed::Fixed(const float i)
{
    std::cout << "Float constructor called"<< std::endl;
    this->fixed_point_value = (int)roundf(i * (1 << fractional_bits));
}

//converts the fixed-point value to a floating-point value
float    Fixed::toFloat(void) const
{
    return((float)fixed_point_value / (1 << fractional_bits));
}

int    Fixed::toInt(void) const
{
    return(fixed_point_value / (1 << fractional_bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fix) //declaration of << operator overload, takes a reference to an output stream 
{
	os << fix.toFloat(); //insert the value of the float into the stream
	return os; //returns reference to the output stream allowing chaining of << operators
}
