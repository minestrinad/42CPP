#include <iostream>

class Animal
{
    protected:
        std::string type;
    private:

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &copy);
        virtual ~Animal();
        Animal &operator=(const Animal &copy);
        void virtual makeSound() const;
};
