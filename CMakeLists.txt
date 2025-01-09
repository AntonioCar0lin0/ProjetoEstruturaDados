cmake_minimum_required(VERSION 3.30)
project(ProjetoEstruturaDados)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Personagens)

add_executable(ProjetoEstruturaDados
    src/Personagens/Demobat.h
    src/Personagens/Demodog.h
    src/Personagens/Demogorgon.h
    src/Personagens/DevoradorDeMentes.h
    src/Personagens/Eleven.h
    src/Personagens/Justin.h
    src/Personagens/Lucas.h
    src/Personagens/Max.h
    src/Personagens/Mike.h
    src/Personagens/Personagem.h
    src/Personagens/Vecna.h
    src/Personagens/Will.h
    src/main.cpp
    src/main.h
    src/controllers/IniciarJogo.cpp
    src/controllers/MenuInicial.cpp)
