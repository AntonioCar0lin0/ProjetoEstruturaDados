#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <vector>
#include "../Itens/Itens.h"

//Declaração da classe base Personagem, que será herdada pelos personagens do jogo
class Personagem {
protected:
    std::wstring nome;
    int vida;
    int forca;
    int inteligencia;
    int reflexo;
    int carisma;
    int instinto;
    std::vector<Item> itens;

public:
    Personagem(std::wstring nome, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto);
    virtual ~Personagem() = default; //Declaração do destrutor virtual para garantir que a destruição de objetos derivados seja correta

    //Métodos getters para acessar os atributos privados do personagem
    std::wstring get_nome() const { return nome; }
    int getVida() const { return vida; }

    //Método para reduzir a vida do personagem ao receber dano
    void receberDano(int dano);

    // Retorna o valor de um atributo específico do personagem com base na string recebida
    int getAtributo(const std::wstring &habilidade) const;

    //Métodos para manipulação de itens do personagem
    void adicionarItem(const Item& item);
    const std::vector<Item>& getItens() const; //Retorna os itens

    //Aplica o bônus de um item nos atributos do personagem
    void adicionarBonusItem(const Item& item);

    //Exibe as características do personagem
    void mostrarCaracteristicas() const;
};

#endif // PERSONAGEM_H
