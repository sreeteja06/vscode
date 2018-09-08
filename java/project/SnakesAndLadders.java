/*
                                            JAVA SEM 4 PROJECT
                                    Project title: Snakes and Ladders
                                Project members: M.Sree Teja  ------ 16stuhh0211
                                                 Anjani       ------ 16stuhh0198
                                                 Rishika      ------ 16stuhh0200

*/
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import java.io.*;
public class SnakesAndLadders extends Applet implements ActionListener{
    Button rollDice;
    int array[];
    Panel rolldicepanel;
    String player1msg="Player 1's Score : ";
    String player2msg="Player 2's Score : ";
    String details="2 players";
    int scoreP1=0,scoreP2=0;
    int turn=0;
    String msg=" ";
    String msg1=" ";
    String msg2=" ";
    Boolean ladder = false;
    Boolean snake = false;
    static String[] numbers={								//array of numbers to be displayed on the game board.
        "100","99","98","97","96","95","94","93","92","91",
        "81","82","83","84","85","86","87","88","89","90",
        "80","79","78","77","76","75","74","73","72","71",
        "61","62","63","64","65","66","67","68","69","70",
        "60","59","58","57","56","55","54","53","52","51",
        "41","42","43","44","45","46","47","48","49","50",
        "40","39","38","37","36","35","34","33","32","31",
        "21","22","23","24","25","26","27","28","29","30",
        "20","19","18","17","16","15","14","13","12","11",
        "1","2","3","4","5","6","7","8","9","10",
    };

    public void init()//starting applet
    {
        Font f=new Font("Verdana",Font.BOLD,12);//setting font
        setFont(f);
        setBackground(Color.white);//setting background
        rollDice=new Button("ROLL DICE");
        rollDice.addActionListener(this);
        setLayout(new BorderLayout());//setting layout
        rolldicepanel=new Panel();
        rolldicepanel.add(rollDice);
        add(rolldicepanel,BorderLayout.EAST);
        array=new int[]{0,0,0,0,0,0};
    }
    
    
    public void paint(Graphics g){
        setBackground(Color.white);
        FontMetrics fm=g.getFontMetrics();
        g.drawString(player1msg,760,230);
        g.drawString(player2msg,760,260);
        g.drawString(details,11,170);
        if(snake == true)
            {
                Font f=new Font("Verdana",Font.BOLD,30);
                g.setFont(f);
                g.setColor(Color.red);
                g.drawString("oops, you are bit by the snake", 760, 290);
                snake = false;
                Font font = new Font("Verdana", Font.BOLD , 15);
                g.setFont(font);
            }
        else if(ladder == true)
            {
                Font f=new Font("Verdana",Font.BOLD,30);
                g.setFont(f);
                g.setColor(Color.green);
                g.drawString("hurray, you found a ladder", 760, 290);
                ladder = false;
                Font font = new Font("Verdana", Font.BOLD , 15);
                g.setFont(font);
            }
        //drawing rectangles 100.
        int odd=0;
        int a=200,b=50;
        for(int i=1;i<101;i++){
            if(odd%2 == 0){
                g.setColor(Color.white);//setting alternate white and gray color background for each square on the board
                odd=1;
            }
            else{
                g.setColor(Color.gray);
                odd=0;
            }
            g.fillRect(a,b,50,50);//filling rectangle
            if(i%10 == 0){
                b=b+50;
                a=200;
                odd++;
            }
            else
                a=a+50;
        }
        
        //numbering 100 to 1;
        g.setColor(Color.black);
        a=220;
        b=70;
        for(int i=1;i<101;i++){
        
            if((Integer.toString(scoreP1)).equals(numbers[i-1]) && (Integer.toString(scoreP2)).equals(numbers[i-1])){ //if both players are at same location
                numbers[i-1] = "P1,P2";
                g.setColor(Color.pink);
                g.drawString(numbers[i-1],a-5,b);
                if(i%10 == 0){
                    b=b+50;
                    a=220;
                }
                else
                    a=a+50;
                numbers[i-1] = (Integer.toString(scoreP1));
            }
            else if((Integer.toString(scoreP1)).equals(numbers[i-1])){//replacing the square number with the name of player occupying that position
                numbers[i-1] = "P1";
                g.setColor(Color.pink);
                g.drawString(numbers[i-1],a,b);
                if(i%10 == 0){
                b=b+50;
                a=220;
                }
                else
                    a=a+50;
                numbers[i-1] = (Integer.toString(scoreP1));

            }
            else if((Integer.toString(scoreP2)).equals(numbers[i-1])){//replacing the square number with the name of player 2 occupying that position.
                g.setColor(Color.blue);
                numbers[i-1] = "P2";
                g.drawString(numbers[i-1],a,b);
                if(i%10 == 0){
                    b=b+50;
                    a=220;
                }
                else
                    a=a+50;
                numbers[i-1] = (Integer.toString(scoreP2));
            }
            else{
                g.setColor(Color.black);
                g.drawString(numbers[i-1],a,b);                             
                if(i%10 == 0){
                    b=b+50;
                    a=220;
                }
                else
                    a=a+50;
            }
        }
        g.setColor(Color.black);
        g.drawLine(200,50,700,50);
        g.drawLine(200,50,200,550);
        g.drawLine(700,50,700,550);
        g.drawLine(200,550,700,550);
        //borders
    
        g.drawLine(750,100,900 ,100);
        g.drawLine(750,100,750,150);
        g.drawLine(900,100,900,150);
        g.drawLine(750,150,900,150);
        g.setColor(Color.red);
        //99-44 snake
    
        g.drawLine(275,75,375,325);
        g.drawLine(274,75,374,325);
        g.drawLine(276,75,376,325);
        //97-76 snake
    
        g.drawLine(375,75,425,175);
        g.drawLine(374,75,424,175);
        g.drawLine(376,75,426,175);
        //72-11 snake
    
        g.drawLine(625,175,675,475);
        g.drawLine(624,175,674,475);
        g.drawLine(626,175,676,475);
        
        //55 - 4 snake
        g.drawLine(475,275,375,525);
        g.drawLine(474,275,374,525);
        g.drawLine(476,275,376,525);
    
        //34 - 13 snake
        g.drawLine(525,375,575,475);
        g.drawLine(524,375,574,475);
        g.drawLine(526,375,576,475);
        g.setColor(Color.green);

        //3 - 41 ladder
        g.drawLine(325,525,225,325);
        g.drawLine(324,525,224,325);
        g.drawLine(326,525,226,325);
    
        //26 - 67 ladder
        g.drawLine(475,425,525,225);
        g.drawLine(474,425,524,225);
        g.drawLine(476,425,526,225);
    
        //26 - 67 ladder
        g.drawLine(375,375,425,225);
        g.drawLine(374,375,424,225);
        g.drawLine(376,375,426,225);
    
        //69 - 96 ladder
        g.drawLine(625,225,425,75);
        g.drawLine(624,225,424,75);
        g.drawLine(626,225,426,75);
    
        //60 - 79 ladder
        g.drawLine(225,275,275,175);
        g.drawLine(224,275,274,175);
        g.drawLine(226,275,276,175);
    
        Font f=new Font("Verdana",Font.BOLD,30);
        g.setFont(f);
        g.setColor(Color.red);
        g.drawString("SNAKES",10,60);
        g.drawString("&",20,100);
        g.drawString("LADDERS",10,140);
        Font font = new Font("Verdana", Font.BOLD , 15);
        g.setFont(font);
        g.setColor(Color.black);
        g.drawString("NUMBER ON THE DICE", 750, 75);
        Font font1 = new Font("Verdana",Font.BOLD , 15);
        g.setFont(font1);
        for(int n=0;n<1;n++){
            g.setColor(Color.black);
            Integer I = new Integer(array[n]);
            g.drawString(I.toString(), 800, 125);
        }
        g.setColor(Color.black);
        g.drawString(" "+scoreP1,900,230);//printing information
        g.drawString(" "+scoreP2,900,260);
        g.drawString(" "+msg,750,170);
        g.drawString(" "+msg1,750,210);
        g.drawString(" "+msg2,750,210);
    }
    
    
    
    
    public void actionPerformed(ActionEvent ev){
        if(msg!="----GAME-OVER----"){
            int exist=0;
            int n =1;
            turn++;
            Random rnd = new Random();
            int i = Math.abs(rnd.nextInt() % 7);
            while(i==0)i = Math.abs(rnd.nextInt() % 7);
            array[0]= i;
            current_score(i,turn);
            repaint();
        }
    }
    
    
    public void current_score(int i,int turn){
        if (turn%2==0 && (scoreP1+i)<=100 && msg!="----GAME-OVER----"){
            msg1="Player 2 to play";
            msg2="";
            if(i<=6)
                scoreP1=scoreP1+i;
            if(scoreP1==3)//logic for ladder
                {scoreP1=scoreP1+38;
                ladder = true;}
            else if(scoreP1==26)//logic for ladder
                {scoreP1=scoreP1+41;
                ladder = true;}
            else if(scoreP1==37)//logic for ladder
                {scoreP1=scoreP1+28;
                ladder = true;}
            else if(scoreP1==60)//logic for ladder
                {scoreP1=scoreP1+19;
                ladder = true;}
            else if(scoreP1==69)//logic for ladder
                {scoreP1=scoreP1+27;
                ladder = true;}
            turn--;
            if(scoreP1==99)//logic for snake
                {scoreP1=scoreP1-55;
                snake = true;}
            else if(scoreP1==97)//logic for snake
                {scoreP1=scoreP1-21;
                snake = true;}
            else if(scoreP1==72)//logic for snake
                {scoreP1=scoreP1-61;
                    snake = true;}
            else if(scoreP1==55)//logic for snake
                {scoreP1=scoreP1-51;
                    snake = true;}
            else if(scoreP1==34)//logic for snake
                {scoreP1=scoreP1-21;
                    snake = true;}
        }
        else if(turn%2!=0 &&(scoreP2+i)<=100 && msg!="----GAME-OVER----"){
            msg2="Player 1 to play";
            msg1="";
            if(i<=6)
                scoreP2=scoreP2+i;
            if(scoreP2==3)//logic for ladder
                {scoreP2=scoreP2+38;
                    ladder = true;}
            else if(scoreP2==26)//logic for ladder
                {scoreP2=scoreP2+41;
                    ladder = true;}
            else if(scoreP2==37)//logic for ladder
                {scoreP2=scoreP2+28;
                    ladder = true;}
            else if(scoreP2==60)//logic for ladder
                {scoreP2=scoreP2+19;
                    ladder = true;}
            else if(scoreP2==69)//logic for ladder
                {scoreP2=scoreP2+27;
                    ladder = true;}
            turn--;//player will get a turn again
            if(scoreP2==99)//logic for snakes
                {scoreP2=scoreP2-55;
                    snake = true;}
            else if(scoreP2==97)//logic for snake
                {scoreP2=scoreP2-21;
                    snake = true;}
            else if(scoreP2==72)//logic for snake
                {scoreP2=scoreP2-61;
                    snake = true;}
            else if(scoreP2==55)//logic for snake
                {scoreP2=scoreP2-51;
                    snake = true;}
            else if(scoreP2==34)//logic for snake
                {scoreP2=scoreP2-21;
                    snake = true;}
        }
        if(scoreP1==100||scoreP2==100){
            msg="----GAME-OVER----";
            if(scoreP1==100)
                msg1=" Wooooooooooooh!!! PLAYER-1 Wins";
            else
                msg2=" Wooooooooooooh!!! PLAYER-2 Wins";
        }
	}

}
/* <applet code = "SnakesAndLadders" width = 1200 height = 900>
</applet>
*/
