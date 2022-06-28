#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>

class	ClapTrap {

public :

	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &ct);
	~ClapTrap(void);

	ClapTrap	&operator=(ClapTrap &ct);

	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	void		setName(std::string name);
	void		setHp(int hp);
	void		setEp(int ep);
	void		setAd(int ad);
	std::string	getName(void) const;
	int			getHp(void) const;
	int			getEp(void) const;
	int			getAd(void) const;

protected :

	std::string	_name;
	int			_hp;
	int			_ep;
	int			_ad;

};

#endif