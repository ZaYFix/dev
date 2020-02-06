package western;

public class Humain
{
    private String nom;
    private String boissonFavorite = "eau";

    public Humain()
    {

    }

    public Humain(String nom)
    {
        this.nom = nom;
    }

    public void setNom(String nom)
    {
        this.nom = nom;
    }

    public final String getNom()
    {
        return this.nom;
    }

    public void setBoissonFavorite(String boissonFavorite)
    {
        this.boissonFavorite = boissonFavorite;
    }

    public final String getBoissonFavorite()
    {
        return this.boissonFavorite;
    }

    public void sePresente()
    {
        String texte = "";
        texte = "Bonjour, je suis " + getNom() + " et j’aime le " + getBoissonFavorite();
        parle(texte);
    }

    public void boit()
    {
        String texte = "";
        texte = "Ah ! un bon verre de " + getBoissonFavorite() + " ! GLOUPS !";
        parle(texte);
    }

    public final void parle(String texte)
    {
        System.out.println("("+getNom()+") -- " + texte);
    }
}


