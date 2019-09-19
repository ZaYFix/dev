#ifndef FICHE_H
#define FICHE_H

#define FICHES_MAX 500

struct Fiche
{
    char nom[FICHES_MAX];
    char prenom[FICHES_MAX];
    unsigned int age;
    char sexe;
};

void inscrireEtudiants();
int rechercherPlusJeune(unsigned int i);
void afficherListeEtudiant();

#endif
