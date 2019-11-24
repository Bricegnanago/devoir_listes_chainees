#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"




/*************************************/
//Defintion des fonctions de la liste
/*************************************/
//taper 6
void deleteWordsBeginingByOneLetter(Liste * liste){
    char letter[1];
    int trouve = 0;
    printf("Veuillez saisir une lettre pour la suppression : ");
    scanf("%s", letter);


    Element * nouveau = malloc(sizeof(*nouveau));
    Element * precedent = malloc(sizeof(*precedent));
    nouveau=liste->premier;

    if(liste->premier != NULL) // verifie si existe un élément à la liste
    {
        if(strncmp(letter,nouveau->mot, 1 ) == 0) //comparaison des deux chaines
        {
            printf("\n ***** Mot suprime avec succes :  %s *****",nouveau->mot);
            nouveau = liste->premier;
            liste->premier=nouveau->suivant;

            free(nouveau);

        }
        else
        {
            trouve=0;
            precedent = nouveau;
            nouveau = nouveau->suivant;
            while(nouveau != NULL && trouve==0)
            {
                if(strcmp(nouveau->mot,letter)==0)
                {
                    printf("%s\t",nouveau->mot);
                    printf("\n Element \n");

                    trouve=1;
                    free(nouveau);
                }
                else
                {
                    precedent=nouveau;
                    nouveau = nouveau->suivant;
                    printf("\n Aucun Element ne correspond dans le dictionnaire \n");
                }
                precedent->suivant=nouveau->suivant;
            }
        }
    }
   //printf("\nNombre de mot commençant par %s: %d", letter, i);
}

void getNbWordsBeginingBy(Liste * liste){
    int i = 0;
    char letter[1];
    printf("Veuillez saisir une lettre pour la recherche : ");
    scanf("%s", letter);

    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else{
        Element *actuel = liste->premier;
        while (actuel != NULL)
        {
            if(strncmp(letter,actuel->mot,1) == 0){
                //Il y a match entre les deux variables
                i++;
            }
            actuel = actuel->suivant;
        }
        printf("\n");
    }

    printf("\nNombre de mot commençant par %s: %d", letter, i);

}


//
String getDefintion(Liste * liste){
    char mot[TAILLE_MAX];
    String expression;
    printf("\n\nVeuillez saisir un mot svp : ");
    scanf("%s", mot);

    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else{
        Element *actuel = liste->premier;
        while (actuel != NULL)
        {
            if(strcmp(mot, actuel->mot) == 0){
                //Il y a match entre les deux variables
                strcpy(expression.definition,actuel->definition);
                break;
            }
            actuel = actuel->suivant;
        }
        printf("\n");
    }

    return expression;
}


Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(element->mot,"");
    strcpy(element->definition,"");
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void loadListFromFile(Liste * liste){
    FILE* fichier = NULL;
    //int position = 0;
    char chaine[TAILLE_MAX];
    StringObject word;
    strcpy(word.mot,"");
    strcpy(word.definition,"");
    fichier = fopen("test.txt", "r");
    liste->premier=NULL;
    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {

            //chaine[strlen(chaine)-1] = ' ';
//            for(int i = 0; i < strlen(chaine); i++){
//                printf("[%d] : %c\t", i, chaine[i]);
//            }
            //position = searchPositionOf(chaine);
            //printf("position : %d\n", position);
            word = extratWord(chaine);

            insertionInList(liste, word);
        }
        fclose(fichier);
    }
}



StringObject extratWord(char chaine[TAILLE_MAX]){
    int i = 0;
    StringObject word;

    int positionOf = searchPositionOf(chaine);

    for(i = 0; i < positionOf; i ++){
        word.mot[i] = chaine[i];
        //insertionInList
    }

    int j = 0;
    for(i = positionOf+1; i < strlen(chaine) ; i ++){
        word.definition[j] = chaine[i];
        j++;
    }

    //printf("mot-extrait : %s \n", word.mot);
    //printf("definition-extrait : %s\n", word.definition);
    //puts(word.mot);
    //puts(word.definition);
    return word;
}

int searchPositionOf(char chaine[TAILLE_MAX]){
    int i;
    int position = 0;
    for( i = 0; i < strlen(chaine); i++){
        if(chaine[i] == '='){
            position = i;
            break;
        }
    }

    return position;
}

void insertion(Liste *liste)
{
    FILE * fichier = NULL;
    char nvChaine1[TAILLE_MAX];
    char nvChaine2[TAILLE_MAX];
    /* Création du nouvel élément */
        fichier = fopen("test.txt", "a+");
    int i = 0;
    char choix = 'O';
    do {

        Element *nouveau = malloc(sizeof(*nouveau));

        if (liste == NULL || nouveau == NULL)
        {
            exit(EXIT_FAILURE);
        }
        printf("Veuillez saisir un mot dans le dictionnaire : ");
        fflush(stdin);
        gets(nvChaine1);
        strcpy(nouveau->mot,nvChaine1);
        printf("Veuillez saisir la définition dans le dictionnaire : ");
        fflush(stdin);
        gets(nvChaine2);
        strcpy(nouveau->definition,nvChaine2);
        fprintf(fichier,"%s=%s\n",nouveau->mot, nouveau->definition);
        nouveau->suivant = liste->premier;
        liste->premier = nouveau;
        //choix de l'utilisateur
        printf("Voulez-vous continuer (Oui) O ou (Non) N ? : ");
        scanf("%c", &choix);
        i++;

    }while(choix == 'O');

    printf("\n\n********* %d Elements inseres avec succes dans le dictionnaire*********** \n\n", i );
    fclose(fichier);
}



void insertionInList(Liste *liste, StringObject word){
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));

    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    //copy des éléments saisie par la liste
    strcpy(nouveau->mot,word.mot);
    strcpy(nouveau->definition, word.definition);
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

//void suppression(Liste *liste)
//{
//    char nvChaine1[TAILLE_MAX];
////    printf("\n\n\nSaisir l'element à un mot dans le dictionnaire :");
////    fflush(stdin);
////    gets(nvChaine1);
//    int trouve;
//    printf("VEUILLEZ ENTRER LE MOT POUR FAIRE LA SUPPRESSION!!! \n");
//    scanf("%s",nvChaine1);
//    liste *nouveau = malloc(sizeof(*nouveau));
//    liste *precedent = malloc(sizeof(*precedent));
//    nouveau=liste->premier;
//    if (liste == NULL)
//    {
//        exit(EXIT_FAILURE);
//    }
//
//    Element *actuel = liste->premier;
//    while (actuel != NULL || liste->premier != NULL)
//    {
//        printf("%s compare avec ---- %s\n\n", actuel->mot,nvChaine1);
//        if(strcmp(actuel->mot, nvChaine1) == 0){
//            printf("****** Mot trouve ****\n\n");
//            Element *aSupprimer = actuel;
//            break;
//        }
//
//
//        else{
//            printf("******Impossible de supprimer ce mot car il n'existe pas dans la liste****\n\n");
//            break;
//        }
//
//        actuel = actuel->suivant;
//
//
//    }
//}
//


//Supprimer un mot de la liste
void supprimer(Liste * liste)
{
    char nvChaine1[TAILLE_MAX];
    int trouve;
    printf("Veuillez saisir un mot pour la suppression : ");
    scanf("%s",nvChaine1);
    Element * nouveau = malloc(sizeof(*nouveau));
    Element * precedent = malloc(sizeof(*precedent));
    nouveau=liste->premier;

    if(liste->premier != NULL) // verifie si existe un élément à la liste
    {
        if(strcmp(nvChaine1,nouveau->mot)==0) //comparaison des deux chaines
        {
            nouveau = liste->premier;
            liste->premier=nouveau->suivant;
            free(nouveau);
            printf("\n ***** Element suprime avec succes ***** \n");
        }
        else
        {
            trouve=0;
            precedent = nouveau;
            nouveau = nouveau->suivant;
            while(nouveau != NULL && trouve==0)
            {
                if(strcmp(nouveau->mot,nvChaine1)==0)
                {
                    printf("%s\t",nouveau->mot);
                    printf("\n Element \n");
                    precedent->suivant=nouveau->suivant;
                    trouve=1;
                    free(nouveau);
                }
                else
                {
                    precedent=nouveau;
                    nouveau = nouveau->suivant;
                    printf("\n Aucun Element ne correspond dans le dictionnaire \n");
                }
            }
        }
    }


}

void rechercheInList(Liste * liste)
{
    char nvChaine1[TAILLE_MAX];
    int trouve;
    printf("Veuillez entrez le mot a rechercher!!! \n");
    scanf("%s",nvChaine1);
    Element * nouveau = malloc(sizeof(*nouveau));
    Element * precedent = malloc(sizeof(*precedent));
    nouveau=liste->premier;

    if(liste->premier != NULL)
    {
        if(strcmp(nvChaine1,nouveau->mot)==0)
            printf("\n ***** Element existe dans de dictionnaire ***** \n");
        else
        {
            trouve=0;
            precedent = nouveau;
            nouveau = nouveau->suivant;
            while(nouveau != NULL && trouve==0)
            {
                if(strcmp(nouveau->mot,nvChaine1)==0)
                {
                    printf("%s\t",nouveau->mot);
                    trouve=1;
                }
                else
                {
                    precedent=nouveau;
                    nouveau = nouveau->suivant;
                }

            }
            if(trouve==1)
            {
                printf("\n Element exite bien dans la Dictionnaire\n");
                precedent->suivant=nouveau->suivant;
            }
            else
            {

                printf("\n Aucun Element ne correspond dans le dictionnaire \n");
            }

        }
    }


}

void afficherListe(Liste *liste)
{
    char definition[TAILLE_MAX];
    char mot[TAILLE_MAX];
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else{
        Element *actuel = liste->premier;
        while (actuel != NULL)
        {
            strcpy(mot, actuel->mot);
            strcpy(definition, actuel->definition);
            printf("%s=%s",mot, definition);
            printf("\n");
            //printf("\n%c\n",actuel->mot[0]);
            actuel = actuel->suivant;
        }
    }
}


int countWordInList(Liste *liste){

    int nb_word = 0;

    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else{
        Element *actuel = liste->premier;
        while (actuel != NULL)
        {
            nb_word++;
            actuel = actuel->suivant;
        }
    return nb_word;
    }
}

//void showListByAlphabeticOrder(Liste * liste){
//
//    int nb_word = 0;
//    // 1)Mettre les mot des listes chainees dans un tableau de chaine de caractère
//    // 2)Ordonner les données du tableau de
//    if (liste == NULL)
//    {
//        exit(EXIT_FAILURE);
//    }
//    else{
//        Element *actuel = liste->premier;
//        while (actuel != NULL)
//        {
//            nb_word++;
//            actuel = actuel->suivant;
//        }
//    return nb_word;
//    }
//}

String getFisrtLetterOfWord(Liste *liste){
    char c ;
    String tableau;
    tableau.definition[0] = '0';
    int j = 0;
    int flag = 0;
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else{
        Element *actuel = liste->premier;
        while (actuel != NULL)
        {
            c = actuel->mot[0];
            flag = verifyLetterInTab(tableau.definition, c);
            if(flag == 0){
                tableau.definition[j] = actuel->mot[0];
                j++;
            }
            actuel = actuel->suivant;
        }
    return tableau;
    }
}

int verifyLetterInTab(char tableau[TAILLE_MAX], char lettre){

    int flag = 0;
    for(int i = 0; i < strlen(tableau); i++){
        if(tableau[i] == lettre){
            flag = 1;
            break;
        }
    }
    return flag;
}
//String StringOrderingBy(char mot[TAILLE_MAX][TAILLE_MAX]){
//
//    for(i = 0 ; i < strlen(mot); i++){
//        if("")
//    }
//
//    return String;
//}
