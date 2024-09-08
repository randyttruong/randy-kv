cmake_minimum_required(VERSION 3.28)
project(randy_kv)
set(CMAKE_OSX_ARCHITECTURES "arm64")

message ("Hello")
set(CMAKE_CXX_STANDARD 17)
set(Boost_INCLUDE_DIR /opt/homebrew/include)
#set(Boost_LIBRARY_DIR /opt/homebrew/lib)

# find_package(Boost CONFIG)
#find_package(Boost CONFIG)
find_package(Boost 1.70 REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    message(STATUS "Project Source Directory: ${PROJECT_SOURCE_DIR}")
    message(STATUS "Project Boost Directory: ${Boost_LIBRARY_DIR}")

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
            src/executor.cpp
            src/executor.h
            src/cli.cpp
            src/cli.h
            src/repl.cpp
            src/repl.h
            src/replcommands.cpp
            src/replcommands.h
            src/clicommands.cpp
            src/clicommands.h

    )

    target_include_directories(randy_kv PRIVATE ${PROJECT_SOURCE_DIR}/include)
    target_link_libraries(randy_kv PRIVATE ${PROJECT_SOURCE_DIR}/lib/libalgo_suite.a)

    target_include_directories(randy_kv PRIVATE ${Boost_INCLUDE_DIR})
    target_link_libraries(randy_kv PRIVATE ${Boost_LIBRARIES})
    message(STATUS "Boost Include Dir: ${Boost_LIBRARIES}")
else()
    message(FATAL_ERROR "Boost not found!")
endif()

