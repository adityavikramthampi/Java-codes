import java.util.*;

/*class student
{
   String name = new String();
   String rollno = new String();
   int pcm;
}
*/

class samVector
{
   public static void main(String args[])
   {
//      student sarry[] = new student[5];
//      Vector list = new Vector();

//      Scanner sc = new Scanner(System.in);
//      int n = sc.nextInt();
    
//      for(int i = 0; i < n; i++)
//         list.addElement(sc.next());

//      list.insertElementAt("COBOL", 2);

//      String listArray[] = new String[(list.size())];
//      list.copyInto(listArray);

//      for(int i = 0; i < list.size(); i++)
//         System.out.print(listArray[i] + " ");

      Vector v = new Vector();
        
         
        v.add(0, 1);
        v.add(1, 2);
        v.add(2, "geeks");
        v.add(3, "forGeeks");
        v.add(4, 3);
        
        System.out.println("Vector is: " + v);
         
        //clearing the vector
        v.clear();
         
        // checking vector
        System.out.println("after clearing: " + v);

   }

}

