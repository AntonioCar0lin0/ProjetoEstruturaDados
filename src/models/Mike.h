#ifndef MIKE_H
#define MIKE_H

#include "Personagem.h"

class Mike : public Personagem {
public:
    Mike()
        : Personagem(L"Mike", 100, 3, 10, 8, 8, 7) {
        adicionarItem(Item(L"Lanterna", L"Reflexo", 6));
    }
};

#endif //MIKE_H