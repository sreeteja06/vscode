import java.text.*;
import java.util.Locale;

public class Neeru{
    public static void main(String []args){
        Double number = 12324.134;
        String myString = NumberFormat.getCurrencyInstance().format(number);
        System.out.println(myString);
        String india = NumberFormat.getCurrencyInstance(new Locale("en", "IN")).format(number);
        System.out.println(india);
        String china = NumberFormat.getCurrencyInstance(Locale.CHINA).format(number);
        System.out.println(china);
        String france = NumberFormat.getCurrencyInstance(Locale.FRANCE).format(number);
        System.out.println(france);
    }
}