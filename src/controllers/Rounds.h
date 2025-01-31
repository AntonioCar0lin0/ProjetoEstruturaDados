#ifndef ROUNDS_H
#define ROUNDS_H

#include <vector>
#include <string>
#include "../models/Personagem.h"

//Classe para representar as rodadas
class Round {
private:
    std::wstring descricao;
    std::vector<std::wstring> desafios;
    std::vector<std::wstring> habilidades;

public:
    //Recebe a descrição da rodada, os desafios e os atributos necessários para conseguir
    Round(const std::wstring& descricao, const std::vector<std::wstring>& desafios, const std::vector<std::wstring>& habilidades)
        : descricao(descricao), desafios(desafios), habilidades(habilidades) {}

    //Método que inicia a rodada
    void iniciar(std::vector<Personagem*>& personagens);
};

#endif // ROUNDS_H
