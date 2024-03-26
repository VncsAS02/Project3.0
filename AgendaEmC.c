#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contato {
    char nome[50];
    char telefone[20];
    char email[50];
    char estado[20];
    char cor_favorita[20];
    char apelido[20];
    char estado_civil[20];
};

struct contato agenda[100];

void AdicionarContato() {
    static int QuantContatos = 0;
    if (QuantContatos == 100) {
        printf("Agenda cheia. Nao foi possivel adicionar o contato !!!\n");
        return;
    }
    struct contato NovoContato;
    printf("Nome: ");
    scanf("%s", NovoContato.nome);
    printf("Telefone: ");
    scanf("%s", NovoContato.telefone);
    printf("Email: ");
    scanf("%s", NovoContato.email);
    printf("Estado: ");
    scanf("%s", NovoContato.estado);
    printf("Cor favorita: ");
    scanf("%s", NovoContato.cor_favorita);
    printf("Apelido: ");
    scanf("%s", NovoContato.apelido);
    printf("Estado civil: ");
    scanf("%s", NovoContato.estado_civil);
    agenda[QuantContatos++] = NovoContato;
    printf("Contato adicionado com sucesso.\n");
}


void BuscarContato() {
    char NomeBusca[75];
    printf("Nome do contato: ");
    scanf("%s", NomeBusca);
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(NomeBusca, agenda[i].nome) == 0) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Email: %s\n", agenda[i].email);
            printf("Estado: %s\n", agenda[i].estado);
            printf("Cor favorita: %s\n", agenda[i].cor_favorita);
            printf("Apelido: %s\n", agenda[i].apelido);
            printf("Estado civil: %s\n", agenda[i].estado_civil);
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}

void RemoverContato() {
    char NomeBusca[50];
    printf("Nome do contato: ");
    scanf("%s", NomeBusca);
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(NomeBusca, agenda[i].nome) == 0) {
            printf("Tem certeza que deseja remover o contato '%s'? Digite (r) para remover ou (c) para cancelar ", NomeBusca);
            char resposta;
            scanf(" %c", &resposta);
            if (resposta == 'r' || resposta == 'R') {
                int j;
                for (j = i; j < 99; j++) {
                    agenda[j] = agenda[j+1];
                }
                printf("Contato removido com sucesso.\n");
                return;
            } else {
                printf("Acao cancelada pelo usuario.\n");
                return;
            }
        }
    }
    printf("Contato nao encontrado.\n");
}

void MostrarAgenda() {
    int i;
    for (i = 0; i < 100; i++) {
        if (strlen(agenda[i].nome) > 0) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Email: %s\n", agenda[i].email);
            printf("Estado: %s\n", agenda[i].estado);
            printf("Cor favorita: %s\n", agenda[i].cor_favorita);
            printf("Apelido: %s\n", agenda[i].apelido);
            printf("Estado civil: %s\n", agenda[i].estado_civil);
            printf("\n");
        }
    }
}


int main() {
    int opcao;
    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Buscar contato\n");
        printf("3 - Remover contato\n");
        printf("4 - Mostrar contatos\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                AdicionarContato();
                break;
            case 2:
                BuscarContato();
                break;
            case 3:
                RemoverContato();
                break;
                
            case 4:
				MostrarAgenda();
				break;

            case 0:
                printf("Ate a proxima.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);
    return 0;
}




