
#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

//A constructor that takes a constant floating-point number as a parameter.

class Fixed
{
	private:
        int fixed_point_value;
        static const int fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float i);
		~Fixed(void);
		Fixed(const Fixed &copy); //copy constructor
        Fixed &operator = (const Fixed &copy); //assignment operation

        int getRawBits(void) const;

		float toFloat( void ) const;
		int    toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fix);

#endif