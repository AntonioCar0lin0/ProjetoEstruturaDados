#ifndef WILL_H
#define WILL_H

#include "Personagem.h"

//Classe que representa o personagem Will no jogo e seus atributos
class Will : public Personagem {
public:
    Will()
        : Personagem(L"Will", 100, 2, 8, 6, 7, 10) {
        adicionarItem(Item(L"Cordão de Luzes", L"Carisma", 6));
    }
};

#endif //WILL_H