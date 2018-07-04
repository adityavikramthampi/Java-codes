import matrw.*;
import java.util.*;

class calsum //extends rw
{
   int sum = 0, tsum = 0;

   void matsum(rMat ob1)
   {
   
      for(int i = 0; i < ob1.m; i++)
      {
         sum = 0;
         for(int j = 0; j < ob1.n; j++)
         {
            System.out.print(ob1.a[i][j] + " ");
            sum = sum + ob1.a[i][j];	//calculating row sum
         }
         System.out.println(sum);
         tsum = tsum + sum;	//calculating total sum
      }

      for(int i = 0; i < ob1.n; i++)
      {
         sum = 0;
         for(int j = 0; j < ob1.m; j++)
            sum = sum + ob1.a[j][i];	//calculating column sum
      
         System.out.print(sum + " ");
      }

      System.out.println(tsum);
   }
}

class mainMat 
{

   public static void main(String args[])
   {
      //int a[][] = new int[10][10];

      rMat ob1 = new rMat();
      ob1.read();

      wMat ob2 = new wMat();
      ob2.write(ob1.m, ob1.n, ob1.a);

      System.out.println('\n');
      
      calsum ob3 = new calsum();
      ob3.matsum(ob1);
      
   }

}
   
