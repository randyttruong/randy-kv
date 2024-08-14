cmake_minimum_required(VERSION 3.28)
project(randy_kv)

set(CMAKE_CXX_STANDARD 17)
message(STATUS "Project Source Directory: ${PROJECT_SOURCE_DIR}")


add_executable(randy_kv src/main.cpp
        src/tokenizer.cpp
        src/tokenizer.h
        src/parser.cpp
        src/parser.h
        src/string_t.cpp
        src/string_t.h
        src/ast.cpp
        src/ast.h
        src/node.cpp
        src/node.h
        src/analyzer.cpp
        src/analyzer.h
        src/debug.cpp
        src/debug.h
        src/symboltable.cpp
        src/symboltable.h
        src/fileparser.cpp
        src/fileparser.h
        src/hashmap.cpp
        src/hashmap.h
)

target_include_directories(randy_kv PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(randy_kv PRIVATE ${PROJECT_SOURCE_DIR}/lib/libalgo_suite.a)

