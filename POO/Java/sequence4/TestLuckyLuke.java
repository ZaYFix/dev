public class TestLuckyLuke
{
    public static void main (String[] args)
    {
        Humain luckyLuke = new Humain("Lucky Luke");
        System.out.println("Une histoire sur " + luckyLuke.getNom());
        luckyLuke.setBoissonFavorite("coca-cola");
        luckyLuke.sePresente();
        luckyLuke.boit();
    }
}