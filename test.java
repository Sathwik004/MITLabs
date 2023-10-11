import java.util.Scanner;

interface A{
    void show();
}
class B implements A{
    public void show()
    {
        System.out.println("Inside B");
    }
}
public class Main {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("HII");
    }
}
