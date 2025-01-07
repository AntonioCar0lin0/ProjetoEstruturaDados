//
// Created by anton on 02/01/2025.
//

#ifndef WILL_H
#define WILL_H

#include "Personagem.h"

class Will : public Personagem {
public:
    Will()
        : Personagem("Will", 100, 2, 8, 6, 7, 10) {
        adicionarItem(Item("Desenhos", "Instinto", 6));
        adicionarItem(Item("Cordão de Luzes", "Carisma", 6));
    }
};

#endif //WILL_H