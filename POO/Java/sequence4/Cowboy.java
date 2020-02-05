public class Cowboy extends Humain
{
    private String nom;
    private String boissonFavorite = "whisky";
    private int popularite = 0;
    private String adjectif = "vaillant";

    public Cowboy(String nom)
    {
        super();
        this.nom = nom;
    }

    public void sePresente()
    {
        String texte = "";
        texte = "Bonjour, je suis le " + getAdjectif() + getNom() + " et j’aime le " + getBoissonFavorite();
        parle(texte);
    }

    public String getAdjectif()
    {
        return adjectif;
    }
}