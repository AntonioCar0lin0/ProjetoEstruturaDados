//
// Created by anton on 02/01/2025.
//

#ifndef DUSTIN_H
#define DUSTIN_H

#include "Personagem.h"
class Dustin : public Personagem {
    public:
    Dustin()
        : Personagem("Dustin", 100, 4, 9, 6, 10, 7 ){
        adicionarItem(Item("Walkie Talkie", "Carisma", 6));
        adicionarItem(Item("Taco de Beisebol", "Força", 6));
        }

};
#endif //DUSTIN_H
