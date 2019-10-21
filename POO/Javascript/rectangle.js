function Rectangle(largeur, longueur) {
    this.largeur = largeur || undefined;
    this.longueur = longueur || undefined;
    this.affiche = function() {
    console.log(this.largeur + " x " + this.longueur);
    }
    this.aire = function() {
        if ( largeur && longueur)
        {
            return this.largeur * this.longueur;
        }
    }
    this.perimetre = function() {
        if ( largeur && longueur)
        {
            return (this.largeur + this.longueur)*2;
        }
        
    }
}

var rectangle = new Rectangle();
rectangle.affiche();
var carre = new Rectangle(100,100);
carre.affiche();

console.log(carre.aire());
console.log(carre.perimetre());