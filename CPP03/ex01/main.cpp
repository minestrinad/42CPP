#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Elio");
    scav.attack("Pippo");
    scav.takeDamage(10);
    scav.beRepaired(10);
    scav.guardGate();
    return 0;
}
