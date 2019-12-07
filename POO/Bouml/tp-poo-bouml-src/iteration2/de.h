#ifndef _DE_H
#define _DE_H


class De 
{
  private:
    //Le nombre maximal de faces pour un d�
    const int nbFaces=  6;

    //un entier repr�sentant la valeur du d� entre 1 et nbFaces
    int valeur;


  public:
    De();

    De(int nbFaces);

    ~De();

    //Accesseur qui retourne la valeur du D�
    int getValeur();

    //Lance le d� !
    void lancer();

};
#endif
