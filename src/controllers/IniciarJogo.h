#ifndef INICIAR_JOGO_H
#define INICIAR_JOGO_H

#include <vector>
#include "../models/Personagem.h"

//Declaração da classe IniciarJogo, responsável por gerenciar o início da partida
class IniciarJogo {
private:
    std::vector<Personagem*> personagensEscolhidos; //Vetor que armazena os personagens selecionados pelo jogador
public:
    void exibirMenuIniciarJogo();
    void escolherPersonagens();
    void escolherItens();
    void iniciarAventura();
};

#endif // INICIAR_JOGO_H