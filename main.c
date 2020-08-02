/* La fonction fromIntToChar &
   fromCharToChar sert pour la
   fonction rand() .
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Menu()
{
    int choix = 0;
    printf("\t\t - { Sudoku by Skywashi } -\n\n");
    printf("\t 1 - Nouvelle Partie \n");
    printf("\t 2 - Quitter \n\n\n");
    printf("Votre choix ? ");

    scanf("%d", &choix);
    return choix;

}

char FromIntToChar(int number)
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

    return 0;

}

void ComparateurDeAncienChiffre(int i, char *tableau)
{
        int e = 0;

    do
    {
        if( tableau[e] == tableau[i] && e != 0 ) /* si */
        {
            tableau[i] = rand() % 9 + 1;
            tableau = FromIntToChar(tableau[i]);

        }
        e++;
    }while(e < i );
}

void AfficheTableau(char *tableau)
{
    printf("%c %c %c\n", tableau[0], tableau[1], tableau[2]);
    printf("%c %c %c\n", tableau[3], tableau[4], tableau[5]);
    printf("%c %c %c\n", tableau[6], tableau[7], tableau[8]);
}

void NouvellePartie()
{
    char tableau[9] = { ' ', ' ', ' ',
                        ' ', ' ', ' ',
                        ' ', ' ', ' ' };
    int nombreDeCasePredefinie = 4, caseAPredefinir = 0, i = 0, x = 0, y = 0;

    caseAPredefinir = rand() % 8 + 0;
    tableau[caseAPredefinir] = rand() % 9 + 1; /*la première case aura un chiffre entre 9 et 1 $
                                   tableau aura un chiffre */
    tableau[caseAPredefinir] = FromIntToChar(tableau[caseAPredefinir]);

    for( i = 0 ; i < nombreDeCasePredefinie ; i++ )
    {
        caseAPredefinir = rand() % 8 + 0;
        tableau[caseAPredefinir] = rand() % 9 + 1;
        tableau[caseAPredefinir] = FromIntToChar(tableau[caseAPredefinir]);
        ComparateurDeAncienChiffre(caseAPredefinir, tableau);
    }

    AfficheTableau(tableau);

    for ( i = 0 ; i < 9 ; i++ )
    {
        printf("%c : %d\n\n", tableau[i], tableau[i]); // affiche 9 normalement
    }

    printf("%c : %d\n\n",tableau[4], tableau[4]);

    printf("Quel case vous voulez modifier ?\n\n");
    printf("x = ?");
    scanf("%d", &x);
    printf("y = ?");
    scanf("%d", &y);

    /* ici la suite du programme pour définir en fonction de x et y */

}

/* ici le programme commence */
int main()
{


    srand(time(NULL));


    switch( Menu() )
    {
        case 1:
            NouvellePartie();
        case 2:
            printf("Merci d'avoir utilisee le programme ;) ");
            break;

    }

    return 0;
}


