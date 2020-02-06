package western;

public class Cowboy extends Humain
{
    private String boissonFavorite = "whisky";
    private int popularite = 0;
    private String adjectif = "vaillant";

    public Cowboy(String nom)
    {
        super(nom);
        setBoissonFavorite(boissonFavorite);
    }

    public void sePresente()
    {
        String texte = "";
        texte = "Bonjour, je suis le " + this.getAdjectif() + " " + this.getNom() + " et j’aime le " + this.getBoissonFavorite();
        parle(texte);
    }

    public final String getAdjectif()
    {
        return adjectif;
    }
}