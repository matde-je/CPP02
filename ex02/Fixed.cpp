#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->fixed_point_value = 0;
    return ;
}

Fixed::Fixed(const Fixed &copy)
{
    this->fixed_point_value = copy.getRawBits();
    return ;
}

Fixed &Fixed::operator = (const Fixed &copy)
{
    this->fixed_point_value = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->fixed_point_value);
}

Fixed::Fixed(const int i)
{
    fixed_point_value = i << fractional_bits;
}

Fixed::Fixed(const float i)
{
    fixed_point_value = (int)roundf(i * (1 << fractional_bits));
}

float    Fixed::toFloat(void) const
{
    return ((float)fixed_point_value / (1 << fractional_bits));
}

float    Fixed::toInt(void) const
{
    return(fixed_point_value / (1 << fractional_bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fix) //declaration of << operator overload, takes a reference to an output stream 
{
	os << fix.toFloat(); //insert the value of the float into the stream
	return os; //returns reference to the output stream allowing chaining of << operators
}

bool Fixed::operator>(const Fixed &fix) 
{
	return (this->toFloat() > fix.toFloat());
}

bool Fixed::operator<(const Fixed &fix) 
{
	return (this->toFloat() < fix.toFloat());
}

bool Fixed::operator>=(const Fixed &fix) 
{
	return (this->toFloat() >= fix.toFloat());
}

bool Fixed::operator<=(const Fixed &fix) 
{
	return (this->toFloat() <= fix.toFloat());
}

bool Fixed::operator!=(const Fixed &fix)
{
	return (this->toFloat() != fix.toFloat());
}

bool Fixed::operator==(const Fixed &fix) 
{
	return (this->toFloat() == fix.toFloat());
}

Fixed Fixed::operator+(const Fixed &fix)
{
    return (this->toFloat() + fix.toFloat());
} 

Fixed Fixed::operator-(const Fixed &fix)
{
    return (this->toFloat() - fix.toFloat());
}

Fixed Fixed::operator*(const Fixed &fix)
{
    return (this->toFloat() * fix.toFloat());
}

Fixed Fixed::operator/(const Fixed &fix)
{
    return (this->toFloat() / fix.toFloat());
}

Fixed Fixed::operator++(void)
{
    this->fixed_point_value += 1;
    return *this;
}

Fixed Fixed::operator--(void)
{
    this->fixed_point_value -= 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    this->fixed_point_value += 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    this->fixed_point_value -= 1;
    return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.toFloat() < b.toFloat())
        return (a);
    else
        return (b);
}

//the function can modify the objects a and b (but it wont)
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.toFloat() > b.toFloat())
        return (a);
    else
        return (b);
}

//the function promises not to modify the objects a and b (const)
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.toFloat() < b.toFloat())
        return (a);
    else
        return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.toFloat() > b.toFloat())
        return (a);
    else
        return (b);
}

Fixed::~Fixed()
{
    return ;
}

