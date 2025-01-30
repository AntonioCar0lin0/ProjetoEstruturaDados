cmake_minimum_required(VERSION 3.30)
project(ProjetoEstruturaDados)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Personagens)

add_executable(ProjetoEstruturaDados
        src/Personagens/Eleven.h
        src/Personagens/Dustin.h
    src/Personagens/Lucas.h
    src/Personagens/Max.h
    src/Personagens/Mike.h
    src/Personagens/Personagem.h
        src/Personagens/Will.h
    src/main.cpp
        src/controllers/IniciarJogo.cpp
    src/controllers/MenuInicial.cpp
    src/Personagens/Personagem.cpp
    src/controllers/Rounds.cpp
)
