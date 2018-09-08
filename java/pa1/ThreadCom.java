// Use wait() and notify() to create a ticking clock.
class TickTock {
synchronized void tick(boolean running) {
if(!running) { // stop the clock
//notify(); // notify any waiting threads
return;
}
System.out.print("Tick ");
//notify(); // let tock() run
//try {
//wait(); // wait for tock() to complete
//}
//catch(InterruptedException exc) {
//System.out.println("Thread interrupted.");
//}
}
synchronized void tock(boolean running) {
if(!running) { // stop the clock
//notify(); // notify any waiting threads
return;
}
System.out.println("Tock");
//notify(); // let tick() run
//try {
//wait(); // wait for tick to complete
//}
//catch(InterruptedException exc) {
//System.out.println("Thread interrupted.");
//}
}
}
class MyThread implements Runnable {
Thread thrd;
TickTock ttOb;
// Construct a new thread.
MyThread(String name, TickTock tt) {
thrd = new Thread(this, name);
ttOb = tt;
thrd.start(); // start the thread
}
// Begin execution of new thread.
public void run() {
if(thrd.getName().compareTo("Tick") == 0) {
for(int i=0; i<5; i++) ttOb.tick(true);
ttOb.tick(false);
}
else {
for(int i=0; i<5; i++) ttOb.tock(true);
ttOb.tock(false);
}
}
}
class ThreadCom {
public static void main(String args[]) {
TickTock tt = new TickTock();
MyThread mt1 = new MyThread("Tick", tt);
MyThread mt2 = new MyThread("Tock", tt);
try {
mt1.thrd.join();
mt2.thrd.join();
} catch(InterruptedException exc) {
System.out.println("Main thread interrupted.");
}
}
}