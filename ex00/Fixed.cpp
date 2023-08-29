/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:11:38 by sbadr             #+#    #+#             */
/*   Updated: 2023/08/29 13:16:38 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor call\n";
	this->fixed = 0;
}

Fixed::~Fixed()
{
	std::cout<< "Destructor called\n";
}


void Fixed:: setRawBits(int const raw)
{
	std::cout<< "setRawBits member function called" <<std::endl;
	this->fixed = raw;
}

int Fixed:: getRawBits() const
{
	std::cout<< "getRawBits member function called" <<std::endl;
	return this->fixed;
}

Fixed::Fixed(int fixed): fixed(fixed)
{
	std::cout<< "constructor called" <<std::endl;
}

Fixed:: Fixed(const Fixed &t)
{
	std::cout<< "copy constructor called" <<std::endl;
	this->fixed = t.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &t)
{
	std::cout<< "copy assignment operator called" <<std::endl;
	this->fixed = t.getRawBits();
	return(*this);
}

