#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[])
{

    int Choix;
    char rep ='O';
//    String tableau1;
    do
    {
		//system("cls");
        Liste *maListe = initialisation();
        loadListFromFile(maListe);
        //afficherListe(maListe);


//        tableau1= getFisrtLetterOfWord(maListe);
//
//        for(int i = 0; i < strlen(tableau1.definition); i++){
//            printf("%c", tableau1.definition[i]);
//        }
        //afficherListe(maListe);
        printf("\n");
        printf("\t\t\t********************************************************\n");
		printf("\t\t\t*\tBienvenue dans la bibliotheque des mots\t\t\t\t\n");
        printf("\t\t\t********************************************************\n");
		printf("\t\t\t1. Afficher la liste triee par ordre alphabetique. \n");
		printf("\t\t\t2. Rechercher la signification d’un mot. \n"); //OK
		printf("\t\t\t3. Supprimer un mot donne. \n"); // OK
		printf("\t\t\t4. Supprimer tous les mots commencant par une lettre donnee. \n");
		printf("\t\t\t5. Ajouter au dictionnaire un mot donné ainsi que sa signification. \n"); //OK
		printf("\t\t\t6. Compter le nombre de mots commençant par une lettre donnee. \n"); //OK
		printf("\t\t\t7. Compter le nombre de mots du dictionnaire. \n "); //OK
		printf("\t\t\t8. Quitter. \n" );


        printf("\t\t\tFaire un choix: ");
        scanf("%d",&Choix);

		switch(Choix)
		{
            case 1:
                printf("Vous avez choisi d affichier par ordre alphabetique");
                break;
            case 2:
                printf("\n\n***************Rechercher la signification d un mot\n\n*************");

                printf("Signification : %s", getDefintion(maListe).definition);

                break;
            case 3:
                supprimer(maListe);
                afficherListe(maListe);
                break;
            case 4:
                //deleteWordsBeginingByOneLetter(maListe);
                afficherListe(maListe);
                break;
			case 5:
			    printf("\n\n*********Ajouter au dictionnaire un mot donné ainsi que sa signification**********\n\n");
			    insertion(maListe);
			    break;
            case 6:
                printf("\n\n*********Recherche le nombre de mot commençant par une lettre donnée**********\n\n");
                getNbWordsBeginingBy(maListe);
                break;
            case 7:
                printf("Compter le nombre de mots du dictionnaire.");
                printf("\n\n**** La liste a son compteur %d element : ****",countWordInList(maListe));
                break;
			default:
                printf("Aucune donnée ne correspond");
		};

        printf("\n voulez vous vraiment repartir au menu o/n?");
        scanf("%c",&rep);
        scanf("%c",&rep);

    }while( rep == 'O' || rep == 'o');

    return 0;
}

