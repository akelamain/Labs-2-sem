#pragma once
#include "person.hpp"

class Professor : public Person {
protected:
    int workingDays;

public:
    Professor(const char* name, int birthYear, int workingDays);
    ~Professor() override;
    void show() const override;
};
