import java.util.*;

interface int1
{
   void add(int a, int b);
}

interface int2
{
   void mul(int a, int b);
}

class imp implements int1, int2
{
   public void add(int a, int b)
   {
      System.out.println("Sum = " + (a + b));
   }

   public void mul(int a, int b)
   {
      System.out.println("Product = " + (a * b));
   }

}

class samInterface
{
   public static void main(String args[])
   {
      int1 i10;
      int2 i20;

      imp iclass = new imp();

      i10 = iclass;
      i10.add(10, 20);

      i20 = iclass;
      i20.mul(3, 4);
   }

}
