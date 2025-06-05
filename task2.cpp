#include <iostream>
#include <string>

int main() {
    std::string text;
    std::cout << "Введите текст (латиница, содержащая 'a'): ";
    std::getline(std::cin, text);

    size_t firstA = text.find('a');
    if (firstA == std::string::npos) {
        std::cout << "Буква 'a' не найдена." << std::endl;
        return 0;
    }

    size_t secondA = text.find('a', firstA + 1);
    std::cout << "Результат: ";
    if (secondA != std::string::npos) {
        for (size_t i = firstA + 1; i < secondA; ++i)
            std::cout << text[i];
    } else {
        for (size_t i = firstA + 1; i < text.length(); ++i)
            std::cout << text[i];
    }
    std::cout << std::endl;
    return 0;
}
