#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap
{
  public:
	FragTrap();
	FragTrap(FragTrap const &src);
	FragTrap(const std::string &name);
	~FragTrap();

	FragTrap &operator=(FragTrap const &rhs);
	void highFivesGuys(void);

  private:
};

std::ostream &operator<<(std::ostream &o, FragTrap const &i);

#endif /* ******************************************************** FRAGTRAP_H */