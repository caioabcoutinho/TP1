#include<stdio.h>
#include<string.h>

int main()
{
    int vezesjogadas, resultados;
    int resultados_cara=0, resultados_coroa=0;

    do{
        resultados_cara = 0;
        resultados_coroa = 0;
    scanf("%d", &vezesjogadas);



            if (vezesjogadas < 0 || vezesjogadas > 10000)
            {
                do
                {
                    printf("Erro! Digite uma quantidade de jogos valida.\n");
                    scanf("%d", &vezesjogadas);
                } while(vezesjogadas > 10000 || vezesjogadas < 1);


            }



            for (int i = 0; i < vezesjogadas; i++)
            {
                scanf("%d", &resultados);
                    if (resultados < 0 || resultados > 1)
                    {
                        printf("!Erro!");
                        break;
                    }
                    else{
                        if (resultados == 0 )
                        {
                            resultados_cara++;
                        }

                        else
                        {
                            resultados_coroa++;
                        }
                    }

            }
            if (vezesjogadas > 0)
            {
                printf("Maria venceu %d vez(es) e Joao venceu %d vez(es).\n", resultados_cara, resultados_coroa);
            }
        }while (vezesjogadas > 0);

    return 0;
}
