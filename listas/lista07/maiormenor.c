#include <stdio.h>

int main()
{
    int n = 0, j = 0;
    int vetor[1000];
    int maior = 0;
    int menor = 1000;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
        if(vetor[i] > maior)
        {
            maior = vetor[i];
        }
        if(vetor[i] < menor)
        {
            menor = vetor[i];
            j = i;
        }
    }
    printf("\nMenor valor: %d \nPosicao: %d", menor, j);
    return 0;
}
