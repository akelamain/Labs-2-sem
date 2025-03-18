#include "Executor.hpp"
#include "fileSystemManager/fileSystemManager.hpp"
#include "planets/planets.hpp"
#include <iostream>

namespace {
const int kBuffSize = 100;
}

namespace Executor {
void ExecutePlanetsApp() {
  int task{};

  int size = 1;
  Planets::Planet *planets = new Planets::Planet[size]();

  while (true) {
    std::cout << "Выберите номер, интересующего вас задания, и введите его в "
                 "консоль для перехода\n";
    std::cout << "1. Чтение БД из файла\n";
    std::cout << "2. Запись БД в файл\n";
    std::cout << "3. Сортировка БД\n";
    std::cout << "4. Добавление нового объекта в БД\n";
    std::cout << "5. Удаление объекта из БД\n";
    std::cout << "6. Редактирование БД\n";
    std::cout << "7. Вывод БД на экран\n";
    std::cout << "0. Выход\n";
    std::cin >> task;
    std::cout << std::endl;

    switch (static_cast<Tasks>(task)) {
    case Tasks::Read: {
      Planets::Planet::ReadDB(planets, size);
      break;
    }
    case Tasks::Write: {
      Planets::Planet::WriteDB(planets, size);
      break;
    }
    case Tasks::Sort: {
      Planets::Planet::SortDB(planets, 0, size - 1);
      break;
    }
    case Tasks::Add: {
      Planets::Planet::AddElement(planets, size);
      break;
    }
    case Tasks::Delete: {
      Planets::Planet::DeleteElement(planets, size);
      break;
    }
    case Tasks::Edit: {
      Planets::Planet::EditDB(planets, size);
      break;
    }
    case Tasks::Print: {
      Planets::Planet::PrintDB(planets, size);
      break;
    }
    case Tasks::Exit: {
      Planets::Planet::DeleteDB(planets);
      return;
    }
    default: {
      std::cout << "Введен неверный номер задачи." << std::endl;
      break;
    }
    }
  }
}
void ExecuteFileManagerApp() {
  int task{};

  int size = 1;
  FileSystemManager::Directory *FileSystemManager =
      new FileSystemManager::Directory[size]();

  while (true) {
    std::cout << "Выберите номер, интересующего вас задания, и введите его в "
                 "консоль для перехода\n";
    std::cout << "1. Чтение БД из файла\n";
    std::cout << "2. Запись БД в файл\n";
    std::cout << "3. Сортировка БД\n";
    std::cout << "4. Добавление нового объекта в БД\n";
    std::cout << "5. Удаление объекта из БД\n";
    std::cout << "6. Редактирование БД\n";
    std::cout << "7. Вывод БД на экран\n";
    std::cout << "0. Выход\n";
    std::cin >> task;
    std::cout << std::endl;

    switch (static_cast<Tasks>(task)) {
    case Tasks::Read: {
      FileSystemManager::Directory::ReadDB(FileSystemManager, size);
      break;
    }
    case Tasks::Write: {
      FileSystemManager::Directory::WriteDB(FileSystemManager, size);
      break;
    }
    case Tasks::Sort: {
      FileSystemManager::Directory::SortDB(FileSystemManager, 0, size - 1);
      break;
    }
    case Tasks::Add: {
      FileSystemManager::Directory::AddElement(FileSystemManager, size);
      break;
    }
    case Tasks::Delete: {
      FileSystemManager::Directory::DeleteElement(FileSystemManager, size);
      break;
    }
    case Tasks::Edit: {
      FileSystemManager::Directory::EditDB(FileSystemManager, size);
      break;
    }
    case Tasks::Print: {
    FileSystemManager::Directory::PrintDB(FileSystemManager, size);
      break;
    }
    case Tasks::Exit: {
      FileSystemManager::Directory::DeleteDB(FileSystemManager);
      return;
    }
    default: {
      std::cout << "Введен неверный номер задачи." << std::endl;
      break;
    }
    }
  }
}

void ExecuteApp() {
  int task{};
  while (true) {
    std::cout << "Выберите режим работы: с планетами (1), управление каталогом "
                 "в файловой системе (2), выход (0): ";
    std::cin >> task;
    std::cout << std::endl;
    switch (static_cast<AppTasks>(task)) {
    case AppTasks::Planets:
      ExecutePlanetsApp();
      break;
    case AppTasks::FileManager:
      ExecuteFileManagerApp();
      break;
    case AppTasks::Exit:
      return;
    default:
      std::cout << "Введен неверный номер режима работы." << std::endl;
      break;
    }
  }
}
} // namespace Executor
