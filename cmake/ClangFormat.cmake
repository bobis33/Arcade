find_program(CLANG_TIDY_EXE NAMES "clang-tidy" REQUIRED)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*;-header-filter=.*;-format-style=llvm;-warnings-as-errors=*")
set(CMAKE_C_CLANG_TIDY ${CMAKE_CXX_CLANG_TIDY})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CLANG_TIDY_EXECUTABLE ${CMAKE_SOURCE_DIR}/.clang-tidy)
list(APPEND CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_OPTIONS}")
list(APPEND CMAKE_C_CLANG_TIDY "${CLANG_TIDY_OPTIONS}")

## else
##     message(WARNING "clang-tidy not found")
