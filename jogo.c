#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void capitalize(char str1[], char str2[]);
unsigned short int strings_iguais(char str1[], char str2[]);
int credito(int menu1);
void atributo();


int main()
{

    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int i = 0, d6 = 0, d12 = 0, d20 = 0, menu = 0, sexo = 0, nome_classe = 0;
    int person = 0, classe = 0, forca = 8, magia = 8, destreza = 8, vigor = 8, inteligencia = 8, sorte = 8, carisma = 8, points = 0, xp = 0;
    int atributos[8] = {8};
    char nome[100], nome2 = 0, nome3 = 0;

    srand(time(NULL));
    d6 = rand() % 6 + 1;
    d12 = rand() % 12 + 1;
    d20 = rand() % 20 + 1;

    printf("\n-------------------------------");
    printf("\n*****Bem Vindo ao Jogo!***** \n \n");
    printf("Digite 1 para Iniciar um Novo Jogo \nDigite 2 para Carregar um Jogo Salvo \nDigite 3 para ver os Créditos \nDigite 4 para Sair \n\n    >>> ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        system("cls");
        printf("-------------------------------\nVocê iniciou um Novo Jogo!\nInsira seu Nick\n    >>> ");
        fflush(stdin);
        gets(nome);
        nome[i - 1] = '\0';
        capitalize(nome, nome);

        printf("\n \n\nDigite 1 para Homem / Digite 2 para Mulher\n\n    >>> ");
        scanf("%d", &sexo);
        if (sexo != 1 || sexo != 2)
        {
            while (sexo != 1 && sexo != 2)
            {
                printf("\n***Comando Inválido***");
                printf("\n \nDigite 1 para Homem / Digite 2 para Mulher\n\n    >>> ");
                scanf("%d", &sexo);
            }
        }

        if (sexo == 1)
            printf("\nBem Vindo ao Jogo, %s!!!\n\n", nome);
        else if (sexo == 2)
            printf("\nBem Vinda ao Jogo, %s!!!\n\n", nome);

        system("pause");
        system("cls");

        printf("\n\nEscolha sua classe, %s!\n1 - Guerreiro / 2 - Assassino / 3 - Mago\n    >>> ", nome);
        fflush(stdin);

        scanf("%d", &nome_classe);
        switch (nome_classe)
        {
        case (1):;
            switch (sexo)
            {
            case (1):;
                char classman[20] = "Guerreiro";
                printf("\nVocê é um %s\n", classman);
                break;
            case (2):;
                char classwoman[20] = "Guerreira";
                printf("\nVocê é uma %s\n", classwoman);
                break;
            }
            points = 0;
            vigor = 15;
            forca = 15;
            destreza = 8;
            inteligencia = 8;
            magia = 8;
            carisma = 12;
            sorte = 8;
            atributo();

            break;

        case (2):
            switch (sexo)
            {
            case (1):;
                char classman[20] = "Assassino";
                printf("\nVocê é um %s\n", classman);
                break;
            case (2):;
                char classwoman[20] = "Assassina";
                printf("\nVocê é uma %s\n", classwoman);
                break;
            }
            points = 0;
            forca = 10;
            destreza = 14;
            magia = 8;
            vigor = 10;
            inteligencia = 11;
            carisma = 8;
            sorte = 14;
            break;
        case (3):
            switch (sexo)
            {
            case (1):;
                char classman[20] = "Mago";
                printf("\nVocê é um %s\n", classman);
                break;
            case (2):;
                char classwoman[20] = "Maga";
                printf("\nVocê é uma %s\n", classwoman);
                break;
            }
            points = 0;
            forca = 8;
            destreza = 10;
            magia = 15;
            vigor = 8;
            inteligencia = 14;
            carisma = 9;
            sorte = 10;
            puts("https://imgur.com/EQQRMSR");
            break;
        }
        printf("\n\n%d %d %d\n", forca, vigor, magia);
        printf("%s", atributos);
        break;
    case (3):
        system("cls");
        credito(menu);
        break;

    default:
        break;
    }

    system("pause");
    return 0;
}

void atributo()
{
   printf("oi");
    
}
int credito(int menu1){
    printf("\n-------------------------------\nVocê Selecionou a opção Créditos!\n\n");
    printf("Feito por Felipe Serejo Monteiro, aluno do 1º período de Ciências da Computação \nda UFRRJ de Nova Iguaçu, no ano de 2023.\n");
    puts("\n");
    return 0;
}
void capitalize(char str1[], char str2[])
{
    int i = 0;
    str2 = str1;
    for (i; str2[i] != '\0'; i++)
    {
        str2[i] = tolower(str2[i]);
    }

    for (i = 0; str2[i] != '\0'; i++)
    {
        if (str2[i] == ' ')
        {
            str2[i + 1] = toupper(str2[i + 1]);
        }
    }
    str2[0] = toupper(str2[0]);
    str2[i] = '\0';
}

