#ifndef DUSTIN_H
#define DUSTIN_H

#include "Personagem.h"

//Classe que representa o personagem Dustin no jogo e seus atributos
class Dustin : public Personagem {
    public:
    Dustin()
        : Personagem(L"Dustin", 100, 4, 9, 6, 10, 7 ){
        adicionarItem(Item(L"Taco de Beisebol", L"Força", 6));
        }
};
#endif //DUSTIN_H
