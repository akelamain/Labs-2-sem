#pragma once
#include "headofdepartment.hpp"

class Professor : public HeadOfDepartment{
protected:
    int workingDays;
    double salary;
public:
    Professor(const char* name, int birthYear, int workingDays, double salary);
    ~Professor() override;
    void show() const override;
};
