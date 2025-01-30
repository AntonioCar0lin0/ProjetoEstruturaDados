# **Projeto RPG - Stranger Things**

## 🎮 Sobre o Jogo
Neste jogo de RPG baseado no universo de *Stranger Things*, você assume o papel de um grupo de três personagens que enfrentará desafios sobrenaturais para impedir que Hawkins seja consumida pelo *Mundo Invertido*. Para isso, será necessário derrotar monstros, superar enigmas e coletar os **Selos do Abismo**, impedindo que Vecna conquiste o mundo real.

O jogo se desenvolve em quatro rodadas, onde cada desafio requer o uso estratégico dos atributos dos personagens para ser superado. **Escolha bem sua equipe, prepare seus itens e vença o mal que assombra Hawkins!**

---

## 🛠️ Funcionalidades
- **Instruções gerais**: O jogador pode acessar um menu de instruções para entender o funcionamento.
- **Escolha de personagens**: O jogador deve selecionar **três personagens fixos** para formar seu grupo. Cada um possui atributos com níveis distintos.
- **Sistema de itens**: Personagens vêm equipados com itens especiais, que aumentam um de seus atributos.
- **Combate baseado em atributos**: Cada desafio exige uma habilidade específica, como **Força, Inteligência, Reflexo, Carisma ou Instinto**.
- **Sistema de rolagem de dados**: O sucesso das ações é determinado por um **D20**, somado ao valor do atributo do personagem e dividido por três.
- **Progressão narrativa**: O jogo avança por **quatro rodadas**, com desafios e histórias diferentes.

---

## 📃 Estrutura do Projeto
O código do jogo segue uma estrutura organizada em **MVC (Model-View-Controller)** para facilitar a manutenção e expansão futura.

ProjetoRPG/ ├── src/ │ ├── controllers/ │ │ ├── IniciarJogo.cpp │ │ ├── MenuInicial.cpp │ │ ├── Rounds.cpp │ ├── models/ │ │ ├── Personagem.cpp │ │ ├── Itens.cpp │ ├── views/ │ │ ├── ExibirMenu.cpp │ ├── main.cpp

---

## 🔥 Rodadas e Desafios
- O jogo é dividido em **4 rodadas**, cada uma contendo **3 desafios diferentes**. O jogador deve utilizar **estratégia** para escolher qual personagem enfrentará cada desafio.

### **🌀 Rodada 1 - Shopping Starcourt**
- **Enfrentar os tentáculos do Devorador de Mentes** *(Força)* 
- **Decodificar uma barreira psíquica** *(Inteligência)* 
- **Motivar o grupo a avançar** *(Carisma)* 

### **🌲 Rodada 2 - Floresta das Trevas**
- **Abrir caminhos na floresta** *(Força - ND 13)*
- **Distrair os Demogorgons** *(Reflexo - ND 15)* 
- **Encontrar o selo entre as árvores** *(Instinto - ND 14)* 

### **🔴 Rodada 3 - Mundo Invertido**
- **Lutar contra os Demodogs** *(Reflexo)* 
- **Usar a sensibilidade para evitar armadilhas** *(Instinto)* 
- **Decodificar o padrão do selo** *(Inteligência)* 

### **🏚️ Rodada 4 - Casa Creel**
- **Inspirar o grupo para a batalha final** *(Carisma)* 
- **Resistir ao ataque psíquico de Vecna** *(Instinto)* 
- **Romper barreiras físicas no covil** *(Força)* 

---

## 📦 **Como Jogar**
### 📌 **Pré-requisitos**
- **Compilador C++** (g++ ou MinGW para Windows)
- **CMake** (caso esteja usando CLion ou outra IDE que requeira CMake)
- **Sistema compatível**: Windows

---

## 🔥 **Conceitos Utilizados no Projeto**
### **1️⃣ Herança**
A herança foi utilizada para **organizar e estruturar os personagens do jogo**, permitindo que todos compartilhem atributos comuns sem duplicação de código. Criamos uma **classe base** chamada `Personagem`, que contém atributos como vida, força, inteligência e métodos essenciais. A partir dela, **cada personagem específico herda suas características e pode ser personalizado** sem precisar reescrever código repetitivo.

📝 **Exemplo no jogo:** Todos os personagens (Eleven, Mike, Will, Dustin, Lucas, Max) **herdam** da classe `Personagem`, mas possuem atributos próprios que os diferenciam.

---

### **2️⃣ Polimorfismo**
O polimorfismo foi aplicado para permitir que diferentes personagens **executem métodos de forma diferente**, mesmo que compartilhem a mesma interface. Isso possibilita que o jogo chame um método genérico (`mostrarCaracteristicas()`), mas cada personagem exiba seus detalhes específicos automaticamente.

📝 **Exemplo no jogo:** Sempre que o jogador escolhe um personagem, o jogo **exibe as características daquele personagem**, sem precisar checar manualmente qual é o tipo dele.

---

### **3️⃣ Encapsulamento**
O encapsulamento garante que os atributos dos personagens sejam protegidos e modificados apenas por métodos controlados. Isso impede alterações diretas que poderiam gerar inconsistências no jogo e permite um **controle seguro sobre as regras do sistema**.

📝 **Exemplo no jogo:** A vida do personagem **não pode ser alterada diretamente pelo jogador**. Quando um personagem sofre dano, ele chama um método que reduz sua vida de forma segura, sem permitir valores negativos ou alterações externas indevidas.

---

### **4️⃣ Sistema de Turnos e Rolagem de Dados**
O jogo utiliza um **sistema de turnos baseado em rolagem de dados** para determinar os resultados das ações. Isso adiciona um elemento de aleatoriedade, **criando tensão e variabilidade nas partidas**.

📝 **Exemplo no jogo:** Para vencer um desafio, um personagem precisa testar um atributo como força, inteligência ou reflexo. O sistema faz a **soma do atributo do personagem com um dado de 20 lados**, garantindo que **cada jogada seja única**.

---

### **5️⃣ Uso de Arquivos para Persistência (CRUD)**
Para manter as escolhas do jogador (como personagens escolhidos e itens equipados), utilizamos **arquivos de texto (`.txt`) para armazenar e recuperar informações**. Isso permite que **o jogo continue de onde parou**, garantindo que as escolhas do jogador **impactem as rodadas seguintes**.

#### **🔄 Como duas funções realizam as quatro operações do CRUD?**
Embora o CRUD geralmente seja implementado com quatro funções separadas (**Create, Read, Update, Delete**), no nosso jogo **apenas duas funções são suficientes para cumprir esses papéis**:

1️⃣ **`salvarPersonagensEscolhidos()`**
- **Create (Criar)**: Quando um novo conjunto de personagens é escolhido, essa função **cria** um arquivo e escreve os nomes dos personagens.
- **Update (Atualizar)**: Se o jogador mudar sua equipe, essa função **sobrescreve** completamente os dados anteriores, funcionando como uma atualização.

2️⃣ **`limparArquivoPersonagensEscolhidos()`**
- **Delete (Remover)**: Essa função **abre o arquivo no modo truncado (`std::ios::trunc`)**, apagando completamente seu conteúdo, garantindo que os personagens da partida anterior não interfiram em uma nova escolha.
- **Read (Ler)**: Apesar de não estar explicitamente no código dessas funções, a leitura dos personagens acontece quando o jogo carrega os dados armazenados no arquivo.

---

#### **📋 Fluxo das operações CRUD no jogo**
1️⃣ O jogador escolhe seus três personagens.  
2️⃣ O jogo **escreve** os nomes no arquivo `personagensEscolhidos.txt` (**Create**).  
3️⃣ Se o jogador quiser trocar os personagens, a nova escolha **sobrescreve** o arquivo (**Update**).  
4️⃣ Antes de iniciar uma nova seleção, o jogo **limpa** completamente o arquivo (**Delete**).  
5️⃣ Quando o jogo começa, ele **lê** os personagens do arquivo para recriar os objetos (**Read**).

---

### **🚀 Benefícios dessa abordagem**
✔ **Código mais enxuto**: Em vez de criar funções separadas para cada operação, agrupamos ações relacionadas, reduzindo redundância.  
✔ **Eficiência**: Sempre que um personagem é salvo, os dados anteriores são automaticamente substituídos, eliminando a necessidade de lógica complexa para atualização.  
✔ **Facilidade de manutenção**: Apenas duas funções controlam toda a persistência de dados, facilitando futuras melhorias.

Essa implementação garante que **o jogo armazene informações de forma confiável**, possibilitando que as decisões do jogador **tenham impacto real na progressão**. 🔥🎮

---

## 📌 **Executando no CLion** ##
- Abra o projeto no CLion.
- Certifique-se de que o CMake esteja configurado corretamente.
Clique em Run para compilar e executar o jogo.

---

## 📌 **Créditos e Autoria** ##
- Projeto desenvolvido por Luiza Trigueiro e Antonio Carolino, inspirado no universo da série Stranger Things.

---

## 📌 **Compilação e Execução via Terminal** ##
```sh
g++ -o rpg main.cpp src/controllers/IniciarJogo.cpp src/controllers/MenuInicial.cpp src/controllers/Rounds.cpp src/models/Personagem.cpp -std=c++14
./rpg
