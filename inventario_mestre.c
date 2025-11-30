#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

// item básico
typedef struct {
    char nome[30];
    char tipo[20];
    int qtd;
} Item;

// nó lista
typedef struct no {
    Item info;
    struct no *prox;
} No;


// =================== FUNÇÕES DO VETOR ===================

// add no vetor
void addV(Item v[], int *n) {
    if (*n >= MAX) {
        printf("\nVetor cheio.\n");
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

// mostrar vetor
void mostraV(Item v[], int n) {
    if (n == 0) {
        printf("\nSem itens.\n");
        return;
    }

    printf("\n--- Itens (vetor) ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nNome: %s", v[i].nome);
        printf("\nTipo: %s", v[i].tipo);
        printf("\nQtd: %d\n", v[i].qtd);
    }
}

// busca seq
int buscaSeq(Item v[], int n, char nome[], int *comp) {
    for (int i = 0; i < n; i++) {
        (*comp)++;
        if (strcmp(v[i].nome, nome) == 0)
            return i;
    }
    return -1;
}

// remover vetor
void remV(Item v[], int *n) {
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

    printf("\nRemovido! Comp: %d\n", comp);
}

// ordenação bubble
void bubble(Item v[], int n) {
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

    printf("\nVetor ordenado (bubble).\n");
}

// ordenação seleção
void selection(Item v[], int n) {
    int menor;
    Item aux;

    for (int i = 0; i < n - 1; i++) {
        menor = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(v[j].nome, v[menor].nome) < 0)
                menor = j;
        }

        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }

    printf("\nVetor ordenado (selection).\n");
}

// busca binária
int buscaB(Item v[], int n, char nome[], int *comp) {
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



// =================== LISTA ===================

// adicionar lista
No* addL(No *lista) {
    No *novo = (No*) malloc(sizeof(No));

    printf("\nNome: ");
    scanf("%s", novo->info.nome);
    printf("Tipo: ");
    scanf("%s", novo->info.tipo);
    printf("Qtd: ");
    scanf("%d", &novo->info.qtd);

    novo->prox = lista;

    printf("\nItem adicionado na lista!\n");

    return novo;
}

// mostrar lista
void mostraL(No *lista) {
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
No* remL(No *lista) {
    char nome[30];

    printf("\nNome para remover: ");
    scanf("%s", nome);

    No *p = lista;
    No *ant = NULL;

    while (p != NULL) {
        if (strcmp(p->info.nome, nome) == 0) {

            if (ant == NULL)
                lista = p->prox;
            else
                ant->prox = p->prox;

            free(p);

            printf("\nItem removido!\n");
            return lista;
        }

        ant = p;
        p = p->prox;
    }

    printf("\nNao achei.\n");
    return lista;
}



// =================== MENU ===================
int main() {
    Item vet[MAX];
    int n = 0;
    No *lista = NULL;

    int op;

    do {
        printf("\n===== Nivel Mestre (Simples) =====\n");
        printf("1 - Add Vetor\n");
        printf("2 - Remover Vetor\n");
        printf("3 - Mostrar Vetor\n");
        printf("4 - Bubble Sort\n");
        printf("5 - Selection Sort\n");
        printf("6 - Buscar Binaria\n\n");

        printf("7 - Add Lista\n");
        printf("8 - Remover Lista\n");
        printf("9 - Mostrar Lista\n");

        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if (op == 1) addV(vet, &n);
        else if (op == 2) remV(vet, &n);
        else if (op == 3) mostraV(vet, n);
        else if (op == 4) bubble(vet, n);
        else if (op == 5) selection(vet, n);
        else if (op == 6) {
            char nome[30];
            int comp = 0;
            printf("\nNome: ");
            scanf("%s", nome);

            int pos = buscaB(vet, n, nome, &comp);

            if (pos == -1) printf("\nNao achei. Comp: %d\n", comp);
            else {
                printf("\nAchei! Comp: %d\n", comp);
                printf("Nome: %s | Tipo: %s | Qtd: %d\n",
                       vet[pos].nome, vet[pos].tipo, vet[pos].qtd);
            }
        }

        else if (op == 7) lista = addL(lista);
        else if (op == 8) lista = remL(lista);
        else if (op == 9) mostraL(lista);

    } while (op != 0);

    printf("\nFinalizando...\n");

    return 0;
}
