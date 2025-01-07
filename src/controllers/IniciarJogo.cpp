#include "IniciarJogo.h"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include "../views/MenuInicial.h"
#include "../Conexao/conexao.cpp"
#include "../Personagens/Personagem.h"
#include "../Personagens/Eleven.h"
#include "../Personagens/Mike.h"
#include "../Personagens/Will.h"
#include "../Personagens/Dustin.h"
#include "../Personagens/Lucas.h"
#include "../Personagens/Max.h"

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
        else if(nome == "Dustin"){
            personagens.push_back(new Dustin());
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
    int escolha;
    do{
        cout << "******************" << endl;
        cout << "***Iniciar Jogo***" << endl;
        cout << "******************" << endl;
        cout << endl;
        cout << "1. Escolher Personagens" << endl;
        cout << "2. Escolher Itens" << endl;
        cout << "3. Iniciar Aventura" << endl;
        cout << "4. Voltar ao Menu" << endl;
        cout << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;
        cout << endl;

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
                MenuInicial menuInicial;
                menuInicial.exibirMenuInicial();
                return;
            }
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
    } while(escolha != 4);
}

void IniciarJogo::escolherPersonagens(){
    vector<Personagem*> personagens = {
        new Eleven(),
        new Mike(),
        new Will(),
        new Dustin(),
        new Lucas(),
        new Max()
    };
    vector<Personagem*> personagensEscolhidos;

    int escolha = 0;
    personagensEscolhidos.clear();

    do {
        cout << endl;
        cout << "***Escolha seus Personagens***" << endl;
        cout << "******* *No máximo 3* ********" << endl;
        cout << endl;

        for (size_t i = 0; i < personagens.size(); i++){
            cout << i + 1 << ". ";
            personagens[i]->mostrarCaracteristicas();
            cout << endl; 
        }
        cout << personagens.size() + 1 << ". Finalizar Escolha" << endl;
        cout << personagens.size() + 2 << ". Voltar ao Menu Principal" << endl;
        cout << endl;

        if (!personagensEscolhidos.empty()){
            cout << ">>Personagens escolhidos até agora:" << endl;
            for (const auto& p : personagensEscolhidos){
                cout << "- " << p->get_nome() << endl;
            }
            cout << endl;
        }

        cout << ">>Escolha um personagem: ";
        cin >> escolha;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida! Por favor, insira um número válido." << endl;
            continue;
        }

        if (escolha >= 1 && escolha <= (int)personagens.size()){
            auto personagemEscolhido = personagens[escolha - 1];
            if(any_of(personagensEscolhidos.begin(), personagensEscolhidos.end(),
                [personagemEscolhido](const Personagem* p) { return p == personagemEscolhido; })){
                cout << "Este personagem já foi escolhido! Tente outro." << endl;
            } 
            else{
                personagensEscolhidos.push_back(personagemEscolhido);
                cout << personagemEscolhido->get_nome() << " foi escolhido!" << endl;
            }
        } 
        else if(escolha == (int)personagens.size() + 1){
            if(!personagensEscolhidos.empty()){
                cout << "Finalizando escolha..." << endl;
                break;
            } 
            else{
                cout << "Você precisa escolher pelo menos 1 personagem para finalizar!" << endl;
            }
        } 
        else if(escolha == (int)personagens.size() + 2){
            limparArquivoPersonagensEscolhidos();
            MenuInicial menuInicial;
            menuInicial.exibirMenuInicial();
            return;
        } 
        else{
            cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (escolha != (int)personagens.size() + 2 && personagensEscolhidos.size() < 3);

    cout << endl;
    cout << "Sua Equipe:" << endl;
    for(const auto& p : personagensEscolhidos){
        p->mostrarCaracteristicas();
    }
    salvarPersonagensEscolhidos(personagensEscolhidos);
}


void IniciarJogo::escolherItens(){
    vector<Personagem*> personagensEscolhidos = carregarPersonagensEscolhidos();
    
    if(personagensEscolhidos.empty()){
        cout << "Você precisa escolher seus personagens antes de escolher os itens!" << endl;
        return;
    }

    bool confirmar = false;
    do{
        for(auto& personagem : personagensEscolhidos){
            cout << endl;
            cout << "Escolha os itens para " << personagem->getNome() << ":" << endl;
            const auto& itens = personagem->getItens();

            for (size_t i = 0; i < itens.size(); i++){
                cout << i + 1 << ". ";
                itens[i].mostrarDetalhes();
            }
            cout << itens.size() + 1 << ". Voltar ao Menu Principal" << endl;

            int escolha;
            cout << "Escolha um item: ";
            cin >> escolha;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida! Por favor, insira um número válido." << endl;
                continue;
            }

            if(escolha >= 1 && escolha <= (int)itens.size()){
                cout << personagem->getNome() << " recebeu o item: ";
                itens[escolha - 1].mostrarDetalhes();
            }
            else if(escolha == (int)itens.size() + 1){
                limparArquivoPersonagensEscolhidos();
                MenuInicial menuInicial;
                menuInicial.exibirMenuInicial();
                return;
            }
            else{
                cout << "Opção inválida! Tente novamente." << endl;
            }
        }

        cout << endl;
        cout << "Deseja confirmar os itens escolhidos?" << endl;
        cout << "1. Sim" << endl;
        cout << "2. Não" << endl;
        cout << endl;
        cout << ">>Escolha uma opção: " << endl;
        int confirmacao;
        cin >> confirmacao;

        if(confirmacao == 1){
            confirmar = true;
        } 
    }while(!confirmar);
}

//implementar depois
void IniciarJogo::iniciarAventura(){
    cout << "Iniciando aventura..." << endl;
    cout << endl;
}