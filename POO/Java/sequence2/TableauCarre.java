public class TableauCarre
{
    final static int n = 5;

	public static void main (String[] args)
	{
        int tableau[];
        tableau = new int[n];

        for(int i=0;i<n;i++)
        {
            tableau[i] = (int) Math.pow((i*2)+1,2);
            System.out.println(tableau[i]);
        }
	}
}