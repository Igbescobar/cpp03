#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
  public:
	ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap(const std::string &name);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &rhs);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	const std::string &getName() const;
	unsigned int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
	const std::string &getClapTrapName() const;

	void setEnergyPoints(int amount);
	void setHitPoints(int amount);
	void setAttackDamage(int amount);
	void setClapTrapName(const std::string &name);

  private:
	std::string _name;
	unsigned int _hitPoints;
	int _energyPoints;
	int _attackDamage;
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &i);

#endif /* ******************************************************** CLAPTRAP_H */