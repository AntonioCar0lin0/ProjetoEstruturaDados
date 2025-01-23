#ifndef INICIAR_JOGO_H
#define INICIAR_JOGO_H

#include <vector>
#include "../Personagens/Personagem.h"

//Classe responsável por iniciar o jogo
class IniciarJogo {
private:
    std::vector<Personagem*> personagensEscolhidos;
public:
    void exibirMenuIniciarJogo();
    void escolherPersonagens();
    void escolherItens();
    void iniciarAventura();
};

#endif // INICIAR_JOGO_H