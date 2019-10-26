import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.Random;

public class DiceGameJavaThreads {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int base = 0;
        double dice;
        double victory;
        double rollTwo;
        Player one = new Player();
        Player two = new Player();
        int i = 0;
        System.out.println("                                    Hello! Welcome to the lucky star game!\n");
        System.out.println("                                        Press any key to start the game\n");
        System.out.print("Enter name for player one: ");
        one.name = (input.next());
        System.out.print("Enter name for player two: ");
        two.name = (input.next());
        System.out.print("First to number of stars? ");
        victory = input.nextInt();
        while (one.total <= victory && two.total <= victory) {
            System.out.print(one.name + ", press any key to roll the dice");
            try{        System.in.read();}catch(Exception e){	e.printStackTrace();}
            Dice rollOne = new Dice(base);
            Thread t1 = new Thread(rollOne);
            t1.start();                         //start thread
            try {
                t1.join();                      //join thread
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            dice = rollOne.a;                   //sets roll value to dice
            one.move = dice;
            one.total += one.move;
            System.out.println(one.name + " rolled the dice for " + one.move);
            if (one.total == victory) {
                System.out.print(one.name + ": ");
                for (i = 0; i < one.total; ++i) {
                    System.out.print("*");
                }
                System.out.print(" Stars(" +one.total + ")");
                System.out.println("");
                System.out.println("--------------------------------------");
                break;
            } else if (one.total > victory) {
                one.over = one.total - (victory);
                System.out.println("Oops, you went over the victory by "+ one.over);
                one.total = victory - one.over;
                one.total = Math.abs(one.total);
            }
            System.out.print(one.name + ": ");
            for (i = 0; i < one.total; ++i) {
                System.out.print("*");
            }
            System.out.print(" Stars(" + one.total + ")");
            System.out.println("");
            System.out.println("--------------------------------------");
            //player two
            System.out.print(two.name + ", press any key to roll the dice");
            try{        System.in.read();}catch(Exception e){	e.printStackTrace();}
            DiceTwo diceTwo = new DiceTwo(10);
            try {
                Future<Integer> result = Executors.newCachedThreadPool().submit(diceTwo);       //calls the thread after it is finish rolling
                rollTwo = result.get();
                two.move = rollTwo;                                                             //set the roll to two.move
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }
            two.total += two.move;
			System.out.println("");
            System.out.println(two.name + " rolled the dice for " + two.move);
            if (two.total == victory) {
                System.out.print(two.name + ": ");
                for (i = 0; i < two.total; ++i) {
                    System.out.print("*");
                }
                System.out.print(" Stars(" +two.total + ")");
                System.out.println("");
                System.out.println("--------------------------------------");
                break;
            } else if (two.total > victory) {
                two.over = two.total - (victory);
                System.out.println("\nOops, you went over the victory by "+ two.over);
                two.total = victory - two.over;
                two.total = Math.abs(two.total);
            }
            System.out.print(two.name + ": ");
            for (i = 0; i < two.total; ++i) {
                System.out.print("*");
            }
            System.out.print(" Stars(" + two.total + ")");
            System.out.println("");
            System.out.println("--------------------------------------");

        }
        if (one.total > two.total)
        {
            System.out.println(one.name + ", you won the game!");
            for (i = 0; i < one.total; ++i)
            {
                System.out.print("*");
            }
            System.out.print(" Stars(" + one.total + ")");
        }
        else
        {
            System.out.println(two.name + ", you won the game!");
            for (i = 0; i < two.total; ++i)
            {
                System.out.print("*");
            }
            System.out.print(" Stars(" + two.total + ")");
        }

    }
}


class Player
{
    public String name;
    public double total;
    public double over;
    public double move;

    public Player ()
    {
        total = 0;
        over = 0;
        move = 0;
    }
}

class Dice implements Runnable {               //roll the dice using runnable

    int a;

    public Dice(int a) {
        this.a = a;
    }

    public void run() {
        Random();
    }

    public void Random() {
        int min = 1;
        int max = 6;
        Random rand = new Random();
        int n = (int)(Math.random()*((max-min)+1))+min;
        synchronized (this) {
            a = n;
        }
    }
}

class DiceTwo implements Callable<Integer> {              //roll the dice using callable
    private int temp = 0;

    public DiceTwo(int temp) {
        this.temp = temp;
    }

    @Override
    public Integer call() {
        temp = (int)getRandomIntegerBetweenRange(1,6);
        return temp;
    }
    public static double getRandomIntegerBetweenRange(double min, double max){
        double x = (int)(Math.random()*((max-min)+1))+min;
        return x;
    }
}






