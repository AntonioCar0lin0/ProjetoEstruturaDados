#ifndef INICIAR_JOGO_H
#define INICIAR_JOGO_H

#include <vector>
#include <src/Conexao/GerenciadorDePersonagens.h>

#include "../Personagens/Personagem.h"

//Classe responsável por iniciar o jogo
class IniciarJogo {
private:
    std::vector<Personagem*> personagensEscolhidos;
public:
    void escolherPersonagens(GerenciadorDePersonagens &gerenciador);

    void escolherItens(GerenciadorDePersonagens &gerenciador);

    void iniciarAventura(const GerenciadorDePersonagens &gerenciador);

    void exibirMenuIniciarJogo();
};

#endif // INICIAR_JOGO_H