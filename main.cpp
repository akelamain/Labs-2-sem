#include <iostream>
#include "mymath/mymath.h"
#include "mymath2/mymath2.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 10+41=";
    std::cout << mymath::sum(10, 41) << std::endl;

    std::cout << "Я умею умножать! Зацени 10*10=";
    std::cout << mymath2::multiply(10, 10) << std::endl;
    return 0;
}
