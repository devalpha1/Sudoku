#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int choix = 0;
    printf("\t\t - { Sudoku by Skywashi } -\n\n");
    printf("\t 1 - Nouvelle Partie \n");
    printf("\t 2 - Quitter \n\n\n");
    printf("Votre choix ? ");

    scanf("%d", &choix);
    return choix;

}

int main()
{
    do
    {

    }while( menu() != 2 );



    return 0;
}
