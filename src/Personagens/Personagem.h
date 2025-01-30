#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <vector>
#include "../Itens/Itens.h"

class Personagem {
protected:
    std::wstring nome;
    int vida;
    int forca;
    int inteligencia;
    int reflexo;
    int carisma;
    int instinto;
    std::vector<Item> itens; // Lista de itens do personagem

public:

    Personagem(std::wstring nome, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto);
    virtual ~Personagem() = default;


    std::wstring get_nome() const { return nome; }
    int getVida() const { return vida; }
    void receberDano(int dano); // Declaração do método receberDano
    int getAtributo(const std::wstring& habilidade) const;


    void adicionarItem(const Item& item);
    const std::vector<Item>& getItens() const; // Retorna os itens
    void adicionarBonusItem(const Item& item);
    void mostrarCaracteristicas() const;
};

#endif // PERSONAGEM_H
