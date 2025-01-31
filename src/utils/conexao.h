#ifndef CONEXAO_H
#define CONEXAO_H

#include <vector>
#include "../models/Personagem.h"

//Salva os personagens escolhidos em um arquivo
void salvarPersonagensEscolhidos(const std::vector<Personagem*>& personagens);

//Carrega os personagens escolhidos anteriormente
std::vector<Personagem*> carregarPersonagensEscolhidos();

//Limpa o arquivo de personagens escolhidos
void limparArquivoPersonagensEscolhidos();
#endif // CONEXAO_H
