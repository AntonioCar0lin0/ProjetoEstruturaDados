#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>

class Personagem {
protected:
    std::string nome;
    int vida;
    int forca;
    int inteligencia;
    int reflexo;
    int carisma;
    int instinto;

public:
    Personagem(std::string nome, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto)
        : nome(nome), vida(vida), forca(forca), inteligencia(inteligencia), reflexo(reflexo), carisma(carisma),instinto(instinto) {}

    // Ações dos personagens (adicionar mais depois)
//    virtual void atacar(Personagem& outro) = 0;
//    virtual void apresentar() const = 0;

    std::string get_nome() const {
        return nome;
    }

    int get_vida() const {
        return vida;
    }

    int get_forca() const {
        return forca;
    }

    int get_inteligencia() const {
        return inteligencia;
    }

    int get_reflexo() const {
        return reflexo;
    }

    int get_carisma() const {
        return carisma;
    }

    int get_instinto() const {
        return instinto;
    }
};

#endif
