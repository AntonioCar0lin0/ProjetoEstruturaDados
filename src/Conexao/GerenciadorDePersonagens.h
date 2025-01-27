#ifndef GERENCIADOR_DE_PERSONAGENS_H
#define GERENCIADOR_DE_PERSONAGENS_H

#include <vector>
#include <string>
#include <fstream>
#include <locale>
#include <iostream>

class GerenciadorDePersonagens {
private:
    const std::wstring nomeArquivo = L"personagensEscolhidos.txt"; // Caminho do arquivo

public:
    // Limpar o arquivo de personagens escolhidos
    void limparArquivo();

    // Salvar uma lista de personagens no arquivo
    void salvarPersonagens(const std::vector<std::wstring>& personagens);

    // Carregar a lista de personagens do arquivo
    std::vector<std::wstring> carregarPersonagens();

    // Atualizar o nome de um personagem no arquivo
    void atualizarPersonagem(const std::wstring& nomeAntigo, const std::wstring& nomeNovo);

    // Deletar um personagem do arquivo
    void deletarPersonagem(const std::wstring& nomePersonagem);
};

#endif // GERENCIADOR_DE_PERSONAGENS_H
