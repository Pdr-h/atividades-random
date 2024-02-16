#include <stdio.h>
#include <string.h>
#include <locale.h>

struct PRODUTO
{
    char nome[500], resultado[200];
    int vendas[3];
    float vmd;
    float Total, emin, tempo, emax, ea, lote;
};

void adicionarProduto(struct PRODUTO produtos[], int qnt)
{
    int i;
    printf("\nDigite o nome do produto %d:\n", qnt + 1);
    gets(produtos[qnt].nome);
    for (i = 0; i < 3; i++)
    {
        printf("Total de vendas no %dº mes:", i + 1);
        scanf("%i", &produtos[qnt].vendas[i]);
        produtos[qnt].Total += produtos[qnt].vendas[i];
    }

    // perguntas
    printf("Tempo de reposição:\n");
    scanf("%f", &produtos[qnt].tempo);

    printf("Lote de reposição:\n");
    scanf("%f", &produtos[qnt].lote);

    printf("Estoque atual:\n");
    scanf("%f", &produtos[qnt].ea);

    // calculos
    produtos[qnt].vmd = ((float)produtos[qnt].Total) / 3 / 25;    // venda media diaria
    produtos[qnt].emin = produtos[qnt].tempo * produtos[qnt].vmd; // estoque min
    produtos[qnt].emax = produtos[qnt].lote + produtos[qnt].emin; // estoque max

    // resultados
    printf("Venda media diaria: %.1f\n", produtos[qnt].vmd);
    printf("Estoque Mínimo = %.1f\n", produtos[qnt].emin);
    printf("Estoque Máximo = %.1f\n", produtos[qnt].emax);

    if (produtos[qnt].ea < produtos[qnt].emin)
    {
        printf("COMPRAR");
        strcpy(produtos[qnt].resultado, "COMPRAR\n\n");
    }
    else
    {
        printf("NÃO COMPRAR\n\n");
        strcpy(produtos[qnt].resultado, "NÃO COMPRAR");
    };
}

int main()
{   
    setlocale(LC_ALL, "portuguese");
    struct PRODUTO produtos[4];
    int escolha, qnt = 0, i, j;
    adicionarProduto(produtos, qnt);
    qnt++;
    printf("Continuar adicionando?\n\n[1] - Sim\n[2] - Nao\n");
    scanf("%d", &escolha);
    fflush(stdin);
    while (escolha == 1 && qnt < 4)
    {
        adicionarProduto(produtos, qnt);

        if (qnt < 3)
        {
            printf("\nContinuar adicionando?\n\n[1] - Sim\n[2] - Não\n");
            scanf("%d", &escolha);
            fflush(stdin);

            if (escolha == 1)
            {
                qnt++;
            }
        }
        else
        {
            printf("Limite de produtos atingido.\n");
            escolha = 2;
            for ( i = 0; i < 4; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    printf("Nome do produto %d: %s", i, produtos[i].nome);
                    printf("Venda média diária: %.1f", produtos[i].vmd);
                    printf("Estoque mínimo: %.1f", produtos[i].emin);
                    printf("Estoque máximo: %.1f", produtos[i].emax);
                    printf("Tomada de Decisão: %s", produtos[i].resultado);
                }   
            }
        }
    }

    return 0;
}
