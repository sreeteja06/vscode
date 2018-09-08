// Create multiple threads.
class MyThread implements Runnable {
int count;
Thread thrd;
// Construct a new thread.
MyThread(String name) {
thrd = new Thread(this, name);
count = 0;
thrd.start(); // start the thread
}
// Begin execution of new thread.
public void run() {
System.out.println(thrd.getName() + " started.");
try {
do {
Thread.sleep(2500);
System.out.println("In " + thrd.getName() +", Completed Stage " + count);
count++;
} while(count < 15);
}
catch(InterruptedException exc) {
System.out.println(thrd.getName() + " Accident.");
}
System.out.println(thrd.getName() + " Near to Deadend .");
}
}
class MoreThreads {
public static void main(String args[]) {
System.out.println("Car race started.");
MyThread mt1 = new MyThread("Car #1");
MyThread mt2 = new MyThread("Car #2");
MyThread mt3 = new MyThread("Car #3");
MyThread mt4 = new MyThread("Car #4");
MyThread mt5 = new MyThread("Car #5");
do {
System.out.print(".");
try {
//Thread.sleep(500);
mt1.thrd.join();
System.out.println("Child #1 Reached Deadend.");
mt2.thrd.join();
System.out.println("Child #2 Reached Deadend.");
mt3.thrd.join();
System.out.println("Child #3 Reached Deadend.");
mt4.thrd.join();
System.out.println("Child #4 Reached Deadend.");
mt5.thrd.join();
System.out.println("Child #5 Reached Deadend.");
}
catch(InterruptedException exc) {
System.out.println("Race interrupted.");
}
} while (mt1.thrd.isAlive() || mt2.thrd.isAlive() || mt3.thrd.isAlive()|| mt4.thrd.isAlive()|| mt5.thrd.isAlive());
//while (mt1.count < 15 ||mt2.count < 15 || mt3.count < 15|| mt4.count < 15|| mt5.count < 15);
System.out.println("Race has Completed.");
}
}