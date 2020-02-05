import java.util.Scanner; 

public class TestPalyndrome2
{
    public static void main (String[] args)
    {
        String string = "";
        String chaineCaractere = "";
        StringUtils stringUtils = new StringUtils();
        Scanner scanner = new Scanner(System.in); 
        
        do
        {
            string = scanner.nextLine();
            if(lireInt(string) != 0)
            {
                chaineCaractere += string;
            }
        } while(lireInt(string) != 0);
        System.out.println(stringUtils.estPalyndrome(chaineCaractere));
    }

    private static int lireInt(String string)
    {
        int stringEnInt = 0;
        try
        {
            stringEnInt = Integer.parseInt(string);
        }
        catch(Exception NumberFormatException)
        {
            return -1;
        }
        return stringEnInt;
    }
}