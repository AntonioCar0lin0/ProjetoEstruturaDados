#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <vector>
#include "../Itens/Itens.h"

class Personagem {
protected:
    std::wstring nome; // Nome do personagem
    int vida;
    int forca;
    int inteligencia;
    int reflexo;
    int carisma;
    int instinto;
    std::vector<Item> itens; // Itens do personagem

public:
    // Construtor principal que aceita std::wstring
    Personagem(std::wstring nome, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto);

    // Construtor que aceita const char* para compatibilidade
    Personagem(const char* str, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto);

    // Destrutor virtual para garantir limpeza correta
    virtual ~Personagem() = default;

    // Getters
    std::wstring get_nome() const { return nome; }
    int get_vida() const { return vida; }
    int get_forca() const { return forca; }
    int get_inteligencia() const { return inteligencia; }
    int get_reflexo() const { return reflexo; }
    int get_carisma() const { return carisma; }
    int get_instinto() const { return instinto; }
    std::vector<Item> getItens() const { return itens; }

    // Adiciona um item ao personagem
    void adicionarItem(const Item& item) { itens.push_back(item); }

    // Método virtual para exibir características (podem ser sobrescritas nas subclasses)
    virtual void mostrarCaracteristicas() const;

    // Getters auxiliares
    int getVida() const { return vida; }
    int getForca() const { return forca; }
    int getInteligencia() const { return inteligencia; }
    int getReflexo() const { return reflexo; }
    int getCarisma() const { return carisma; }
    int getInstinto() const { return instinto; }
};

#endif // PERSONAGEM_H
