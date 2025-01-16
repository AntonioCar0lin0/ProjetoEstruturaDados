#include "Personagem.h"
#include <iostream>
#include <cstring> // Para strlen

// Construtor principal que aceita std::wstring
Personagem::Personagem(std::wstring nome, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto)
    : nome(std::move(nome)), vida(vida), forca(forca), inteligencia(inteligencia), reflexo(reflexo), carisma(carisma), instinto(instinto) {}

// Construtor que aceita const char* e converte para std::wstring
Personagem::Personagem(const char* str, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto)
    : nome(std::wstring(str, str + strlen(str))), vida(vida), forca(forca), inteligencia(inteligencia), reflexo(reflexo), carisma(carisma), instinto(instinto) {}

// Método para exibir as características do personagem
void Personagem::mostrarCaracteristicas() const {
    std::wcout << L"Nome: " << nome << std::endl;
    std::wcout << L"Vida: " << vida << std::endl;
    std::wcout << L"Força: " << forca << std::endl;
    std::wcout << L"Inteligência: " << inteligencia << std::endl;
    std::wcout << L"Reflexo: " << reflexo << std::endl;
    std::wcout << L"Carisma: " << carisma << std::endl;
    std::wcout << L"Instinto: " << instinto << std::endl;
    std::wcout << std::endl;
}
