#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), _name()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), FragTrap(src),
	ScavTrap(src), _name(src._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name),
	FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap parameter constructor called" << std::endl;
	ClapTrap::setClapTrapName(name + "_clap_name");
	setAttackDamage(30);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (this != &rhs)
	{
		FragTrap::operator=(rhs);
		ScavTrap::operator=(rhs);
		this->_name = rhs._name;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, DiamondTrap const &i)
{
	o << "DiamondTrap " << i.getName() << " [HP: " << i.getHitPoints() << " Energy: " << i.getEnergyPoints() << " Attack: " << i.getAttackDamage() << "]";
	return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << " ,ClapTrap name : " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */