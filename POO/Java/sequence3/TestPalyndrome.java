import java.util.Scanner; 

public class TestPalyndrome
{
    public static void main (String[] args)
    {
        StringUtils stringUtils = new StringUtils();
        Scanner scanner = new Scanner(System.in); 
        
        String string = scanner.nextLine();
        System.out.println(stringUtils.estPalyndrome(string));
    }
}