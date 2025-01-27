#ifndef ROUNDS_H
#define ROUNDS_H

#include <vector>
#include <string>
#include "../Personagens/Personagem.h"

class Round {
private:
    std::wstring descricao; // Descrição do round
    std::vector<std::wstring> desafios; // Lista de desafios
    std::vector<std::wstring> habilidades; // Habilidades necessárias para os desafios

public:
    // Construtor
    Round(const std::wstring& descricao, const std::vector<std::wstring>& desafios, const std::vector<std::wstring>& habilidades)
        : descricao(descricao), desafios(desafios), habilidades(habilidades) {}

    void iniciar(std::vector<Personagem*>& personagens);
};

#endif // ROUNDS_H
