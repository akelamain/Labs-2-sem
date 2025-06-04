#include <iostream>
#include "Executor.hpp"

void addElement(MyStack::MyStack<Person*>& people) {
    int type;
    std::cout << "Выберите должность:" << std::endl;
    std::cout << "1. Заведующий Кафедрой" << std::endl;
    std::cout << "2. Студент" << std::endl;
    std::cout << "3. Профессор" << std::endl;
    std::cin >> type;

    char name[100];
    int birthYear;
    std::cin.ignore();
    std::cout << "Введите имя: ";
    std::cin.getline(name, 100);
    std::cout << "Введите год рождения: ";
    std::cin >> birthYear;

    switch (static_cast<Type>(type)) {
        case Type::HeadOfDepartment: {
            double salary;
            std::cout << "Введите зарплату: ";
            std::cin >> salary;
            people.push(new HeadOfDepartment(name, birthYear, salary));
            break;
        }
        case Type::Student: {
            int workingDays;
            std::cout << "Введите количество рабочих дней: ";
            std::cin >> workingDays;
            int grade;
            std::cout << "Введите курс: ";
            std::cin >> grade;
            people.push(new Student(name, birthYear, workingDays, grade));
            break;
        }
        case Type::Professor: {
            int workingDays;
            std::cout << "Введите количество рабочих дней: ";
            std::cin >> workingDays;
            people.push(new Professor(name, birthYear, workingDays));
            break;
        }
        default:
            std::cout << "Неверный выбор типа! Элемент не добавлен." << std::endl;
    }
}

void demo(MyStack::MyStack<Person*>& people) {
    people.push(new HeadOfDepartment("Владимир Яковлев", 1956, 100000));
    people.push(new Student("Сильвестр Сталлоне", 1990, 10, 6));
    people.push(new Professor("Алексей Сушко", 1978, 3));

    print(people);

    std::cout << "Удаление первого элемента:" << std::endl;
    remove(people, 0);
    print(people);

    std::cout << "Очистка контейнера:" << std::endl;
    clear(people);
    print(people);
}

void menu() {
    MyStack::MyStack<Person*> people;
    int choice = 0;

    std::cout << "======================================================" << std::endl;

    while (true) {
        std::cout << "1. Добавить элемент в контейнер\n"
                  << "2. Печать содержимого контейнера\n"
                  << "3. Удалить элемент по индексу\n"
                  << "4. Очистить контейнер\n"
                  << "5. Инициализация демо\n"
                  << "6. Выход\n"
                  << "Выберите задание: ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (static_cast<Task>(choice)) {
            case Task::Add:
                addElement(people);
                break;
            case Task::Print:
                print(people);
                break;
            case Task::Delete: {
                int index;
                std::cout << "Введите индекс элемента для удаления: ";
                std::cin >> index;
                remove(people, index);
                break;
            }
            case Task::Clear:
                clear(people);
                break;
            case Task::Initialize:
                demo(people);
                return;
            case Task::Exit:
                return;
            default:
                std::cout << "Неверный номер задания" << std::endl;
        }
    }
}
