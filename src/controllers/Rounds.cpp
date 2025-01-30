#include "Rounds.h"
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <cstdlib>
#include "../models/Personagem.h"

void Round::iniciar(std::vector<Personagem*>& personagens) {
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");

    std::wcout << L"\n=====" << descricao << L"=====\n" << std::endl;

    for (size_t i = 0; i < desafios.size(); ++i) {
        std::wcout << L"Desafio: " << desafios[i] << L" (Habilidade: " << habilidades[i] << L")\n" << std::endl;
        std::wcout << L"<<Sua Equipe>>" << std::endl;
        for (size_t j = 0; j < personagens.size(); ++j) {
            std::wcout << j + 1 << L". " << personagens[j]->get_nome()
               << L" (Vida: " << personagens[j]->getVida() << L", Força: " << personagens[j]->getAtributo(L"Força")
               << L", Inteligência: " << personagens[j]->getAtributo(L"Inteligência")
               << L", Reflexo: " << personagens[j]->getAtributo(L"Reflexo")
               << L", Carisma: " << personagens[j]->getAtributo(L"Carisma")
               << L", Instinto: " << personagens[j]->getAtributo(L"Instinto") << L")" << std::endl;
}

        std::wcout << std::endl;
        std::wcout << L">>Escolha um personagem para batalhar nesse desafio: ";
        int escolha;
        std::cin >> escolha;

        if (escolha < 1 || escolha > static_cast<int>(personagens.size())) {
            std::wcout << L"Escolha inválida. Pulando o desafio...\n";
            continue;
        }

        Personagem* personagemEscolhido = personagens[escolha - 1];
        int dado = rand() % 20 + 1;
        int atributoPersonagem = personagemEscolhido->getAtributo(habilidades[i]);

        int resultado = (atributoPersonagem + dado) / 3;

        std::wcout << L"--Rolagem de dado: " << dado << std::endl;
        std::wcout << L"--Atributo: " << personagemEscolhido->getAtributo(habilidades[i]) << std::endl;
        std::wcout << std::endl;
        std::wcout << L"--Resultado: " << resultado << std::endl;

        if (resultado > 5) {
            std::wcout << std::endl;
            std::wcout << personagemEscolhido->get_nome() << L" completou o desafio após muito esforço. Continue assim!\n";
        } else {
            personagemEscolhido->receberDano(40);
            std::wcout << personagemEscolhido->get_nome() << L" falhou no desafio e sofreu 40 de dano\n";
            std::wcout << L"--Vida atual: " << personagemEscolhido->getVida() << std::endl;
        }

        std::wcout << std::endl;

        if (personagemEscolhido->getVida() <= 0) {
            std::wcout << personagemEscolhido->get_nome() << L" ficou enfraquecido demais e morreu! A equipe se abala muito, mas não pode deixar de seguir em frente. É questão de honra!\n";
            personagens.erase(personagens.begin() + (escolha - 1));
        }

        if (personagens.empty()) {
            static bool jaExibiuMensagem = false;
            if (!jaExibiuMensagem) {
                std::wcout << L"Todos os personagens morreram. A névoa escura do Mundo Invertido dominou Hawkins e a população se encontra em um estado de calamidade.\n";
                jaExibiuMensagem = true;
            }
            return;
        }
    }
    std::wcout << std::endl;
}
