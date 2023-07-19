#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>

typedef struct _ATRIBUTOS
{
    int habilidade, energia, sorte;
} ATRIBUTOS;

typedef struct _PERSONAGEM
{
    int vida;
    ATRIBUTOS atributo;
    char nome[40];
    int inimigo[10];
    char classe[15];
    int posicao;
    int level;

} PERSONAGEM;

int jogar_dado(int n);
PERSONAGEM dado_inicio(PERSONAGEM);
void press();
void limpar_tela();
void imprimir_menu();
PERSONAGEM ler_pagina(PERSONAGEM jogador);
void salvar_jogo(PERSONAGEM jogador1);

PERSONAGEM carregar_jogo(int *valor, PERSONAGEM);

int main()
{
    srand(time(NULL));

    setlocale(LC_ALL, "portuguese");

    PERSONAGEM jogador1;
    int i, opcao = 1, salvar, carregar, sair = 1, posicao = 0, d, dado;
    int vazio = 0;
    char comando;
    char palavra[30], temp[23];

    jogador1 = carregar_jogo(&opcao, jogador1);
    

    press();
    while (opcao)
    {
        limpar_tela();
        imprimir_menu();
        scanf("%c", &comando);
        switch (comando)
        {
        case 'A':
            printf("\nQuantos dados voce quer jogar? \n     >>> ");
            scanf("%d", &d);
            dado = jogar_dado(d);
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
            scanf("%d", &jogador1.posicao);
            ler_pagina(jogador1);

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
                    salvar_jogo(jogador1);
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
        default:
            puts("***Comando Inválido, digite qualquer tecla para tentar novamente...***");
            scanf("%s", temp);
            
            limpar_tela();
            break;
        }
    }


    printf("\n%s fechou o jogo", jogador1.nome);
    // scanf("%d", &jogador1.atributo.energia);
    // printf("\nvoce tem %d de energia", jogador1.atributo.energia);
    return 0;
}
void salvar_jogo(PERSONAGEM jogador1)
{
    FILE *gravar;

    if (gravar == NULL)
    {
        perror("\nmano deu erro\n");
    }
    gravar = fopen("gravar.dat", "wb");
    fwrite(&jogador1, sizeof(PERSONAGEM), 1, gravar);
    printf("%s salvou seu jogo", jogador1.nome);
    fclose(gravar);
}
PERSONAGEM ler_pagina(PERSONAGEM jogador)
{
    FILE *entrada, *saida;
    char c[3500];
    char texto;
    entrada = fopen("teste.txt", "r");
    saida = fopen("saida.dat", "wb");
    while(texto != '@')
    {
        fscanf(entrada, "%c", &texto);
        fwrite(&texto, sizeof(texto), 1, saida);
        printf("%c", texto);
    }
    press();

    fclose(entrada);
    fclose(saida);
}

void press()
{
    char temp[20];
    printf("\n \nPressione qualquer letra para se continuar...\n");
    scanf("%s", temp);

}
void limpar_tela()
{
    system("cls");
    fflush(stdin);
}

int jogar_dado(int n)
{
    int dado;
    dado = (rand() % 6) +1;
    printf("%d ", dado);
    if (n == 1)
        return dado;
    else
        {
        dado = 0;
        return jogar_dado(n-1);
        }
}

void imprimir_menu()
{
    printf("\n%10s %10s %10s %10s %10s %10s\n", "A - Atacar", "M - Movimentar", "O - Olhar", "I - Info", "Q = Sair", "D - Dica");
    printf("\nEscolha uma opção:\n     >>> ");
}

PERSONAGEM carregar_jogo(int *valor, PERSONAGEM jogador1)
{
    PERSONAGEM jogador2;
    int carregar, parada = 1, confirma, menu =1;
    char genero, classe;
    char temp[23];

    while(menu)
    {    
        system("cls");
        printf("\nBem Vindo ao nosso jogo!\n");

        printf("\n%10s \t %10s \t %10s \t %10s\n \n    >>> ", "{0} - Iniciar Novo Jogo", "{1} - Carregar Jogo Salvo", "{2} - Creditos", "{3} - Sair");
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
                    printf("\nA classe Guerreiro possui as seguintes vantagens iniciais:\n -> {dado} + 6 de habilidade, {2*dado} + 12 de energia e {dado} + 6 de sorte <-\n\n \n");
                    printf("Deseja selecionar a classe Guerreiro?");
                    printf("\n%s / %15s\n", "{1} - Sim", "{2} - Voltar\n");
                    scanf("%d", &confirma);
                    limpar_tela();

                    switch (confirma)
                    {
                    case 1:
                        
                        printf("Você quer ser um {guerreiro} ou uma {guerreira}?\n    >>> ");
                        fflush(stdin);
                        gets(jogador2.classe);
                        limpar_tela();
                    
                        if(strcmp(jogador2.classe, "guerreiro") == 0 || strcmp(jogador2.classe, "guerreira") == 0)
                        {
                        limpar_tela();
                        printf("%s, Você escolheu a classe: %s\n", jogador2.nome, jogador2.classe);
                        jogador2.atributo.habilidade = 6, jogador2.atributo.energia = 12, jogador2.atributo.sorte = 6;
                        jogador2 = dado_inicio(jogador2);
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
                
                    printf("\nA classe Assassino possui as seguintes vantagens iniciais:\n -> {dado} + 12 de habilidade, {2*dado} + 6 de energia e {dado} + 6 de sorte <-\n\n \n");
                    printf("Deseja selecionar a classe Assassino?");
                    printf("\n%s / %15s\n", "{1} - Sim", "{2} - Voltar\n");
                    scanf("%d", &confirma);
                    switch (confirma)
                    {
                    case 1:
                        
                        printf("Você quer ser um {assassino} ou uma {assassina}?\n    >>> ");
                        fflush(stdin);
                        gets(jogador2.classe);
                    
                        if(strcmp(jogador2.classe, "assassino") == 0 || strcmp(jogador2.classe, "assassina") == 0)
                        {
                        limpar_tela();
                        printf("%s, Você escolheu a classe: %s", jogador2.nome, jogador2.classe);
                        jogador2.atributo.habilidade = 18, jogador2.atributo.energia = 8, jogador2.atributo.sorte = 10;
                        jogador2 = dado_inicio(jogador2);
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
                    printf("\nA classe Mago possui as seguintes vantagens iniciais:\n -> {dado} + 3 de habilidade, {2*dado} + 6 de energia e {dado} + 14 de sorte <-\n\n \n");
                    printf("Deseja selecionar a classe Mago?");
                    printf("\n%s / %15s\n", "{1} - Sim", "{2} - Voltar\n");
                    scanf("%d", &confirma);
                    switch (confirma)
                    {
                    case 1:
                        
                        printf("Você quer ser um {mago} ou uma {maga}?\n    >>> ");
                        fflush(stdin);
                        gets(jogador2.classe);
                    
                        if(strcmp(jogador2.classe, "mago") == 0 || strcmp(jogador2.classe, "maga") == 0)
                        {
                        jogador2.atributo.habilidade = 4, jogador2.atributo.energia = 8, jogador2.atributo.sorte = 10;
                        limpar_tela();
                        printf("%s, Você escolheu a classe: %s", jogador2.nome, jogador2.classe);
                        jogador2 = dado_inicio(jogador2);
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
            menu = 0;
            return jogador2;
        }
        if (carregar == 1)
        {
            FILE *fp_carregar;
            fp_carregar = fopen("gravar.dat", "rb");
            if (fp_carregar == NULL)
            {
                perror("coe deu ruim");
            }
            i = 1;
            while (!feof(fp_carregar))
            {
                fread(&jogador2, sizeof(PERSONAGEM), 1, fp_carregar);
            }
            printf("\nBem Vindo de volta %s! Sua classe é %s, voce esta no level %d,", jogador2.nome, jogador2.classe, jogador2.level);
            fclose(fp_carregar);
            menu = 0;
            return jogador2;
        }
        
        if (carregar == 2)
        {
            printf("Feito por Felipe Serejo Monteiro e Rafael Ferreira Siqueira, alunos do 1 periodo de Ciencia da Computacao.");
            press();
        }

        if (carregar == 3)
        {
            *valor = 0;
            printf("%d", *valor);
            menu = 0;
        }    
    }
}

PERSONAGEM dado_inicio(PERSONAGEM jogador)
{
    int parada = 1, dados = 4, dado, i = 0, hab = jogador.atributo.habilidade, ener = jogador.atributo.energia, sor = jogador.atributo.sorte;
    char temp[20];
    while(i<3)
    {  
        dado = (rand() % 6) +1;
        printf("\n\033[1mTESTE SUA SORTE %s!\033[0m\n", jogador.nome);
        
        printf("\nDigite qualquer tecla para jogar o dado!\n");
        scanf("%s", temp);
        limpar_tela();


        if(i == 0)
        {
            
            jogador.atributo.habilidade += dado;
            printf("\nVocê tirou %d no dado, agora você tem %d de Habilidade\n", jogador.atributo.habilidade - hab, jogador.atributo.habilidade);

        }
        if(i == 1)
        {
            
            jogador.atributo.energia += (dado*2);
            printf("\nVocê tirou %d no dado, agora você tem %d de Energia\n", jogador.atributo.energia - ener, jogador.atributo.energia);

        }
        if(i == 2)
        {
            
            jogador.atributo.sorte += (dado);
            printf("\nVocê tirou %d no dado, agora você tem %d de Sorte\n", jogador.atributo.sorte - sor, jogador.atributo.sorte);

        }
        i++;
       
    }   
        
    return jogador;
}