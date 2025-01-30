
#include <cstddef>
#include <iostream>
#include "menuInicial.h"
#include "IniciarJogo.h"
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <clocale>
#include <limits>
using namespace std;

void exibirMenuInstrucoesGerais() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");
    int opcao;
    do {
        std::wcout << L"Instruções gerais" << std::endl;
        std::wcout << L"1. Objetivo do jogo" << std::endl;
        std::wcout << L"2. Jogabilidade" << std::endl;
        std::wcout << L"3. Voltar ao menu inicial" << std::endl;
        std::wcout << L"4. Sair" << std::endl;
        std::wcout << L">>Escolha uma opção: ";
        cin >> opcao;


        switch(opcao) {
            case 1:
                std::wcout << L"[OBJETIVO DO JOGO] O grupo recebe pistas através de pesadelos compartilhados entre Will e Eleven. "<< std::endl;
                std::wcout << L"Esses pesadelos revelam que o Abismo está quase completamente aberto, e com isso, o Devorador de Mentes poderá assumir forma física total no mundo real."<< std::endl;
                std::wcout << L"Para evitar isso, os heróis devem localizar e destruir os quatro Selos do Abismo, escondidos em Hawkins e protegidos por monstros." << std::endl;
                std::wcout << L"A missão é urgente, e as decisões tomadas podem influenciar profundamente o destino da cidade e dos personagens." << std::endl;
                break;
            case 2:
                std::wcout << L"[JOGABILIDADE] O jogo será dividido em turnos, onde o jogador poderá controlar três personagens do grupo em cada turno. " << std::endl;
                std::wcout << L"Cada personagem possui habilidades únicas e atributos que podem ser usados estrategicamente para atacar, defender-se ou usar habilidades especiais." << std::endl;
                std::wcout << L"O progresso será baseado em decisões, combates e a resolução de enigmas, com um sistema que incorpora evolução e ganho  de experiência." << std::endl;
                std::wcout << L"Além disso, o jogo apresenta um inventário limitado, cenários únicos e desafios crescentes ." << std::endl;
                break;
            case 3:
                return;
            case 4:
                cout << "Saindo do jogo..." << endl;
                exit(0);
                break;
            default:
                std::wcout << L"Opção inválida!" << std:: endl;
                exit(0);
                break;
        };
    } while (opcao != 4);
}

void MenuInicial::exibirMenuInicial() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");
    int opcao;
    IniciarJogo iniciarJogo;
    std::wcout << L"\n" << std::endl;
    std::wcout <<L"***********************************************"<< std::endl;
    std::wcout <<L"*************[APRESENTAÇÃO DO JOGO]************"<< std::endl;
    std::wcout <<L"***********************************************"<< std::endl;
    std::wcout << L"Hawkins está à beira de um novo colapso sobrenatural, mais sombrio e devastador do que qualquer coisa enfrentada antes. Uma fissura antiga, chamada O Abismo, começa a se abrir no coração da 'Floresta das Trevas', uma conexão entre o mundo  real, o Mundo Invertido e algo ainda mais primitivo e maligno."  << std::endl;
    std::wcout << L"Enquanto fenômenos sobrenaturais se espalham, sinais da presença de antigos inimigos, como o Devorador de Mentes. Desta vez, ele não está sozinho. Vecna, o arquiteto de todo o mal causado em Hawkins, ressurgiu, mais  poderoso, e se tornou o supremo guardião do Abismo, determinado a trazê-lo à totalidade," << std::endl;
    std::wcout <<L"juntamente às outras diversas criaturas do Mundo Invertido: Demogorgons, Demodogs e os letais Demobats. O seu desafio é coletar os quatro Selos do Abismo -partes do Vecna espalhadas por Hawkins- e destruí-los para salvar a cidade desse mal! " << std::endl;
    do {
        std::wcout << L"\nEscolha uma opção:" << std::endl;
        std::wcout << L"1. Iniciar o jogo" << std::endl;
        std::wcout << L"2. Instruções gerais" << std::endl;
        std::wcout << L"3. Sair" << std::endl;
        std::wcout << std::endl;
        std::wcout << L">>Escolha uma opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                iniciarJogo.exibirMenuIniciarJogo();
                break;
            case 2:
                exibirMenuInstrucoesGerais();
                break;
            case 3:
                cout << "Saindo do jogo..." << endl;
                exit(0);
                break;
            default:
                cout << "Opção inválida!" << endl;
                exit(0);
                break;
        };
    } while (opcao != 3);
}

