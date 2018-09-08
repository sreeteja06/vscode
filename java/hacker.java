import java.util.Scanner;
import java.time.LocalDate;
import java.time.Month;
public class hacker {
    public static String getDay(String day, String month, String year) {
        int yearInt = Integer.parseInt(year);
        Month monthMonth = month;
        int dayInt = Integer.parseInt(day);
        LocalDate dt = LocalDate.of(yearInt, monthMonth, dayInt);
        return dt.getDayOfWeek();
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String month = in.next();
        String day = in.next();
        String year = in.next();
        
        System.out.println(getDay(day, month, year));
    }
}