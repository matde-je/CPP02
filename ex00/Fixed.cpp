
#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->fixed_point_value = 0;
    return ;
}

Fixed::~Fixed()
{
    return ;
}

int Fixed::getRawBits(void) const
{
    return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point_value = raw;
    return ;
}

