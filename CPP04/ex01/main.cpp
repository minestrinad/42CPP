// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
// #include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
    const Animal* zoo = new Animal("cow");
    const Animal* mew = new Cat("cat");
    const Animal* dog = new Dog("dog");
    
    std::cout << mew->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    mew->makeSound();
    zoo->makeSound();
    dog->makeSound();
    delete zoo;
    delete mew;
    delete dog;

    // std::cout << "-------------WRONG!-------------" << std::endl;

    // const WrongAnimal* Wrongzoo = new WrongAnimal("Wrongcow");
    // const WrongAnimal* Wrongmew = new WrongCat("Wrongcat");
    // const WrongAnimal* Wrongdog = new WrongDog("WrongDog");
    
    // std::cout << Wrongmew->getType() << std::endl;
    // std::cout << Wrongdog->getType() << std::endl;
    // Wrongmew->makeSound();
    // Wrongzoo->makeSound();
    // Wrongdog->makeSound();
    // delete Wrongzoo;
    // delete Wrongmew;
    // delete Wrongdog;

    //              Subject tests
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();

    return 0;
}
