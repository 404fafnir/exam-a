#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1 
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/

const L = 9;
const H = 9;




// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls
int generer(int arr[H][L]){
    int nbNonNul = 0;

    int i, j;

    for (i = 0; i < H; i++){
        for (j = 0; j < L; j++){
            if (arr[i][j] != 0){
            nbNonNul ++;
            }
        }
    }
      
    return nbNonNul;
}



// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/


/*
Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée
*/

int remplissage = 0;

void saisir(int arr[H][L]){

    int i, j, v;

    printf("Quelle sont les coordonnées auxquelles vous voulez placer votre valeur ? (i,j) i = ?");
    scanf("%d", &i);
    printf("quelle est la deuxième coordonnée j ? ");
    scanf("%d", &j);
    printf("par quelle valeur voulez vous remplasser cette case ? ");
    scanf("%d", v);

    if ((i >= 0 && i <= 9) && (j >= 0 && j <= 9) && (v >= 0 && v <= 9))
    {
        if (arr[i][j] == 0)
        {
            arr[i][j] = v;
            remplissage ++;
        }
    }
    
}



/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/

const int HORIZ = 0;
const int VERT = 1;

int verifierLigneColonne(int num, int sens, int arr[9][9]){

    int res = 1;

    int tableauInter[9];

    if (sens = 0)
    {
        tableauInter[9] = arr[9][num];

        int count = sizeof(tableauInter) / sizeof(tableauInter[0]);

        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (tableauInter[i] == tableauInter[j]) {
                res = 0;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            tableauInter[i] = arr[num][i];
        }
        
        int count = sizeof(tableauInter) / sizeof(tableauInter[0]);

        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (tableauInter[i] == tableauInter[j]) {
                res = 0;
                }
            }
        }


    }

    return res;


}




/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/

int verifierRegion(int k, int l, int arr[9][9]){
    int res = 1;

    int tableauInter[9];

    tableauInter[0] = arr[0+k][0+l];
    tableauInter[1] = arr[0+k][1+l];
    tableauInter[2] = arr[0+k][2+l];
    tableauInter[3] = arr[1+k][0+l];
    tableauInter[4] = arr[1+k][1+l];
    tableauInter[5] = arr[1+k][2+l];
    tableauInter[6] = arr[2+k][0+l];
    tableauInter[7] = arr[2+k][1+l];
    tableauInter[8] = arr[2+k][2+l];

    int count = sizeof(tableauInter) / sizeof(tableauInter[0]);

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (tableauInter[i] == tableauInter[j]) {
            res = 0;
            }
        }
    }
    
    return res;
}



//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon

int verifierGrille(int arr[9][9])
{
    int res = 0;
    int resInter = 0;


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (verifierRegion(i, j, arr))
            {
                resInter++;
            }
            
        }
        
    }

    for (int k = 0; k < 2; k++)
    {
        for (int w = 0; w < 9; w++)
        {
            if (verifierLigneColonne(w, k, arr))
            {
                resInter++;
            }
            
        }
        
    }

    if (resInter == 27)
    {
        res = 1;
    }

    return res;
 
}




//Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)


int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    int solution[9][9];
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  
    for(j=0;j<9; ++j) 
    {
    for(i=0; i<9; ++i)
        solution[j][i] = (i + j*3 +j /3) %9 +1 ; 
    }
    
    for(i=0;i<9; ++i) 
    {
    for(j=0; j<9; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 
    
    printf("%d",rand() % 2);
    
  



    //Ne pas toucher au code ci dessous
    getchar();
    return 0;
}

