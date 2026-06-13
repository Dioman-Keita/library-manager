cmake_minimum_required(VERSION 3.10)

project(LibraryManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(library_app
    src/main.cpp
    src/models/Book.cpp
    src/models/User.cpp
    src/services/Library.cpp
    src/services/BookManager.cpp
    src/services/UserManager.cpp
    src/services/LoanManager.cpp
    src/utils/Backup.cpp
    src/utils/IdGenerator.cpp
)

target_include_directories(library_app PRIVATE src)

set(DATA_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/data")
set(DATA_RUNTIME_DIR "$<TARGET_FILE_DIR:library_app>/data")

add_custom_command(TARGET library_app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${DATA_SOURCE_DIR}"
            "${DATA_RUNTIME_DIR}"
)
