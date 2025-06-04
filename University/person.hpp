#pragma once

#include <cstring>
#include <iostream>

class Person {
 protected:
    char* name;
    int birthYear;

 public:
    Person(const char* name, int year);
    virtual ~Person();

    virtual void show() const = 0;
};
