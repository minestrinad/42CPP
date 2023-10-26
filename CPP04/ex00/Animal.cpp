#include "Animal.hpp"

Animal::Animal() { }

Animal::Animal(const Animal &src) { *this = src; }

Animal::~Animal() { }

Animal::&operator=(const Animal &copy){
    type = copy.type;
}
