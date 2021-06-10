
// sdi1900113
#include <iostream>
#include <string>

using namespace std;

class Teacher{
      private:
            string name;
            int floor;
            int clas;
      public:
            Teacher(string nm,int fl,int cl):name(nm),floor(fl),clas(cl) {cout << name << " Teacher created" << endl;}
            Teacher() {}
            void set(string nm,int fl,int cl){name = nm; floor = fl; clas = cl; cout << name << " Is our new teacher" << endl; }
            ~Teacher() {cout << name << "destroyed" << endl; }
            int get_floor() { return floor; }
            int get_class() { return clas; }
            string get_name() { return name; }
            void print() {cout << "Teacher name is " << name << endl; }

            
};

class Student{
      private:
            string name;
            int floor;
            int clas;
            string where;
      public:
            Student(string nm,int fl,int cl):name(nm),floor(fl),clas(cl)
                  {where = "Nowhere"; cout << name << " Is our new Student" << endl;}
            Student() {where = "Nowhere";}
            void set(string nm,int fl,int cl){name = nm; floor = fl; clas = cl; cout << name << " Is our new teacher" << endl; }
            ~Student(){ cout << this->name << " Destroyed" << endl;}
            void set_where(string wh) { where = wh; }
            string get_where() { return where; }
            string get_name() { return name; }
            int get_floor() { return floor; }
            int get_class() { return clas; }
            void print() { cout << "Student name is " << name << endl; }

};


class Inschool{
      private:
            int* ppl_in;
            Student** students_in;
            int C_inschool;
            string name;
            //ΜΟΝΟ ΓΙΑ ΤΙΣ ΤΑΞΕΙΣ
            int* teacher_in;
            string class_teacher; 
      public:
            Inschool();
            void set_name(string newname) { name = newname; if(name != "NULL") cout << name <<  " Just Created" << endl;}
            ~Inschool() {if (name != "NULL") cout << name << " destroyed" << endl;}
            void set_C_inschool(int c) { C_inschool = c; }
            int get_C_inschool() { return C_inschool; }
            int get_ppl_in() { return *ppl_in; }
            int* pointer_get_ppl_in() { return ppl_in; }
            int enter_inschool(Student& s,Inschool& insc);
            void enter_inschool(Teacher& t);
            void exit_inschool(Student& s);
            void print();
            
            

};

Inschool::Inschool(){
      ppl_in = new int(0);
      students_in = new Student*[0];
      teacher_in = new int(0);
}



int Inschool::enter_inschool(Student& s,Inschool& insc){
      Inschool nowhere;
      nowhere.set_name("NULL");
      if (C_inschool > *ppl_in){
            
            Student** new_stud_in = new Student*[*ppl_in + 1];
            for(int i = 0 ; i < *ppl_in ; i++)
                  new_stud_in[i] = students_in[i];
            
            new_stud_in[*ppl_in] = &s;
            students_in = new Student*[*ppl_in + 1];
            students_in = new_stud_in;
            
            *ppl_in += 1; 
            

            if(name == "1st_class" || name == "2nd_class" || name == "3rd_class" || name == "4th_class" || name == "5th_class" || name == "6th_class"){
                  if(*teacher_in == 1){
                        *ppl_in -= 1;
                        students_in[*ppl_in] = NULL;
                        cout << "teacher is in class. You can't go in " << s.get_name() << endl;
                        return 0;
                  }
                  cout << s.get_name() << " Exit Corridor" << endl;
                  s.set_where(name);
                  cout << s.get_name() << " Enters " << name << endl;
                  return 1;
            }

            if(name == "Yard"){
                  cout << s.get_name() << " Enters Yard" << endl;
                  if( insc.enter_inschool(s,nowhere) == 2){
                        // cout << "lathos" << endl;
                        Inschool::exit_inschool(s);
                        cout << s.get_name() << " Enters Stairs" << endl;
                        return 2;
                  }
            }
            if(name == "Stair"){
                  cout << s.get_name() << " Exit Yard" << endl;
                  s.set_where(name);
                  return 2;
            }

            if(name == "Corridor"){
                  cout << s.get_name() << " Exit Stairs" << endl;
                  s.set_where(name);
            }

            return 1;
                  
      }
            return 0;
      
}

void Inschool::enter_inschool(Teacher& t){
      *teacher_in = 1;
      class_teacher = t.get_name();
      cout << "teacher " << name << " is in class" << endl;
}

void Inschool::exit_inschool(Student& s){
      *ppl_in -= 1;
      students_in[*ppl_in] = NULL;
      // cout << s.get_name() << " Exit from " << name << endl;
}

void Inschool::print(){
      cout << "People in " << name << " are:" << endl;
      for(int i = 0 ; i < *ppl_in ; i++)
            cout << students_in[i]->get_name() << endl;
}



class Floors{
      private:
            int C_corr;
            int C_class;
            Inschool corridor;
            Inschool class1, class2, class3, class4, class5, class6;
            string name;
      public:
            Floors();
            void set_name(string newname) { name = newname; if(name != "NULL") cout << name <<  " Floor Just Created" << endl;}
            ~Floors() { cout << name << " floor destroyed" << endl;}
            void set_C_corr(int num) { C_corr = num; }
            void set_C_class(int num) {C_class = num; }
            int get_C_corr() { return C_corr; }
            int get_C_class() { return C_class; }
            int enter_floor(Student& s);
            void enter_floor(Teacher& t);
            void print();

};

Floors::Floors(){
      corridor.set_name("Corridor");
      class1.set_name("1st_class");
      class2.set_name("2nd_class");
      class3.set_name("3rd_class");
      class4.set_name("4th_class");
      class5.set_name("5th_class");
      class6.set_name("6th_class");
}

int Floors::enter_floor(Student& s){
      Inschool nowhere;
      nowhere.set_name("NULL");
      int st_class = s.get_class();
      corridor.set_C_inschool(C_corr);
      int in_cor = corridor.enter_inschool(s,nowhere);
      if (in_cor == 0)
            return 0;
      
      if (in_cor == 1){
            cout << s.get_name() << " Enters Corridor" << endl;
            s.set_where("Corridor");
            if (st_class == 1){
                  class1.set_C_inschool(C_class);
                  
                  if(class1.enter_inschool(s,nowhere) == 1)
                        corridor.exit_inschool(s);
            }
            else if(st_class == 2){
                  class2.set_C_inschool(C_class);
                  
                  if(class2.enter_inschool(s,nowhere) == 1)
                        corridor.exit_inschool(s);
            }
            else if(st_class == 3){
                  class3.set_C_inschool(C_class);
                  
                  if(class3.enter_inschool(s,nowhere) == 1)
                        corridor.exit_inschool(s);
            }
            else if(st_class == 4){
                  class4.set_C_inschool(C_class);
                  
                  if(class4.enter_inschool(s,nowhere) == 1)
                        corridor.exit_inschool(s);
            }
            else if(st_class == 5){
                  class5.set_C_inschool(C_class);
                  
                  if(class5.enter_inschool(s,nowhere) == 1)
                        corridor.exit_inschool(s);
            }
            else {
                  class6.set_C_inschool(C_class);
                  
                  if(class6.enter_inschool(s,nowhere) == 1)
                        corridor.exit_inschool(s);
            }

      }

      return 1;
}

void Floors::enter_floor(Teacher& t){
      int cl = t.get_class();

      if(cl == 1){
            class1.enter_inschool(t);
      }
      else if( cl == 2){
            class2.enter_inschool(t);
      }
      else if(cl == 3){
            class3.enter_inschool(t);
      }
      else if(cl == 4){
            class4.enter_inschool(t);
      }
      else if(cl == 5){
            class5.enter_inschool(t);
      }
      else if( cl == 6){
            class6.enter_inschool(t);
      }
      
}

void Floors::print(){
      cout << name << " Floor" << endl;
      corridor.print();
      class1.print();
      class2.print();
      class3.print();
      class4.print();
      class5.print();
      class6.print();

}

class School{
      private:
            Floors first , second , third;
            Inschool yard;
            Inschool stair;
            int* ppl_in;
            Student** students_in;
            int C_yard, C_stair, C_corr;
      public:
            School();
            ~School() { cout << " School Destroyed" << endl;}
            void enter(Student& s);
            void enter(Teacher& t);
            void exit_school() { *ppl_in -= 1; students_in[*ppl_in] = NULL; cout << "Exit from School" << endl;}
            void print();
            int get_C_yard() { return yard.get_C_inschool(); }
            int* get_ppl_yard() { return yard.pointer_get_ppl_in(); }

};

School::School(){
      students_in = new Student*[0];  
      ppl_in = new int(0);               
      yard.set_name("Yard");             
      stair.set_name("Stair");          
      first.set_name("first");          
      second.set_name("second");
      third.set_name("third");

      cout << "A New School Has Been Created" << endl;
	int c;
	
	cout << "Please write the C yard" << endl;
	cin >> c;
	yard.set_C_inschool(c);
	cout << "C yard is " << yard.get_C_inschool() << endl;
	
	cout << "Please write the C stairs" << endl;
	cin >> c;
      stair.set_C_inschool(c);
      cout << "C stair is " <<  stair.get_C_inschool() << endl;

      cout << "Please write the C corr" << endl;
	cin >> c;
      first.set_C_corr(c);
      second.set_C_corr(c);
      third.set_C_corr(c);
      cout << "C corridor is " <<  first.get_C_corr() << endl;

      cout << "Please write the C class" << endl;
      cin >> c;
      first.set_C_class(c);
      second.set_C_class(c);
      third.set_C_class(c);
      cout << "C class is " <<  first.get_C_class() << endl;


}

void School::enter(Student& s){
      s.set_where("School");
      
      Student** new_stud_in = new Student*[*ppl_in + 1];
      for(int i = 0 ; i < *ppl_in ; i++)
            new_stud_in[i] = students_in[i];
      
      new_stud_in[*ppl_in] = &s;
      students_in = new Student*[*ppl_in + 1];
      students_in = new_stud_in;

      *ppl_in += 1;
      int student_floor = s.get_floor();
      cout << *ppl_in << endl;
      
      int dektos = yard.enter_inschool(s,stair);
      
      if(dektos == 1)
            s.set_where("Yard");
      
      if ((dektos == 1) || (dektos == 2)){
            *ppl_in -= 1;
            students_in[*ppl_in] = NULL;
      }

      if ( dektos == 2){
            if (student_floor == 1){
                  if(first.enter_floor(s) == 1)
                        stair.exit_inschool(s);
            }
            else if (student_floor == 2){
                  if(second.enter_floor(s) == 1)
                        stair.exit_inschool(s);
            }
            else if (student_floor == 3){
                  if(third.enter_floor(s) == 1)
                        stair.exit_inschool(s);
            }
      }
}

void School::enter(Teacher& t){
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

void School::print(){
      cout << " SCHOOL " << endl;
      yard.print();
      stair.print();
      first.print();
      second.print();
      third.print();
}

int main(){
      
      School new_school;

      string st,x;
      int stdnt = 0;
      int fl,cl;
      int C_yrd = new_school.get_C_yard();
      int* ppl_in_yard = new_school.get_ppl_yard();
      Student* stud;
      Teacher* teach; 


      cout << "Enter student or teacher?" << endl;
      cin >> x;
      cout << "Enter his name" << endl;    // mexri to yard na gemisei kai na einai iso CYard me toplithos sto yard
      cin >> st;
      cout << "His/Her floor" << endl;
      cin >> fl;
      cout << "His/Her class" << endl;
      cin >> cl;
      while (*ppl_in_yard < C_yrd){
            
            if(x == "s"){
                  stud = new Student;
                  stud->set(st,fl,cl);
                  new_school.enter(*stud);
                  
            
            }
            else if(x == "t"){
                  teach = new Teacher;
                  teach->set(st,fl,cl);
                  new_school.enter(*teach);
            }


            if(*ppl_in_yard == C_yrd)
                  continue;
            
            cout << "Enter student or teacher?" << endl;
            cin >> x;
            cout << "Enter his name" << endl;
            cin >> st;
            cout << "His/Her floor" << endl;
            cin >> fl;
            cout << "His/Her class" << endl;
            cin >> cl;

      }

      new_school.print();




}