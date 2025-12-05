#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
  public:
	DiamondTrap();
	DiamondTrap(DiamondTrap const &src);
	DiamondTrap(const std::string &name);
	~DiamondTrap();

	DiamondTrap &operator=(DiamondTrap const &rhs);
	void attack(const std::string &target);
	void whoAmI();

  private:
	std::string _name;
};

std::ostream &operator<<(std::ostream &o, DiamondTrap const &i);

#endif /* ***************************************************** DIAMONDTRAP_H */