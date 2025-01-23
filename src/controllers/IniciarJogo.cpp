#undef byte
#include <cstddef>
#include "IniciarJogo.h"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include "MenuInicial.h"
#include "../Conexao/conexao.cpp"
#include "../Personagens/Personagem.h"
#include "../Personagens/Eleven.h"
#include "../Personagens/Mike.h"
#include "../Personagens/Will.h"
#include "../Personagens/Justin.h"
#include "../Personagens/Lucas.h"
#include "../Personagens/Max.h"
#include "../controllers/Rounds.h"
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <clocale>
using namespace std;

vector<Personagem*> carregarPersonagensEscolhidos(){
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");
    ifstream arquivo("personagensEscolhidos.txt");
    vector<Personagem*> personagens;
    string nome;

    if(!arquivo.is_open()){
        cerr << "Erro ao abrir o arquivo para carregar os personagens!" << endl;
        return personagens;
    }

    while(getline(arquivo, nome)){
        if(nome == "Eleven"){
            personagens.push_back(new Eleven());
        } 
        else if(nome == "Mike"){
            personagens.push_back(new Mike());
        } 
        else if(nome == "Will"){
            personagens.push_back(new Will());
        } 
        else if(nome == "Justin"){
            personagens.push_back(new Justin());
        } 
        else if(nome == "Lucas"){
            personagens.push_back(new Lucas());
        } 
        else if(nome == "Max"){
            personagens.push_back(new Max());
        }
    }

    arquivo.close();
    return personagens;
}

void IniciarJogo::exibirMenuIniciarJogo(){
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");
    int escolha;
    MenuInicial menuInicial;
    do{
        std::wcout << L"****************************" << std::endl;
        std::wcout << L"********Iniciar Jogo********" << std::endl;
        std::wcout << L"****************************" << std::endl;
        std::wcout << std::endl;
        std::wcout << L"1. Escolher Personagens" << std::endl;
        std::wcout << L"2. Escolher Itens" << std::endl;
        std::wcout << L"3. Iniciar Aventura" << std::endl;
        std::wcout << L"4. Voltar ao Menu" << std::endl;
        std::wcout << std::endl;
        std::wcout << L">>Escolha uma opção: ";
        cin >> escolha;

        switch(escolha){
            case 1:
                escolherPersonagens();
                break;
            case 2:
                escolherItens();
                break;
            case 3:
                iniciarAventura();
                break;
            case 4: {
                menuInicial.exibirMenuInicial();
                return;
            }
            default:
                std::wcout << L"Opção inválida! Tente novamente." << std:: endl;
                break;
        }
    } while(escolha != 4);
}

void IniciarJogo::escolherPersonagens(){
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");
    vector<Personagem*> personagens = {
        new Eleven(),
        new Mike(),
        new Will(),
        new Justin(),
        new Lucas(),
        new Max()
    };
    vector<Personagem*> personagensEscolhidos;

    int escolha = 0;
    personagensEscolhidos.clear();

    do {
        std::wcout << L"****Escolha seus Personagens****" << std::endl;
        std::wcout << L"**********(No máximo 3)*********" << std::endl;
        std::wcout << endl;

        for (size_t i = 0; i < personagens.size(); i++){
            std::wcout << i + 1 << ". " << std::endl;
            personagens[i]->mostrarCaracteristicas();
            std::wcout << std::endl;
        }
        std::wcout << personagens.size() + 1 << L". Finalizar Escolha" << std::endl;
        std::wcout << personagens.size() + 2 << L". Voltar ao Menu Principal" << std::endl;
        std::wcout << std::endl;

        if (!personagensEscolhidos.empty()){
            std::wcout << L">>Personagens escolhidos:" << std::endl;
            for (const auto& p : personagensEscolhidos){
                std::wcout << "- " << p->get_nome() << std::endl;
            }
            std::wcout << endl;
        }

        std::wcout << L">>Escolha um personagem: ";
        cin >> escolha;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::wcout << L"Entrada inválida! Por favor, insira um número válido." << std::endl;
            continue;
        }

        if (escolha >= 1 && escolha <= (int)personagens.size()){
            auto personagemEscolhido = personagens[escolha - 1];
            if(any_of(personagensEscolhidos.begin(), personagensEscolhidos.end(),
                [personagemEscolhido](const Personagem* p) { return p == personagemEscolhido; })){
                std::wcout << L"Este personagem já foi escolhido! Tente outro." << std::endl;
            } 
            else{
                personagensEscolhidos.push_back(personagemEscolhido);
                std::wcout << personagemEscolhido->get_nome() << L" foi escolhido!" << std::endl;
                std::wcout << L"----------------------" << std::endl;
            }
        } 
        else if(escolha == (int)personagens.size() + 1){
            if(!personagensEscolhidos.empty()){
                std::wcout << L"Finalizando escolha..." << std::endl;
                break;
            } 
            else{
                std::wcout << L"Você precisa escolher pelo menos 1 personagem para finalizar!" << std::endl;
            }
        } 
        else if(escolha == (int)personagens.size() + 2){
            limparArquivoPersonagensEscolhidos();
            MenuInicial menuInicial;
            menuInicial.exibirMenuInicial();
            return;
        } 
        else{
            std::wcout << L"Opção inválida! Tente novamente." << std::endl;
        }
    } while (escolha != (int)personagens.size() + 2 && personagensEscolhidos.size() < 3);

    std::wcout << std::endl;
    std::wcout << L"<<Sua Equipe>>:" << std::endl;
    std::wcout << std::endl;
    for(const auto& p : personagensEscolhidos){
        p->mostrarCaracteristicas();
    }
    salvarPersonagensEscolhidos(personagensEscolhidos);
}


void IniciarJogo::escolherItens(){
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");
    vector<Personagem*> personagensEscolhidos = carregarPersonagensEscolhidos();
    
    if(personagensEscolhidos.empty()){
        std::wcout << L"Você precisa escolher seus personagens antes de escolher os itens!" << std::endl;
        return;
    }

    bool confirmar = false;
    do{
        for(auto& personagem : personagensEscolhidos){
            std::wcout << endl;
            std::wcout << L"<<Itens de " << personagem->get_nome() << ">>";
            std::wcout << std::endl;
            const auto& itens = personagem->getItens();

            for (size_t i = 0; i < itens.size(); i++){
                std::wcout << i + 1 << ". ";
                itens[i].mostrarDetalhes();
            }
            std::wcout << L"---------------------------" << std::endl;
            std::wcout << itens.size() + 1 << L". Voltar ao Menu Principal" << std::endl;
            std::wcout << std::endl;

            int escolha;
            std::wcout << L">>Escolha um item: ";
            cin >> escolha;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::wcout << L"Entrada inválida! Por favor, insira um número válido." << std::endl;
                continue;
            }

            if(escolha >= 1 && escolha <= static_cast<int>(itens.size())){
                const auto& itemEscolhido = itens[escolha - 1];
                std::wcout << L"<<" << personagem->get_nome() << L" recebeu o item: " << std::endl;
                itens[escolha - 1].mostrarDetalhes();

                //adiciona pontos do item ao atributo
                personagem->adicionarBonusItem(itemEscolhido);
            }
            else if(escolha == static_cast<int>(itens.size() + 1)){
                limparArquivoPersonagensEscolhidos();
                MenuInicial menuInicial;
                menuInicial.exibirMenuInicial();
                return;
            }
            else{
                std::wcout << L"Opção inválida! Tente novamente." << std::endl;
            }
        }

        std::wcout << std::endl;
        std::wcout << L"Deseja confirmar os itens escolhidos?" << std::endl;
        std::wcout << L"1. Sim" << std::endl;
        std::wcout << L"2. Não" << std::endl;
        std::wcout << std::endl;
        std::wcout << L">>Escolha uma opção: ";
        int confirmacao;
        cin >> confirmacao;

        if(confirmacao == 1){
            confirmar = true;
        } 
    }while(!confirmar);
}

void IniciarJogo::iniciarAventura() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");

    std::vector<Personagem*> personagens = carregarPersonagensEscolhidos();

    if (personagens.empty()) {
        std::wcout << L"Você precisa selecionar personagens antes de começar a aventura.\n";
        return;
    }

    std::vector<std::wstring> desafios = {
        L"Enfrentar os tentáculos do Devorador de Mentes",
        L"Decodificar uma barreira psíquica",
        L"Motivar o grupo a avançar"
    };

    std::vector<std::wstring> habilidades = {
        L"Força", L"Inteligência", L"Carisma"
    };

    Round round1(
        L"Shopping Starcourt: Enquanto você desce para o subsolo do antigo Shopping Starcourt, uma névoa densa e pulsante toma conta do ar. No centro do local, uma massa negra, viscosa e viva, se agita. É o Devorador de Mentes, estendendo tentáculos que chicoteiam pelo espaço, tentando impedir qualquer aproximação. Seu objetivo é destruir essa barreira viva para alcançar o primeiro selo e enfraquecer a conexão entre Hawkins e o Mundo Invertido.",
        desafios,
        habilidades
    );

    round1.iniciar(personagens);

    if (personagens.empty()) {
        std::wcout << L"Todos os personagens morreram. O jogo terminou.\n";
    } else {
        std::wcout << L"Parabéns! Você completou o primeiro round.\n";
    }
}
