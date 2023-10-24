#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &src);
        ~ClapTrap();
        ClapTrap &operator=(const ClapTrap &src);
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
