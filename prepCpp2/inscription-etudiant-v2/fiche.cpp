#include <ctype.h>
#include <iostream>
#include "fiche.h"
using namespace std;

Fiche fiches[FICHES_MAX];
unsigned int nbFemmes = 0;
unsigned int positionPlusJeuneEleve = 0;
unsigned int nbFiches = 0;

void inscrireEtudiants()
{   
    do
    {
        cin >> nbFiches;
    }
    while(nbFiches > FICHES_MAX);
    
    for(unsigned int i=0;i<nbFiches;i++)
    {
        cout << "Nom : ";
        cin >> fiches[i].nom;
        cout << "Prénom : ";
        cin >> fiches[i].prenom;
        cout << "Sexe (f/m) : ";
        cin >> fiches[i].sexe;
        cout << "Age : ";
        cin >> fiches[i].age;
        
        rechercherPlusJeune(i, nbFiches);
        compterFemmes(i);
        reecriture(i);
    }
}

void reecriture(unsigned int i)
{
    // Réécriture majuscule
    fiches[i].nom[0] = toupper(fiches[i].nom[0]);
    fiches[i].prenom[0] = toupper(fiches[i].prenom[0]);

    // Réécriture minuscule
    for(unsigned int j=1; fiches[i].nom[j] != CARACTERE_NUL ;j++)
    {
        fiches[i].nom[j] = tolower(fiches[i].nom[j]);
        fiches[i].prenom[j] = tolower(fiches[i].prenom[j]);
    }
}

void compterFemmes(unsigned int i)
{
    if((fiches[i].sexe == SEXE_FEMININ_MINUSCULE) || ( fiches[i].sexe == SEXE_FEMININ_MAJUSCULE))
    {
        nbFemmes++;
    }
}

int rechercherPlusJeune(unsigned int i, unsigned int nbFiches)
{
    unsigned int plusJeuneEleve = fiches[0].age;
            
    for(unsigned int i = 0; i < nbFiches;i++)
    {
        if(plusJeuneEleve > fiches[i].age)
        {
            plusJeuneEleve = fiches[i].age;
            positionPlusJeuneEleve = i;
        }
    }
    return positionPlusJeuneEleve;
}

void afficherListeEtudiant()
{
    cout << "Nombre de femmes : " << nbFemmes << endl;
    cout << "Etudiant le plus jeune : " << fiches[positionPlusJeuneEleve].nom << " " << fiches[positionPlusJeuneEleve].prenom << " " << fiches[positionPlusJeuneEleve].age << " " << fiches[positionPlusJeuneEleve].sexe << endl;
    cout << "Liste des étudiants : " << endl;
    
    for(unsigned int i=0;i<nbFiches;i++)
    {
        cout << fiches[i].nom << " ";
        cout << fiches[i].prenom << " ";
        cout << fiches[i].age << " ";
        cout << fiches[i].sexe << endl;
    }
}
