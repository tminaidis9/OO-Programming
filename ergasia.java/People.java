public class People {
      
      String first;
      String last;
      int floor;
      int hisclass;
      String where;
      int bk;
      int in;

      People(String f,String l,int fl,int cl){

            first = f;
            last = l;
            floor = fl;
            hisclass = cl;
            where = "Nowhere";
            in = 0;

      }

      int get_floor() { 
            return floor;
      }

      int get_class(){
            return hisclass;
      }

      String get_name(){
            return last;
      }

      String get_where(){
            return where;
      }

      int get_bk(){
            return bk;
      }

      void set_bk(int num){
            bk = num;
      }

      void set_where(String wh){
            where = wh;
      }

}
