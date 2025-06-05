#include <iostream>
#include <string>

int main() {
    std::string name, secondname, surname;
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Введите отчество: ";
    std::cin >> secondname;
    std::cout << "Введите фамилию: ";
    std::cin >> surname;

    std::string initials;
    initials += name[0];
    initials += ". ";
    initials += secondname[0];
    initials += ". ";
    initials += surname[0];
    initials += ".";

    std::cout << "Инициалы: " << initials << std::endl;
    return 0;
}
