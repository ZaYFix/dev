package western;

public class Dame extends Humain
{
    private String boissonFavorite = "lait";
    private String couleurRobe = "blanche";
    private String etat = "";

    public Dame(String nom)
    {
        super(nom);
        setBoissonFavorite(boissonFavorite);
    }

    public void sePresente()
    {
        String texte = "";
        texte = "Bonjour, je suis Miss " + this.getNom() + " et j’ai une jolie robe " + this.getCouleurRobe();
        parle(texte);
    }

    public final String getCouleurRobe()
    {
        return couleurRobe;
    }

    public void changeDeRobe(String nouvelleCouleur)
    {
        String texte = "";
        couleurRobe = nouvelleCouleur;
        texte = "Regardez ma nouvelle robe " + couleurRobe + " !";
        parle(texte);
    }
}