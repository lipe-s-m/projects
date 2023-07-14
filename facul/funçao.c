#include <stdio.h>
#include <locale.h>

int eh_letramaiuscula(char letra);
int eh_letraminuscula(char letra);

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int i = 0, j, k;
    char letra;

    printf("Digite uma letra ");
    scanf("%c", &letra);

    if (eh_letramaiuscula(letra))
    {
        printf("É letra maiuscula");
    }
    else if(eh_letraminuscula(letra))
    {
        printf("É Letra minuscula");
    }

    else
    {
        printf("Não é letra");
    }

    return 0;
}

int eh_letramaiuscula(char letra)
{
    if (letra >= 'A' && letra <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int eh_letraminuscula(char letra)
{
    if (letra >= 'a' && letra <= 'z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*#include <stdio.h>
#include <locale.h>

int eh_letramaiuscula(char letra);
int eh_letraminuscula(char letra);

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int i = 0, j, k = 0;
    char vetor[50];
    int cont[50] = {0};

    printf("Digite uma letra ");
    fgets(vetor, 50, stdin);

    for(i; vetor[i] != '\0'; i++)
    {
        if(eh_letramaiuscula(vetor[i]))
        {
            printf("oi");
            cont[vetor[i] - 'A']+=1;
            k++;
        }
        else if(eh_letraminuscula(vetor[i]))
        {
            cont[vetor[i] - 'a']+=1;
            k++;
        }
    }

    for(i= 0; vetor[i] != '\0'; i++)
    {
        if(cont[i] > 0)
        {
            printf("%c --> %d\n", i + 'a', cont[i]);
        }
    }

    return 0;
}

int eh_letramaiuscula(char letra)
{
    if (letra >= 'a' && letra <= 'z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int eh_letraminuscula(char letra)
{
    if (letra >= 'A' && letra <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}*/