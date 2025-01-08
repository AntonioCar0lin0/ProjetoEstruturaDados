#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Item{
private:
    string nome;
    string habilidade;
    int valor;

public:
    Item(string nome, string habilidade, int valor)
        : nome(nome), habilidade(habilidade), valor(valor) {}

    string getNome() const { return nome; }
    string getHabilidade() const { return habilidade; }
    int getValor() const { return valor; }

    void mostrarDetalhes() const {
        cout << nome << " (" << habilidade << " + " << valor << ")" << endl;
    }
};

#endif // ITEM_H
