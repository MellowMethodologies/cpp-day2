/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:11:38 by sbadr             #+#    #+#             */
/*   Updated: 2023/08/27 14:39:25 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int pow(double a, int b)
{
	while (b--)
		a *= a;
	return a;
}

Fixed::Fixed()
{
	std::cout << "Default constructor call\n";
	this->fixed_num = 0;
}


Fixed::~Fixed()
{
	std::cout<< "A destructor call\n";
}


void Fixed:: setRawBits(int const raw)
{
	std::cout<< "setRawBits member function called" <<std::endl;
	this->fixed_num = raw;
}

int Fixed:: getRawBits() const
{
	std::cout<< "getRawBits member function called" <<std::endl;
	return this->fixed_num;
}

Fixed::Fixed(const int fixed)
{
	std::cout<< "Int constructor called" <<std::endl;
	this->fixed_num = fixed * pow(2, fractional_bits);
}

Fixed::Fixed(const float fixed)
{
	std::cout<< "Float constructor called" <<std::endl;
	this->fixed_num = roundf(fixed * pow(2, fractional_bits));
}

Fixed:: Fixed(const Fixed &t)
{
	std::cout<< "copy constructor called" <<std::endl;
	this->fixed_num = t.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &t)
{
	std::cout<< "copy assignment operator called" <<std::endl;
	this->fixed_num = t.getRawBits();
	return(*this);
}

float Fixed::toFloat( void ) const
{
	return ((float)roundf(this->fixed_num) / pow(2, fractional_bits));
}

int Fixed:: toInt( void ) const
{
	return (this->fixed_num / pow(2, fractional_bits));
}

std::ostream& operator<<(std::ostream& o, const Fixed& i)
{
    o << i.toFloat();
    return o;
}
