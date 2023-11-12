cmake_minimum_required(VERSION 3.5)

project(InformationSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(InformationSystem main.cpp person.cpp employee.cpp person.h employee.h)

install(TARGETS InformationSystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
