cmake_minimum_required(VERSION 3.1)
project(ranJamp)

#Añadir tantos subdirectorios como se necesiten
#En cada subdirectorio debe haber un fichero CMakeLists.txt
#Habitualmente cada subdirectorio determinará una libreria 


add_library(libClases STATIC)
add_subdirectory(Player)
add_subdirectory(Bullet)
add_subdirectory(Animacion)
add_subdirectory(enemigos)
add_subdirectory(Collider)
add_subdirectory(Plataforma)

#Opciones a pasar al compilador de C++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")
#Se desea generar un ejecutable, se especifica donde está el main
#y ficheros que aporten código que no sean librerias o subcarpetas 
add_executable(reptante enemRep.cpp)
add_executable(matar matarpersonaje.cpp)
add_executable(murcielago enemMurcielago.cpp)
add_executable(centinela enemCentil.cpp)
add_executable(ranJamp main.cpp)

add_executable(sonido sonido.cpp)
add_executable(mapa mapa.cpp tinyxml.cpp tinystr.cpp tinyxmlerror.cpp tinyxmlparser.cpp) 
add_executable(mapaObjeto mapaObjeto.cpp tinyxml.cpp tinystr.cpp tinyxmlerror.cpp tinyxmlparser.cpp) 
add_executable(Gravedad caer.cpp)
add_executable(Menu menu.cpp)

add_executable(Acciones acciones.cpp)


#Añadir todos los objetos (ficheros o) que requiera el ejecutable. 
#Habitualmente todas las librerias definidas mediante subcarpetas
#aportaran código
target_link_libraries(murcielago libClases)
target_link_libraries(centinela libClases)
target_link_libraries(ranJamp libClases)
target_link_libraries(Gravedad libClases)
    target_link_libraries(Menu libClases)

    target_link_libraries(Acciones libClases)
  

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#Para usar SFML
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(reptante ${SFML_LIBRARIES})
    target_link_libraries(matar ${SFML_LIBRARIES})
    target_link_libraries(murcielago ${SFML_LIBRARIES})
    target_link_libraries(centinela ${SFML_LIBRARIES})
    target_link_libraries(ranJamp ${SFML_LIBRARIES})
    target_link_libraries(sonido ${SFML_LIBRARIES})
    target_link_libraries(mapa ${SFML_LIBRARIES})
    target_link_libraries(mapaObjeto ${SFML_LIBRARIES})
    target_link_libraries(Gravedad ${SFML_LIBRARIES})
    target_link_libraries(Menu ${SFML_LIBRARIES})

    target_link_libraries(Acciones ${SFML_LIBRARIES})
   
endif()
