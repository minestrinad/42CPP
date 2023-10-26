#include "Animal.hpp"

class Cat : public Animal
{
    private:
        
    public:
        Cat();
        Cat(std::string type);
        Cat(Cat &src);
        ~Cat();
        void virtual makeSound();
};
