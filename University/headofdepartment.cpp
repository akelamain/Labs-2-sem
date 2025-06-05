#include "headofdepartment.hpp"

HeadOfDepartment::HeadOfDepartment(const char* name, int birthYear, double salary)
    : Person(name, birthYear), salary(salary) {
    std::cout << "HeadOfDepartment()" << std::endl;
}

HeadOfDepartment::~HeadOfDepartment() {
    std::cout << "~HeadOfDepartment()" << std::endl;
}

void HeadOfDepartment::show() const {
    std::cout << "Заведующий Кафедрой: " << name << ", год рождения: " << birthYear
              << ", зарплата: " << salary << std::endl;
}
