cmake_minimum_required(VERSION 3.30)
project(ProjetoEstruturaDados)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Personagens)

add_executable(ProjetoEstruturaDados
    Personagens/Demobat.h
    Personagens/Demodog.h
    Personagens/Demogorgon.h
    Personagens/DevoradorDeMentes.h
    Personagens/Eleven.h
    Personagens/Justin.h
    Personagens/Lucas.h
    Personagens/Max.h
    Personagens/Mike.h
    Personagens/Personagem.h
    Personagens/Vecna.h
    Personagens/Will.h
    main.cpp
    main.h)
