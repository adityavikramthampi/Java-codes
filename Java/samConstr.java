import java.util.*;

class initiateZero
{
   int a[][] = new int[20][41];

   initiateZero()
   {
      for(int i = 0; i < 20; i++)
         for(int j = 0; j < 41; j++)
            a[i][j] = 0;
   }

   initiateZero(int b[][], int m)
   {
      for(int i = 0; i < m; i++)
         for(int j = 0; j <= (m*2); j++)
            b[i][j] = 0;
   }

}

class pascal extends initiateZero
{   
   pascal()
   {
//      super();
   
      int i, j, n = 5;      

      a[0][n] = 1;

      for(i = 1; i < n; i++)
         for(j = 1; j <= (n*2); j++)
            a[i][j] = a[i-1][j-1] + a[i-1][j+1];

      for(i = 0; i < n; i++)
      {
         for(j = 0; j <= (n*2); j++)
         {
            if(a[i][j] == 0)
               System.out.print("  ");
            else
               System.out.print(a[i][j] + " ");
         }
         System.out.println();
      }
               
   }

   pascal(int c[][], int m)
   {
//      super(c,m);   
      int i, j;
      c[0][m] = 1;

      for(i = 1; i < m; i++)
         for(j = 1; j <= (m*2); j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j+1];

      for(i = 0; i < m; i++)
      {
         for(j = 0; j <= (m*2); j++)
         {
            if(c[i][j] == 0)
               System.out.print("  ");
            else
               System.out.print(c[i][j] + " ");
         }
         System.out.println();
      }
               
   }


}


class samConstr
{
   public static void main(String args[])
   {
      int n;
      int b[][] = new int[20][41];

      Scanner sc = new Scanner(System.in);
      System.out.print("Enter no of rows: ");
      n = sc.nextInt();

      pascal ob1 = new pascal();
      pascal ob2 = new pascal(b,n);
   }

}





