#include "headofdepartment.hpp"

HeadOfDepartment::HeadOfDepartment(const char* name, int birthYear, double salary)
    : Person(name, birthYear), salary(salary) {
    std::cout << "Student()" << std::endl;
}

HeadOfDepartment::~HeadOfDepartment() {
    std::cout << "~Student()" << std::endl;
}

void HeadOfDepartment::show() const {
    std::cout << "Заведующий Кафедрой: " << name << ", год рождения: " << birthYear
              << ", зарплата: " << salary << std::endl;
}
