#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// struct que guarda os dados de cada item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// função para inserir item no vetor
void inserirItem(Item mochila[], int *qtd) {
    if (*qtd >= MAX_ITENS) {
        printf("\nA mochila esta cheia! Nao da pra adicionar mais itens.\n");
        return;
    }

    printf("\n=== Cadastro de Item ===\n");

    printf("Nome do item: ");
    scanf("%s", mochila[*qtd].nome);

    printf("Tipo do item (arma, cura, munição...): ");
    scanf("%s", mochila[*qtd].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*qtd].quantidade);

    (*qtd)++;

    printf("\nItem cadastrado com sucesso!\n");
}

// função para listar os itens
void listarItens(Item mochila[], int qtd) {
    printf("\n=== Itens na Mochila ===\n");

    if (qtd == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}

// função para buscar um item pelo nome (busca linear)
int buscarItem(Item mochila[], int qtd, char nome[]) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            return i; // retorna a posição onde achou
        }
    }
    return -1; // não encontrou
}

// função para remover item
void removerItem(Item mochila[], int *qtd) {
    char nome[30];
    printf("\nDigite o nome do item que quer remover: ");
    scanf("%s", nome);

    int pos = buscarItem(mochila, *qtd, nome);

    if (pos == -1) {
        printf("\nItem nao encontrado!\n");
        return;
    }

    // move os itens para "tapar o buraco"
    for (int i = pos; i < *qtd - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*qtd)--;

    printf("\nItem removido com sucesso!\n");
}

int main() {
    Item mochila[MAX_ITENS]; // vetor de até 10 itens
    int qtd = 0; // quantidade de itens cadastrados
    int opcao;

    do {
        printf("\n===== Sistema de Inventario - Nivel Novato =====\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            inserirItem(mochila, &qtd);
        } else if (opcao == 2) {
            removerItem(mochila, &qtd);
        } else if (opcao == 3) {
            listarItens(mochila, qtd);
        } else if (opcao == 4) {
            char nomeBuscado[30];
            printf("\nDigite o nome do item para buscar: ");
            scanf("%s", nomeBuscado);

            int pos = buscarItem(mochila, qtd, nomeBuscado);

            if (pos == -1) {
                printf("\nItem nao encontrado!\n");
            } else {
                printf("\n=== Item Encontrado ===\n");
                printf("Nome: %s\n", mochila[pos].nome);
                printf("Tipo: %s\n", mochila[pos].tipo);
                printf("Quantidade: %d\n", mochila[pos].quantidade);
            }
        }

    } while (opcao != 0);

    printf("\nSaindo... Ate mais!\n");

    return 0;
}
