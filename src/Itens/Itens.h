#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {
private:
    std::wstring nome;
    std::wstring habilidade;
    int valor;

public:
    Item(const std::wstring& nome, const std::wstring& habilidade, int valor)
        : nome(nome), habilidade(habilidade), valor(valor) {}


    std::wstring getNome() const { return nome; }
    std::wstring getHabilidade() const { return habilidade; }
    int getValor() const { return valor; }


    void mostrarDetalhes() const {
        std::wcout << nome << L" (" << habilidade << L" + " << valor << L")" << std::endl;
    }
};

#endif // ITEM_H
