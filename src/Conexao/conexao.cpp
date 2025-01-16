#include <fstream>
#include <vector>
#include "../Personagens/Personagem.h"
#include <ostream>
#include <string>

// Função para salvar personagens escolhidos em um arquivo
void limparArquivoPersonagensEscolhidos() {
    ofstream arquivo("personagensEscolhidos.txt", ios::trunc); // Modo trunc limpa o conteúdo
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para limpar os personagens escolhidos!" << endl;
        return;
    }
    arquivo.close();
    std::wcout << "Arquivo de personagens escolhidos foi limpo!" << std::endl;
}
;

void salvarPersonagensEscolhidos(const vector<Personagem*>& personagens) {
    ofstream arquivo("personagensEscolhidos.txt"); // Cria ou abre o arquivo

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para salvar os personagens!" << std::endl;
        return;
    }

    // Grava o nome de cada personagem no arquivo
    for (const auto& personagem : personagens) {
        arquivo << personagem->get_nome() << endl;
    }

    arquivo.close();
    std::wcout << "Personagens escolhidos salvos com sucesso!" << std::endl;
}
