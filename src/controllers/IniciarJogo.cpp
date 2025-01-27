// IniciarJogo.cpp
#include "IniciarJogo.h"
#include "MenuInicial.h"
#include "Rounds.h"
#include "src/Conexao/GerenciadorDePersonagens.h"
#include "src/Personagens/Personagem.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include "src/Personagens/Eleven.h"
#include "src/Personagens/Justin.h"
#include "src/Personagens/Lucas.h"
#include "src/Personagens/Max.h"
#include "src/Personagens/Mike.h"
#include "src/Personagens/Will.h"

void IniciarJogo::exibirMenuIniciarJogo() {
    GerenciadorDePersonagens gerenciador;
    int escolha;
    do {
        std::wcout << L"\n**** Menu Iniciar Jogo ****\n";
        std::wcout << L"1. Escolher Personagens\n";
        std::wcout << L"2. Escolher Itens\n";
        std::wcout << L"3. Iniciar Aventura\n";
        std::wcout << L"4. Voltar ao Menu\n";
        std::wcout << L">> Escolha: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                escolherPersonagens(gerenciador);
                break;
            case 2:
                escolherItens(gerenciador);
                break;
            case 3:
                iniciarAventura(gerenciador);
                break;
            case 4:
                return;
            default:
                std::wcout << L"Opção inválida!\n";
        }
    } while (escolha != 4);
}

void IniciarJogo::escolherPersonagens(GerenciadorDePersonagens& gerenciador) {
    std::vector<Personagem*> personagensDisponiveis = {
        new Eleven(), new Mike(), new Will(), new Justin(), new Lucas(), new Max()
    };
    std::vector<Personagem*> personagensEscolhidos;


    int escolha;
    do {
        std::wcout << L"\nEscolha seus personagens (máximo 3):\n";
        for (size_t i = 0; i < personagensDisponiveis.size(); ++i) {
            std::wcout << i + 1 << L". ";
            personagensDisponiveis[i]->mostrarCaracteristicas();
        }
        std::wcout << personagensDisponiveis.size() + 1 << L". Finalizar Escolha\n";
        std::wcout << L">> Escolha: ";
        std::cin >> escolha;

        if (escolha >= 1 && escolha <= static_cast<int>(personagensDisponiveis.size())) {
            personagensEscolhidos.push_back(personagensDisponiveis[escolha - 1]);
        } else if (escolha == static_cast<int>(personagensDisponiveis.size()) + 1) {
            if (!personagensEscolhidos.empty()) {
                gerenciador.salvarPersonagens(personagensEscolhidos);
                std::wcout << L"Personagens salvos com sucesso!\n";
                break;
            } else {
                std::wcout << L"Escolha pelo menos um personagem!\n";
            }
        } else {
            std::wcout << L"Opção inválida!\n";
        }
    } while (personagensEscolhidos.size() < 3);
}

void IniciarJogo::escolherItens(GerenciadorDePersonagens& gerenciador) {
    auto personagensEscolhidos = gerenciador.carregarPersonagens();
    if (personagensEscolhidos.empty()) {
        std::wcout << L"Você precisa escolher personagens antes de selecionar itens!\n";
        return;
    }

    for (auto& personagem : personagensEscolhidos) {
        std::wcout << L"\nEscolha itens para " << personagem->get_nome() << L":\n";
        // Simulação de itens...
    }
}

void IniciarJogo::iniciarAventura(const GerenciadorDePersonagens &gerenciador) {
    auto personagens = gerenciador.carregarPersonagens();
    if (personagens.empty()) {
        std::wcout << L"Nenhum personagem carregado. Escolha antes de iniciar!\n";
        return;
    }

    Round round1(L"Primeiro desafio", {L"Desafio 1"}, {L"Força"});
    round1.iniciar(personagens);

    gerenciador.salvarPersonagens(personagens);
}
