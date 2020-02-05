public class TestWestern2
{
    public static void main (String[] args)
    {
        Cowboy lucky = new Cowboy("Lucky Luke");
        Dame jenny = new Dame("Jenny");
        // 1. La rencontre ...
        lucky.sePresente();
        jenny.sePresente();
        // 2. Allons boire un coup ...
        jenny.changeDeRobe("verte");
        lucky.boit();
        jenny.boit();
    }   
}