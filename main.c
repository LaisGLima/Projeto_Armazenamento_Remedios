#include <stdio.h>
#include <string.h>

#define formatBool(b) ((b) ? "true" : "false")
#define MAX_MEDICAMENTOS 100

typedef enum { false, true } bool;

struct Remedio {
    int id;
    char nome[50];
    char fabricante[50];
    float preco;
    bool receita;
    int quantidade;
};

struct Remedio medicamentos[MAX_MEDICAMENTOS];
int totalMedicamentos = 0;

int main() {
    struct Remedio remedio;
    int opcao1 = 1;
    int opcao2 = 1;
    int id;

    while (opcao1 != 0) {
        printf("\n\nSelecione uma opção:\n");
        printf("1 - Cadastrar novo remédio\n");
        printf("2 - Pesquisar remédio por ID\n");
        printf("3 - Alterar remédio por ID\n");
        printf("4 - Remover remédio por ID\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao1);


        switch (opcao1) {
            
            case 1:
            
                if (totalMedicamentos == MAX_MEDICAMENTOS) {
                    printf("Limite de medicamentos atingido.\n");
                    
                    break;
                }

                printf("Digite o ID do remédio: ");
                scanf("%d", &remedio.id);

                printf("Digite o nome do remédio: ");
                scanf(" %[^\n]", remedio.nome);

                printf("Digite o nome do fabricante: ");
                scanf(" %[^\n]", remedio.fabricante);

                printf("Digite o preco: ");
                scanf("%f", &remedio.preco);

                printf("Digite a quantidade: ");
                scanf("%d", &remedio.quantidade);

                printf("Necessita de receita?\n");
                printf("1 - Sim\n");
                printf("2 - Nao\n");
                scanf("%d", &opcao2);

                remedio.receita = (opcao2 == 1) ? true : false;

                medicamentos[totalMedicamentos++] = remedio;

                printf("\nRemédio cadastrado com sucesso!\n");
                
                break;


            case 2:
                if (totalMedicamentos == 0) {
                    printf("Nenhum remédio cadastrado.\n");
                    
                break;
                }

                printf("Digite o ID do remédio a ser pesquisado: ");
                scanf("%d", &id);

                for (int i = 0; i < totalMedicamentos; i++) {
                    
                    if (medicamentos[i].id == id) {
                        printf("\nREMÉDIO ENCONTRADO:\n");
                        printf("ID: %d\n", medicamentos[i].id);
                        printf("Nome: %s\n", medicamentos[i].nome);
                        printf("Fabricante: %s\n", medicamentos[i].fabricante);
                        printf("Preco: R$%.2f\n", medicamentos[i].preco);
                        printf("Quantidade: %d\n", medicamentos[i].quantidade);
                        printf("Receita: %s\n", formatBool(medicamentos[i].receita));
                        
                    break;
                    }
                    else{
                        printf("Remédio não encontrado.\n");
                    }
                }
                break;
                
                
            case 3:
                if (totalMedicamentos == 0) {
                    printf("Nenhum remédio cadastrado.\n");
                    
                break;
                }

                printf("Digite o ID do remédio a ser alterado: ");
                scanf("%d", &id);

                int alterar = 0;

                for (int i = 0; i < totalMedicamentos; i++) {
                    if (medicamentos[i].id == id) {
                        alterar = 1;
                        printf("Digite o novo id: ");
                        scanf("%d", &medicamentos[i].id);
                        
                        printf("Digite o novo nome do remédio: ");
                        scanf(" %[^\n]", medicamentos[i].nome);

                        printf("Digite o novo nome do fabricante: ");
                        scanf(" %[^\n]", medicamentos[i].fabricante);

                        printf("Digite o novo preco: ");
                        scanf("%f", &medicamentos[i].preco);

                        printf("Digite a nova quantidade: ");
                        scanf("%d", &medicamentos[i].quantidade);

                        printf("Necessita de receita?\n");
                        printf("1 - Sim\n");
                        printf("2 - Nao\n");
                        scanf("%d", &opcao2);
                        
                        medicamentos[i].receita = (opcao2 == 1) ? true : false;
                        printf("Remédio alterado com sucesso!\n");
                        
                    break;
                    }
                }
                if (!alterar) {
                    printf("Remédio não encontrado.\n");
                }
                break;
                
                
            case 4:
                if (totalMedicamentos == 0) {
                    printf("Nenhum remédio cadastrado.\n");
                    break;
                }
                printf("Digite o ID do remédio a ser removido: ");
                scanf("%d", &id);
                int remover = 0;
                for (int i = 0; i < totalMedicamentos; i++) {
                    if (medicamentos[i].id == id) {
                        remover = 1;
                        for (int j = i; j < totalMedicamentos - 1; j++) {
                            medicamentos[j] = medicamentos[j + 1];
                        }
                        totalMedicamentos--;
                        printf("Remédio removido com sucesso!\n");
                        break;
                    }
                }
                if (!remover) {
                    printf("Remédio não encontrado.\n");
                }
                break;


            case 0:
                printf("Saindo...\n");
                break;


            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
    return 0;
}
