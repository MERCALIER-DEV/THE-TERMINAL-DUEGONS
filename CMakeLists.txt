cmake_minimum_required(VERSION 3.14)
project(THE_TERMINAL_DUEGONS CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Descargar FTXUI desde GitHub
include(FetchContent)
FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
    GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

# 2. Buscar TODOS los archivos .cpp en subcarpetas de niveles
file(GLOB_RECURSE FUENTES_NIVEL "niveles/*.cpp")

add_executable(THE_TERMINAL_DUEGONS
    src/Main.cpp
    ${FUENTES_NIVEL}
)

# 3. Detectar e incluir automáticamente TODAS las subcarpetas que tengan archivos .h
file(GLOB_RECURSE HEADER_FILES "niveles/*.h" "niveles/*.hpp")
file(GLOB_RECURSE FUENTES_SRC "src/*.cpp")

set(NIVELES_INCLUDE_DIRS "")
foreach(HEADER ${HEADER_FILES})
    get_filename_component(HEADER_DIR ${HEADER} DIRECTORY)
    list(APPEND NIVELES_INCLUDE_DIRS ${HEADER_DIR})
endforeach()

list(REMOVE_DUPLICATES NIVELES_INCLUDE_DIRS)

target_include_directories(THE_TERMINAL_DUEGONS PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/niveles
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${NIVELES_INCLUDE_DIRS}
)

# 4. Vincular las librerías de FTXUI
target_link_libraries(THE_TERMINAL_DUEGONS PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)