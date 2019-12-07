#ifndef _DE_H
#define _DE_H


class De 
{
  private:
    //Le nombre maximal de faces pour un dé
    const int nbFaces=  6;

    //un entier représentant la valeur du dé entre 1 et nbFaces
    int valeur;


  public:
    De();

    De(int nbFaces);

    ~De();

    //Accesseur qui retourne la valeur du Dé
    int getValeur();

    //Lance le dé !
    void lancer();

};
#endif
