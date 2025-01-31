#include "Personagem.h"
#include <iostream>

//Inicializa os atributos do personagem com os valores passados no momento da criação
Personagem::Personagem(std::wstring nome, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto)
    : nome(std::move(nome)), vida(vida), forca(forca), inteligencia(inteligencia), reflexo(reflexo), carisma(carisma), instinto(instinto) {}

const std::vector<Item>& Personagem::getItens() const {
    return itens;
}

//Método para diminuir a vida do personagem ao receber dano
void Personagem::receberDano(int dano) {
    vida -= dano;
    if (vida < 0) vida = 0; //Garante que a vida não fique negativa
}

//Método para obter o valor de um atributo específico do personagem com bônus
int Personagem::getAtributo(const std::wstring& habilidade) const {
    //Inicializa a variável base com valor zero
    int base = 0;

    //Aplica essa variável como base nos atributos
    if (habilidade == L"Força") base = forca;
    else if (habilidade == L"Inteligência") base = inteligencia;
    else if (habilidade == L"Reflexo") base = reflexo;
    else if (habilidade == L"Carisma") base = carisma;
    else if (habilidade == L"Instinto") base = instinto;
    else return 0;

    //Adiciona os bônus dos itens que afetam o atributo específico
    for (const auto& item : itens) {
        if (item.getHabilidade() == habilidade) {
            base += item.getValor();
        }
    }
    return base;
}
//Método para atribuir um item a um personagem
void Personagem::adicionarItem(const Item& item) {
    itens.push_back(item);
}

//Método para adicionar o bônus de um item diretamente aos atributos do personagem
void Personagem::adicionarBonusItem(const Item& item) {
    const std::wstring& habilidade = item.getHabilidade();

    // Verifica qual atributo o item afeta e adiciona o valor correspondente
    if (habilidade == L"Força") {
        forca += item.getValor();
    } else if (habilidade == L"Inteligência") {
        inteligencia += item.getValor();
    } else if (habilidade == L"Reflexo") {
        reflexo += item.getValor();
    } else if (habilidade == L"Carisma") {
        carisma += item.getValor();
    } else if (habilidade == L"Instinto") {
        instinto += item.getValor();
    } else {
        std::wcout << L"Erro: Habilidade desconhecida no item!\n";
    }
}


// Método para exibir as características do personagem
void Personagem::mostrarCaracteristicas() const {
    std::wcout << L"Nome: " << nome << std::endl;
    std::wcout << L"Vida: " << vida << std::endl;
    std::wcout << L"---------------" << std::endl;
    std::wcout << L"Força: " << forca << std::endl;
    std::wcout << L"Inteligência: " << inteligencia << std::endl;
    std::wcout << L"Reflexo: " << reflexo << std::endl;
    std::wcout << L"Carisma: " << carisma << std::endl;
    std::wcout << L"Instinto: " << instinto << std::endl;
    std::wcout << L"---------------";
    std::wcout << std::endl;

    //Exibe os itens do personagem, caso ele possua algum
    if (itens.empty()) {
        std::wcout << L"Itens: Nenhum" << std::endl;
    } else {
        std::wcout << L"Itens:" << std::endl;
        for (const auto& item : itens) {
            item.mostrarDetalhes();
        }
    }
    std::wcout << std::endl;
}
