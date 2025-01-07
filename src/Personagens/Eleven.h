//
// Created by anton on 02/01/2025.
//

#ifndef ELEVEN_H
#define ELEVEN_H

#include "Personagem.h"

class Eleven : public Personagem {
public:
    Eleven()
        : Personagem("Eleven", 100, 10, 7, 10, 6, 9) {
        adicionarItem(Item("Telecinese", "Instinto", 6));
        adicionarItem(Item("Máscara de Privação Sensorial", "Reflexo", 6));
    }
};

#endif //ELEVEN_H
