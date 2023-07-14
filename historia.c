#include <stdio.h>

int main(){

    FILE *fp, *historia;
    char a;
    historia = fopen("oi.txt", "r");


    if(historia == NULL)
    {
        printf("\n arquivo erroo");
        return 1;
    }

    while(!feof(historia))
    {
        fscanf(historia, "%c", &a);
        printf("%c", a);
    }
    fclose(historia);
    return 0;
}
