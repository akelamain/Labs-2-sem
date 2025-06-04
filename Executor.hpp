#pragma once
#include "Functions/functions.hpp"
#include "MyStack/MyStack.hpp"
#include "University/professor.hpp"
#include "University/person.hpp"
#include "University/student.hpp"
#include "University/headofdepartment.hpp"

enum class Task {
    Add = 1,
    Print = 2,
    Delete = 3,
    Clear = 4,
    Initialize = 5,
    Exit = 6
};

enum class Type {
    HeadOfDepartment = 1,
    Student = 2,
    Professor = 3
};

void menu();
