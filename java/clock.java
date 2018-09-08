import java.lang.Thread;

import jdk.nashorn.internal.runtime.regexp.joni.exception.InternalException;
class T extends Thread{
    Thread thread;
    int StartingNumber;
    static int divisors[] = new int[10000];
    int EndingNUmber;
    T(String name, int startingNumber, int endingNumber)
    {
        EndingNUmber = endingNumber;
        StartingNumber = startingNumber;
        thread = new Thread(this, name);
        thread.start();
        System.out.println("thread"+thread.getName()+"started");
    }
    synchronized public void run(){
        for(int i = StartingNumber;i<EndingNUmber;i++){
            for(int j = 1;j<=i;j++){
                if(i%j==0){
                    divisors[i]++;
                }
            }
        }
    }
    public void highestDivisors(){
        int highest=divisors[0];
        int j = 0;
        System.out.println(divisors[7560]);
        for(int i=0;i<10000;i++){
            if(highest<divisors[i]){
                highest = divisors[i];
                j = i;
            }
        }
        System.out.println("highest number of divisors = " + highest + "\nAnd the number is:" + j);
    }
}

public class clock{
    public static void main(String[] args) {
        T t1 = new T("first",0,2000);
        T t2 = new T("second",2000,4000);
        T t3 = new T("third",4000,6000);
        T t4 = new T("forth",6000,8000);
        T t5 = new T("fifth",8000,10000);
        t4.setPriority(1);
        t4.highestDivisors();
    }
}