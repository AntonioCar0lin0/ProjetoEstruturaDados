#undef byte
#include <cstddef>
#include <iostream>
#include "menuInicial.h"
#include "IniciarJogo.h"
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <clocale>
using namespace std;

void exibirMenuInstrucoesGerais() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");
    int opcao;
    do {
        std::wcout << L"Instruções gerais" << std::endl;
        std::wcout << L"1. Objetivo do jogo" << std::endl;
        std::wcout << L"2. Jogabilidade" << std::endl;
        std::wcout << L"3. Jogar tutorial" << std::endl;
        std::wcout << L"4. Voltar ao menu inicial" << std::endl;
        std::wcout << L"5. Sair" << std::endl;
        cin >> opcao;
        switch(opcao) {
            case 1:
                std::wcout << L"[OBJETIVO DO JOGO] O grupo recebe pistas através de pesadelos compartilhados entre Will e Eleven..." << std::endl;
                break;
            case 2:
                std::wcout << L"[JOGABILIDADE] O jogo será dividido em turnos, o jogador poderá escolher três personagens..." << std::endl;
                break;
            case 3:
                //exibirTutorial();
                break;
            case 4:

                return;
            case 5:
                break;
            default:
                std::wcout << L"Opção inválida!" << std:: endl;
                break;
        };
    } while (opcao != 5);
}

void MenuInicial::exibirMenuInicial() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");
    int opcao;
    //IniciarJogo jogo; (ALERTA): EXPLICAÇÃO -> INSTANCIO AQUI PARA EVITAR DAR ERRO, MAS DÁ ERRO COM E SEM ISSO
    std::wcout <<L"***********************************************"<< std::endl;
    std::wcout <<L"*************[APRESENTAÇÃO DO JOGO]************"<< std::endl;
    std::wcout <<L"***********************************************"<< std::endl;
    std::wcout << L"Hawkins está à beira de um novo colapso sobrenatural, mais sombrio e devastador do que qualquer coisa enfrentada antes. Uma fissura antiga, chamada O Abismo, começa a se abrir no coração da 'Floresta das Trevas', uma conexão entre o mundo  real, o Mundo Invertido e algo ainda mais primitivo e maligno."  << std::endl;
    std::wcout << L"Enquanto fenômenos sobrenaturais se espalham, sinais da presença de antigos inimigos, como o Devorador de Mentes. Desta vez, ele não está sozinho. Vecna, o arquiteto de todo o mal causado em Hawkins, ressurgiu, mais  poderoso, e se tornou o supremo guardião do Abismo, determinado a trazê-lo à totalidade." << std::endl;
    std::wcout <<L"Juntando-se às outras diversas criaturas do Mundo Invertido: Demogorgons, Demodogs e os letais Demobats, que patrulham o céu e atacam qualquer intruso que se  aproxime." << std::endl;
    do {
        std::wcout << L"\nEscolha uma opção:" << std::endl;
        std::wcout << L"1. Iniciar o jogo" << std::endl;
        std::wcout << L"2. Instruções gerais" << std::endl;
        std::wcout << L"3. Sair" << std::endl;
        cin >> opcao;

        switch(opcao) {
            case 1:
                //IniciarJogo jogo; (ALERTA)
                //jogo.exibirMenuIniciarJogo(); (ALERTA)

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
                break;
        };
    } while (opcao != 3);
}

// main para ver se a aplicação individualmente tá rodando
int main() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");

    // Chama o menu inicial
    MenuInicial menuInicial;
    menuInicial.exibirMenuInicial();

    return 0;
}
//