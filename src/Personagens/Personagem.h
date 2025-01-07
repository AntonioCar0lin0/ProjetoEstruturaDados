#ifndef PERSONAGEM_H
#define PERSONAGEM_H

using namespace std;

#include <string>

class Personagem {
protected:
    string nome;
    int vida;
    int forca;
    int inteligencia;
    int reflexo;
    int carisma;
    int instinto;

public:
    Personagem(string nome, int vida, int forca, int inteligencia, int reflexo, int carisma, int instinto)
        : nome(nome), vida(vida), forca(forca), inteligencia(inteligencia), reflexo(reflexo), carisma(carisma),instinto(instinto) {}

    string get_nome() const { return nome; }
    int get_vida() const { return vida; }
    int get_forca() const { return forca; }
    int get_inteligencia() const { return inteligencia; }
    int get_reflexo() const { return reflexo; }
    int get_carisma() const { return carisma; }
    int get_instinto() const { return instinto; }

    // Método para exibir as características do personagem
    virtual void mostrarCaracteristicas() const {
        cout << "Nome: " << nome << endl;
        cout << "Vida: " << vida << endl;
        cout << "Força: " << forca << endl;
        cout << "Inteligência: " << inteligencia << endl;
        cout << "Reflexo: " << reflexo << endl;
        cout << "Carisma: " << carisma << endl;
        cout << "Instinto: " << instinto << endl;;
        cout << endl;
    }

// Ações dos personagens (adicionar mais depois)
//    virtual void atacar(Personagem& outro) = 0;
//    virtual void apresentar() const = 0;

    string getNome() const {
        return nome;
    }

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
