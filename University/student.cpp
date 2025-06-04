#include "student.hpp"

Student::Student(const char* name, int birthYear, int workingDays , int grade)
    : Professor(name, birthYear, workingDays), grade(grade) {
    std::cout << "Student()" << std::endl;
}

Student::~Student() {
    std::cout << "~Student()" << std::endl;
}

void Student::show() const {
    std::cout << "Студент: " << name << ", год рождения: " << birthYear
              << ", курс: " << grade << ", количество рабочих дней: " << workingDays << std::endl;
}
