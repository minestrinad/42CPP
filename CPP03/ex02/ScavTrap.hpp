#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap &src);
        ~ScavTrap();

        void attack(const std::string &target);
        void getDamage(int amount);
        void beRepaired (int amount);
        void guardGate();
};
