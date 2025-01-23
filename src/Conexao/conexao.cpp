#include <fstream>
#include <vector>
#include "../Personagens/Personagem.h"
#include <ostream>
#include <string>

// Função para salvar personagens escolhidos em um arquivo
void limparArquivoPersonagensEscolhidos() {
    std::ofstream arquivo("personagensEscolhidos.txt", std::ios::trunc); // Modo trunc limpa o conteúdo
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para limpar os personagens escolhidos!" << std::endl;
        return;
    }
    arquivo.close();
    std::wcout << L"Arquivo de personagens escolhidos foi limpo!" << std::endl;
}
void salvarPersonagensEscolhidos(const std::vector<Personagem*>& personagens) {
    // Usar std::wofstream para lidar com std::wstring
    std::wofstream arquivo("personagensEscolhidos.txt", std::ios::out | std::ios::trunc);

    // Configurar a localidade para suportar Unicode (UTF-8)
    arquivo.imbue(std::locale(""));

    if (!arquivo.is_open()) {
        std::wcerr << L"Erro ao abrir o arquivo para salvar os personagens!" << std::endl;
        return;
    }

    // Grava o nome de cada personagem no arquivo
    for (const auto& personagem : personagens) {
        arquivo << personagem->get_nome() << std::endl;
    }

    arquivo.close();
    std::wcout << L"Personagens escolhidos salvos com sucesso!" << std::endl;
}