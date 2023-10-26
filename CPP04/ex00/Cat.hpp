#include "Animal.hpp"

class Cat : public Animal
{
    protected:
        std::string type;
    private:
        
    public:
        Cat();
        Cat(const Cat &src);
        virtual ~Cat();
        Cat &operator=(const Cat &src);
        void makeSound() const;
};
