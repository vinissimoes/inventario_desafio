# inventario_desafio
Projeto de inventáSistema de Inventário e Ordenação – Free Fire (C)

Este repositório contém o desenvolvimento do projeto dividido em três níveis:
Novato, Aventureiro e Mestre.
Cada fase adiciona novas funcionalidades e melhora a lógica do mini game de sobrevivência inspirado no Free Fire.

🧩 Nível Novato

Primeira parte do desafio.
Neste nível eu aprendi a trabalhar com struct, vetor e operações básicas.

✔ Funcionalidades:

Cadastro de até 10 itens

Remoção de item por nome

Listagem dos itens da mochila

Busca sequencial simples

Uso de vetor de structs

📄 Arquivo:

inventario_novato.c

🛠️ Nível Aventureiro

Nesta etapa, o sistema cresce e ganha duas versões:
uma usando vetor e outra com lista encadeada.

✔ Funcionalidades:

Inserção, remoção, busca e listagem no vetor

Inserção, remoção, busca e listagem na lista encadeada

Ordenação por nome (Bubble Sort ou Selection Sort)

Busca binária no vetor depois de ordenar

Comparação entre estruturas sequenciais e encadeadas

📄 Arquivo:

inventario_aventureiro.c

🧠 Nível Mestre

Último nível do desafio, unindo tudo e adicionando algoritmos de ordenação mais completos e métrica de desempenho.

✔ Funcionalidades:

Cadastro de até 20 componentes

Ordenação por:

Nome → Bubble Sort

Tipo → Insertion Sort

Prioridade → Selection Sort

Contagem do número de comparações

Medição de tempo de cada algoritmo (clock())

Busca binária por nome, após ordenar

Exibição final dos componentes ordenados

📄 Arquivo:

inventario_mestre.c

🗂 Organização do Repositório
📁 Projeto-FreeFire-C
 ├── inventario_novato.c
 ├── inventario_aventureiro.c
 ├── inventario_mestre.c
 └── README.md

🚀 Como executar

Abra o arquivo .c desejado

Compile com GCC:

gcc nome_do_arquivo.c -o programa


Execute:

./programario
