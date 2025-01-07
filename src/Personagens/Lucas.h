//
// Created by anton on 02/01/2025.
//

#ifndef LUCAS_H
#define LUCAS_H

#include "Personagem.h"
class Lucas : public Personagem {
    public:
    Lucas()
        : Personagem("Lucas", 100, 7, 8, 8, 7 , 9) {
        adicionarItem(Item("Fogos de Artifício", "Força", 6));
        adicionarItem(Item("Estilingue", "Reflexo", 6));
    }
};
#endif //LUCAS_H
