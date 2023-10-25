#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:
        
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap::ScavTrap &src);
        ~ScavTrap();

        void attack(const std::string &target);
        void getDamage(int amount);
        void beRepaired (int amount);
};
