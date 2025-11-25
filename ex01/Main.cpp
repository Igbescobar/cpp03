#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	// ========== Test 1: Constructor Messages ==========
    std::cout << "=== TEST 1: Creating ClapTrap ===" << std::endl;
    ClapTrap clap("Clappy");
    std::cout << std::endl;

    std::cout << "=== TEST 2: Creating ScavTrap (Check Constructor Order) ===" << std::endl;
    ScavTrap scav("Scavvy");
    std::cout << "Expected: ClapTrap constructor THEN ScavTrap constructor" << std::endl;
    std::cout << std::endl;

    // ========== Test 2: Initial Values Comparison ==========
    std::cout << "=== TEST 3: Comparing Initial Stats ===" << std::endl;
    std::cout << "ClapTrap stats - HP: " << clap.getHitPoints()
              << " | Energy: " << clap.getEnergyPoints()
              << " | Attack: " << clap.getAttackDamage() << std::endl;
    std::cout << "ScavTrap stats - HP: " << scav.getHitPoints()
              << " | Energy: " << scav.getEnergyPoints()
              << " | Attack: " << scav.getAttackDamage() << std::endl;
    std::cout << "✓ ScavTrap should have higher values (100 HP, 50 Energy, 20 Attack)" << std::endl;
    std::cout << std::endl;

    // ========== Test 3: Method Override - Attack ==========
    std::cout << "=== TEST 4: Method Override - attack() ===" << std::endl;
    std::cout << "ClapTrap attack message:" << std::endl;
    clap.attack("Target1");
    std::cout << "ScavTrap attack message (should be different):" << std::endl;
    scav.attack("Target2");
    std::cout << "✓ Messages should be different!" << std::endl;
    std::cout << std::endl;

    // ========== Test 4: Inherited Methods ==========
    std::cout << "=== TEST 5: Inherited Methods (takeDamage & beRepaired) ===" << std::endl;
    std::cout << "ScavTrap before damage - HP: " << scav.getHitPoints() << std::endl;
    scav.takeDamage(25);
    std::cout << "ScavTrap after 25 damage - HP: " << scav.getHitPoints() << std::endl;
    scav.beRepaired(15);
    std::cout << "ScavTrap after 15 repair - HP: " << scav.getHitPoints() << std::endl;
    std::cout << "✓ Inherited methods working on derived class!" << std::endl;
    std::cout << std::endl;

    // ========== Test 5: ScavTrap Special Method ==========
    std::cout << "=== TEST 6: ScavTrap-Specific Method ===" << std::endl;
    scav.guardGate();
    std::cout << "✓ guardGate() is unique to ScavTrap!" << std::endl;
    std::cout << std::endl;

    // ========== Test 6: Copy Constructor ==========
    std::cout << "=== TEST 7: Copy Constructor (Check Constructor Order) ===" << std::endl;
    ScavTrap scavCopy(scav);
    std::cout << "Copied ScavTrap stats - HP: " << scavCopy.getHitPoints()
              << " | Energy: " << scavCopy.getEnergyPoints()
              << " | Name: " << scavCopy.getName() << std::endl;
    std::cout << "✓ Should show ClapTrap copy constructor THEN ScavTrap copy constructor" << std::endl;
    std::cout << std::endl;

    // ========== Test 7: Assignment Operator ==========
    std::cout << "=== TEST 8: Assignment Operator ===" << std::endl;
    ScavTrap scavAssign("ToBeReplaced");
    std::cout << "Before assignment - Name: " << scavAssign.getName()
              << " | HP: " << scavAssign.getHitPoints() << std::endl;
    scavAssign = scav;
    std::cout << "After assignment  - Name: " << scavAssign.getName()
              << " | HP: " << scavAssign.getHitPoints() << std::endl;
    std::cout << "✓ Values should match the source ScavTrap" << std::endl;
    std::cout << std::endl;

    // ========== Test 8: Energy Depletion ==========
    std::cout << "=== TEST 9: Energy Depletion ===" << std::endl;
    ScavTrap tired("Exhausted");
    tired.setEnergyPoints(2);
    std::cout << "Starting energy: " << tired.getEnergyPoints() << std::endl;
    
    tired.attack("Enemy1");
    std::cout << "After attack 1 - Energy: " << tired.getEnergyPoints() << std::endl;
    
    tired.attack("Enemy2");
    std::cout << "After attack 2 - Energy: " << tired.getEnergyPoints() << std::endl;
    
    tired.attack("Enemy3");
    std::cout << "After attack 3 - Energy: " << tired.getEnergyPoints() << std::endl;
    std::cout << "✓ Last attack should fail (no energy)" << std::endl;
    std::cout << std::endl;

    // ========== Test 9: Default Constructor ==========
    std::cout << "=== TEST 10: Default Constructor ===" << std::endl;
    ScavTrap defaultScav;
    std::cout << "Default ScavTrap - HP: " << defaultScav.getHitPoints()
              << " | Energy: " << defaultScav.getEnergyPoints()
              << " | Attack: " << defaultScav.getAttackDamage() << std::endl;
    std::cout << "Should still have ScavTrap values (100, 50, 20)" << std::endl;
    std::cout << std::endl;

	return (0);
}