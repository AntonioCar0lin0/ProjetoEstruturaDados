#include "GerenciadorDePersonagens.h"
#include <algorithm>

void GerenciadorDePersonagens::limparArquivo() {
    std::wofstream arquivo(nomeArquivo.c_str(), std::ios::trunc); // Converte std::wstring para const wchar_t*
    arquivo.imbue(std::locale("en_US.UTF-8")); // Configura UTF-8
    if (!arquivo.is_open()) {
        std::wcerr << L"Erro ao abrir o arquivo para limpar os personagens escolhidos!" << std::endl;
        return;
    }
    arquivo.close();
    std::wcout << L"Arquivo de personagens escolhidos foi limpo!" << std::endl;
}

void GerenciadorDePersonagens::salvarPersonagens(const std::vector<std::wstring>& personagens) {
    std::wofstream arquivo(nomeArquivo.c_str(), std::ios::out | std::ios::trunc);
    arquivo.imbue(std::locale("en_US.UTF-8"));
    if (!arquivo.is_open()) {
        std::wcerr << L"Erro ao abrir o arquivo para salvar os personagens!" << std::endl;
        return;
    }
    for (const auto& nome : personagens) {
        arquivo << nome << std::endl;
    }
    arquivo.close();
    std::wcout << L"Personagens salvos com sucesso!" << std::endl;
}

std::vector<std::wstring> GerenciadorDePersonagens::carregarPersonagens() {
    std::wifstream arquivo(nomeArquivo.c_str());
    arquivo.imbue(std::locale("en_US.UTF-8"));
    std::vector<std::wstring> personagens;
    if (!arquivo.is_open()) {
        std::wcerr << L"Erro ao abrir o arquivo para carregar os personagens!" << std::endl;
        return personagens;
    }

    std::wstring linha;
    while (std::getline(arquivo, linha)) {
        personagens.push_back(linha);
    }
    arquivo.close();
    return personagens;
}

void GerenciadorDePersonagens::atualizarPersonagem(const std::wstring& nomeAntigo, const std::wstring& nomeNovo) {
    auto personagens = carregarPersonagens();
    bool atualizado = false;

    for (auto& nome : personagens) {
        if (nome == nomeAntigo) {
            nome = nomeNovo;
            atualizado = true;
            break;
        }
    }

    if (atualizado) {
        salvarPersonagens(personagens);
        std::wcout << L"Personagem atualizado com sucesso!" << std::endl;
    } else {
        std::wcerr << L"Personagem '" << nomeAntigo << L"' não encontrado!" << std::endl;
    }
}

void GerenciadorDePersonagens::deletarPersonagem(const std::wstring& nomePersonagem) {
    auto personagens = carregarPersonagens();

    // Depuração: Mostrar antes da remoção
    std::wcout << L"Antes da remoção:\n";
    for (const auto& nome : personagens) {
        std::wcout << L"- " << nome << std::endl;
    }

    personagens.erase(std::remove(personagens.begin(), personagens.end(), nomePersonagem), personagens.end());

    // Depuração: Mostrar após a remoção
    std::wcout << L"Depois da remoção:\n";
    for (const auto& nome : personagens) {
        std::wcout << L"- " << nome << std::endl;
    }

    salvarPersonagens(personagens);
    std::wcout << L"Personagem '" << nomePersonagem << L"' deletado com sucesso!" << std::endl;
}
