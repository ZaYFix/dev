<?php

    class CompteBancaire
    {
        private $titulaire;
        private $solde;
        private $devise;

        public function __construct($titulaire="", $solde=0, $devise="euros")
      {
      $this->titulaire = $titulaire;
      $this->solde = $solde;
      $this->devise = $devise;
      }

      public function getTitulaire()
      {
          return $this->titulaire;
      }

      public function getSolde()
      {
          return $this->solde;
      }

      public function getDevise()
      {
          return $this->devise;
      }

      public function crediter($montant)
      {
          $this->solde = $this->solde + $montant;
      }

      public function debiter($montant)
      {
          $this->solde = $this->solde - $montant;
      }

      public function affiche()
      {
          echo "Titulaire : $this->titulaire \n";
          echo "Solde: $this->solde \n";
          echo "Devise : $this->devise \n";
      }
    }

$compte1 = new CompteBancaire();
$compte2 = new CompteBancaire("Bill Gates", 105000000000, "USD");

echo "Le solde du compte est ".$compte2->getSolde()."\n";
echo "La devise du compte est ".$compte2->getDevise()."\n";

$compte1->affiche();
$compte2->affiche();

$compte2->debiter(666000000);
$compte2->getSolde();

?>