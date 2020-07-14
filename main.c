#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void modificationTableau( char *tableau)
{
    tableau[4] = '1';
}

char fromIntToChar(int number)
{
    if ( number == 1)
    {
        return  '1';
    }
    else if( number == 2)
    {
        return '2';
    }
    else if( number == 3)
    {
        return '3';
    }
    else if( number == 4)
    {
        return  '4';
    }
    else if( number == 5)
    {
        return '5';
    }
    else if( number == 6)
    {
        return '6';
    }
    else if( number == 7)
    {
        return  '7';
    }
    else if( number == 8)
    {
        return  '8';
    }
    else if( number == 9)
    {
        return  '9';
    }

}


int main()
{
    char tableau[9] = { '1', '2', '3',
                        '4', '5', '6',
                        '7', '8', '9' };
    int i = 0;

    srand(time(NULL));

    tableau[0] = rand() % 9 + 1;
    tableau[0] = fromIntToChar(tableau[0]);

    for( i = 1 ; i < 9 ; i++ )
    {
        tableau[i] = rand() % 9 + 1;

        tableau[i] = fromIntToChar(tableau[i]);
    }

    for ( i = 0 ; i < 9 ; i++ )
    {
        printf("%c : %d\n\n", tableau[i], tableau[i]); // affiche 5 normalement
    }

    modificationTableau(tableau);

    printf("%c : %d\n\n",tableau[4], tableau[4]);

    scanf("%c", &tableau[4]);

    printf("%c : %d\n\n", tableau[4], tableau[4]);


    do
    {

    }while( menu() != 2 );




    return 0;
}


