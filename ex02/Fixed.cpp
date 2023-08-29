/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:11:38 by sbadr             #+#    #+#             */
/*   Updated: 2023/08/29 11:09:12 by sbadr            ###   ########.fr       */
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
	this->fixed_num = 0;
}


Fixed::~Fixed()
{
}


void Fixed:: setRawBits(int const raw)
{
	this->fixed_num = raw;
}

int Fixed:: getRawBits() const
{
	return this->fixed_num;
}

Fixed::Fixed(const int fixed)
{
	this->fixed_num = fixed * pow(2, fractional_bits);
}

Fixed::Fixed(const float fixed)
{
	this->fixed_num = roundf(fixed * pow(2, fractional_bits));
}

Fixed:: Fixed(const Fixed &t)
{
	this->fixed_num = t.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &t)
{
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


bool Fixed::operator>(const Fixed &t)
{
	if (this->getRawBits() > t.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &t)
{
	if (this->getRawBits() >= t.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &t)
{
	if (this->getRawBits() < t.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &t)
{
	if (this->getRawBits() <= t.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &t)
{
	if (this->getRawBits() == t.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &t)
{
	if (this->getRawBits() != t.getRawBits())
		return true;
	return false;
}
	
Fixed Fixed::operator+(const Fixed &t){
	return (this->toFloat() + t.toFloat());
}

Fixed Fixed::operator-(const Fixed &t){
	return (this->toFloat() - t.toFloat());
}

Fixed Fixed::operator*(const Fixed &t){
	return (this->toFloat() * t.toFloat());
}

Fixed Fixed::operator/(const Fixed &t){
	return (this->toFloat() / t.toFloat());
}

Fixed& Fixed:: operator++(void)
{
	this->fixed_num++;
	return *this;
}

Fixed& Fixed:: operator--(void)
{
	this->fixed_num--;
	return *this;
}

Fixed Fixed:: operator++(int) {
    Fixed temp(*this);
    fixed_num++;
    return temp;
}

Fixed Fixed:: operator--(int) {
    Fixed temp(*this);
    fixed_num--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a,const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a,const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}
