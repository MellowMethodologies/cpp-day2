/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:11:36 by sbadr             #+#    #+#             */
/*   Updated: 2023/08/27 14:37:21 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

/*                 My First Class in Orthodox Canonical Form              */

class Fixed {
	private:
		int fixed_num;
		static const int fractional_bits = 8;
	public:
		Fixed();
		Fixed(const int fixed);
		Fixed(const float fixed);
		Fixed(const Fixed& fx);
		// Copy assignment operator
		Fixed& operator=(const Fixed &t);
		// destructor
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits() const;
		void setRawBits(int const raw);
};

int ft_pow(double a, int b);
std::ostream& operator<<(std::ostream& o, const Fixed& i);

#endif