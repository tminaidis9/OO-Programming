public class Floors {
      
      int C_class;
      Corridor corridor = new Corridor();
      Class c1 = new Class();
      Class c2 = new Class();
      Class c3 = new Class();
      Class c4 = new Class();
      Class c5 = new Class();
      Class c6 = new Class();
      int Lt,Ls,Lj,N;
      String name;

      Floors(String nm){
            System.out.println("Floor created");
            name = nm;
      }

      void set_C_class(int num){
            C_class = num;
      }

      void set_Lt(int num){
            Lt = num;
      }

      void set_Ls(int num){
            Ls = num;
      }
      
      void set_Lj(int num){
            Lj = num;
      } 

      void set_N(int num){
            N = num;
      }

      int get_C_class(){
            return C_class;
      }

      int enter_floor(Student s){
            
            System.out.println(s.get_name() + " Enters Floor" );

            int st_class = s.get_class();
            corridor.enter_Corridor(s);
            
            if (st_class == 1){
                  if(c1.enter_Class(s) == 1)
                        corridor.exit_Corridor(s);
            }
            else if(st_class == 2){
                  if(c2.enter_Class(s) == 1)
                        corridor.exit_Corridor(s);
            }
            else if(st_class == 3){
                  if(c3.enter_Class(s) == 1)
                        corridor.exit_Corridor(s);
            }
            else if(st_class == 4){
                  if(c4.enter_Class(s) == 1)
                        corridor.exit_Corridor(s);
            }
            else if(st_class == 5){
                  if(c5.enter_Class(s) == 1)
                        corridor.exit_Corridor(s);
            }
            else{
                  if(c6.enter_Class(s) == 1)
                        corridor.exit_Corridor(s);
            }

            return 1;
      }

      void enter_floor(Teacher t){
            
            int cl = t.get_class();

            if(cl == 1){
                  c1.enter_Class(t);
            }
            else if( cl == 2){
                  c2.enter_Class(t);
            }
            else if(cl == 3){
                  c3.enter_Class(t);
            }
            else if(cl == 4){
                  c4.enter_Class(t);
            }
            else if(cl == 5){
                  c5.enter_Class(t);
            }
            else if( cl == 6){
                  c6.enter_Class(t);
            }
      }

      void print(){
            System.out.println( name + " Floor\n");
            corridor.print();
            c1.print();
            c2.print();
            c3.print();
            c4.print();
            c5.print();
            c6.print();
      }
      
      void set_all(){
            c1.set_all(C_class,Lj,Lt,N);
            c2.set_all(C_class,Lj,Lt,N);
            c3.set_all(C_class,Lj,Lt,N);
            c4.set_all(C_class,Ls,Lt,N);
            c5.set_all(C_class,Ls,Lt,N);
            c6.set_all(C_class,Ls,Lt,N);
      }

      int floor_is_full(){
            if ( c1.class_is_full() == 0 || c2.class_is_full() == 0)
                  return 0;
            if ( c3.class_is_full() == 0 || c4.class_is_full() == 0)
                  return 0;
            if ( c5.class_is_full() == 0 || c6.class_is_full() == 0)
                  return 0;
            return 1;
      }

      void operate(){
            
            c1.operate();
            c2.operate();
            c3.operate();
            c4.operate();
            c5.operate();
            c6.operate();
      }

      void empty(School sc){
            System.out.println(name + " Floor");
            corridor.empty(sc,this);
            c1.empty(sc,this);
            c2.empty(sc,this);
            c3.empty(sc,this);
            c4.empty(sc,this);
            c5.empty(sc,this);
            c6.empty(sc,this);

      }

      Corridor get_coridor(){
            return corridor;
      }
}
