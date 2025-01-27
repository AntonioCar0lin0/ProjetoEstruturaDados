#include "controllers/IniciarJogo.h"
#include "controllers/MenuInicial.h"
#include <iostream>

//main teste
int main() {
    std::wcout.imbue(std::locale(""));
    MenuInicial menuInicial;
    menuInicial.exibirMenuInicial();

    return 0;
}
