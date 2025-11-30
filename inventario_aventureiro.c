#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

// item básico
typedef struct {
    char nome[30];
    char tipo[20];
    int qtd;
} Item;

// nó da lista encadeada
typedef struct no {
    Item info;
    struct no *prox;
} No;


// ======================== FUNÇÕES DO VETOR ========================

// inserir item no vetor (bem simples)
void addVetor(Item v[], int *n) {
    if (*n >= MAX) {
        printf("\nVetor cheio!\n");
        return;
    }

    printf("\nNome: ");
    scanf("%s", v[*n].nome);
    printf("Tipo: ");
    scanf("%s", v[*n].tipo);
    printf("Qtd: ");
    scanf("%d", &v[*n].qtd);

    (*n)++;

    printf("\nItem adicionado!\n");
}

// listar vetor
void mostrarVetor(Item v[], int n) {
    if (n == 0) {
        printf("\nVetor vazio.\n");
        return;
    }

    printf("\n--- Itens (vetor) ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nNome: %s", v[i].nome);
        printf("\nTipo: %s", v[i].tipo);
        printf("\nQtd: %d\n", v[i].qtd);
    }
}

// busca sequencial
int buscaSeq(Item v[], int n, char nome[], int *comp) {
    for (int i = 0; i < n; i++) {
        (*comp)++;
        if (strcmp(v[i].nome, nome) == 0)
            return i;
    }
    return -1;
}

// remover vetor
void delVetor(Item v[], int *n) {
    char nome[30];
    int comp = 0;

    printf("\nNome para remover: ");
    scanf("%s", nome);

    int pos = buscaSeq(v, *n, nome, &comp);

    if (pos == -1) {
        printf("\nNao achei. Comp: %d\n", comp);
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        v[i] = v[i + 1];
    }

    (*n)--;

    printf("\nItem removido! Comp: %d\n", comp);
}

// ordenar vetor (bubble simples)
void ordenar(Item v[], int n) {
    Item aux;
    int trocou = 1;

    while (trocou) {
        trocou = 0;
        for (int i = 0; i < n - 1; i++) {
            if (strcmp(v[i].nome, v[i+1].nome) > 0) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                trocou = 1;
            }
        }
    }

    printf("\nVetor ordenado.\n");
}

// busca binária simples
int buscaBin(Item v[], int n, char nome[], int *comp) {
    int ini = 0, fim = n - 1, meio;

    while (ini <= fim) {
        meio = (ini + fim) / 2;

        (*comp)++;

        int r = strcmp(nome, v[meio].nome);

        if (r == 0)
            return meio;

        if (r > 0)
            ini = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}



// ======================== LISTA SIMPLES ========================

// inserir no início
No* addLista(No *lista) {
    No *novo = (No*) malloc(sizeof(No));

    printf("\nNome: ");
    scanf("%s", novo->info.nome);
    printf("Tipo: ");
    scanf("%s", novo->info.tipo);
    printf("Qtd: ");
    scanf("%d", &novo->info.qtd);

    novo->prox = lista;

    printf("\nItem colocado na lista!\n");

    return novo;
}

// listar lista
void mostrarLista(No *lista) {
    if (lista == NULL) {
        printf("\nLista vazia.\n");
        return;
    }

    printf("\n--- Itens (lista) ---\n");

    No *p = lista;

    while (p != NULL) {
        printf("\nNome: %s", p->info.nome);
        printf("\nTipo: %s", p->info.tipo);
        printf("\nQtd: %d\n", p->info.qtd);

        p = p->prox;
    }
}

// remover da lista
No* delLista(No *lista) {
    char nome[30];
    printf("\nNome para remover: ");
    scanf("%s", nome);

    No *ant = NULL;
    No *p = lista;

    while (p != NULL) {
        if (strcmp(p->info.nome, nome) == 0) {

            if (ant == NULL) { // remove primeiro nó
                lista = p->prox;
            } else {
                ant->prox = p->prox;
            }

            free(p);
            printf("\nRemovido!\n");
            return lista;
        }

        ant = p;
        p = p->prox;
    }

    printf("\nNao achei.\n");
    return lista;
}



// ======================== MENU PRINCIPAL ========================
int main() {
    Item vet[MAX];
    int n = 0;
    No *lista = NULL;

    int op;

    do {
        printf("\n===== Nivel Aventureiro (Simples) =====\n");
        printf("1 - Add Vetor\n");
        printf("2 - Remover Vetor\n");
        printf("3 - Mostrar Vetor\n");
        printf("4 - Ordenar Vetor\n");
        printf("5 - Buscar Binaria\n\n");

        printf("6 - Add Lista\n");
        printf("7 - Remover Lista\n");
        printf("8 - Mostrar Lista\n");

        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if (op == 1)
            addVetor(vet, &n);

        else if (op == 2)
            delVetor(vet, &n);

        else if (op == 3)
            mostrarVetor(vet, n);

        else if (op == 4)
            ordenar(vet, n);

        else if (op == 5) {
            char nome[30];
            int comp = 0;

            printf("\nNome: ");
            scanf("%s", nome);

            int pos = buscaBin(vet, n, nome, &comp);

            if (pos == -1)
                printf("\nNao achei. Comp: %d\n", comp);
            else {
                printf("\nAchei! Comp: %d\n", comp);
                printf("Nome: %s | Tipo: %s | Qtd: %d\n",
                       vet[pos].nome, vet[pos].tipo, vet[pos].qtd);
            }
        }

        else if (op == 6)
            lista = addLista(lista);

        else if (op == 7)
            lista = delLista(lista);

        else if (op == 8)
            mostrarLista(lista);

    } while (op != 0);

    printf("\nSaindo...\n");

    return 0;
}
