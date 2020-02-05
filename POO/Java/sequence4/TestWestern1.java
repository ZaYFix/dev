public class TestWestern1
{
    public static void main (String[] args)
    {
        Humain joe = new Humain("Joe");
        System.out.println("Une histoire sur " + joe.getNom());
        joe.setBoissonFavorite("whisky");
        joe.sePresente();
        joe.boit();
    }
}