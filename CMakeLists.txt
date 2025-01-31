cmake_minimum_required(VERSION 3.30)
project(ProjetoEstruturaDados)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Personagens)

add_executable(ProjetoEstruturaDados
        src/models/Eleven.h
        src/models/Dustin.h
        src/models/Lucas.h
        src/models/Max.h
        src/models/Mike.h
        src/models/Personagem.h
        src/models/Will.h
        src/main.cpp
        src/controllers/IniciarJogo.cpp
        src/controllers/MenuInicial.cpp
        src/models/Personagem.cpp
        src/controllers/Rounds.cpp
        src/utils/conexao.cpp
        src/utils/conexao.h
)
