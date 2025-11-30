Sistema de Inventário – Projeto em C
Desenvolvido em três níveis: Novato → Aventureiro → Mestre

Este repositório contém o desenvolvimento completo do sistema de inventário solicitado no PDF.
O projeto evolui em três etapas, cada uma adicionando novos recursos e usos de estruturas de dados, sempre com código simples e claro.

 
 NÍVEL NOVATO

Primeira versão do sistema de inventário, usando apenas vetor.

- Funcionalidades

Estrutura Item com nome, tipo e quantidade

Inserir item

Remover item

Listar itens

Busca sequencial (linear)

Menu inicial simples

Arquivo: inventario_novato.c




NÍVEL AVENTUREIRO

Expansão do inventário com vetor e lista encadeada, permitindo comparar estruturas.

- Funcionalidades – Vetor

Inserir itens

Remover itens

Listar

Ordenar por nome (Bubble Sort)

Busca binária

Contador de comparações

- Funcionalidades – Lista Encadeada

Inserir

Remover

Listar

Arquivo: inventario_aventureiro.c




NÍVEL MESTRE

Última evolução do projeto, adicionando dois métodos de ordenação e aprimorando o sistema.

- Funcionalidades

Ordenação Bubble Sort

Ordenação Selection Sort

Busca binária com contagem

Comparação entre métodos

Lista encadeada mantida

Sistema final mais organizado e completo

Arquivo: inventario_mestre.c


COMO COMPILAR E EXECUTAR
Compilar:
gcc nome_do_arquivo.c -o programa

Executar:
./programa


Exemplo:

gcc inventario_mestre.c -o mestre
./mestre


- ESTRUTURA DO REPOSITÓRIO
-inventario_desafio
  - inventario_novato.c
  - inventario_aventureiro.c
  - inventario_mestre.c
  - README.md
