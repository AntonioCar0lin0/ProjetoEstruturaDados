#ifndef ROUNDS_H
#define ROUNDS_H

#include <vector>
#include <string>
#include "../Personagens/Personagem.h"

class Round {
private:
    std::wstring descricao;
    std::vector<std::wstring> desafios;
    std::vector<std::wstring> habilidades;

public:

    Round(const std::wstring& descricao, const std::vector<std::wstring>& desafios, const std::vector<std::wstring>& habilidades)
        : descricao(descricao), desafios(desafios), habilidades(habilidades) {}

    void iniciar(std::vector<Personagem*>& personagens);
};

#endif // ROUNDS_H
