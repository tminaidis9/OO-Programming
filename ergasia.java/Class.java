public class Class extends Inschool2{
      
      Class(){
            super("Class");
      }

      int class_is_full(){
            if(get_C_class() == get_ppl_in() && get_teacher_in() == 1)
                  return 1;
            
            return 0;
      }
}

