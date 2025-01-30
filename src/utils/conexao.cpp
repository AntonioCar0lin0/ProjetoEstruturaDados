#include <fstream>
#include <vector>
#include "../models/Personagem.h"
#include <ostream>
#include <string>

void limparArquivoPersonagensEscolhidos() {
    std::ofstream arquivo("personagensEscolhidos.txt", std::ios::trunc);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para limpar os personagens escolhidos!" << std::endl;
        return;
    }
    arquivo.close();
    std::wcout << L"Arquivo de personagens escolhidos foi limpo!" << std::endl;
}
void salvarPersonagensEscolhidos(const std::vector<Personagem*>& personagens) {
    std::wofstream arquivo("personagensEscolhidos.txt", std::ios::out | std::ios::trunc);

    arquivo.imbue(std::locale(""));

    if (!arquivo.is_open()) {
        std::wcerr << L"Erro ao abrir o arquivo para salvar os personagens!" << std::endl;
        return;
    }

    for (const auto& personagem : personagens) {
        arquivo << personagem->get_nome() << std::endl;
    }

    arquivo.close();
    std::wcout << std::endl;
}