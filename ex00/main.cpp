#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap("TestBot");

	std::cout << "\n--- Initial Stats ---" << std::endl;
	std::cout << clap << std::endl;

	std::cout << "\n--- Testing attack function ---" << std::endl;

	std::cout << "\nBefore Attack 1:" << std::endl;
	std::cout << clap << std::endl;
	clap.attack("Enemy1");
	std::cout << "After Attack 1:" << std::endl;
	std::cout << clap << std::endl;

	std::cout << "\nBefore Attack 2:" << std::endl;
	std::cout << clap << std::endl;
	clap.attack("Enemy2");
	std::cout << "After Attack 2:" << std::endl;
	std::cout << clap << std::endl;

	std::cout << "\nBefore Attack 3:" << std::endl;
	std::cout << clap << std::endl;
	clap.attack("Enemy3");
	std::cout << "After Attack 3:" << std::endl;
	std::cout << clap << std::endl;

	std::cout << "\n--- Testing takeDamage function ---" << std::endl;

	std::cout << "\nBefore taking 3 damage:" << std::endl;
	std::cout << clap << std::endl;
	clap.takeDamage(3);
	std::cout << "After taking 3 damage:" << std::endl;
	std::cout << clap << std::endl;

	std::cout << "\nBefore taking 4 damage:" << std::endl;
	std::cout << clap << std::endl;
	clap.takeDamage(4);
	std::cout << "After taking 4 damage:" << std::endl;
	std::cout << clap << std::endl;

	std::cout << "\nTrying to take damage when already dead:" << std::endl;
	clap.takeDamage(5);
	std::cout << clap << std::endl;

	std::cout << "\n--- Testing beRepaired function ---" << std::endl;

	std::cout << "\nBefore repair (dead with 0 energy):" << std::endl;
	std::cout << clap << std::endl;
	clap.beRepaired(5);
	std::cout << "After repair attempt:" << std::endl;
	std::cout << clap << std::endl;

	ClapTrap clap2("TestBot2");

	std::cout << "\nNew ClapTrap - Initial Stats:" << std::endl;
	std::cout << clap2 << std::endl;

	clap2.attack("Enemy");
	clap2.attack("Enemy");
	std::cout << "\nAfter 2 attacks:" << std::endl;
	std::cout << clap2 << std::endl;

	clap2.takeDamage(5);
	std::cout << "\nAfter taking 5 damage:" << std::endl;
	std::cout << clap2 << std::endl;

	std::cout << "\nBefore repair:" << std::endl;
	std::cout << clap2 << std::endl;
	clap2.beRepaired(4);
	std::cout << "After repair with 4 hit points:" << std::endl;
	std::cout << clap2 << std::endl;

	return (0);
}