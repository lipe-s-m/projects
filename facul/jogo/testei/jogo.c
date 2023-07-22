#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <ctype.h>

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
    char posicao[20];
    int itens[10];

} PERSONAGEM;

int jogar_dado(int n);
PERSONAGEM dado_inicio(PERSONAGEM);
void press();
void limpar_tela();
void imprimir_menu();
PERSONAGEM ler_pagina(char *page, PERSONAGEM jogador1);
void salvar_jogo(PERSONAGEM jogador1);
PERSONAGEM compare(char *page, PERSONAGEM jogador1);
PERSONAGEM combate(char *page, PERSONAGEM jogador1);
PERSONAGEM final(char *page, PERSONAGEM jogador1);
PERSONAGEM morte(char *page, PERSONAGEM jogador1);


PERSONAGEM carregar_jogo(int *valor, PERSONAGEM);

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    PERSONAGEM jogador1;
    int i, opcao = 1, salvar, carregar, sair = 1, posicao = 0, d, dado = 1;
    int vazio = 0;
    char comando;
    char palavra[30], temp[23], lugar[20];
    limpar_tela();
    jogador1 = carregar_jogo(&opcao, jogador1);
    press();
    while (opcao)
    {
        limpar_tela();
        imprimir_menu();
        scanf("%c", &comando);
        comando = toupper(comando);
        switch (comando)
        {
        case 'A':
        
            jogar_dado(d);
            printf("%s", jogador1.posicao);
            press();

            break;
        case 'I':
            printf("%s, voce tem %d vidas, classe %s", jogador1.nome, jogador1.vida, jogador1.classe);
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
            jogador1 = ler_pagina(lugar, jogador1);
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
                sair = 0;
                break;
            default:
                puts("***Comando Inv�lido, digite qualquer tecla para tentar novamente...***");
                scanf("%s", temp);
                sair = 1;
                limpar_tela();
                break;
            }
            }
            break;
        default:
            puts("***Comando Inv�lido, digite qualquer tecla para tentar novamente...***");
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
PERSONAGEM ler_pagina(char *page, PERSONAGEM jogador1)
{
    FILE *entrada, *ir;
    char p[20], c;
    char *u;
    char inicio[5] = "0000";
    if(strcmp(jogador1.posicao, inicio) == 0)
    {
        entrada = fopen("1001.txt", "r");
        if(entrada == NULL)
        {
            perror("Caminho Inv�lido");
            return ler_pagina(page, jogador1);
        }
        while(!feof(entrada))
        {
            fscanf(entrada, "%c", &c);
            if(c != '$')
                printf("%c", c);        
        }
        printf("\nDigite 'sair' para voltar ao menu de op��es\n");
        fclose(entrada);
    }
    strcpy(jogador1.posicao, page);
    printf("\nPara onde voce deseja ir, %s?\n     >>> ", jogador1.nome);
    scanf("%s", page);
    
    // jogador1 = compare(page, jogador1);
    // jogador1 = combate(page, jogador1);
    if(strcmp(page, "10") == 0 || strcmp(page, "11") == 0)
        final(page, jogador1);
    if(strcmp(page, "278") == 0)
        morte(page, jogador1);

    limpar_tela();
    char arquivo[20];
    char txt[8] = "001.txt";
    if(strcmp(page, "sair") == 0) 
    {
        return jogador1;
    }
    strcat(page, txt);
    entrada = fopen(page, "r");
    // ir = fopen()
    if(entrada == NULL)
    {
        printf("Caminho Inv�lido");
        return ler_pagina(page, jogador1);
    }
    while(!feof(entrada))
    {
            fscanf(entrada, "%c", &c);
            if(c != '$')
                printf("%c", c);        
    }
    printf("\nDigite 'sair' para voltar ao menu de op��es\n");
    fclose(entrada);
                
    return ler_pagina(page, jogador1);
}
PERSONAGEM final(char *page, PERSONAGEM jogador1)
{
    FILE *entrada;
    char txt[9] = "001.txt", c;
    int opcao = 0;
    limpar_tela();
    if(strcmp(page, "10") == 0 || strcmp(page, "11") == 0)
    {
        strcat(page, txt);
        entrada = fopen(page, "r");
        if(entrada == NULL)
        {
            printf("Caminho Inv�lido");
            return final(page, jogador1);
        }
        while(!feof(entrada))
        {
                fscanf(entrada, "%c", &c);
                if(c != '$')
                    printf("%c", c);        
        }
        printf("\n");
        printf("\nPara onde voce deseja ir, %s?\n     >>> ", jogador1.nome);
        scanf("%s", page);
        fclose(entrada);
        return final(page, jogador1);
    }
        if(strcmp(page, "12") == 0)
        {
            strcat(page, txt);
            entrada = fopen(page, "r");
            if(entrada == NULL)
            {
                printf("Caminho Inv�lido");
                return final(page, jogador1);
            }
            while(!feof(entrada))
            {
                    fscanf(entrada, "%c", &c);
                    if(c != '$')
                        printf("%c", c);        
            }
            printf("\n%s, Voce acaba de se tornar mais um desses ossos, ao ser jogado, voce sente seus ossos quebrarem,\nseu destino agora, eh viver o resto de sua vida miseravel ao lado desses ossos secos...", jogador1.nome);
            press();
            fclose(entrada);
            return morte(page, jogador1);
        }
    else
    {
        return ler_pagina(page, jogador1);
        }
}
PERSONAGEM morte(char *page, PERSONAGEM jogador1)
{
    FILE *morreu, *entrada;
    char c, txt[8] = "001.txt";
    int opcao = 1;
    morreu = fopen("morte.txt", "r");
    if(morreu == NULL)
    {
        printf("Voce morreu!");
        return ler_pagina(page, jogador1);
    }
    if(strcmp(page, "278") == 0)
    {
        strcat(page, txt);
        entrada = fopen(page, "r");
        if(entrada == NULL)
        {
            printf("Caminho Inv�lido");
            return final(page, jogador1);
        }
        while(!feof(entrada))
        {
                fscanf(entrada, "%c", &c);
                if(c != '$')
                    printf("%c", c);        
        }

        press();
        
        return ler_pagina(page, jogador1);
    }
    
    if(strcmp(page, "12001.txt") == 0)
    {
        while(!feof(morreu))
        {
            fscanf(morreu, "%c", &c);
            printf("%c", c);
        }
        fclose(morreu);
        press();
        limpar_tela();
        printf("Voce escolheu um pessimo caminho, reveja suas atitudes %s, talvez voce devesse recomecar tudo denovo... \n", jogador1.nome);
        press();
        FILE *gameover, *reset;
        gameover = fopen("gameover.txt", "r");
        while(!feof(gameover))
        {
            fscanf(gameover, "%c", &c);
            printf("%c", c);
        }
        fclose(gameover);
        press();
        limpar_tela();
        remove("gravar.dat");
        return carregar_jogo(&opcao, jogador1);
    }

}

PERSONAGEM compare(char *page, PERSONAGEM jogador1)
{
    if(strcmp(page, "242") == 0 || strcmp(page, "371") || strcmp(page, "221") || strcmp(page, "") || strcmp(page, "") || strcmp(page, "") || strcmp(page, "") || strcmp(page, "") || strcmp(page, "") || strcmp(page, "") || strcmp(page, ""))
    {

    }
}
PERSONAGEM combate(char *page, PERSONAGEM jogador1)
{
    if(strcmp(page, "240") == 0 || strcmp(page, "116") || strcmp(page, "338") || strcmp(page, "") || strcmp(page, "") || strcmp(page, "") || strcmp(page, "") || strcmp(page, "") || strcmp(page, "") || strcmp(page, "") || strcmp(page, ""))
    {

    }
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
   
    if(dado > 3)
        printf("Voce tirou %d no dado, deu dano!", dado);
    else
        printf("Voce tirou %d no dado, nao deu dano!", dado);


    
    return dado;
}

void imprimir_menu()
{
    printf("\n%10s %10s %10s %10s %10s %10s\n", "A - Atacar", "M - Movimentar", "O - Olhar", "I - Info", "Q = Sair", "D - Dica");
    printf("\nEscolha uma op��o:\n     >>> ");
}

PERSONAGEM carregar_jogo(int *valor, PERSONAGEM jogador1)
{
    PERSONAGEM jogador2;
    int carregar, parada = 1, confirma, menu =1;
    char genero, classe;
    char temp[23];

    while(menu)
    {    
        ("cls");
        printf("\nBem Vindo ao nosso jogo!\n");

        printf("\n%10s \t %10s \t %10s \t %10s\n \n    >>> ", "{0} - Iniciar Novo Jogo", "{1} - Carregar Jogo Salvo", "{2} - Creditos", "{3} - Sair");
        scanf("%d", &carregar);

        int i;
        while(parada)
        {    
            if (carregar == 0)
            {
                limpar_tela();
                printf("Insira seu nome: ");
                scanf("%s", jogador2.nome);
                system("cls");
                jogador2.vida = 3;

                while (parada)
                {
                    system("cls");
                    printf("Escolha uma classe: ");
                    printf("\n%s %16s   %16s\n", "1 - Guerreiro", "2 - Assassino", "3 - Desbravador");
                    fflush(stdin);
                    scanf("%c", &classe);
                    limpar_tela();
                    switch (classe)
                    {
                    case '1':
                        printf("\n    A classe Guerreiro possui as seguintes vantagens iniciais:\n -> {dado} + 6 de habilidade, {2*dado} + 12 de energia e {dado} + 6 de sorte <-\n\n");
                        printf("Ideal para jogadores iniciantes, pois eh uma classe bem resistente. Se for sua primeira experiencia, recomendamos que comece por ela.\n \n \n");
                        printf("Deseja selecionar a classe Guerreiro?");
                        printf("\n%s / %15s\n", "{1} - Sim", "{2} - Voltar\n");
                        scanf("%d", &confirma);
                        limpar_tela();

                        switch (confirma)
                        {
                        case 1:
                            
                            printf("Voc� quer ser um {guerreiro} ou uma {guerreira}?\n    >>> ");
                            fflush(stdin);
                            gets(jogador2.classe);
                            limpar_tela();
                        
                            if(strcmp(jogador2.classe, "guerreiro") == 0 || strcmp(jogador2.classe, "guerreira") == 0)
                            {
                            limpar_tela();
                            printf("%s, Voc� escolheu a classe: %s\n", jogador2.nome, jogador2.classe);
                            jogador2.atributo.habilidade = 6, jogador2.atributo.energia = 12, jogador2.atributo.sorte = 6;
                            jogador2 = dado_inicio(jogador2);
                            parada = 0;
                            }
                            else
                            {
                                puts("***Comando Inv�lido, digite qualquer tecla para tentar novamente...***");
                                scanf("%s", temp);
                            }
                            break;
                        case 2:
                            break;
                        default:
                            puts("***Comando Inv�lido, digite qualquer tecla para tentar novamente...***");
                            scanf("%s", temp);
                            break;
                        }
                        break;    
                    case '2':
                    
                        printf("\n    A classe Assassino possui as seguintes vantagens iniciais:\n -> {dado} + 12 de habilidade, {2*dado} + 5 de energia e {dado} + 6 de sorte <-\n\n");
                        printf("Ideal para jogadores mais corajosos, possui menos resistencia, porem, tem maior chance de conseguir realizar com sucesso suas escolhas.\n \n \n");
                        printf("Deseja selecionar a classe Assassino?");
                        printf("\n%s / %15s\n", "{1} - Sim", "{2} - Voltar\n");
                        scanf("%d", &confirma);
                        limpar_tela();
                        switch (confirma)
                        {
                        case 1:
                            
                            printf("Voc� quer ser um {assassino} ou uma {assassina}?\n    >>> ");
                            fflush(stdin);
                            gets(jogador2.classe);
                        
                            if(strcmp(jogador2.classe, "assassino") == 0 || strcmp(jogador2.classe, "assassina") == 0)
                            {
                            limpar_tela();
                            printf("%s, Voc� escolheu a classe: %s", jogador2.nome, jogador2.classe);
                            jogador2.atributo.habilidade = 12, jogador2.atributo.energia = 6, jogador2.atributo.sorte = 6;
                            jogador2 = dado_inicio(jogador2);
                            parada = 0;
                            }
                            else
                            {
                                puts("***Comando Inv�lido, digite qualquer tecla para tentar novamente...***");
                                scanf("%s", temp);
                            }
                            break;
                        case 2:
                            break;
                        default:
                            printf("***Comando Inv�lido, tente novamente...***");
                            break;
                        }
                        break;    
                    case '3':
                        printf("\n    A classe Desbravador possui as seguintes vantagens iniciais:\n -> {dado} + 4 de habilidade, {2*dado} + 4 de energia e {dado} + 10 de sorte <-\n\n");
                        printf("Escolha essa classe apenas se ja tiver experiencia com o jogo. Essa classe seria como o modo Hardcore, apenas os melhores tem sucesso com ela.\n \n \n");

                        printf("Deseja selecionar a classe Desbravador?");
                        printf("\n%s / %15s\n", "{1} - Sim", "{2} - Voltar\n");
                        scanf("%d", &confirma);
                        switch (confirma)
                        {
                        case 1:
                            
                            printf("Voc� quer ser um {desbravador} ou uma {desbravadora}?\n    >>> ");
                            fflush(stdin);
                            gets(jogador2.classe);
                        
                            if(strcmp(jogador2.classe, "desbravador") == 0 || strcmp(jogador2.classe, "desbravadora") == 0)
                            {
                            jogador2.atributo.habilidade = 4, jogador2.atributo.energia = 4, jogador2.atributo.sorte = 10;
                            limpar_tela();
                            printf("%s, Voc� escolheu a classe: %s", jogador2.nome, jogador2.classe);
                            jogador2 = dado_inicio(jogador2);
                            parada = 0;
                            }
                            else
                            {
                                puts("***Comando Inv�lido, digite qualquer tecla para tentar novamente...***");
                                scanf("%s", temp);
                            }
                            break;
                        case 2:
                            break;
                        default:
                            printf("***Comando Inv�lido, tente novamente...***");
                            break;
                        }
                        break;    
                        default:
                            
                            puts("***Comando Inv�lido, digite qualquer tecla para tentar novamente...***");
                            scanf("%s", temp);
                        
                            break;
                    }
                }
                menu = 0;

                printf("\nDigite qualquer tecla para Come�ar o jogo!");
                scanf("%s", temp);
                limpar_tela();
                FILE *prologo;
                char caractere;
                prologo = fopen("0001.txt", "r");
                while(!feof(prologo))
                {
                    fscanf(prologo, "%c", &caractere);
                    printf("%c", caractere);
                }
                printf("\n\n\nE assim, come�a a jornada de %s. Divirta-se!", jogador2.nome);
                strcpy(jogador2.posicao, "0000");
                return jogador2;
            }
            if (carregar == 1)
            {
                FILE *fp_carregar;
                fp_carregar = fopen("gravar.dat", "rb");
                if (fp_carregar == NULL)
                {
                    limpar_tela();
                    printf("Voce nao tem nenhum jogo salvo");
                    press();
                    limpar_tela();
                    break;
                }
                i = 1;
                while (!feof(fp_carregar))
                {
                    fread(&jogador2, sizeof(PERSONAGEM), 1, fp_carregar);
                }
                printf("\nBem Vindo de volta %s, voce tem %d vidas! Sua classe � %s.", jogador2.nome, jogador2.vida, jogador2.classe);
                fclose(fp_carregar);
                menu = 0;
                return jogador2;
            }
            
            if (carregar == 2)
            {
                limpar_tela();
                printf("Feito por Felipe Serejo Monteiro, Rafael Ferreira Siqueira e Luiz Felipe Bissoli, alunos do 1 periodo de Ciencia da Computacao.");
                press();
                limpar_tela();
                break;
            }

            if (carregar == 3)
            {
                *valor = 0;
                menu = 0;
                exit(1);
            }   
            else
            {
                puts("***Comando Inv�lido, digite qualquer tecla para tentar novamente...***");
                scanf("%s", temp);
                fflush(stdin);
                limpar_tela();
                break;
                
            } 
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
            printf("\nVoc� tirou %d no dado, agora voc� tem %d de Habilidade\n", jogador.atributo.habilidade - hab, jogador.atributo.habilidade);

        }
        if(i == 1)
        {
            
            jogador.atributo.energia += (dado*2);
            printf("\nVoc� tirou %d no dado, agora voc� tem %d de Energia\n", ((jogador.atributo.energia - ener)/2), jogador.atributo.energia);

        }
        if(i == 2)
        {
            
            jogador.atributo.sorte += (dado);
            printf("\nVoc� tirou %d no dado, agora voc� tem %d de Sorte\n", jogador.atributo.sorte - sor, jogador.atributo.sorte);

        }
        i++;
       
    }   
        
    return jogador;
}