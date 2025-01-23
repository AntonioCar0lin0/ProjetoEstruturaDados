#include "Personagem.h"
#include <iostream>
#include <cstring> // Para strlen


Personagem::Personagem(std::wstring nome, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto)
    : nome(std::move(nome)), vida(vida), forca(forca), inteligencia(inteligencia), reflexo(reflexo), carisma(carisma), instinto(instinto) {}


Personagem::Personagem(const char* str, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto)
    : nome(std::wstring(str, str + strlen(str))), vida(vida), forca(forca), inteligencia(inteligencia), reflexo(reflexo), carisma(carisma), instinto(instinto) {}


void Personagem::adicionarBonusItem(const Item& item) {
    if (item.getHabilidade() == L"Força") { // Adicione L antes da string
        this->forca += item.getValor();
    } else if (item.getHabilidade() == L"Inteligência") {
        this->inteligencia += item.getValor();
    } else if (item.getHabilidade() == L"Reflexo") {
        this->reflexo += item.getValor();
    } else if (item.getHabilidade() == L"Carisma") {
        this->carisma += item.getValor();
    } else if (item.getHabilidade() == L"Instinto") {
        this->instinto += item.getValor();
    }
}

void Personagem::mostrarCaracteristicas() const {
    std::wcout << L"Nome: " << nome << std::endl;
    std::wcout << L"Vida: " << vida << std::endl;
    std::wcout << L"Força: " << forca << std::endl;
    std::wcout << L"Inteligência: " << inteligencia << std::endl;
    std::wcout << L"Reflexo: " << reflexo << std::endl;
    std::wcout << L"Carisma: " << carisma << std::endl;
    std::wcout << L"Instinto: " << instinto << std::endl;

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
