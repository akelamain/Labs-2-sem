#pragma once
#include <cstddef>

namespace Executor {
enum class Tasks {
    Read = 1,
    Write = 2,
    Sort = 3,
    Add = 4,
    Delete = 5,
    Edit = 6,
    Print = 7,
    Exit = 0,
};

enum class AppTasks {
    Planets = 1,
    FileManager = 2,
    Exit = 0,
};

void ExecutePlanetsApp();
void ExecuteFileManagerApp();
void ExecuteApp();
}  // namespace Executor
