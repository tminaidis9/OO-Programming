public class Inschool2 {
      
      Student [] students_in = new Student[1];
      String name;
      int teacher_in = 0;
      Teacher teacher;
      String class_teacher;
      int C_class;
      int L,Lt;
      int hours;
      int ppl_in = 0;

      Inschool2(String nm){
            name = nm;
      }

      void set_all(int C,int l,int t,int N){
            C_class = C;
            L = l;
            Lt = t;
            hours = N;
      }

      int get_ppl_in(){
            return ppl_in;
      }

      int get_C_class(){
            return C_class;
      }

      int get_teacher_in(){
            return teacher_in;
      }

      int enter_Class(Student s){
            if(name == "Class"){
                  if (C_class > ppl_in){
                        
                        Student [] new_stud_in = new Student[ppl_in + 1];
                        for(int i = 0 ; i < ppl_in ; i++)
                              new_stud_in[i] = students_in[i];
                        
                        new_stud_in[ppl_in] = s;
                        students_in = new Student[ppl_in + 1];
                        students_in = new_stud_in;
                        
                        ppl_in += 1;
      
                        if(teacher_in == 1){
                              ppl_in -= 1;
                              System.out.println( "teacher is in class. You can't go in " + s.get_name());
                              return 0;
                        }
                        
                        System.out.println(s.get_name() + " Exit Corridor");
                        s.set_where(name);
                        System.out.println(s.get_name() + " Enters " + name);
                        return 1;
                  }
                  System.out.println("Class is full. You can't go in");
            }
            else{
                  System.out.println(s.get_name() + " Enters " + name );
                  Student [] new_stud_in = new Student[ppl_in + 1];
                        for(int i = 0 ; i < ppl_in ; i++)
                              new_stud_in[i] = students_in[i];
                        
                        new_stud_in[ppl_in] = s;
                        students_in = new Student[ppl_in + 1];
                        students_in = new_stud_in;
                        
                        ppl_in += 1;
            }
            return 1;
      }

      void enter_Class(Teacher t){
            if(teacher_in == 00){
                  teacher_in = 1;
                  class_teacher = t.get_name();
                  teacher = t;
                  System.out.println("Teacher " + t.get_name() + (" is in class"));
            }
            else{
                  System.out.println("This class has already a teacher");
            }
      }

      void exit_Corridor(Student s){
            ppl_in -= 1;
      }

      void print(){
            System.out.println("People in " + name + " are:");
            for(int i = 0 ; i < ppl_in ; i++)
                  System.out.println(students_in[i].get_name() + " with bk = " + students_in[i].get_bk());
            
            if(this.name == "Class")
                  System.out.println("Teacher " + teacher.get_name() + "with bk = " + teacher.get_bk());
      }

      void operate(){
            if(ppl_in > 0){
                  int hl = hours * L;
                  for(int i = 0 ; i < ppl_in ; i++){
                       students_in[i].set_bk(hl);
                 }
           }
           if(teacher_in > 0){
                  int hl = hours * Lt;
                 teacher.set_bk(hl);
           }
      }

      void exit(Student s){
            System.out.println(s.get_name() + " exit" + name);
            ppl_in -= 1;
            
      }

      void empty(School sc,Floors fl){
            Student s;
            for(int i = 0; i < ppl_in ; i++){
                  s = students_in[i];
                  System.out.println(s.get_name() + " start exiting");
                  exit(s);
                  if(name.equals("Class")){
                        fl.get_coridor().enter_Corridor(s);
                        fl.get_coridor().exit_Corridor(s);
                        System.out.println(s.get_name() + " Exit Corridor");
                  }
                  sc.get_stair().enter_Stairs(s);
                  sc.get_yard().enter_Yard(s);
            }

            if(name.equals("Class")){
                  System.out.println(teacher.get_name() + " start exiting");
                  sc.get_stair().enter_Stairs(teacher);
                  sc.get_yard().enter_Yard(teacher);
            }
      }

}
