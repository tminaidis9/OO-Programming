public class Teacher extends People{
      
      Teacher(String f, String l, int fl, int cl){
            
            super(f,l,fl,cl);
            System.out.println("Teacher " + f + " " + l + " is our new student");

      }

      void print(){
            System.out.println("Teacher name is " + this.get_name());
      }
}
