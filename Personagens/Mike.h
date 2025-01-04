//
// Created by anton on 02/01/2025.
//

#ifndef MIKE_H
#define MIKE_H

#include "Personagem.h"

class Mike : public Personagem {
public:
    Mike()
        : Personagem("Mike", 100, 3, 10, 8, 8, 7) {
    }
};

#endif //MIKE_H