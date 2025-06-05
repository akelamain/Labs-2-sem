#pragma once
#include "person.hpp"

class Student : public Person {
protected:
    int grade;

public:
    Student(const char* name, int birthYear, int grade);
    ~Student() override;
    void show() const override;
};
