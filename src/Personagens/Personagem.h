#ifndef PERSONAGEM_H
#define PERSONAGEM_H

using namespace std;

#include <string>
#include <utility>
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
    vector<Item> itens;

public:
    Personagem(std::wstring nome, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto)
        : nome(nome), vida(vida), forca(forca), inteligencia(inteligencia), reflexo(reflexo), carisma(carisma),instinto(instinto) {}

    Personagem(const char * str, int i, int i1, int i2, int i3, int i4, int i5);

    virtual ~Personagem() = default;

    std::wstring get_nome() const { return nome; }
    int get_vida() const { return vida; }
    int get_forca() const { return forca; }
    int get_inteligencia() const { return inteligencia; }
    int get_reflexo() const { return reflexo; }
    int get_carisma() const { return carisma; }
    int get_instinto() const { return instinto; }


    vector<Item> getItens() const {return itens;}
    void adicionarItem(const Item& item) {itens.push_back(item);}

    // Método para exibir as características do personagem
    virtual void mostrarCaracteristicas() const {
        std::wcout << "Nome: " << nome << std::endl;
        std::wcout << "Vida: " << vida << std::endl;
        std::wcout << "Força: " << forca << std::endl;
        std::wcout << "Inteligência: " << inteligencia << std::endl;
        std::wcout << "Reflexo: " << reflexo << std::endl;
        std::wcout << "Carisma: " << carisma << std::endl;
        std::wcout << "Instinto: " << instinto << std::endl;;
        std::wcout << std::endl;
    }

// Ações dos personagens (adicionar mais depois)
//    virtual void atacar(Personagem& outro) = 0;
//    virtual void apresentar() const = 0;

    int getVida() const {
        return vida;
    }

    int getForca() const {
        return forca;
    }

    int getInteligencia() const {
        return inteligencia;
    }

    int getReflexo() const {
        return reflexo;
    }

    int getCarisma() const {
        return carisma;
    }

    int getInstinto() const {
        return instinto;
    }
};

#endif
