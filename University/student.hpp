#pragma once
#include "professor.hpp"

class Student : public Professor {
protected:
    int grade;
    int workingDays;

public:
    Student(const char* name, int birthYear, int workingDays, int grade);
    ~Student() override;
    void show() const override;
};
