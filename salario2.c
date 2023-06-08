#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lerFuncionario (int *anos_de_experiencia, int *horas_trabalhadas, int *horas_contratadas, char *funcao)
{
    do
    {
        fflush(stdin);
        printf(" - Funcao: ");
        scanf("%c", funcao);
        if (*funcao != 'p' && *funcao != 'P' && *funcao != 'g' && *funcao != 'G' && *funcao != 'a' && *funcao != 'A')
            {
                printf("Erro! Valor invalido, digite um valor valido.\n");
            }
    } while (*funcao != 'p' && *funcao != 'P' && *funcao != 'g' && *funcao != 'G' && *funcao != 'a' && *funcao != 'A');

    do
    {
        printf(" - Anos de exp: ");
        scanf("%d", anos_de_experiencia);
        if(*anos_de_experiencia < 0)
            {
                printf("Erro! Valor invalido, digite um valor valido.\n");
            }
    } while (*anos_de_experiencia < 0);

    do
    {
        printf(" - Horas contratadas: ");
        scanf("%d", horas_contratadas);
        if(*horas_contratadas < 1)
            {
                printf("Erro! Valor invalido, digite um valor valido.\n");
            }
    } while (*horas_contratadas < 1);

    do
    {
        printf(" - Horas trabalhadas: ");
        scanf("%d", horas_trabalhadas);
        if (*horas_trabalhadas < 0)
        {
            printf("Erro! Valor invalido, digite um valor valido.\n");
        }
    } while (*horas_trabalhadas < 0);
}

void imprimirFolhaPagamento (int horas_excedentes, float salario_bruto_final, float salario, float valor_INSS, float valor_IR)
{
    printf(" - Salario bruto...(R$): %.2f \n", salario_bruto_final);
    if (horas_excedentes > 0)
    {
        printf(" - Horas Excedentes (h): %dhr\n", horas_excedentes);
    }
    printf(" - Desconto INSS...(R$): %.2f \n", valor_INSS);
    if (salario_bruto_final > 1500)
        {
            printf(" - Desconto IR.....(R$): %.2f \n", valor_IR);
        }
    printf(" - Salario liquido.(R$): %.2f \n", salario);
}

float calcularSalario(char funcao, int anos_de_experiencia, int horas_contratadas, int horas_trabalhadas, float *salario_bruto_final, float *valor_INSS, float *valor_IR, int *horas_excedentes)
{
   float aux, salario_bruto, salario_liquido, salario_liquido_1, desc_INSS, desc_IR, salario, salario_liquido_final;
   int horas_extras, salario_extra;



   if(horas_contratadas < horas_trabalhadas)
    {
        *horas_excedentes = horas_trabalhadas - horas_contratadas;
        if (*horas_excedentes <= 13 )
        {
            aux = 1.23;
            horas_extras = *horas_excedentes;
        }
        if (*horas_excedentes > 13 && *horas_excedentes < 23)
        {
            aux = 1.37;
            horas_extras = *horas_excedentes;
        }
        if (*horas_excedentes > 22)
        {
            aux = 1.56;
            horas_extras = *horas_excedentes;
        }
    }
    else
    {
        *horas_excedentes = 0;
        horas_extras = 0;
        aux = 0;
    }

    if(horas_trabalhadas <= horas_contratadas)
    {
        if(anos_de_experiencia < 3)
        {
            if (funcao == 'p' || funcao == 'P')
            {
                salario_bruto = horas_trabalhadas * 25;
                salario_extra = 0;
            }
            if (funcao == 'a' || funcao == 'A')
            {
                salario_bruto = horas_trabalhadas * 45;
                salario_extra = 0;
            }
            if (funcao == 'g' || funcao == 'G')
            {
                salario_bruto = horas_trabalhadas * 85;
                salario_extra = 0;
            }
        }

        if(anos_de_experiencia >= 3 && anos_de_experiencia <= 5)
        {
            if (funcao == 'p' || funcao == 'P')
            {
                salario_bruto = horas_trabalhadas * 30;
                salario_extra = 0;
            }
            if (funcao == 'a' || funcao == 'A')
            {
                salario_bruto = horas_trabalhadas * 55;
                salario_extra = 0;
            }
            if (funcao == 'g' || funcao == 'G')
            {
                salario_bruto = horas_trabalhadas * 102;
                salario_extra = 0;
            }
        }


        if(anos_de_experiencia > 5)
        {
            if (funcao == 'p' || funcao == 'P')
            {
                salario_bruto = horas_trabalhadas * 38;
                salario_extra = 0;
            }
            if (funcao == 'a' || funcao == 'A')
            {
                salario_bruto = horas_trabalhadas * 70;
                salario_extra = 0;
            }
            if (funcao == 'g' || funcao == 'G')
            {
                salario_bruto = horas_trabalhadas * 130;
                salario_extra = 0;
            }
        }
    }
    else
    {
        if(anos_de_experiencia < 3)
        {
            if (funcao == 'p' || funcao == 'P')
            {
                salario_bruto = horas_contratadas * 25;
                salario_extra = 25;
            }
            if (funcao == 'a' || funcao == 'A')
            {
                salario_bruto = horas_contratadas * 45;
                salario_extra = 45;
            }
            if (funcao == 'g' || funcao == 'G')
            {
                salario_bruto = horas_contratadas * 85;
                salario_extra = 85;
            }
        }

        if(anos_de_experiencia >= 3 && anos_de_experiencia <= 5)
        {
            if (funcao == 'p' || funcao == 'P')
            {
                salario_bruto = horas_contratadas * 30;
                salario_extra = 30;
            }
            if (funcao == 'a' || funcao == 'A')
            {
                salario_bruto = horas_contratadas * 55;
                salario_extra = 55;
            }
            if (funcao == 'g' || funcao == 'G')
            {
                salario_bruto = horas_contratadas * 102;
                salario_extra = 102;
            }
        }


        if(anos_de_experiencia > 5)
        {
            if (funcao == 'p' || funcao == 'P')
            {
                salario_bruto = horas_contratadas * 38;
                salario_extra = 38;
            }
            if (funcao == 'a' || funcao == 'A')
            {
                salario_bruto = horas_contratadas * 70;
                salario_extra = 70;
            }
            if (funcao == 'g' || funcao == 'G')
            {
                salario_bruto = horas_contratadas * 130;
                salario_extra = 130;
            }
        }
    }


    *salario_bruto_final = salario_bruto + ((salario_extra * horas_extras) * aux);

    salario_liquido = *salario_bruto_final * 0.89;

    *valor_INSS = *salario_bruto_final - salario_liquido ;

    if (salario_liquido <= 1500)
    {
        desc_IR = 1;
    }
    if (salario_liquido > 1500 && salario_liquido <= 2700)
    {
        desc_IR = 0.85;
    }
    if (salario_liquido > 2700 && salario_liquido <= 4200)
    {
        desc_IR = 0.8;
    }
    else
    {
        desc_IR = 0.7;
    }

    salario_liquido_final = salario_liquido * desc_IR;

    *valor_IR = salario_liquido - salario_liquido_final;


    return salario_liquido_final;
}

int main()
{
    int quantidade_de_funcionarios, anos_de_experiencia, horas_trabalhadas, horas_contratadas, quantidade, i, horas_excedentes;
    char funcao;
    float salario_bruto_final, valor_INSS, valor_IR, salario;

    do {
        printf("Qtd: ");
        scanf("%d", &quantidade);

        if (quantidade <= 0)
        {
            printf("ATENCAO: a quantidade de funcionarios deve ser maior que zero. Informe novamente.\n");
        }

        } while (quantidade <= 0);

    for (i = 1; i <= quantidade; i++)
    {
        printf("==============\n");
        printf("Funcionario %d\n", i);
        lerFuncionario(&anos_de_experiencia, &horas_trabalhadas, &horas_contratadas, &funcao);
        printf("Folha de Pagamento do Func. %d\n", i);
        salario = calcularSalario(funcao, anos_de_experiencia, horas_contratadas, horas_trabalhadas, &salario_bruto_final, &valor_INSS, &valor_IR, &horas_excedentes);
        imprimirFolhaPagamento(horas_excedentes, salario_bruto_final, salario, valor_INSS, valor_IR);
    }

    return EXIT_SUCCESS;
}
