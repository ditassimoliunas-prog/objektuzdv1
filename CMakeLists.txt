cmake_minimum_required(VERSION 3.10)

# Projekto pavadinimas
project(ObjektinisUzdavinys)

# Nustatome C++ versiją
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Svarbu MSVC kompiliatoriui – priverčiame CMak'o Release režimą VISIŠKAI ignoruoti savo defaultinius nustatymus.
# Taip apsaugome mygtuko /O2 perrašymą.
set(CMAKE_CXX_FLAGS_RELEASE "") 

# Jei skripte perduosime OPT_LEVEL (pvz per terminalą), tada į jį bus atsižvelgta.
# Pagal nutylėjimą - be optimizacijų arba dedame O1.
if(MSVC)
    if(DEFINED OPT_LEVEL)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /${OPT_LEVEL}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /O2")
    endif()
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3")
endif()

# Nurodome kur ieškoti header failų (.h)
include_directories(header_files)

# Visi išeitiniai (source) .cpp failai išskyrus patį main
set(SOURCES 
    objekt1uzd.cpp 
    extra_cpp/duomenu_valdymas.cpp 
    extra_cpp/input.cpp 
    extra_cpp/mat_funkcijos.cpp 
    extra_cpp/menu.cpp 
    extra_cpp/output.cpp 
    extra_cpp/testavimas.cpp
)

# Sukuriame ezkekutuojamąjį (executable) failą
add_executable(programa ${SOURCES})
