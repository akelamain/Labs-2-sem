#include "fileSystemManager.hpp"
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

namespace {
const int kBuffSize = 100;
int BinarySearch(FileSystemManager::Directory *directories, int size,
                 const char *target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (directories[mid] == target) {
      return mid;
    } else if (directories[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}
} // namespace

namespace FileSystemManager {
Directory::Directory(const char *n, const char *p, int fc) {
  name = new char[strlen(n) + 1];
  strcpy(name, n);

  path = new char[strlen(p) + 1];
  strcpy(path, p);

  fileCount = fc;
}

Directory::Directory(const Directory &other) {
  name = new char[strlen(other.name) + 1];
  strcpy(name, other.name);

  path = new char[strlen(other.path) + 1];
  strcpy(path, other.path);

  fileCount = other.fileCount;
}

Directory::~Directory() {
  delete[] name;
  delete[] path;
}

void Directory::SetName(const char *n) {
  if (name) {
    delete[] name;
  }
  name = new char[strlen(n) + 1];
  strcpy(name, n);
}

void Directory::SetPath(const char *p) {
  if (path) {
    delete[] path;
  }
  path = new char[strlen(p) + 1];
  strcpy(path, p);
}

void Directory::SetFileCount(int fc) { fileCount = fc; }

const char *Directory::GetName() const { return name; }

const char *Directory::GetPath() const { return path; }

int Directory::GetFileCount() const { return fileCount; }

Directory &Directory::operator=(const Directory &other) {
  if (this == &other)
    return *this;

  delete[] name;
  delete[] path;

  name = new char[strlen(other.name) + 1];
  strcpy(name, other.name);

  path = new char[strlen(other.path) + 1];
  strcpy(path, other.path);

  fileCount = other.fileCount;

  return *this;
}

std::ostream &operator<<(std::ostream &os, const Directory &directory) {
  os << std::setw(0) << directory.name << std::setw(30) << directory.path
     << std::setw(20) << directory.fileCount << std::endl;
  return os;
}

std::istream &operator>>(std::istream &is, Directory &directory) {
  is >> directory.name >> directory.path >> directory.fileCount;
  return is;
}

bool Directory::operator==(const char *n) { return strcmp(this->name, n) == 0; }

bool Directory::operator<(const Directory &dir2) {
  return strcmp(this->name, dir2.name) < 0;
}

bool Directory::operator<(const char *n) { return strcmp(this->name, n) < 0; }

void Directory::Resize(Directory *&directories, int &size) {
  Directory *newDirectories = new Directory[size + 1];
  for (int i = 0; i < size; ++i) {
    newDirectories[i] = directories[i];
  }
  DeleteDB(directories);
  directories = newDirectories;
  ++size;
}

void Directory::DeleteDB(Directory *&directories) {
  if (!directories) {
    return;
  }
  delete[] directories;
  directories = nullptr;
}

void Directory::ReadDB(Directory*& directories, int& size) {
  std::ifstream file("Directories.txt");
  if (!file) {
    std::cout << "Ошибка открытия файла!" << std::endl;
    return;
  }

  DeleteDB(directories);
  size = 0;

  Directory temp;

  while (file >> temp) {
    if (size == 1 && directories[0] == "\0") {
      directories[0] = temp;
    } else {
      Resize(directories, size);
      directories[size - 1] = temp;
    }
  }
  file.close();
}

void Directory::WriteDB(Directory *&directories, int size) {
  if (!directories) {
    return;
  }
`
  std::ofstream file("Directories.txt");
  if (!file) {
    std::cout << "Ошибка открытия файла!" << std::endl;
    return;
  }

  for (int i = 0; i < size; ++i) {
    file << directories[i];
  }

  file.close();
}

void Directory::SortDB(Directory *&directories, int left, int right) {
  if (!directories || left >= right) {
    return;
  }

  Directory pivot = directories[right];
  int partitionIndex = left;

  for (int i = left; i < right; ++i) {
    if (directories[i] < pivot) {
      std::swap(directories[i], directories[partitionIndex]);
      ++partitionIndex;
    }
  }
  std::swap(directories[right], directories[partitionIndex]);

  SortDB(directories, left, partitionIndex - 1);
  SortDB(directories, partitionIndex + 1, right);
}

void Directory::AddElement(Directory *&directories, int &size) {
  Resize(directories, size);
  std::cout << "Введите имя каталога, путь и количество файлов: ";
  std::cin >> directories[size - 1];
  std::cout << std::endl;
}

void Directory::DeleteElement(Directory *&directories, int &size) {
  if (!directories) {
    return;
  }

  char n[kBuffSize]{};
  std::cout << "Введите имя каталога для удаления: ";
  std::cin >> n;
  std::cout << std::endl;

  int point = BinarySearch(directories, size, n);
  if (point == -1) {
    std::cout << "Каталог не найден." << std::endl;
    return;
  }

  for (int i = point; i < size - 1; ++i) {
    directories[i] = directories[i + 1];
  }
  --size;
}

void Directory::EditDB(Directory *&directories, int size) {
  if (!directories) {
    return;
  }

  char nameToEdit[kBuffSize]{};
  std::cout << "Введите имя каталога, который хотите изменить: ";
  std::cin >> nameToEdit;
  std::cout << std::endl;

  SortDB(directories, 0, size - 1);

  int point = BinarySearch(directories, size, nameToEdit);

  if (point == -1) {
    std::cout << "Каталог не найден." << std::endl;
    return;
  }

  std::cout << "Введите измененные имя каталога, путь, количество файлов: ";
  std::cin >> directories[point];
  std::cout << std::endl;
}

void Directory::PrintDB(Directory *&directories, int size) {
  if (!directories) {
    return;
  }

  std::cout << "Список каталогов в системе:\n";
  std::cout << "Имя каталога" << std::setw(15) << "Путь" << std::setw(60)
            << "Количество файлов" << '\n';
  for (int i = 0; i < size; ++i) {
    std::cout << directories[i];
  }
  std::cout << "------------------------------------------------\n";
}
} // namespace FileSystemManager
