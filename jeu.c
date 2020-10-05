#include <stdio.h> /* pour printf */
#include <time.h> /* pour rand */

int CaseChoisie(int x, int y)
{
    if(x == 1 && y == 1)
    {
        return 0; // la première case
    }
    else if(x == 2 && y == 1)
    {
        return 1; // la deuxième case
    }
    else if(x == 3 && y == 1)
    {
        return 2; // la troisième case
    }
    else if(x == 1 && y == 2)
    {
        return 3;
    }
    else if(x == 2 && y == 2)
    {
        return 4;
    }
    else if(x == 3 && y == 2)
    {
        return 5;
    }
    else if(x == 1 && y == 3)
    {
        return 6;
    }
    else if(x == 2 && y == 3)
    {
        return 7;
    }
    else if(x == 3 && y == 3 )
    {
        return 8;
    }

    return 0;
}


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
            tableau[i] = FromIntToChar(tableau[i]);

        }
        e++;
    }while(e < i );
}

void AfficheTableau(char *tableau)
{
    printf("__________\n");
    printf("|%c | %c | %c |\n", tableau[0], tableau[1], tableau[2]);
    printf("|%c | %c | %c |\n", tableau[3], tableau[4], tableau[5]);
    printf("|%c | %c | %c |\n", tableau[6], tableau[7], tableau[8]);
    printf("__________\n");
}

void NouvellePartie()
{
    /* déclaration de variable */
    char tableau[9] = { ' ', ' ', ' ',
                        ' ', ' ', ' ',
                        ' ', ' ', ' ' };
    /* nombreDeCasePredefinie pour le nombre total de case prédéfinir,
       caseAPredefinir la case qui doit être prédéfini
       stockCasePredefini,
       modificationAccorde 1 si la modification est accordé */
    int nombreDeCasePredefinie = 4, caseAPredefinir = 0, i = 0, x = 0, y = 0;
    int stockCasePredefini[4] = { 0, 0, 0, 0}, caseADefinir = 0, modificationAccorde =  -1;

    srand(time(NULL)); /* pour les chiffre au hasard */

    caseAPredefinir = rand() % 8 + 0;
    tableau[caseAPredefinir] = rand() % 9 + 1; /*la première case aura un chiffre entre 9 et 1 $
                                   tableau aura un chiffre */
    tableau[caseAPredefinir] = FromIntToChar(tableau[caseAPredefinir]);

    for( i = 0 ; i < nombreDeCasePredefinie ; i++ )
    {
        caseAPredefinir = rand() % 8 + 0;
        stockCasePredefini[i] = caseAPredefinir;
        tableau[caseAPredefinir] = rand() % 9 + 1;
        tableau[caseAPredefinir] = FromIntToChar(tableau[caseAPredefinir]);
        ComparateurDeAncienChiffre(caseAPredefinir, tableau);
    }

    do
    {
        system("CLS");
        modificationAccorde = 1;

        AfficheTableau(tableau);

        printf("Quel case vous voulez modifier ?\n\n");
        printf("x = ?(entre 1 et 3)\n");
        scanf("%d", &x);
        printf("y = ?(entre 1 et 3)\n");
        scanf("%d", &y);

        /* ici la suite du programme pour définir en fonction de x et y */
        caseADefinir = CaseChoisie(x, y);

        for( i = 0 ; i < nombreDeCasePredefinie ; i++ )
        {
            if ( caseADefinir == stockCasePredefini[i] )
            {
                modificationAccorde = 0;
            }
        }
    }while(!modificationAccorde);



}

