#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap &src);
        ~FragTrap();

        void attack(const std::string &target);
        void getDamage(int amount);
        void beRepaired (int amount);
        void highFivesGuys();
};
