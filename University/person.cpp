#include "person.hpp"

Person::Person(const char* name, int birthYear) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->birthYear = birthYear;
    std::cout << "Person()" << std::endl;
}

Person::~Person() {
    delete[] name;
    std::cout << "~Person()" << std::endl;
}
