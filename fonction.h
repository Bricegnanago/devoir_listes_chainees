typedef struct Element Element;
typedef struct StringObject StringObject;
typedef struct String String;
#define TAILLE_MAX 100000
struct Element
{
    char mot[TAILLE_MAX];
    char definition[TAILLE_MAX];
    Element *suivant;
};

struct String
{
    char definition[TAILLE_MAX];
};


struct StringObject
{
    char mot[TAILLE_MAX];
    char definition[TAILLE_MAX];
};


typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

void loadListFromFile(Liste *liste);
StringObject extratWord(char chaine[TAILLE_MAX]);
int searchPositionOf(char chaine[TAILLE_MAX]);
Liste *initialisation();
void afficherListe(Liste *liste);
void insertionInList(Liste *liste, StringObject word);
//Liste * insertionfichierVersListe(Liste maListe);
//void insertionVersChaine(Liste *liste, char nvChaine[TAILLE_MAX]);
void rechercheInList(Liste * liste);
void insertion(Liste *liste);
//void suppression(Liste * liste);
void supprimer(Liste * liste);
int countWordInList(Liste *liste);
String getDefintion(Liste * liste);
void getNbWordsBeginingBy(Liste * liste);
void deleteWordsBeginingByOneLetter(Liste * liste);
void showListByAlphabeticOrder(Liste * liste);
String getFisrtLetterOfWord(Liste *liste);
//void suppression(Liste *liste);
int verifyLetterInTab(char tableau[TAILLE_MAX], char lettre);
