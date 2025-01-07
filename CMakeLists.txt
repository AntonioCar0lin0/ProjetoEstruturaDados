cmake_minimum_required(VERSION 3.30)
project(ProjetoEstruturaDados)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Personagens)

add_executable(ProjetoEstruturaDados
    scr/Personagens/Demobat.h
    scr/Personagens/Demodog.h
    scr/Personagens/Demogorgon.h
    scr/Personagens/DevoradorDeMentes.h
    scr/Personagens/Eleven.h
    scr/Personagens/Justin.h
    scr/Personagens/Lucas.h
    scr/Personagens/Max.h
    scr/Personagens/Mike.h
    scr/Personagens/Personagem.h
    scr/Personagens/Vecna.h
    scr/Personagens/Will.h
    src/main.cpp
    src/main.h
    src/controllers/IniciarJogo.cpp)
