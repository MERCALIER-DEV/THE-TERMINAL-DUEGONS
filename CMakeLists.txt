cmake_minimum_required(VERSION 3.14)
project(THE_TERMINAL_DUEGONS CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Descargar FTXUI desde GitHub
include(FetchContent)
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

# 2. Registrar Main y los archivos de cada zona con el nuevo nombre del ejecutable
add_executable(THE_TERMINAL_DUEGONS 
    Main.cpp
    
)
 
# 3. Incluir las cabeceras de FTXUI
target_include_directories(THE_TERMINAL_DUEGONS PRIVATE ${ftxui_SOURCE_DIR}/include)

# 4. Vincular las librerías de FTXUI
target_link_libraries(THE_TERMINAL_DUEGONS
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
)