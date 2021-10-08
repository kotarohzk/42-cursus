/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:33:41 by jseo              #+#    #+#             */
/*   Updated: 2021/10/08 16:08:52 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int								Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point);
}

void							Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point = raw;
}

Fixed&							Fixed::operator=(const Fixed& f)
{
	std::cout << "Assignation operator called" << std::endl;
	_fixed_point = f.getRawBits();
	return (*this);
}

Fixed::Fixed(void)
	: _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
