#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libEnemigos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/mimodulo.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/mimodulo2.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/centinela.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/murcielago.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/centinela.cpp"
)

#Y donde se encuentran los .h
target_include_directories(libEnemigos PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}"
)

