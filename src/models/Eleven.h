#ifndef ELEVEN_H
#define ELEVEN_H

#include "Personagem.h"

//Classe que representa a personagem Eleven no jogo e seus atributos
class Eleven : public Personagem {
public:
    Eleven()
        : Personagem(L"Eleven", 100, 10, 7, 10, 6, 9) {
        adicionarItem(Item(L"Telecinese", L"Instinto", 6));
    }
};

#endif //ELEVEN_H
