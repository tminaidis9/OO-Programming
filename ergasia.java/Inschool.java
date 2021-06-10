public class Inschool {
      
      String name;

      Inschool(String nm){
            name = nm;
            System.out.println(name + " created");
      }

      void enter_inschool(Student s){
            System.out.println(s.get_name() + " Enters " + name);
            System.out.println(s.get_name() + " Exit " + name);
      }

      void enter_inschool(Teacher t){
            System.out.println(t.get_name() + " Enters " + name);
            System.out.println(t.get_name() + " Exit " + name);
      }

}
