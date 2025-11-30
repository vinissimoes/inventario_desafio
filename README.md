# inventario_desafio
Projeto de inventáSistema de Inventário e Ordenação – Free Fire (C)

Este repositório contém o desenvolvimento do projeto dividido em três níveis:
Novato, Aventureiro e Mestre.
Cada fase adiciona novas funcionalidades e melhora a lógica do mini game de sobrevivência inspirado no Free Fire.

NÍVEL NOVATO
Objetivo

Criar a primeira versão do inventário usando vetor e operações básicas.

Funcionalidades Implementadas

struct com nome, tipo e quantidade

inserir item

remover item

listar itens

busca sequencial (linear)

menu simples para navegação

📄 Arquivo: inventario_novato.c

🟨 NÍVEL AVENTUREIRO
Objetivo

Ampliar o sistema e começar a comparar duas estruturas de dados: vetor e lista encadeada.

Funcionalidades – Vetor

inserir item

remover item

listar itens

ordenação simples (Bubble Sort)

busca binária

contagem de comparações na busca

Funcionalidades – Lista Encadeada

inserir item

remover item

listar itens

📄 Arquivo: inventario_aventureiro.c

🟥 NÍVEL MESTRE
Objetivo

Aprimorar o trabalho adicionando dois métodos de ordenação e melhor organização lógica.

Funcionalidades Implementadas

ordenação Bubble Sort

ordenação Selection Sort

busca binária com contagem de comparações

vetor funcionando com todas as operações

lista encadeada com inserir, remover e listar

comparação simples entre métodos de ordenação

📄 Arquivo: inventario_mestre.c

▶️ COMO COMPILAR E EXECUTAR
Compilar:
gcc nome_do_arquivo.c -o programa

Executar:
./programa


Exemplo:

gcc inventario_mestre.c -o mestre
./mestre

📁 ESTRUTURA DO REPOSITÓRIO
📁 inventario_desafio
 ├── inventario_novato.c
 ├── inventario_aventureiro.c
 ├── inventario_mestre.c
 └── README.md
