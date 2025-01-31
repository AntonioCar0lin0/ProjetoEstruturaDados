#include <fstream>
#include <vector>
#include "../models/Personagem.h"
#include <ostream>
#include <string>

//Função para limpar o arquivo onde os personagens escolhidos são armazenados
void limparArquivoPersonagensEscolhidos() {
    //Abre o arquivo "personagensEscolhidos.txt" no modo truncado, que apaga todo o conteúdo existente
    std::ofstream arquivo("personagensEscolhidos.txt", std::ios::trunc);

    //Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para limpar os personagens escolhidos!" << std::endl;
        return;
    }
    arquivo.close(); //Fecha o arquivo após ser esvaziado
    std::wcout << L"Arquivo de personagens escolhidos foi limpo!" << std::endl;
}

//Função para salvar os personagens escolhidos em um arquivo
void salvarPersonagensEscolhidos(const std::vector<Personagem*>& personagens) {
    //Abre o arquivo "personagensEscolhidos.txt" para escrita e limpa o conteúdo existente
    std::wofstream arquivo("personagensEscolhidos.txt", std::ios::out | std::ios::trunc);

    //Configura o locale do arquivo para suportar caracteres especiais
    arquivo.imbue(std::locale(""));

    //Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        std::wcerr << L"Erro ao abrir o arquivo para salvar os personagens!" << std::endl;
        return;
    }

    //Escreve os nomes dos personagens no arquivo
    for (const auto& personagem : personagens) {
        arquivo << personagem->get_nome() << std::endl;
    }

    arquivo.close(); //Fecha o arquivo após a escrita
    std::wcout << std::endl;
}