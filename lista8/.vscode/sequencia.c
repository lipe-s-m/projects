#include <stdio.h>
#include <windows.h>

int sequencia(int a[], int tam, int j);
int main()
{

    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int i = 0, x[200], n, soma, t;
    scanf("%d", &n);

    for (i; i < n; i++)
    {
        scanf("%d", &x[i]);
        t = i;
    }
    for (i = 0; x[i] < n; i++)
    {
        printf("Caso %d: numero %d\n", i, soma);
        printf("%d", t);
        printf("\nesse é o i %d\n", i);
    }

    return 0;
}

int sequencia(int a[], int tam, int j)
{
}
