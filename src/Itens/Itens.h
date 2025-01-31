#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

//Classe que representa os itens do jogo
class Item {
private:
    std::wstring nome;
    std::wstring habilidade;
    int valor;

public:
    Item(const std::wstring& nome, const std::wstring& habilidade, int valor)
        : nome(nome), habilidade(habilidade), valor(valor) {}

    //Métodos para acessar os atributos do item
    std::wstring getNome() const { return nome; }
    std::wstring getHabilidade() const { return habilidade; }
    int getValor() const { return valor; }

    //Método para exibir os detalhes do item
    void mostrarDetalhes() const {
        std::wcout << nome << L" (" << habilidade << L" + " << valor << L")" << std::endl;
    }
};

#endif // ITEM_H
