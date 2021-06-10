public class Yard extends Inschool{

      Yard(){
            super("Yard");
      }
      
      void enter_Yard(Student s){
            enter_inschool(s);
      }

      void enter_Yard(Teacher t){
            enter_inschool(t);
      }
}
