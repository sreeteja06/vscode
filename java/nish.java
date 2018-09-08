import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
 
public class nish extends Frame
{
  static JFrame frame;
  static JLabel MovieLabel1, RatingLabel1;
  static int ratingNumbers[] = {6,8,3,6};
  static double rating[] = {4.5,2.5,3.4,2};
  static void nish(int a)
  {
    final String Moviename[] = {"xps15","fish","mutton","chicken"};
    frame = new JFrame();
    frame.setLayout(null);
    MovieLabel1 = new JLabel("Movie Name");
    MovieLabel1.setBounds(10, 10+(250*a), 100, 100);
    RatingLabel1 = new JLabel("Rating");
    RatingLabel1.setBounds(400, 10+(250*a), 100, 100);
    JTextField t1,t2,t3;  
    t1=new JTextField(Moviename[a]);  
    t1.setBounds(150,45+(250*a), 200,30);  
    t2=new JTextField(Double.toString(rating[a]));  
    t2.setBounds(500,45+(250*a), 200,30);
    t3 = new JTextField();
    t3.setBounds(750, 45+(250*a), 200, 30);
    t1.setEditable(false);    
    t2.setEditable(false);
    Button b1 = new Button("submit rating");
    b1.setBounds(1000, 45+(250*a), 100, 30);
    frame.add(b1);
    b1.addActionListener(new ActionListener()
    {
      public void actionPerformed(ActionEvent e)
      {
        double uservalue1 = Double.valueOf(t3.getText().trim()).floatValue();
        ratingNumbers[0] = ratingNumbers[0]+1;
        rating[0] = ((uservalue1)+(rating[0]*(ratingNumbers[0]-1)))/(ratingNumbers[0]);
        t2.setText(Double.toString(rating[0]));
      }
    });
    frame.add(t3);
    frame.add(t1); frame.add(t2);  
    frame.add(MovieLabel1);
    frame.add(RatingLabel1);
    //
    //
    //
    MovieLabel1 = new JLabel("Movie Name");
    MovieLabel1.setBounds(10, 10+(150*1), 100, 100);
    RatingLabel1 = new JLabel("Rating");
    RatingLabel1.setBounds(400, 10+(150*1), 100, 100);
    JTextField t4,t5,t6;  
    t4=new JTextField(Moviename[1]);  
    t4.setBounds(150,45+(150*1), 200,30);  
    t5=new JTextField(Double.toString(rating[1]));  
    t5.setBounds(500,45+(150*1), 200,30);
    t6 = new JTextField();
    t6.setBounds(750, 45+(150*1), 200, 30);
    t4.setEditable(false);    
    t5.setEditable(false);
    Button b2 = new Button("submit rating");
    b2.setBounds(1000, 45+(150*1), 100, 30);
    frame.add(b2);
    b2.addActionListener(new ActionListener()
    {
      public void actionPerformed(ActionEvent e)
      {
        double uservalue2 = Double.valueOf(t6.getText().trim()).floatValue();
        ratingNumbers[1] = ratingNumbers[1]+1;
        rating[1] = ((uservalue2)+(rating[1]*(ratingNumbers[1]-1)))/(ratingNumbers[1]);
        t5.setText(Double.toString(rating[1]));
      }
    });
    frame.add(t6);
    frame.add(t5); frame.add(t4);  
    frame.add(MovieLabel1);
    frame.add(RatingLabel1);
    //
    //
    //
    //
    //
    //
    MovieLabel1 = new JLabel("Movie Name");
    MovieLabel1.setBounds(10, 10+(150*2), 100, 100);
    RatingLabel1 = new JLabel("Rating");
    RatingLabel1.setBounds(400, 10+(150*2), 100, 100);
    JTextField t7,t8,t9;  
    t7=new JTextField(Moviename[2]);  
    t7.setBounds(150,45+(150*2), 200,30);  
    t8=new JTextField(Double.toString(rating[2]));  
    t8.setBounds(500,45+(150*2), 200,30);
    t9 = new JTextField();
    t9.setBounds(750, 45+(150*2), 200, 30);
    t7.setEditable(false);    
    t8.setEditable(false);
    Button b3 = new Button("submit rating");
    b3.setBounds(1000, 45+(150*2), 100, 30);
    frame.add(b3);
    b3.addActionListener(new ActionListener()
    {
      public void actionPerformed(ActionEvent e)
      {
        double uservalue3 = Double.valueOf(t9.getText().trim()).floatValue();
        ratingNumbers[2] = ratingNumbers[2]+1;
        rating[2] = ((uservalue3)+(rating[2]*(ratingNumbers[2]-1)))/(ratingNumbers[2]);
        t8.setText(Double.toString(rating[2]));
      }
    });
    frame.add(t9);
    frame.add(t8); frame.add(t7);  
    frame.add(MovieLabel1);
    frame.add(RatingLabel1);
    //
    //
    //
    //
    //
    //
    MovieLabel1 = new JLabel("Movie Name");
    MovieLabel1.setBounds(10, 10+(150*3), 100, 100);
    RatingLabel1 = new JLabel("Rating");
    RatingLabel1.setBounds(400, 10+(150*3), 100, 100);
    JTextField t10,t11,t12;  
    t10=new JTextField(Moviename[3]);  
    t10.setBounds(150,45+(150*3), 200,30);  
    t11=new JTextField(Double.toString(rating[3]));  
    t11.setBounds(500,45+(150*3), 200,30);
    t12 = new JTextField();
    t12.setBounds(750, 45+(150*3), 200, 30);
    t10.setEditable(false);    
    t11.setEditable(false);
    Button b4 = new Button("submit rating");
    b4.setBounds(1000, 45+(150*3), 100, 30);
    frame.add(b4);
    b4.addActionListener(new ActionListener()
    {
      public void actionPerformed(ActionEvent e)
      {
        double uservalue4 = Double.valueOf(t12.getText().trim()).floatValue();
        ratingNumbers[3] = ratingNumbers[3]+1;
        rating[3] = ((uservalue4)+(rating[3]*(ratingNumbers[3]-1)))/(ratingNumbers[3]);
        t11.setText(Double.toString(rating[3]));
      }
    });
    frame.add(t12);
    frame.add(t11); frame.add(t10);  
    frame.add(MovieLabel1);
    frame.add(RatingLabel1);
    //
    //
    //
    frame.setTitle("Movie Ratings");
    frame.setSize(300,300);
    frame.setVisible(true);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }
  public void actionPerformed(ActionEvent e){
    System.out.println("action performed");
  }
   public static void main(String[] args)
   {
     
     nish.nish(0);
     //nish.nish(1);
   }
  }
     /*b1.addActionListener(new ActionListener(){
       public void actionPerformed(ActionEvent e)
       {

       }
     });*/
   /*public static void main(String args[])
   {
     Frame f = new Frame("hello");
     f.setVisible(true);
     f.setLayout(null);
     f.setSize(800,800);
     TextField tf = new TextField("enter");
     tf.setBounds(80, 100, 40, 20);
     f.add(tf);
     Button bt = new Button("submit");
     bt.setBounds(100, 100, 40, 50);;
     f.add(bt);
     bt.addActionListener(new ActionListener()
    {
      public void actionPerformed(ActionEvent e)
      {
        tf.setText("hello");
      }
    });
   }}*/