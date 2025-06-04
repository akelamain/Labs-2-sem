#include "professor.hpp"

Professor::Professor(const char* name, int birthYear, int workingDays)
    : Person(name, birthYear), workingDays(workingDays) {
    std::cout << "Professor()" << std::endl;
}

Professor::~Professor() {
    std::cout << "~Professor()" << std::endl;
}

void Professor::show() const {
    std::cout << "Преподаватель: " << name << ", год рождения: " << birthYear
              << ", количество рабочих дней: " << workingDays << std::endl;
}
