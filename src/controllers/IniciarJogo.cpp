#include "IniciarJogo.h"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include "../Personagens/Personagem.h"
#include "../Personagens/Eleven.h"
#include "../Personagens/Mike.h"
#include "../Personagens/Will.h"
#include "../Personagens/Dustin.h"
#include "../Personagens/Lucas.h"
#include "../Personagens/Max.h"

using namespace std;

void IniciarJogo::exibirMenu(){
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
            case 4:
                cout << "Voltando ao menu principal...";
                break;
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
            cout << "Voltando ao menu principal..." << endl;
            break;
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
}
//implementar depois
void IniciarJogo::escolherItens(){
    cout << "Escolhendo itens..." << endl;
    cout << endl;
}

//implementar depois
void IniciarJogo::iniciarAventura(){
    cout << "Iniciando aventura..." << endl;
    cout << endl;
}