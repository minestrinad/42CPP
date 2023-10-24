#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Clap");
    ClapTrap trap("Trap");

    clap.attack("Trap");
    trap.takeDamage(2);
    trap.beRepaired(1);
    return 0;
}
