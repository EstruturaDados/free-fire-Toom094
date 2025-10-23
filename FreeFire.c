#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Item, que armazena informações sobre cada objeto
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor de structs para armazenar os itens na mochila. Capacidade maxima de 10 itens.
Item mochila[10];

// Variavel global para rastrear o numero atual de itens na mochila.
int numItens = 0;

// Funcao para inserir um novo item na mochila.
void inserirItem() {
    if (numItens >= 10) {
        printf("\nSua mochila esta cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    printf("\n--- Cadastrar Novo Item ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", mochila[numItens].nome);

    printf("Tipo (ex: arma, municao, cura): ");
    scanf(" %[^\n]", mochila[numItens].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[numItens].quantidade);

    numItens++; // Incrementa o contador de itens
    printf("\nItem adicionado com sucesso!\n");
}

// Funcao para remover um item da mochila pelo nome.
void removerItem() {
    if (numItens == 0) {
        printf("\nSua mochila esta vazia! Nao ha itens para remover.\n");
        return;
    }

    char nomeBusca[30];
    printf("\n--- Remover Item ---\n");
    printf("Digite o nome do item a ser removido: ");
    scanf(" %[^\n]", nomeBusca);

    int i, encontrado = 0;
    // Loop para buscar o item no vetor de structs
    for (i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = 1;
            // Desloca os itens subsequentes para preencher o espaco vazio
            for (int j = i; j < numItens - 1; j++) {
                mochila[j] = mochila[j+1];
            }
            numItens--; // Decrementa o contador de itens
            printf("\nItem '%s' removido com sucesso!\n", nomeBusca);
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem '%s' nao encontrado na mochila.\n", nomeBusca);
    }
}

// Funcao para listar todos os itens atualmente na mochila.
void listarItens() {
    if (numItens == 0) {
        printf("\nSua mochila esta vazia.\n");
        return;
    }

    printf("\n--- Itens na Mochila (%d de 10) ---\n", numItens);
    // Loop para percorrer o array e exibir os dados de cada item
    for (int i = 0; i < numItens; i++) {
        printf("----------------------------------\n");
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
    printf("----------------------------------\n");
}

// Funcao de busca sequencial para localizar um item pelo nome.
void buscarItem() {
    if (numItens == 0) {
        printf("\nSua mochila esta vazia! Nao ha itens para buscar.\n");
        return;
    }

    char nomeBusca[30];
    printf("\n--- Buscar Item ---\n");
    printf("Digite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nomeBusca);

    int i, encontrado = 0;
    // Loop de busca sequencial
    for (i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = 1;
            printf("\n--- Item Encontrado ---\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            break; // Sai do loop assim que encontra o item
        }
    }

    if (!encontrado) {
        printf("\nItem '%s' nao encontrado na mochila.\n", nomeBusca);
    }
}

// Funcao principal do programa, que gerencia o menu e a execucao.
int main() {
    int opcao;

    do {
        printf("\n=== Menu da Mochila ===\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar todos os itens\n");
        printf("4. Buscar item por nome\n");
        printf("0. Sair do jogo\n");
        printf("----------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserirItem();
                listarItens(); // Chama a função para listar após a adição
                break;
            case 2:
                removerItem();
                listarItens(); // Chama a função para listar após a remoção
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf("\nSaindo do jogo... Ate a proxima!\n");
                break;
            default:
                printf("\nOpcao invalida. Por favor, tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}