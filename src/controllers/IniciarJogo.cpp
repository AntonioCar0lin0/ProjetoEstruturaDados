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
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <clocale>
using namespace std;

vector<Personagem*> carregarPersonagensEscolhidos(){
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
        std::wcout << L"******************" << std::endl;
        std::wcout << L"***Iniciar Jogo***" << std::endl;
        std::wcout << L"******************" << std::endl;
        std::wcout << std::endl;
        std::wcout << L"1. Escolher Personagens" << std::endl;
        std::wcout << L"2. Escolher Itens" << std::endl;
        std::wcout << L"3. Iniciar Aventura" << std::endl;
        std::wcout << L"4. Voltar ao Menu" << std::endl;
        std::wcout << std::endl;
        std::wcout << L"Escolha uma opção: " << std::endl;
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
                //MenuInicial menuInicial;
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
        std::wcout << endl;
        std::wcout << "***Escolha seus Personagens***" << std::endl;
        std::wcout << "******* *No máximo 3* ********" << std::endl;
        std::wcout << endl;

        for (size_t i = 0; i < personagens.size(); i++){
            std::wcout << i + 1 << ". " << std::endl;
            personagens[i]->mostrarCaracteristicas();
            std::wcout << std::endl;
        }
        std::wcout << personagens.size() + 1 << ". Finalizar Escolha" << std::endl;
        std::wcout << personagens.size() + 2 << ". Voltar ao Menu Principal" << std::endl;
        std::wcout << std::endl;

        if (!personagensEscolhidos.empty()){
            std::wcout << ">>Personagens escolhidos até agora:" << std::endl;
            for (const auto& p : personagensEscolhidos){
                std::wcout << "- " << p->get_nome() << std::endl;
            }
            std::wcout << endl;
        }

        std::wcout << ">>Escolha um personagem: " << std::endl;
        cin >> escolha;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::wcout << "Entrada inválida! Por favor, insira um número válido." << std::endl;
            continue;
        }

        if (escolha >= 1 && escolha <= (int)personagens.size()){
            auto personagemEscolhido = personagens[escolha - 1];
            if(any_of(personagensEscolhidos.begin(), personagensEscolhidos.end(),
                [personagemEscolhido](const Personagem* p) { return p == personagemEscolhido; })){
                std::wcout << "Este personagem já foi escolhido! Tente outro." << std::endl;
            } 
            else{
                personagensEscolhidos.push_back(personagemEscolhido);
                std::wcout << personagemEscolhido->get_nome() << " foi escolhido!" << std::endl;
            }
        } 
        else if(escolha == (int)personagens.size() + 1){
            if(!personagensEscolhidos.empty()){
                std::wcout << "Finalizando escolha..." << std::endl;
                break;
            } 
            else{
                std::wcout << "Você precisa escolher pelo menos 1 personagem para finalizar!" << std::endl;
            }
        } 
        else if(escolha == (int)personagens.size() + 2){
            limparArquivoPersonagensEscolhidos();
            MenuInicial menuInicial;
            menuInicial.exibirMenuInicial();
            return;
        } 
        else{
            std::wcout << "Opção inválida! Tente novamente." << std::endl;
        }
    } while (escolha != (int)personagens.size() + 2 && personagensEscolhidos.size() < 3);

    std::wcout << std::endl;
    std::wcout << "Sua Equipe:" << std::endl;
    for(const auto& p : personagensEscolhidos){
        p->mostrarCaracteristicas();
    }
    salvarPersonagensEscolhidos(personagensEscolhidos);
}


void IniciarJogo::escolherItens(){
    vector<Personagem*> personagensEscolhidos = carregarPersonagensEscolhidos();
    
    if(personagensEscolhidos.empty()){
        std::wcout << "Você precisa escolher seus personagens antes de escolher os itens!" << std::endl;
        return;
    }

    bool confirmar = false;
    do{
        for(auto& personagem : personagensEscolhidos){
            std::wcout << endl;
            std::wcout << "Escolha os itens para " << personagem->get_nome() << ":" << std::endl;
            const auto& itens = personagem->getItens();

            for (size_t i = 0; i < itens.size(); i++){
                std::wcout << i + 1 << ". " << std::endl;
                itens[i].mostrarDetalhes();
            }
            std::wcout << itens.size() + 1 << ". Voltar ao Menu Principal" << std::endl;

            int escolha;
            std::wcout << "Escolha um item: " << std::endl;
            cin >> escolha;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::wcout << "Entrada inválida! Por favor, insira um número válido." << std::endl;
                continue;
            }

            if(escolha >= 1 && escolha <= (int)itens.size()){
                std::wcout << personagem->get_nome() << " recebeu o item: " << std::endl;
                itens[escolha - 1].mostrarDetalhes();
            }
            else if(escolha == (int)itens.size() + 1){
                limparArquivoPersonagensEscolhidos();
                MenuInicial menuInicial;
                menuInicial.exibirMenuInicial();
                return;
            }
            else{
                std::wcout << "Opção inválida! Tente novamente." << std::endl;
            }
        }

        std::wcout << std::endl;
        std::wcout << "Deseja confirmar os itens escolhidos?" << std::endl;
        std::wcout << "1. Sim" << std::endl;
        std::wcout << "2. Não" << std::endl;
        std::wcout << std::endl;
        std::wcout << ">>Escolha uma opção: " << std::endl;
        int confirmacao;
        cin >> confirmacao;

        if(confirmacao == 1){
            confirmar = true;
        } 
    }while(!confirmar);
}

//implementar depois
void IniciarJogo::iniciarAventura(){
    std::wcout << "Iniciando aventura..." << std::endl;
    std::wcout << std::endl;
}