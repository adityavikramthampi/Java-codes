class A extends Thread
{
   public void run()
   {
      for(int i = 1; i <= 50; i++)
      {
         if (i == 10) yield(); 
         System.out.println("\tFrom thread A: i = "+ i);
      }
      System.out.println("Exit from A");
   }
}

class B extends Thread
{
   public void run()
   {
      for(int j = 1; j <= 100; j++)
      {
         if (j == 30) stop(); 
         System.out.println("\tFrom thread B: j = "+ j);
      }
      System.out.println("Exit from B");
   }
}

class C extends Thread
{
   public void run()
   {
      for(int k = 1; k <= 200; k++)
      {
         System.out.println("\tFrom thread C: k = "+ k);
         if (k == 40)
            try
               {
                  sleep(1000);
               }
            catch (Exception e)
               {
//                  sleep(1000);
               } 
      }
      System.out.println("Exit from C");
   }
}

class samThread
{
   public static void main(String args[])
   {
      System.out.println("Start thread A");
      new A().start();

      System.out.println("Start thread B");
      new B().start();

      System.out.println("Start thread C");
      new C().start();

      System.out.println("End of main thread");

   }
}

