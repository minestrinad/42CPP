// #include "Animal.hpp"
#include "Cat.hpp"
// #include "Dog.hpp"
// #include "WrongCat.hpp"
// #include "WrongDog.hpp"

int main()
{
    const Animal* zoo = new Animal();
    const Animal* mew = new Cat();
    
    std::cout << mew->getType() << " " << std::endl;
    mew->makeSound();
    zoo->makeSound();
}
