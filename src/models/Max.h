#ifndef MAX_H
#define MAX_H

#include "Personagem.h"

//Classe que representa a personagem Max no jogo e seus atributos
class Max : public Personagem {
    public:
    Max()
        : Personagem(L"Max", 100, 4, 9, 8, 7, 8 ) {
        adicionarItem(Item(L"Skate", L"Reflexo", 6));
    }
};
#endif //MAX_H
