/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:11:33 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 21:28:32 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAP_TRAP_H__
# define __CLAP_TRAP_H__

# include <string>
# include <iomanip>
# include <iostream>

# define RED						"\033[0;31m"
# define GREEN						"\033[0;32m"
# define YELLOW						"\033[1;33m"
# define EOC						"\033[0;0m"
# define W_SIZE						12
# define C_NAME						"ClapTrap"
# define C_HP						10
# define C_EP						10
# define C_AD						0

class ClapTrap
{
	private:
		std::string					_name;
		unsigned int				_hp;
		unsigned int				_ep;
		unsigned int				_ad;

		const std::string			_class_name;
		const unsigned int			_class_hp;
		const unsigned int			_class_ep;
		const unsigned int			_class_ad;

	public:
		void						print(std::ostream& o) const;

		void						attack(const std::string& target);
		void						takeDamage(unsigned int amount);
		void						beRepaired(unsigned int amount);

		void						setName(const std::string& name);
		void						setHP(unsigned int& hp);
		void						setEP(unsigned int& ep);
		void						setAD(unsigned int& ad);

		std::string					getName(void) const;
		unsigned int				getHP(void) const;
		unsigned int				getEP(void) const;
		unsigned int				getAD(void) const;

		void						setClassName(const std::string& name);
		void						setClassHP(const unsigned int& hp);
		void						setClassEP(const unsigned int& ep);
		void						setClassAD(const unsigned int& ad);

		std::string					getClassName(void) const;
		unsigned int				getClassHP(void) const;
		unsigned int				getClassEP(void) const;
		unsigned int				getClassAD(void) const;

		ClapTrap&					operator=(const ClapTrap& c);
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& c);
		~ClapTrap(void);
};

#endif