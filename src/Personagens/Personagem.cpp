#include "Personagem.h"
#include <iostream>
#include <cstring>

Personagem::Personagem(std::wstring nome, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto)
    : nome(std::move(nome)), vida(vida), forca(forca), inteligencia(inteligencia), reflexo(reflexo), carisma(carisma), instinto(instinto) {}

const std::vector<Item>& Personagem::getItens() const {
    return itens;
}

void Personagem::receberDano(int dano) {
    vida -= dano;
    if (vida < 0) vida = 0; // Garante que a vida não fique negativa
}

int Personagem::getAtributo(const std::wstring& habilidade) const {
    int base = 0;

    if (habilidade == L"Força") base = forca;
    else if (habilidade == L"Inteligência") base = inteligencia;
    else if (habilidade == L"Reflexo") base = reflexo;
    else if (habilidade == L"Carisma") base = carisma;
    else if (habilidade == L"Instinto") base = instinto;
    else return 0;


    for (const auto& item : itens) {
        if (item.getHabilidade() == habilidade) {
            base += item.getValor();
        }
    }

    return base;
}


void Personagem::adicionarItem(const Item& item) {
    itens.push_back(item);
}

void Personagem::adicionarBonusItem(const Item& item) {
    const std::wstring& habilidade = item.getHabilidade();
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
