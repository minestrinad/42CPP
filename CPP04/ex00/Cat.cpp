#include "Cat.hpp"

Cat::Cat(): Animal(){ }

Cat::Cat(std::string type): Animal(type) {
    this->type = type;
    std::cout << "A new cat is born!" << std::endl;
}

Cat::Cat(Cat &src): Animal(src) { }

Cat::~Cat() { 
    std::cout << "A cat is dead! :(" << std::endl;
}

void Cat::makeSound(){
    std::cout << "mew :3" << std::endl;
}
