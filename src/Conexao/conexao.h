#ifndef CONEXAO_H
#define CONEXAO_H

#include <vector>
#include "../Personagens/Personagem.h"

void salvarPersonagensEscolhidos(const vector<Personagem*>& personagens);
vector<Personagem*> carregarPersonagensEscolhidos();
void limparArquivoPersonagensEscolhidos(); 
#endif // CONEXAO_H
