#pragma once
#include "person.hpp"

class HeadOfDepartment : public Person {
protected:
    double salary;

public:
    HeadOfDepartment(const char* name, int birthYear, double salary);
    ~HeadOfDepartment() override;
    void show() const override;
};
