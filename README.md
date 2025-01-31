# **Projeto RPG - Stranger Things**
Projeto da disciplina de Estrutura de Dados Orientada a Objetos, no Centro de Informática da Universidade de Pernambuco, ministrada pelo Professor Francisco Paulo Magalhães. O objetivo do trabalho era realizar um projeto utilizando a linguagem de programação C++, aplicando os conceitos vistos em sala, tais como: lógica da programação em c++, conceitos da programação orientada a objetos (herança, polimorfismo, encapsulamento) e o CRUD (Create, Read, Update & Delete) informações de um banco de dados. 

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
O código do jogo segue uma estrutura organizada em uma variação do modelo **MVC (Model-View-Controller)** para facilitar a manutenção e expansão futura. No caso do código, a lógica da View está misturada Controller. 
Abaixo você pode conferir uma prévia da organização do código: 
```
📂 src/
├── 📂 controllers/
│   ├── 📄 IniciarJogo.cpp
│   ├── 📄 IniciarJogo.h
│   ├── 📄 MenuInicial.cpp
│   ├── 📄 MenuInicial.h
│   ├── 📄 Rounds.cpp
│   ├── 📄 Rounds.h
├── 📂 models/
│   ├── 📄 Dustin.h
│   ├── 📄 Eleven.h
│   ├── 📄 Lucas.h
│   ├── 📄 Max.h
│   ├── 📄 Mike.h
│   ├── 📄 Personagem.cpp
│   ├── 📄 Personagem.h
│   ├── 📄 Will.h
├── 📂 utils/
│   ├── 📄 conexao.cpp
│   ├── 📄 conexao.h
├── 📂 data/
│   ├── 📄 personagensEscolhidos.txt
├── 📂 Itens/
│   ├── 📄 Itens.h
└── 📄 main.cpp
```

---
## 🎮Jogabilidade 
---
## Menu Inicial 
![Menu Inicial](https://media.discordapp.net/attachments/1211775373038059521/1334670256114892920/image.png?ex=679d600a&is=679c0e8a&hm=8972979c004ef80acec5c96e70411b924ae9a58f9aedf3df79487bcdec6b8afb&=&format=webp&quality=lossless&width=1440&height=563)

# Menu de Instruções Gerais
![Menu de Instruções Gerais](https://media.discordapp.net/attachments/1211775373038059521/1334670645786837002/image.png?ex=679d6066&is=679c0ee6&hm=c11133c5ed72730d4236fb204664e4b13f569246e90b2e7e63146346b7e8ef7b&=&format=webp&quality=lossless&width=540&height=207)

## Menu Iniciar Jogo
![Menu Iniciar Jogo](https://media.discordapp.net/attachments/1211775373038059521/1334670863139864668/image.png?ex=679d609a&is=679c0f1a&hm=733fc4126c229361916819ebec908195775646e942f95db5d38366da6ffe07ff&=&format=webp&quality=lossless&width=400&height=283)

Interessado em mais? É só jogar o nosso jogo!!!
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

### **5️⃣ Uso de Arquivos para armazenar os dados (CRUD)**
Para manter as escolhas do jogador (como personagens escolhidos e itens equipados), utilizamos **arquivos de texto (`.txt`) para armazenar e recuperar informações**. Isso permite que **o jogo continue de onde parou**, garantindo que as escolhas do jogador **impactem as rodadas seguintes**.

**Embora o CRUD geralmente seja implementado com quatro funções separadas (**Create, Read, Update, Delete**), no nosso jogo apenas duas funções são suficientes para cumprir esses papéis:**

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
Nomes   | Github
--------- | ------
Antonio Carolino | [AntonioCar0lin0](https://github.com/AntonioCar0lin0)
Luiza Trigueiro | [luizatrigueiro](https://github.com/luizatrigueiro)
---

---

## 📌 **Compilação e Execução via Terminal** ##
```sh
g++ -o rpg main.cpp src/controllers/IniciarJogo.cpp src/controllers/MenuInicial.cpp src/controllers/Rounds.cpp src/models/Personagem.cpp -std=c++14
./rpg
