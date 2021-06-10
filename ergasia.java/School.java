import java.util.Scanner;

public class School {
      
      Floors first = new Floors("first");
      Floors second = new Floors("second");
      Floors third = new Floors("third");
      Yard yard = new Yard();
      Stairs stair = new Stairs();
      Student st = new Student("0","0",0,0);
      int N;

      School(){
            System.out.println("A New School Has Been Created");
            Scanner scan = new Scanner(System.in);
            System.out.println("Please write the C class");
            int c = scan.nextInt();
            first.set_C_class(c);
            second.set_C_class(c);
            third.set_C_class(c);

            System.out.println("Please write the Lj");
            c = scan.nextInt();
            first.set_Lj(c);
            second.set_Lj(c);
            third.set_Lj(c);

            System.out.println("Please write the Ls");
            c = scan.nextInt();
            first.set_Ls(c);
            second.set_Ls(c);
            third.set_Ls(c);

            System.out.println("Please write the Lt");
            c = scan.nextInt();
            first.set_Lt(c);
            second.set_Lt(c);
            third.set_Lt(c);

            System.out.println("Please write the N");
            c = scan.nextInt();
            N = c;
            first.set_N(c);
            second.set_N(c);
            third.set_N(c);

            first.set_all();
            second.set_all();
            third.set_all();
            // System.out.println("\n");
            scan.close();
      }

      void enter(Student s){
            s.set_where("School");
            st = s;
            System.out.println(s.get_name() + " Enters School");
            
            yard.enter_Yard(s);
            stair.enter_Stairs(s);

            int student_floor = s.get_floor(); 
            // cout << student_floor << endl;

            if (student_floor == 1)
                  first.enter_floor(s);
            else if (student_floor == 2)
                  second.enter_floor(s);
            else if (student_floor == 3)
                  third.enter_floor(s);
            else
                  System.out.println("Student's floor is wrong. End of program");
      }

      void enter(Teacher t){
            
            int fl = t.get_floor();

            if( fl == 1){
                  first.enter_floor(t);
            }
            else if(fl == 2){
                  second.enter_floor(t);
            }
            else if(fl == 3){
                  third.enter_floor(t);
            }
      }

      void exit_school(){
            System.out.println("Exit from School");
      }

      void print(){
            first.print();
            second.print();
            third.print();

      }

      int school_is_full(){
            
            if(first.floor_is_full() == 0 ||second.floor_is_full() == 0 || third.floor_is_full() == 0)
                  return 0;
      
            return 1;
      }

      void operate(){
            System.out.println( "School operate for " + N + " hours\n");
            first.operate();
            second.operate();
            third.operate();
      }

      void empty(){
            first.empty(this);
            second.empty(this);
            third.empty(this);
      }

      Stairs get_stair(){
            return stair;
      }

      Yard get_yard(){
            return yard;
      }
}
