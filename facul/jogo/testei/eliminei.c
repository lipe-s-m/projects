#include <stdio.h>
#include <string.h>
int main()
{
    int i = 68;
    char txt[7] = "001.txt";
    int tamanho[i];
    char c;
    FILE *entrada;
    
    
    while(!feof(entrada))
    {
        fscanf(entrada, "%c", &c);
        strcat(c, txt);
        remove(c);

    }
}