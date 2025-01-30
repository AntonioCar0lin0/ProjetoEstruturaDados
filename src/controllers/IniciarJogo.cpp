#undef byte
#include <map>
#include <cstddef>
#include "IniciarJogo.h"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include "MenuInicial.h"
#include "../utils/conexao.h"
#include "../models/Personagem.h"
#include "../models/Eleven.h"
#include "../models/Mike.h"
#include "../models/Will.h"
#include "../models/Dustin.h"
#include "../models/Lucas.h"
#include "../models/Max.h"
#include "../controllers/Rounds.h"
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <clocale>
#include <fstream>
using namespace std;

vector<Personagem*> carregarPersonagensEscolhidos(){
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");
    ifstream arquivo("personagensEscolhidos.txt");
    vector<Personagem*> personagens;
    string nome;

    if(!arquivo.is_open()){
        cerr << "Erro ao abrir o arquivo para carregar os personagens!" << endl;
        return personagens;
    }

    while(getline(arquivo, nome)){
        if(nome == "Eleven"){
            personagens.push_back(new Eleven());
        }
        else if(nome == "Mike"){
            personagens.push_back(new Mike());
        }
        else if(nome == "Will"){
            personagens.push_back(new Will());
        }
        else if(nome == "Dustin"){
            personagens.push_back(new Dustin());
        }
        else if(nome == "Lucas"){
            personagens.push_back(new Lucas());
        }
        else if(nome == "Max"){
            personagens.push_back(new Max());
        }
    }

    arquivo.close();
    return personagens;
}

void IniciarJogo::exibirMenuIniciarJogo(){
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");
    int escolha;
    MenuInicial menuInicial;

    bool personagensEscolhidos = false;
    bool itensEscolhidos = false;

    do{
        std::wcout << std::endl;
        std::wcout << L"****************************" << std::endl;
        std::wcout << L"********Iniciar Jogo********" << std::endl;
        std::wcout << L"****************************" << std::endl;
        std::wcout << std::endl;
        std::wcout << L"1. Escolher Personagens" << std::endl;
        std::wcout << L"2. Visualizar/Selecionar item" << std::endl;
        std::wcout << L"3. Iniciar Aventura" << std::endl;
        std::wcout << L"4. Voltar ao Menu" << std::endl;
        std::wcout << std::endl;
        std::wcout << L">>Escolha uma opção: ";
        cin >> escolha;

        switch(escolha){
            case 1:
                escolherPersonagens();
                personagensEscolhidos = true;
                break;
            case 2:
                if (!personagensEscolhidos) {
                    std::wcout << L"Você precisa escolher os personagens antes de selecionar seu item" << std::endl;
                } else {
                    escolherItens();
                    itensEscolhidos = true;
                }
                break;
            case 3:
                if (!personagensEscolhidos) {
                    std::wcout << L"Você precisa escolher seus personagens antes de iniciar a aventura!" << std::endl;
                } else if (!itensEscolhidos) {
                    std::wcout << L"Você precisa escolher e visualizar seu itenm antes de iniciar a aventura!" << std::endl;
                } else {
                    iniciarAventura();
                }
                break;
            case 4:
                menuInicial.exibirMenuInicial();
                return;
            default:
                std::wcout << L"Opção inválida! Tente novamente." << std:: endl;
                break;
        }
    } while(escolha != 4);
}

void IniciarJogo::escolherPersonagens(){
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");
    vector<Personagem*> personagens = {
        new Eleven(),
        new Mike(),
        new Will(),
        new Dustin(),
        new Lucas(),
        new Max()
    };
    vector<Personagem*> personagensEscolhidos;

    int escolha = 0;
    personagensEscolhidos.clear();

    do {
        std::wcout << L"****Escolha seus 3 Personagens****" << std::endl;
        std::wcout << endl;

        for (size_t i = 0; i < personagens.size(); i++){
            std::wcout << i + 1 << ". " << std::endl;
            personagens[i]->mostrarCaracteristicas();
            std::wcout << std::endl;
        }
        std::wcout << personagens.size() + 1 << L". Voltar ao Menu Principal" << std::endl;
        std::wcout << std::endl;

        if (!personagensEscolhidos.empty()){
            std::wcout << L">>Personagens escolhidos:" << std::endl;
            for (const auto& p : personagensEscolhidos){
                std::wcout << "- " << p->get_nome() << std::endl;
            }
            std::wcout << endl;
        }

        std::wcout << L">>Escolha um personagem: ";
        cin >> escolha;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::wcout << L"Entrada inválida! Por favor, insira um número válido." << std::endl;
            continue;
        }

        if (escolha >= 1 && escolha <= (int)personagens.size()){
            auto personagemEscolhido = personagens[escolha - 1];
            if(any_of(personagensEscolhidos.begin(), personagensEscolhidos.end(),
                [personagemEscolhido](const Personagem* p) { return p == personagemEscolhido; })){
                std::wcout << L"Este personagem já foi escolhido! Tente outro." << std::endl;
            }
            else{
                personagensEscolhidos.push_back(personagemEscolhido);
                std::wcout << personagemEscolhido->get_nome() << L" foi escolhido!" << std::endl;
                std::wcout << L"----------------------" << std::endl;
            }
        }
        else {
            std::wcout << L"Opção inválida! Tente novamente." << std::endl;
        }
    }while ( personagensEscolhidos.size() < 3);

    std::wcout << L"Você escolheu seus 3 personagens! Prosseguindo..." << std::endl;
    std::wcout << std::endl;

    std::wcout << std::endl;
    std::wcout << L"<<Sua Equipe>>:" << std::endl;
    std::wcout << std::endl;
    for(const auto& p : personagensEscolhidos){
        p->mostrarCaracteristicas();
    }
    salvarPersonagensEscolhidos(personagensEscolhidos);
}


void IniciarJogo::escolherItens() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");

    vector<Personagem*> personagensEscolhidos = carregarPersonagensEscolhidos();

    if (personagensEscolhidos.empty()) {
        std::wcout << L"Você precisa escolher seus personagens antes de selecionar seu item" << std::endl;
        std::wcout << std::endl;
        return;
    }

    std::map<std::wstring, std::vector<Item>> itensEscolhidosPorPersonagem;

    bool confirmar = false;
    do {
        for (auto& personagem : personagensEscolhidos) {
            std::wcout << endl;
            std::wcout << L"<<Menu do item de: " << personagem->get_nome() << ">>";
            std::wcout << std::endl;

            const auto& itens = personagem->getItens();
            for (size_t i = 0; i < itens.size(); i++) {
                std::wcout << i + 1 << ". ";
                itens[i].mostrarDetalhes();
            }

            std::wcout << itens.size() + 1 << L". Voltar ao Menu Principal" << std::endl;
            std::wcout << std::endl;

            int escolha;
            std::wcout << L">>Selecione a opção: ";
            cin >> escolha;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::wcout << L"Entrada inválida! Por favor, insira um número válido." << std::endl;
                continue;
            }

            if (escolha >= 1 && escolha <= static_cast<int>(itens.size())) {
                const auto& itemEscolhido = itens[escolha - 1];
                std::wcout << L"<<" << personagem->get_nome() << L" recebeu o item: " << std::endl;
                itemEscolhido.mostrarDetalhes();

                itensEscolhidosPorPersonagem[personagem->get_nome()].push_back(itemEscolhido);

                personagem->adicionarBonusItem(itemEscolhido);
            } else if (escolha == static_cast<int>(itens.size() + 1)) {
                limparArquivoPersonagensEscolhidos();
                MenuInicial menuInicial;
                menuInicial.exibirMenuInicial();
                return;
            } else {
                std::wcout << L"Opção inválida! Tente novamente." << std::endl;
            }
        }

        std::wcout << std::endl;
        std::wcout << L"<<Resumo dos Personagens e Itens Escolhidos>>" << std::endl;
        for (const auto& personagem : personagensEscolhidos) {
            std::wcout << L"Personagem: " << personagem->get_nome() << std::endl;

            const auto& itensEscolhidos = itensEscolhidosPorPersonagem[personagem->get_nome()];
            if (!itensEscolhidos.empty()) {
                std::wcout << L"Item Escolhido:" << std::endl;
                for (const auto& item : itensEscolhidos) {
                    std::wcout << L"- ";
                    item.mostrarDetalhes();
                }
            }
            std::wcout << L"---------------------------" << std::endl;
        }

        std::wcout << L"Deseja confirmar o item escolhido" << std::endl;
        std::wcout << L"1. Sim" << std::endl;
        std::wcout << L"2. Não" << std::endl;
        std::wcout << std::endl;
        std::wcout << L">>Escolha uma opção: ";
        int confirmacao;
        cin >> confirmacao;

        if (confirmacao == 1) {
            confirmar = true;
        }
    } while (!confirmar);
}

void IniciarJogo::iniciarAventura() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_ALL, "");

    srand(static_cast<unsigned int>(time(nullptr)));

    std::vector<Personagem*> personagens = carregarPersonagensEscolhidos();

    if (personagens.empty()) {
        std::wcout << L"Você precisa selecionar personagens antes de começar a aventura.\n";
        std::wcout << std::endl;
        return;
    }

    //RODADA 1
    std::vector<std::wstring> desafios = {
        L"Enfrentar os tentáculos do Devorador de Mentes: Os tentáculos viscosos e pulsantes do Devorador de Mentes se movem rapidamente, chicoteando o ar e esmagando tudo em seu caminho. Para seguir em frente, é necessário enfrentá-los e afastá-los com pura força, antes que eles bloqueiem completamente a passagem",
        L"Decodificar uma barreira psíquica: Uma barreira invisível, mas esmagadora, bloqueia seu avanço. O ar ao seu redor parece vibrar com energia psíquica, enviando impulsos confusos para sua mente. Você precisa decifrar os padrões dessa barreira para desarmá-la antes que ela sobrecarregue suas capacidades",
        L"Motivar o grupo a avançar: O medo tomou conta do grupo. Olhares de desespero e vozes vacilantes começam a sugerir a retirada. É seu papel inspirar esperança e coragem, lembrando a todos do que está em jogo e do objetivo maior de salvar Hawkins"
    };

    std::vector<std::wstring> habilidades = {
        L"Força", L"Inteligência", L"Carisma"
    };

    Round round1(
        L"Shopping Starcourt: Enquanto você desce para o subsolo do antigo Shopping Starcourt, uma névoa densa e escura toma conta do ar. No centro do local, uma massa negra e viva se agita. É o Devorador de Mentes, estendendo tentáculos que chicoteiam pelo espaço, tentando impedir qualquer aproximação. Seu objetivo é destruir essa barreira viva para alcançar o primeiro selo e enfraquecer a conexão entre Hawkins e o Mundo Invertido.",
        desafios,
        habilidades
    );

    round1.iniciar(personagens);

    if (personagens.empty()) {
        std::wcout << L"Todos os personagens morreram. A névoa escura do Mundo Invertido dominou Hawkins e a população se encontra em um estado de calamidade.\n";
    } else {
        std::wcout << L"Parabéns! A equipe completou o primeiro desafio após derrotar o gigante Devorador de Mentes.\n";
        std::wcout << L"Pegue seu primeiro Selo do Abismo e siga em frente para próximos desafios!\n";
    }

    //RODADA 2
    std::vector<std::wstring> desafiosRound2 = {
        L"Abrir caminhos na floresta: A vegetação da floresta é espessa e retorcida, como se fosse viva. Galhos entrelaçados e raízes gigantes bloqueiam o caminho, exigindo força bruta para criar uma passagem e continuar avançando rumo ao selo escondido",
        L"Distrair os Demogorgons: Os rugidos das criaturas ecoam pela floresta enquanto eles se aproximam de sua posição. Para salvar o grupo, você precisa agir rápido, criando uma distração que os desvie do rastro de seus companheiros",
        L"Encontrar o selo entre as árvores: O selo está escondido em algum lugar da floresta, camuflado pela névoa densa e pelas árvores antigas. Você sente que ele está perto, mas apenas seguindo sua intuição e observando cada detalhe ao redor será possível encontrá-lo antes que as criaturas o alcancem"
    };

    std::vector<std::wstring> habilidadesRound2 = {
        L"Força", L"Reflexo", L"Instinto"
    };

    Round round2(
        L"Floresta das Trevas: A escuridão da Floresta das Trevas é quase impenetrável, e o ambiente parece sussurrar com vida própria. Cada passo é seguido por olhos famintos. Assim que você se aproxima do centro da clareira, o som de folhas sendo esmagadas anuncia a chegada dos Demogorgons, criaturas ferozes e implacáveis que patrulham o local. Você precisa enfrentá-los para abrir caminho até o segundo selo escondido entre as árvores antigas.",
        desafiosRound2,
        habilidadesRound2
    );

    round2.iniciar(personagens);

    if (personagens.empty()) {
        std::wcout << L"Todos os personagens morreram. A névoa escura do Mundo Invertido dominou Hawkins e a população se encontra em um estado de calamidade.\n";
    } else {
        std::wcout << L"Sua equipe conseguiu sobreviver aos ataques dos amedrontadores Demogorgons.\n";
        std::wcout << L"Sigam em busca dos últimos dois Selos do Abismo!\n";
        std::wcout << std::endl;
    }

    //RODADA 3
    std::vector<std::wstring> desafiosRound3 = {
        L"Lutar contra os Demodogs: Os Demodogs avançam rapidamente, seus grunhidos ressoando como ecos no Mundo Invertido. Eles atacam com ferocidade, tentando cercar você. Sua única chance é reagir com velocidade e precisão, desviando e contra-atacando antes que seja tarde demais",
        L"Usar a sensibilidade para evitar armadilhas: O solo do Mundo Invertido está coberto por armadilhas sobrenaturais que parecem se ativar com o menor movimento. Você deve confiar em sua sensibilidade e atenção aos detalhes para evitar um desastre fatal",
        L"Decodificar o padrão do selo: O selo pulsa com energia vermelha enquanto padrões complexos de luz surgem nele. Apenas decifrando os padrões corretamente será possível desbloquear sua energia e enfraquecer o domínio do Mundo Invertido"
    };

    std::vector<std::wstring> habilidadesRound3 = {
        L"Reflexo", L"Instinto", L"Inteligência"
    };

    Round round3(
        L"Mundo Invertido: Atravessando uma fenda pulsante no ar, você entra no Mundo Invertido. O ar é pesado, como se algo estivesse comprimindo seu peito a cada respiração. A paisagem é retorcida e inóspita, coberta por um vermelho sombrio. Demodogs vigiam o solo, enquanto Demobats circulam o céu acima, protegendo o selo localizado em uma caverna de cristais distorcidos. Cada passo é um risco de ativar uma armadilha sobrenatural ou atrair as criaturas.",
        desafiosRound3,
        habilidadesRound3
    );

    round3.iniciar(personagens);

    if (personagens.empty()) {
        std::wcout << L"Todos os personagens morreram. A névoa escura do Mundo Invertido dominou Hawkins e a população se encontra em um estado de calamidade.\n";
        return;
    } else {
        std::wcout << L"Após muitos desafios, sua equipe derrotou os Demodogs e coletou o penúltimo Selo do Abismo.\n";
        std::wcout << L"Vamos lá! Você está a uma rodada de salvar Hawkins! Mas cuidado, o que vem a seguir não é fácil!\n";
        std::wcout << std::endl;
    }

    //RODADA 4
    std::vector<std::wstring> desafiosRound4 = {
        L"Inspirar o grupo para a batalha final: Diante das visões de terror e do poder avassalador de Vecna, o grupo começa a hesitar. Você precisa lembrá-los de que, juntos, são mais fortes e que esta é a última chance de salvar Hawkins, reacendendo a chama da determinação",
        L"Resistir ao ataque psíquico de Vecna: A mente de Vecna invade a sua, trazendo memórias sombrias e criando ilusões que parecem reais. Você sente seu instinto de sobrevivência sendo testado ao limite enquanto tenta resistir ao poder esmagador de sua manipulação psíquica",
        L"Romper barreiras físicas no covil: O coração do covil de Vecna está bloqueado por barreiras físicas imensas, feitas de um material resistente e sobrenatural. Usando toda sua força, você deve abrir caminho para o grupo e destruir o último selo antes que seja tarde demais"
    };

    std::vector<std::wstring> habilidadesRound4 = {
        L"Carisma", L"Instinto", L"Força"
    };

    Round round4(
        L"Casa Creel: A Casa Creel, agora em ruínas, é um eco sombrio de sua antiga glória. Cada passo dentro dela parece trazer à tona visões do passado, ilusões assustadoras que testam sua sanidade. No coração do local, Vecna aguarda, cercado por energia pulsante e pronto para desferir ataques psíquicos devastadores. Seu objetivo é resistir às manipulações mentais de Vecna enquanto tenta destruir o selo final e encerrar a conexão entre o mundo real e o Mundo Invertido.",
        desafiosRound4,
        habilidadesRound4
    );

    round4.iniciar(personagens);

    if (personagens.empty()) {
        std::wcout << L"Todos os personagens morreram. A névoa escura do Mundo Invertido dominou Hawkins e a população se encontra em um estado de calamidade.\n";
        return;
    } else {
        std::wcout << L"Parabéns, você venceu o Vecna e o Mundo Invertido começa a desmoronar. A névoa se dissipam no ar e as Criaturas finalmente desaparecem.\n";
        std::wcout << L"Hawkins agora agracede à sua perseverança e está segura do mal\n";
        std::wcout << L"(Por enquanto...)\n";
        std::wcout << std::endl;
    }

    std::wcout << L"\nJogo encerrado. Obrigado por jogar!\n";
    exit(0);
}

