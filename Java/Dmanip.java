import java.util.*;
class manip
{
    Scanner sc = new Scanner(System.in);
    int a[] = new int[100];
    int n; 

    void read()
    {
        System.out.println("Enter the number of entries");
        n = sc.nextInt();

        System.out.println("Enter "+n+" entries");
        for(int i = 0; i < n; i++)
            a[i] = sc.nextInt();
    }
    void display()
    {
        for(int i = 0; i < n; i++)
            System.out.print(a[i] + " ");
        System.out.println("\n");
    }
    void sort()
    {
        int temp;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
    }
    void merge(manip ob1, manip ob2)
    {
        int i = 0, j = 0, k = 0;
        n = ob1.n + ob2.n;
        
        while( (i < ob1.n) && (j < ob2.n) )
        {
            if(ob1.a[i] < ob2.a[j])
            {
                a[k] = ob1.a[i];
                ++k;
                ++i;
            }
            else
            {
                a[k] = ob2.a[j];
                ++k;
                ++j;
            }
        }
        while(i < ob1.n)
        {
            a[k] = ob1.a[i];
            ++k;
            ++i;
        }
        while(j < ob2.n)
        {
            a[k] = ob1.a[j];
            ++k;
            ++j;
        }
    }
    void delete(int no)
    {
        int i; 
        for( i = 0; i < n; i++)
            if(a[i] == no)
                break;
        while(i < n-1)
        {
            a[i] = a[i+1];
            ++i;
        }
        --n;
    }
    void insert(int no)
    {
        int i = 0, x;
        
        while(a[i] < no)
            ++i;
        x = i;
        i = n;
    
        while(i > x)
        {
            a[i] = a[i-1];
            --i;
        }
        a[x] = no;
        ++n;
    }
}

class Dmanip
{
    public static void main(String args[])
    {
        manip ob1 = new manip();
        manip ob2 = new manip();
        manip ob3 = new manip();

        ob1.read();
        ob1.display(); 
        ob2.read();
        ob2.display(); 
        ob1.sort();
        ob2.sort();
        ob3.merge(ob1, ob2);
        ob3.display();
        ob3.delete(4);
        ob3.display();
        ob3.insert(10);
        ob3.display();
    }
}




           







