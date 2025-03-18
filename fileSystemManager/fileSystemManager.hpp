#pragma once
#include <cstddef>
#include <iostream>

namespace FileSystemManager {
class Directory {
private:
  char *name;
  char *path;
  int fileCount;

public:
  Directory(const char *n = "\0", const char *p = "\0", int fc = 0);
  Directory(const Directory &other);

  ~Directory();

  void SetName(const char *n);
  void SetPath(const char *p);
  void SetFileCount(int fc);

  const char *GetName() const;
  const char *GetPath() const;
  int GetFileCount() const;

  Directory &operator=(const Directory &other);
  friend std::ostream &operator<<(std::ostream &os, const Directory &directory);
  friend std::istream &operator>>(std::istream &is, Directory &directory);
  bool operator==(const char *n);
  bool operator<(const Directory &dir2);
  bool operator<(const char *n);

  static void Resize(Directory *&directories, int &size);
  static void DeleteDB(Directory *&directories);

  static void ReadDB(Directory *&directories, int &size);
  static void WriteDB(Directory *&directories, int size);
  static void SortDB(Directory *&directories, int left, int right);
  static void AddElement(Directory *&directories, int &size);
  static void DeleteElement(Directory *&directories, int &size);
  static void EditDB(Directory *&directories, int size);
  static void PrintDB(Directory *&directories, int size);
};
} // namespace FileSystemManager
