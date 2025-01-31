#ifndef LUCAS_H
#define LUCAS_H

#include "Personagem.h"

//Classe que representa o personagem Lucas no jogo e seus atributos
class Lucas : public Personagem {
    public:
    Lucas()
        : Personagem(L"Lucas", 100, 7, 8, 8, 7 , 9) {
        adicionarItem(Item(L"Fogos de Artifício", L"Força", 6));
    }
};
#endif //LUCAS_H
