public class StringUtils
{
    public String inverse(String s)
    {
        return(new StringBuffer(s).reverse()).toString();
    }
    public boolean estPalyndrome(String s)
    {
        if(s.equals(inverse(s)))
            return true;
        else
            return false;
    }
}