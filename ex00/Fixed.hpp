 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:11:36 by sbadr             #+#    #+#             */
/*   Updated: 2023/08/25 16:24:31 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <string>
# include <iostream>

/*                 My First Class in Orthodox Canonical Form              */


class Fixed {
	private:
		int					fixed;
		static const int	fractional_bits = 8;
	public:
		// default constructor
		Fixed();
		Fixed(int fixed);
		Fixed(const Fixed& fx);
		// Copy assignment operator
		Fixed& operator=(const Fixed &t);
		// destructor
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif