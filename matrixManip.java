import java.util.*;

class matrix
{
    int a[][] = new int[10][10];
    Scanner sc = new Scanner(System.in);
    public int m, n;

    void readMatrix()
    {
        m = sc.nextInt();
        n = sc.nextInt();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = sc.nextInt();
    }


    void displayMatrix()
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                System.out.print(" " + a[i][j]);
            System.out.println();
        }
    }
    void addMatrix(matrix obj1, matrix obj2)
    {
       m = obj1.m;
       n = obj2.n;

       for(int i = 0; i < m; i++)
          for(int j = 0; j < n; j++)
              a[i][j] = obj1.a[i][j] + obj2.a[i][j];
    }
    void multMatrix(matrix obj1, matrix obj2)
    {
       m = obj1.m;
       n = obj2.n;
    
       for(int i = 0; i < m; i++)
           for(int j = 0; j < n; j++)
           {
              a[i][j]=0;
              for(int k = 0; k < obj1.n; k++)
                 a[i][j] = a[i][j] + obj1.a[i][k] * obj2.a[k][j];
           }
    }

}
class matrixManip
{
    public static void main(String args[])
    {
        matrix obj1 = new matrix();
        matrix obj2 = new matrix();
        matrix obj3 = new matrix();

        obj1.readMatrix();
        obj2.readMatrix();

        obj3.addMatrix(obj1, obj2);
        obj3.displayMatrix();

        obj3.multMatrix(obj1, obj2);
        obj3.displayMatrix();
    }
}
