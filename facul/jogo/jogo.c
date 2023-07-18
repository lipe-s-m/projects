#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>

typedef struct _ATRIBUTOS
{
    int ataque, defesa, vigor, magia;
} ATRIBUTOS;

typedef struct _PERSONAGEM
{
    int vida;
    ATRIBUTOS habilidade;
    char nome[40];
    int inimigo[10];
    char classe[15];
    int posicao[30];
    int level;

} PERSONAGEM;

void press();
void limpar_tela();
void imprimir_menu();
void ler_pagina();

PERSONAGEM carregar_jogo(int *valor, PERSONAGEM);

int main()
{
    setlocale(LC_ALL, "portuguese");

    PERSONAGEM jogador1;
    int i, opcao = 1, salvar, carregar, sair = 1, posicao = 0;
    int vazio = 0;
    char comando;
    char palavra[30], temp[23];

    jogador1 = carregar_jogo(&opcao, jogador1);
    FILE *gravar;
    gravar = fopen("gravar.txt", "w");

    if (gravar == NULL)
    {
        printf("\nmano deu erro\n");
    }

    press();
    while (opcao)
    {
        limpar_tela();
        imprimir_menu();
        scanf("%c", &comando);
        switch (comando)
        {
        case 'A':
            printf("\nVocê atacou, %s deu %d de dano, (so pra mostrar a classe: %s)", jogador1.nome, jogador1.habilidade.ataque, jogador1.classe);
            press();

            break;
        case 'I':
            printf("%s está no level %d, classe %s", jogador1.nome, jogador1.level, jogador1.classe);
            press();
            break;
        case 'O':
            puts("Ta olhando oq doidao?");
            press();
            break;

        case 'D':
            printf("%s, Digite em MAIUSCULO as letras correspondentes as que estao no menu", jogador1.nome);
            press();
            break;
        case 'M':
            printf("\n%s, Para onde voce deseja ir?\n     >>> ", jogador1.nome);
            scanf("%d", posicao);

            break;
        case 'Q':
            while(sair)
            {
            printf("\n%s %15s %15s\n", "0 - NAO", "1 - SIM", "2 - VOLTAR");
            printf("Deseja Salvar seu progresso? \n    >>> ");
            scanf("%d", &salvar);
            switch (salvar)
            {
            case 0:
                if (salvar == 0)
                {
                    opcao = 0;
                    

                }
                sair = 0;
                break;
            case 1:
                if (salvar == 1)
                {
                    printf("%s salvou seu jogo", jogador1.nome);

                    fprintf(gravar, "%s %s %d", jogador1.nome, jogador1.classe, jogador1.level);

                    opcao = 0;
                }
                sair = 0;
                break;

            case 2:
                break;
            default:
                puts("***Comando Inválido, digite qualquer tecla para tentar novamente...***");
                scanf("%s", temp);
                sair = 1;
                limpar_tela();
                break;
            }
            }
            break;
        }
    }

    fclose(gravar);

    printf("\n%s fechou o jogo", jogador1.nome);
    // scanf("%d", &jogador1.habilidade.defesa);
    // printf("\nvoce tem %d de defesa", jogador1.habilidade.defesa);
    return 0;
}
void ler_pagina()
{
    
}

void press()
{
    int temp;
    printf("\n \nPressione qualquer letra para se continuar...\n");
    scanf("%d", &temp);
}
void limpar_tela()
{
    system("cls");
    fflush(stdin);
}
void imprimir_menu()
{
    printf("\n%10s %10s %10s %10s %10s %10s\n", "A - Atacar", "M - Movimentar", "O - Olhar", "I - Info", "Q = Sair", "D - Dica");
    printf("\nEscolha uma opção:\n     >>> ");
}

PERSONAGEM carregar_jogo(int *valor, PERSONAGEM jogador1)
{
    PERSONAGEM jogador2;
    int carregar, parada = 1, confirma;
    char genero, classe;
    char temp[23];

    system("cls");
    printf("\nBem Vindo ao nosso jogo!\n");

    printf("\n%10s / %10s / %10s\n \n    >>> ", "(0) - Iniciar Novo Jogo", "{1} - Carregar Jogo Salvo", "2 - Sair");
    scanf("%d", &carregar);

    int i;
    if (carregar == 0)
    {
        printf("Insira seu nome: ");
        scanf("%s", jogador2.nome);
        system("cls");
        jogador2.level = 1;

        while (parada)
        {
            system("cls");
            printf("Escolha uma classe: ");
            printf("\n%s %15s %15s\n", "1 - Guerreiro", "2 - Assassino", "3 - Mago");
            fflush(stdin);
            scanf("%c", &classe);
            switch (classe)
            {
            case '1':
                printf("\nA classe Guerreiro tem 12 de ataque, 12 de defesa, 12 de vigor, 0 de magia\n\n");
                printf("Deseja selecionar a classe Guerreiro?");
                printf("\n%s / %15s\n", "{1} - Sim", "{2} - Voltar\n");
                scanf("%d", &confirma);
                switch (confirma)
                {
                case 1:
                    
                    jogador2.habilidade.ataque = 12, jogador2.habilidade.defesa = 12, jogador2.habilidade.vigor = 0, jogador2.habilidade.magia = 12;
                    printf("Você quer ser um {guerreiro} ou uma {guerreira}?\n    >>> ");
                    fflush(stdin);
                    gets(jogador2.classe);
                
                    if(strcmp(jogador2.classe, "guerreiro") == 0 || strcmp(jogador2.classe, "guerreira") == 0)
                    {
                    printf("%s, Você escolheu a classe: %s", jogador2.nome, jogador2.classe);
                    parada = 0;
                    }
                    else
                    {
                        puts("***Comando Inválido, digite qualquer tecla para tentar novamente...***");
                        scanf("%s", temp);
                    }
                    break;
                case 2:
                    break;
                default:
                    puts("***Comando Inválido, digite qualquer tecla para tentar novamente...***");
                    scanf("%s", temp);
                    break;
                }
                break;    
            case '2':
            
                printf("\nA classe Assassino tem 18 de ataque, 8 de defesa, 10 de vigor, 0 de magia\n\n");
                printf("Deseja selecionar a classe Assassino?");
                printf("\n%s / %15s\n", "{1} - Sim", "{2} - Voltar\n");
                scanf("%d", &confirma);
                switch (confirma)
                {
                case 1:
                    
                    jogador2.habilidade.ataque = 18, jogador2.habilidade.defesa = 8, jogador2.habilidade.vigor = 10, jogador2.habilidade.magia = 0;
                    printf("Você quer ser um {assassino} ou uma {assassina}?\n    >>> ");
                    fflush(stdin);
                    gets(jogador2.classe);
                
                    if(strcmp(jogador2.classe, "assassino") == 0 || strcmp(jogador2.classe, "assassina") == 0)
                    {
                    printf("%s, Você escolheu a classe: %s", jogador2.nome, jogador2.classe);
                    parada = 0;
                    }
                    else
                    {
                        puts("***Comando Inválido, digite qualquer tecla para tentar novamente...***");
                        scanf("%s", temp);
                    }
                    break;
                case 2:
                    break;
                default:
                    printf("***Comando Inválido, tente novamente...***");
                    break;
                }
                break;    
            case '3':
                printf("\nA classe Mago tem 4 de ataque, 8 de defesa, 10 de vigor, 14 de magia\n");
                printf("Deseja selecionar a classe Mago?");
                printf("\n%s / %15s\n", "{1} - Sim", "{2} - Voltar\n");
                scanf("%d", &confirma);
                switch (confirma)
                {
                case 1:
                    
                    jogador2.habilidade.ataque = 4, jogador2.habilidade.defesa = 8, jogador2.habilidade.vigor = 10, jogador2.habilidade.magia = 14;
                    printf("Você quer ser um {mago} ou uma {maga}?\n    >>> ");
                    fflush(stdin);
                    gets(jogador2.classe);
                
                    if(strcmp(jogador2.classe, "mago") == 0 || strcmp(jogador2.classe, "maga") == 0)
                    {
                    printf("%s, Você escolheu a classe: %s", jogador2.nome, jogador2.classe);
                    parada = 0;
                    }
                    else
                    {
                        puts("***Comando Inválido, digite qualquer tecla para tentar novamente...***");
                        scanf("%s", temp);
                    }
                    break;
                case 2:
                    break;
                default:
                    printf("***Comando Inválido, tente novamente...***");
                    break;
                }
                break;    
                default:
                    
                    puts("***Comando Inválido, digite qualquer tecla para tentar novamente...***");
                    scanf("%s", temp);
                   
                    break;
            }
        }
        return jogador2;
    }
    if (carregar == 1)
    {
        char texto[200];
        char nome[40];
        int vida;
        FILE *fp_carregar;
        fp_carregar = fopen("gravar.txt", "r+");
        if (fp_carregar == NULL)
        {
            printf("coe deu ruim");
        }
        i = 1;
        while (!feof(fp_carregar))
        {
            fscanf(fp_carregar, "%s %s %d", jogador2.nome, jogador2.classe, jogador2.level);
        }
        printf("\nBem Vindo de volta %s! Sua classe é %s, voce esta no level %d,", jogador2.nome, jogador2.classe, jogador2.level);

        fclose(fp_carregar);
        return jogador2;
    }
    if (carregar == 2)
    {
        *valor = 0;
        printf("%d", *valor);
    }
}
