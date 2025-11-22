#include <stdio.h>
#include <conio.h>
int main()
{
    int i,j,n ; long s = 0, nbritiration = 0;
    printf("Donner un nombre entier n : ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            s = s + 1;
            nbritiration++;
        }
    }
    printf("La somme des %d premiers entiers est : %ld\n", n, s);
    printf("Le nombre d'iterations est : %ld\n", nbritiration);
}