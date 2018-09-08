
import Vechile.*;
public class maruthi extends Vechile.car{
    public void Display(){
        System.out.println("overrided");
    }
    public static void main(String[] args) {
        maruthi c = new maruthi();
        c.GeneralDetails();
        c.Display();
    }

}