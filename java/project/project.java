import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.*;
import java.util.Random;
import java.util.Scanner;
import java.io.*;

public class project {

  public static void main(String[] args) throws Exception {
    SnakeNLadder s = new SnakeNLadder();
    s.startGame();
  }
}
class superstart{
  static int DisplaySave()
  {
    for(int i=0;i<50;i++){
      System.out.println(); 
    }
    System.out.println("\t\t\t\t\t\t\tDo u wanna continue the last played game?");
    System.out.println("\t\t\t\t\t\t\t\t\t[Y\\N]");
    Scanner sc = new Scanner(System.in);
    for(int i=0;i<20;i++){
      System.out.println(); 
    }
    char ch = sc.next().charAt(0);
    if(ch == 'Y' || ch == 'y')
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  static void DisplayPlayerStatus(int player[])
  {
    for(int i=0;i<50;i++){
      System.out.println(); 
    }
    System.out.println("\t\t\t\t\t\t\t\tFirst Player :: " + player[0]);
    System.out.println("\t\t\t\t\t\t\t\tSecond Player :: " + player[1]);
    System.out.println("\t\t\t\t\t\t\t\t------------------");
  }
  static void DisplayPlayerTurn(int currentPlayer)
  {
    System.out.println("\t\t\t\t\t\t\t\t------------------");
    System.out.println(currentPlayer==-1?"\n\n\t\t\t\t\t\t\t\tFIRST PLAYER TURN":"\n\n\t\t\t\t\t\t\t\tSECOND PLAYER TURN");
    System.out.println("\t\t\t\t\t\t\t\tPress r to roll Dice");
  }
}
class write{
  static void write_file(int players[])
  {
    try(Writer writer=new BufferedWriter(new FileWriter("temp.txt")))
    {
      for(int i=0;i<players.length;i++)
      {
        writer.write(" "+ String.valueOf(players[i]) );
      }
      writer.close();
    }
    catch(IOException e){
      e.printStackTrace();
    }
  }
}
class SnakeNLadder
{
  
  final static int WINPOINT = 100;
  
  
  static Map<Integer,Integer> snake = new HashMap<Integer,Integer>();
  static Map<Integer,Integer> ladder = new HashMap<Integer,Integer>();
  
  {
    snake.put(99,54);
    snake.put(70,55);
    snake.put(52,42);
    snake.put(25,2);
    snake.put(95,72);
    snake.put(97,1);
    snake.put(80,17);
    snake.put(76,25);
    
    ladder.put(6,25);
    ladder.put(11,40);
    ladder.put(60,85);
    ladder.put(46,90);
    ladder.put(17,69);
  }
  
  public int rollDice()
  {
    int n = 0;
    Random r = new Random();
    n=r.nextInt(7);
    while(n==0)
    {
      n = r.nextInt(7);
    }
    System.out.print("\t\t\t\t\t\t\t\tDice value:\n\t\t\t\t\t\t\t\t");
    System.out.println(n);
    try        
    {
        Thread.sleep(1000);
    } 
    catch(InterruptedException ex) 
    {
        Thread.currentThread().interrupt();
    }
    return n;
  }
  
  public void startGame()
  {
    int player[] = new int[4];
    int currentPlayer = -1;
    Scanner s = new Scanner(System.in);
    String str;
    int diceValue =0;
    int resume_game = superstart.DisplaySave();
    if(resume_game == 0)
    {
      player[0] = 0;
      player[1] = 0;
    }
    else if(resume_game == 1)
    {
        try{  
          /***int a[] = new int[2];
          int i = 0;
          Scanner sc = new Scanner(file);
          while(sc.hasNextInt())
          {
              a[i++] = sc.nextInt();
          }
          sc.close();
          System.out.println(a[0]);
          System.out.println(a[1]);***/
          Scanner scanner = new Scanner(new File("temp.txt"));
          int i = 0;
          while (scanner.hasNextInt()) {
          player[i++] = scanner.nextInt();
          }
          scanner.close();
          superstart.DisplayPlayerStatus(player);
      }
      catch(Exception e)
      {
          e.printStackTrace();
      }
    }
    do
    {
      superstart.DisplayPlayerTurn(currentPlayer);
      System.out.print("\t\t\t\t\t\t\t\t");
      str = s.next();
      diceValue = rollDice();
      if(currentPlayer == -1)
      {
        player[0] = calculatePlayerValue(player[0],diceValue);
        superstart.DisplayPlayerStatus(player);
        if(isWin(player[0]))
        {
          System.out.println("First player wins");
          player[0] = 0;
          player[1] = 0;
          write.write_file(player);
          return;
        }
        write.write_file(player);
      }
      else
      {
        player[1] = calculatePlayerValue(player[0],diceValue);
        superstart.DisplayPlayerStatus(player);
        if(isWin(player[1]))
        {
          System.out.println("Second player wins");
          player[0] = 0;
          player[1] = 0;
          write.write_file(player);
          return;
        }
        write.write_file(player);
      }
      currentPlayer= -currentPlayer;  
    }while("r".equals(str));
    
  }
  
  
  public int calculatePlayerValue(int player, int diceValue)
  {
    player = player + diceValue;
    if(player > WINPOINT)
    {
      player = player - diceValue;
      return player;
    }
    
    if(null!=snake.get(player))
    {
      System.out.println("swallowed by snake");
      player= snake.get(player);
      try        
      {
          Thread.sleep(2000);
      } 
      catch(InterruptedException ex) 
      {
          Thread.currentThread().interrupt();
      }
    }
    
    if(null!=ladder.get(player))
    {
      System.out.println("climb up the ladder");
      player= ladder.get(player);
      try        
      {
          Thread.sleep(2000);
      } 
      catch(InterruptedException ex) 
      {
          Thread.currentThread().interrupt();
      }
    }
    return player;
  }
  
  public boolean isWin(int player)
  {
    return WINPOINT == player;
  }

}