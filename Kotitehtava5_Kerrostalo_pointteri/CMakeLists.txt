cmake_minimum_required(VERSION 3.5)

project(Kotitehtava4_Kerrostalo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Kotitehtava4_Kerrostalo
    asunto.h
    asunto.cpp






)

include(GNUInstallDirs)
install(TARGETS Kotitehtava4_Kerrostalo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
