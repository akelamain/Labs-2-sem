
#pragma once

#include "../University/person.hpp"
#include "../MyStack/MyStack.hpp"

void print(MyStack::MyStack<Person*>& container);
bool remove(MyStack::MyStack<Person*>& container, int index);
void clear(MyStack::MyStack<Person*>& container);
