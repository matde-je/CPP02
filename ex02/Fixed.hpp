
#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>


class Fixed {
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

		bool operator>(const Fixed &fix);
		bool operator<(const Fixed &fix);
		bool operator>=(const Fixed &fix);
		bool operator<=(const Fixed &fix);
		bool operator==(const Fixed &fix);
		bool operator!=(const Fixed &fix);

		Fixed operator+(const Fixed &fix);
		Fixed operator-(const Fixed &fix);
		Fixed operator*(const Fixed &fix);
		Fixed operator/(const Fixed &fix);
		Fixed operator++(void);
		Fixed operator--(void);

		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

        int getRawBits(void) const;

		float toFloat( void ) const;
		float    toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fix);

#endif