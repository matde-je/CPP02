
#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>

class Fixed {
    private:
        int fixed_point_value;
        static const int fractional_bits = 8;

	public:
		Fixed(void);
		~Fixed(void);

        Fixed(const Fixed &copy); //copy constructor
        Fixed &operator = (const Fixed &copy); //assignment operation

        int getRawBits(void) const;
        void setRawBits(int const raw);
};


#endif