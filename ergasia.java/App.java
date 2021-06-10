import java.io.File;
import java.util.Scanner;
// import java.io.FileNotFoundException; 

class App {
     public static void main(String[] args) throws java.io.FileNotFoundException{
        
        File file = new File("C:\\Users\\θοδωρης\\Documents\\di\\3o\\OOprogramming\\ergasia.java\\filename");
        School new_school = new School();

        String f,l,x;
        String fl2,cl2;
        int fl,cl;
        char fl3,cl3;
        Student stud ;
        Teacher teach; 
        Scanner new_scan = new Scanner(file);

  
        System.out.println("Enter student or teacher?");
        x = new_scan.nextLine();
        System.out.println(x);
        System.out.println("Enter his name");    // mexri to yard na gemisei kai na einai iso CYard me toplithos sto yard
        f = new_scan.nextLine();
        l = new_scan.nextLine();
        System.out.println(f);
        System.out.println(l);
        System.out.println("His/Her floor");
        fl2 = new_scan.nextLine();
        fl3 = fl2.charAt(0);
        fl = fl3 - 48;
        System.out.println(fl);
        System.out.println("His/Her class");
        cl2 = new_scan.nextLine();
        cl3 = cl2.charAt(0);
        cl = cl3 - 48;
        System.out.println(cl);
        String st = new String("s");
        String te = new String("t");
  
        while (new_school.school_is_full() == 0){
              if(x.equals(st)){
                    stud = new Student(f,l,fl,cl);
                    stud.print();
                    new_school.enter(stud);
              }
              else if(x.equals(te)){
                    teach = new Teacher(f,l,fl,cl);
                    new_school.enter(teach);
              }
              else {
                    System.out.println("wrong type of people");
              }
  
              if(new_school.school_is_full() != 0)
                    break;
              
            System.out.println("Enter student or teacher?");
            x = new_scan.nextLine();
            System.out.println("Enter his name");    // mexri to yard na gemisei kai na einai iso CYard me toplithos sto yard
            f = new_scan.nextLine();
            l = new_scan.nextLine();
            System.out.println("His/Her floor");
            fl2 = new_scan.nextLine();
            fl3 = fl2.charAt(0);
            fl = fl3 - 48;
            System.out.println("His/Her class");
            cl2 = new_scan.nextLine();
            cl3 = cl2.charAt(0);
            cl = cl3 - 48;
        }
        
        System.out.println("\n");
        new_school.operate();
        new_school.print();
        new_scan.close();
        new_school.empty();
  
  
    }
}