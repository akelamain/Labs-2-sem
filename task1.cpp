#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string word1;
    std::string word2;

    std::cout << "Введите первое слово: ";
    std::cin >> word1;

    std::cout << "Введите второе слово: ";
    std::cin >> word2;


    if (word1.length() < 3) {
        std::cout << "Первое слово слишком короткое. Невозможно определить третью букву." << std::endl;
        return 1;
    }


    char thirdChar = word1[2];


    int count = std::count(word2.begin(), word2.end(), thirdChar);

    std::cout << "Третья буква первого слова ('" << thirdChar << "') встречается во втором слове " << count << " раз(а)." << std::endl;

    return 0; 
}
