#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
    // ========== Test 1: Constructor Messages ==========
    std::cout << "=== TEST 1: Creating ClapTrap ===" << std::endl;
    ClapTrap clap("Clappy");
    std::cout << std::endl;

    std::cout << "=== TEST 2: Creating FragTrap (Check Constructor Order) ===" << std::endl;
    FragTrap frag("Fraggy");
    std::cout << "Expected: ClapTrap constructor THEN FragTrap constructor" << std::endl;
    std::cout << std::endl;

    // ========== Test 2: Initial Values Comparison ==========
    std::cout << "=== TEST 3: Comparing Initial Stats ===" << std::endl;
    std::cout << "ClapTrap stats - HP: " << clap.getHitPoints()
              << " | Energy: " << clap.getEnergyPoints()
              << " | Attack: " << clap.getAttackDamage() << std::endl;
    std::cout << "FragTrap stats - HP: " << frag.getHitPoints()
              << " | Energy: " << frag.getEnergyPoints()
              << " | Attack: " << frag.getAttackDamage() << std::endl;
    std::cout << "✓ FragTrap should have higher values (100 HP, 100 Energy, 30 Attack)" << std::endl;
    std::cout << std::endl;

    // ========== Test 3: Method Override - Attack ==========
    std::cout << "=== TEST 4: Method Override - attack() ===" << std::endl;
    std::cout << "ClapTrap attack message:" << std::endl;
    clap.attack("Target1");
    std::cout << "FragTrap attack message (should be different):" << std::endl;
    frag.attack("Target2");
    std::cout << "✓ Messages should be different!" << std::endl;
    std::cout << std::endl;

    // ========== Test 4: Inherited Methods ==========
    std::cout << "=== TEST 5: Inherited Methods (takeDamage & beRepaired) ===" << std::endl;
    std::cout << "FragTrap before damage - HP: " << frag.getHitPoints() << std::endl;
    frag.takeDamage(25);
    std::cout << "FragTrap after 25 damage - HP: " << frag.getHitPoints() << std::endl;
    frag.beRepaired(15);
    std::cout << "FragTrap after 15 repair - HP: " << frag.getHitPoints() << std::endl;
    std::cout << "✓ Inherited methods working on derived class!" << std::endl;
    std::cout << std::endl;

    // ========== Test 5: FragTrap Special Method ==========
    std::cout << "=== TEST 6: FragTrap-Specific Method ===" << std::endl;
    frag.highFivesGuys();
    std::cout << "✓ highFivesGuys() is unique to FragTrap!" << std::endl;
    std::cout << std::endl;

    // ========== Test 6: Copy Constructor ==========
    std::cout << "=== TEST 7: Copy Constructor (Check Constructor Order) ===" << std::endl;
    FragTrap fragCopy(frag);
    std::cout << "Copied FragTrap stats - HP: " << fragCopy.getHitPoints()
              << " | Energy: " << fragCopy.getEnergyPoints()
              << " | Name: " << fragCopy.getName() << std::endl;
    std::cout << "✓ Should show ClapTrap copy constructor THEN FragTrap copy constructor" << std::endl;
    std::cout << std::endl;

    // ========== Test 7: Assignment Operator ==========
    std::cout << "=== TEST 8: Assignment Operator ===" << std::endl;
    FragTrap fragAssign("ToBeReplaced");
    std::cout << "Before assignment - Name: " << fragAssign.getName()
              << " | HP: " << fragAssign.getHitPoints() << std::endl;
    fragAssign = frag;
    std::cout << "After assignment  - Name: " << fragAssign.getName()
              << " | HP: " << fragAssign.getHitPoints() << std::endl;
    std::cout << "✓ Values should match the source FragTrap" << std::endl;
    std::cout << std::endl;

    // ========== Test 8: Energy Depletion ==========
    std::cout << "=== TEST 9: Energy Depletion ===" << std::endl;
    FragTrap tired("Exhausted");
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
    FragTrap defaultFrag;
    std::cout << "Default FragTrap - HP: " << defaultFrag.getHitPoints()
              << " | Energy: " << defaultFrag.getEnergyPoints()
              << " | Attack: " << defaultFrag.getAttackDamage() << std::endl;
    std::cout << "Should still have FragTrap values (100, 100, 30)" << std::endl;
    std::cout << std::endl;

    // ========== Destructor Test ==========
    std::cout << "=== TEST 11: Destruction Order ===" << std::endl;
    std::cout << "When objects go out of scope, destruction should be:" << std::endl;
    std::cout << "FragTrap destructor THEN ClapTrap destructor (reverse of construction)" << std::endl;
    std::cout << std::endl;

    return (0);
}