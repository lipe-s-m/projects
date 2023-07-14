#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct _ATRIBUTOS
{
    int ataque, defesa, vigor, magia;
}ATRIBUTOS;

typedef struct _PERSONAGEM
{
    int vida;
    ATRIBUTOS habilidade;
    char nome[40];
    int inimigo[10];
    char classe[15];
    int posicao[30];

}PERSONAGEM;

void press();
void limpar_tela();
void imprimir_menu();
PERSONAGEM carregar_jogo(int *valor, PERSONAGEM);

int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *gravar;
    gravar = fopen("gravar.txt", "w");

    if(gravar == NULL)
    {
        printf("\nmano deu erro\n");
    }

    PERSONAGEM jogador1;
    int i, opcao = 1, salvar, carregar;
    int vazio = 0;
    char comando;
    char palavra[30];

    jogador1 = carregar_jogo(&opcao, jogador1);




  


    press();
    while(opcao)
    {
        limpar_tela();
        imprimir_menu();
        scanf("%c", &comando);
        switch(comando)
        {
            case 'A':
            printf("\nVocê atacou, %s deu %d de dano", jogador1.nome, jogador1.habilidade.ataque);
            press();


            break;
            
            
            case 'Q':
            printf("\n%s %15s %15s\n", "0 - NAO", "1 - SIM", "2 - VOLTAR");
            printf("Deseja Salvar seu progresso? \n    >>> ");
            scanf("%d", &salvar);
            switch(salvar)
            {
                case 0:
                if(salvar == 0)
                {
                    opcao = 0;
                }
                break;
                case 1:
                if(salvar == 1);
                    printf("%s salvou seu jogo", jogador1.nome);
                    
                    fprintf(gravar, "%s", jogador1.nome);
                    fprintf(gravar, "%d", jogador1.vida);

                    opcao = 0;
                break;

                case 2:
                break;
                default:
                puts("**Valor Inválido, Tente novamente...**");
                break;
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
    printf("\n%10s %10s %10s %10s %10s %10s\n", "A - Atacar", "M - Menu", "O - Olhar", "I - Ir", "Q = Sair", "D - Dica");
    printf("\nEscolha uma opção:\n     >>> ");
}

PERSONAGEM carregar_jogo(int *valor, PERSONAGEM jogador1)
{
    PERSONAGEM jogador2;
    int carregar, classe, parada = 1, confirma;
    

    system("cls");
    printf("\nBem Vindo ao nosso jogo!\n");

    printf("\n%10s / %10s / %10s\n \n    >>> ", "(0) - Iniciar Novo Jogo", "{1} - Carregar Jogo Salvo", "2 - Sair");
    scanf("%d", &carregar);

    int i;
    if(carregar == 0)
    {
        printf("Insira seu nome: ");
        scanf("%s", jogador2.nome);
        system("cls");
        
        while(parada)
        {
            system("cls");
            printf("Escolha uma classe: ");
            printf("\n%s %15s %15s\n", "1 - Guerreiro", "2 - Assassino", "3 - VOLTAR");
            scanf("%d", &classe);
            switch(classe)
            {
                case 1:
                    printf("\nA classe guerreiro tem 12 de ataque, 12 de defesa, 12 de vigor, 0 de magia\n");
                    printf("Deseja selecionar a classe Guerreiro?");
                    printf("\n%s / %15s\n", "{1} - Sim", "{2} - Voltar\n");
                    scanf("%d", &confirma);
                    switch(confirma)
                    {
                        case 1:
                        jogador2.habilidade.ataque = 12, jogador2.habilidade.defesa = 12, jogador2.habilidade.vigor = 0, jogador2.habilidade.magia = 12;        
                        printf("%s, você é um Guerreiro", jogador2.nome);
                        parada = 0;
                        break;
                        case 2:
                        break;
                    }
                    break;
                case 2:
                    printf("\nA classe Assassino tem 18 de ataque, 8 de defesa, 10 de vigor, 0 de magia\n");
                    printf("Deseja selecionar a classe Assassino?");
                    printf("\n%s / %15s\n", "{1} - Sim", "{2} - Voltar\n");
                    scanf("%d", &confirma);
                    switch(confirma)
                    {
                        case 1:
                        jogador2.habilidade.ataque = 18, jogador2.habilidade.defesa = 8, jogador2.habilidade.vigor = 10, jogador2.habilidade.magia = 0;        
                        printf("%s, você é um Assassino", jogador2.nome);
                        parada = 0;
                        break;
                        case 2:
                        break;
                    }
                    break;
                default:
                break;


            }
        }
        return jogador2;
    }
    if(carregar == 1)
    {
        char texto[200];
        char nome[40];
        int vida;
        FILE *fp_carregar;
        FILE *fp_salvar;
        fp_carregar = fopen("gravar.txt", "r+");
        fp_salvar = fopen("carregarjogo.txt", "w");
        if(fp_carregar == NULL)
        {
            printf("coe deu ruim");
        }
        i = 1;
        while(!feof(fp_carregar))
        {
            fscanf(fp_carregar, "%c", &texto);
            fprintf(fp_salvar, "%c", texto);
        }
        printf("\nBem Vindo de volta %s! Voce esta com %d de vida", jogador2.nome, jogador2.vida);

        fclose(fp_carregar);
        fclose(fp_salvar);
        return jogador2;

    }
    if (carregar == 2)
    {   
        *valor = 0;
        printf("%d", *valor);
    }
}
