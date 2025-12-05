#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	std::cout << "This is the default constructor!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "This is the parameter constructor!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) : _name(copy._name),
	_hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints),
	_attackDamage(copy._attackDamage)
{
	std::cout << "This is the copy constructor!" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "This is the deconstructor!" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &i)
{
	o << "ClapTrap " << i.getName() << " \
Hit Points: "
		<< i.getHitPoints() << " | Energy Points: " << i.getEnergyPoints() << " | Attack Damage: " << i.getAttackDamage();
	return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const std::string &target)
{
	int	points;

	if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
	{
		std::cout << "Not enough energy/health" << std::endl;
		return ;
	}
	else
	{
		points = this->getEnergyPoints() - 1;
		this->setEnergyPoints(points);
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ",\
 causing " << _attackDamage
					<< " points of damage!" << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() == 0)
		std::cout << "ClapTrap is already dead!" << std::endl;
	else if (amount >= this->getHitPoints())
	{
		this->setHitPoints(0);
		std::cout << "ClapTrap " << this->getName() << " recieves " << amount << " of damage,\
 is now dead!" << std::endl;
	}
	else
	{
		this->setHitPoints(this->getHitPoints() - amount);
		std::cout << "ClapTrap " << this->getName() << " recieves " << amount << " of damage!" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() <= 0)
		std::cout << this->getName() << " has no energy points" << std::endl;
	else
	{
		this->setHitPoints(this->getHitPoints() + amount);
		std::cout << this->getName() << " has gain " << amount << " of hit points!" << std::endl;
	}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string &ClapTrap::getName() const
{
	return (_name);
}

int ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

const std::string &ClapTrap::getClapTrapName() const
{
	return (_name);
}

void ClapTrap::setEnergyPoints(int amount)
{
	this->_energyPoints = amount;
}

void ClapTrap::setHitPoints(int amount)
{
	this->_hitPoints = amount;
}

void ClapTrap::setAttackDamage(int amount)
{
	this->_attackDamage = amount;
}

void ClapTrap::setClapTrapName(const std::string &name)
{
	this->_name = name;
}

/* ************************************************************************** */