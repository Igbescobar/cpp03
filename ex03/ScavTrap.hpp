#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : virtual public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(ScavTrap const &src);
	ScavTrap(const std::string &name);
	~ScavTrap();

	ScavTrap &operator=(ScavTrap const &rhs);
	void guardGate();
	void attack(const std::string &target);

  private:
};

std::ostream &operator<<(std::ostream &o, ScavTrap const &i);

#endif /* ******************************************************** SCAVTRAP_H */