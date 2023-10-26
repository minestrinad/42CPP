#include "Animal.hpp"

Animal::Animal() { 
    this->type = "zoo";
    std::cout << "A new animal is born!" << std::endl;
}

Animal::Animal(std::string type){
    this->type = type;
    std::cout << "New animal of type: " << type << " is born!" << std::endl;
}

Animal::Animal(Animal &src) { *this = src; }

Animal::~Animal() { 
    std::cout << "An animal is dead! :(" << std::endl;
}

Animal &Animal::operator=(Animal &copy){
    type = copy.type;
    return copy;
}

void Animal::makeSound() {
    std::cout << "Zoo sounds" << std::endl;
}