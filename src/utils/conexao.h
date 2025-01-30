#ifndef CONEXAO_H
#define CONEXAO_H

#include <vector>
#include "../models/Personagem.h"

using namespace std;
void salvarPersonagensEscolhidos(const vector<Personagem*>& personagens);
vector<Personagem*> carregarPersonagensEscolhidos();
void limparArquivoPersonagensEscolhidos(); 
#endif // CONEXAO_H
