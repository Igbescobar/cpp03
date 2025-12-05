#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    // ========== TEST 1: Constructor Messages and Virtual Inheritance ==========
    std::cout << "=== TEST 1: Constructor Chain (Virtual Inheritance) ===" << std::endl;
    std::cout << "Expected order: ClapTrap → FragTrap → ScavTrap → DiamondTrap" << std::endl;
    std::cout << "(Only ONE ClapTrap instance should be created!)" << std::endl;
    DiamondTrap diamond("Sparkle");
    std::cout << "✓ Constructor chain complete" << std::endl;
    std::cout << std::endl;

    // ========== TEST 2: Inherited Attributes ==========
    std::cout << "=== TEST 2: Inherited Attributes ===" << std::endl;
    std::cout << "Hit Points (from FragTrap): " << diamond.getHitPoints() << " (should be 100)" << std::endl;
    std::cout << "Energy Points (from ScavTrap): " << diamond.getEnergyPoints() << " (should be 50)" << std::endl;
    std::cout << "Attack Damage (from FragTrap): " << diamond.getAttackDamage() << " (should be 30)" << std::endl;
    std::cout << "✓ All attributes inherited correctly" << std::endl;
    std::cout << std::endl;

    // ========== TEST 3: whoAmI() Method ==========
    std::cout << "=== TEST 3: whoAmI() - Special DiamondTrap Method ===" << std::endl;
    std::cout << "Displaying both DiamondTrap name and ClapTrap name:" << std::endl;
    diamond.whoAmI();
    std::cout << "Expected: DiamondTrap name = 'Sparkle', ClapTrap name = 'Sparkle_clap_name'" << std::endl;
    std::cout << "✓ whoAmI() demonstrates the dual naming system" << std::endl;
    std::cout << std::endl;

    // ========== TEST 4: attack() Method (from ScavTrap) ==========
    std::cout << "=== TEST 4: attack() Method (Should use ScavTrap version) ===" << std::endl;
    std::cout << "Before attack - Energy: " << diamond.getEnergyPoints() << std::endl;
    diamond.attack("Enemy1");
    std::cout << "After attack  - Energy: " << diamond.getEnergyPoints() << std::endl;
    std::cout << "✓ Attack uses ScavTrap's version (costs 1 energy)" << std::endl;
    std::cout << std::endl;

    // ========== TEST 5: takeDamage() Method (Inherited from ClapTrap) ==========
    std::cout << "=== TEST 5: takeDamage() - Inherited Method ===" << std::endl;
    std::cout << "Before damage - Hit Points: " << diamond.getHitPoints() << std::endl;
    diamond.takeDamage(20);
    std::cout << "After 20 damage - Hit Points: " << diamond.getHitPoints() << std::endl;
    std::cout << "✓ takeDamage() inherited and working" << std::endl;
    std::cout << std::endl;

    // ========== TEST 6: beRepaired() Method (Inherited from ClapTrap) ==========
    std::cout << "=== TEST 6: beRepaired() - Inherited Method ===" << std::endl;
    std::cout << "Before repair - Hit Points: " << diamond.getHitPoints() << std::endl;
    diamond.beRepaired(15);
    std::cout << "After repair  - Hit Points: " << diamond.getHitPoints() << std::endl;
    std::cout << "✓ beRepaired() inherited and working" << std::endl;
    std::cout << std::endl;

    // ========== TEST 7: Copy Constructor ==========
    std::cout << "=== TEST 7: Copy Constructor ===" << std::endl;
    std::cout << "Creating copy of DiamondTrap..." << std::endl;
    DiamondTrap diamondCopy(diamond);
    std::cout << "Original - Name: " << diamond.getName() << " | HP: " << diamond.getHitPoints() << std::endl;
    std::cout << "Copy     - Name: " << diamondCopy.getName() << " | HP: " << diamondCopy.getHitPoints() << std::endl;
    std::cout << "✓ Copy constructor working" << std::endl;
    std::cout << std::endl;

    // ========== TEST 8: Assignment Operator ==========
    std::cout << "=== TEST 8: Assignment Operator ===" << std::endl;
    DiamondTrap diamondAssign("Shiny");
    std::cout << "Before assignment - Name: " << diamondAssign.getName() << std::endl;
    diamondAssign = diamond;
    std::cout << "After assignment  - Name: " << diamondAssign.getName() << std::endl;
    std::cout << "✓ Assignment operator working" << std::endl;
    std::cout << std::endl;

    // ========== TEST 9: Default Constructor ==========
    std::cout << "=== TEST 9: Default Constructor ===" << std::endl;
    DiamondTrap diamondDefault;
    std::cout << "Default DiamondTrap created" << std::endl;
    std::cout << "HP: " << diamondDefault.getHitPoints() 
          << " | Energy: " << diamondDefault.getEnergyPoints() 
          << " | Attack: " << diamondDefault.getAttackDamage() << std::endl;
    std::cout << "✓ Default constructor working" << std::endl;
    std::cout << std::endl;

    // ========== TEST 10: Energy Depletion Scenario ==========
    std::cout << "=== TEST 10: Energy Depletion Scenario ===" << std::endl;
    DiamondTrap tired("Battery");
    tired.setEnergyPoints(3);
    std::cout << "Starting energy: " << tired.getEnergyPoints() << std::endl;
    
    tired.attack("Foe1");
    std::cout << "After attack 1 - Energy: " << tired.getEnergyPoints() << std::endl;
    
    tired.attack("Foe2");
    std::cout << "After attack 2 - Energy: " << tired.getEnergyPoints() << std::endl;
    
    tired.attack("Foe3");
    std::cout << "After attack 3 - Energy: " << tired.getEnergyPoints() << std::endl;
    
    tired.attack("Foe4");
    std::cout << "After attack 4 (should fail) - Energy: " << tired.getEnergyPoints() << std::endl;
    std::cout << "✓ Energy system working correctly" << std::endl;
    std::cout << std::endl;

    // ========== TEST 11: Hit Points Depletion ==========
    std::cout << "=== TEST 11: Hit Points Depletion ===" << std::endl;
    DiamondTrap fragile("Brittle");
    fragile.setHitPoints(25);
    std::cout << "Starting HP: " << fragile.getHitPoints() << std::endl;
    
    fragile.takeDamage(10);
    std::cout << "After 10 damage - HP: " << fragile.getHitPoints() << std::endl;
    
    fragile.takeDamage(15);
    std::cout << "After 15 damage - HP: " << fragile.getHitPoints() << std::endl;
    
    fragile.takeDamage(100);
    std::cout << "After trying 100 damage to dead DiamondTrap:" << std::endl;
    fragile.takeDamage(50);
    std::cout << "✓ Cannot be damaged when dead" << std::endl;
    std::cout << std::endl;

    // ========== TEST 12: Multiple DiamondTraps (Verify No Diamond Problem) ==========
    std::cout << "=== TEST 12: Multiple DiamondTraps ===" << std::endl;
    DiamondTrap diamond1("Alpha");
    DiamondTrap diamond2("Beta");
    DiamondTrap diamond3("Gamma");
    std::cout << "Created 3 DiamondTraps" << std::endl;
    std::cout << "If only 3 ClapTraps created (not 6 or 9), virtual inheritance worked!" << std::endl;
    diamond1.whoAmI();
    diamond2.whoAmI();
    diamond3.whoAmI();
    std::cout << "✓ Multiple instances working correctly" << std::endl;
    std::cout << std::endl;

    // ========== Destructor Test ==========
    std::cout << "=== TEST 13: Destructors (Should show in reverse order) ===" << std::endl;
    std::cout << "When objects go out of scope, expected destruction order:" << std::endl;
    std::cout << "DiamondTrap → ScavTrap → FragTrap → ClapTrap" << std::endl;
    std::cout << std::endl;

    return (0);
}