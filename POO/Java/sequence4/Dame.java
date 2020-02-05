public class Dame extends Humain
{
    private String nom;
    private String boissonFavorite = "lait";
    private String couleurRobe = "";
    private String etat = "";

    public Dame(String nom)
    {
        super();
        this.nom = nom;
    }

    public void sePresente()
    {
        String texte = "";
        texte = "Bonjour, je suis Miss " + getNom() + " et j’ai une jolie robe " + getCouleurRobe();
        parle(texte);
    }

    public String getCouleurRobe()
    {
        return couleurRobe;
    }

    public void changeDeRobe(String nouvelleCouleur)
    {
        couleurRobe = nouvelleCouleur;
    }
}