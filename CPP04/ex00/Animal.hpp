#include <iostream>

class Animal
{
    protected:
        std::string type;
    private:

    public:
        Animal();
        Animal(std::string type);
        Animal(Animal &copy);
        virtual ~Animal();
        Animal &operator=(Animal &copy);
        void virtual makeSound();
};
