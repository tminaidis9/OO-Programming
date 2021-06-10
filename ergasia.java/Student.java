public class Student extends People{
      
      Student(String f, String l, int fl, int cl){
            
            super(f,l,fl,cl);
            System.out.println("Student " + f + " " + l + " is our new student");

      }

      void print(){
            System.out.println("Student name is " + this.get_name());
      }
}
