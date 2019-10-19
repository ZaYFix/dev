#!/usr/bin/python
# coding: utf-8

class Article:
    designation = ""
    prix = 0.0 # float car il n'existe pas de double en Python

    def __init__(self, designation=None, prix=None):
        self.designation = designation
        self.prix = prix
        
    def __del__(self):
        print("Je suis le destructeur !")

    def getDesignation(self):
        return self.designation

    def getPrix(self):
        return self.prix

    def affiche(self):
        """Affiche la designation et le prix  de l'objet"""
        print(self.designation)
        print(self.prix)
        
article1 = Article()
article2 = Article('Le Trône de fer, Tome 1', 13.29)

article1.getDesignation()
article1.getPrix()
article1.affiche()

article2.getDesignation()
article2.getPrix()
article2.affiche()

del article1
del article2
