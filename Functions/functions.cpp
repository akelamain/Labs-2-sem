#include "functions.hpp"

void print(MyStack::MyStack<Person*>& container) {
    if (container.empty()) {
        std::cout << "Стек пустой." << std::endl;
        return;
    }

    MyStack::MyStack<Person*> tempStack;
    std::cout << "Содержимое стека:" << std::endl;
    int i{};
    while (!container.empty()) {
        Person* org = container.top_inf();
        std::cout << i++ << ". ";
        org->show();
        tempStack.push(org);
        container.pop();
    }

    while (!tempStack.empty()) {
        container.push(tempStack.top_inf());
        tempStack.pop();
    }

    std::cout << std::endl;
}

bool remove(MyStack::MyStack<Person*>& container, int index) {
    if (container.empty()) {
        return false;
    }

    MyStack::MyStack<Person*> tempStack;
    int currentIndex = 0;

    while (!container.empty()) {
        if (currentIndex == index) {
            Person* org = container.top_inf();
            delete org;
            container.pop();
            ++currentIndex;
            continue;
        }

        Person* org = container.top_inf();
        tempStack.push(org);
        container.pop();
        ++currentIndex;
    }

    while (!tempStack.empty()) {
        container.push(tempStack.top_inf());
        tempStack.pop();
    }

    return true;
}

void clear(MyStack::MyStack<Person*>& container) {
    while (!container.empty()) {
        Person* org = container.top_inf();
        delete org;
        container.pop();
    }
}
