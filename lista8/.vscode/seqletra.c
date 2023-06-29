#include <stdio.h>
#include <string.h>

int letra(char texto[]);

int main(){
    
    int n, i = 0, cont, t = 0;
    char texto[200];
    
    scanf("%d", &n);
    
    for(i; i<n; i++)
    {

        fflush(stdin);
        fgets(texto, 200, stdin);
        t = strlen(texto);

        printf("\n%d ", t);
    }
    
    return 0;
}
  