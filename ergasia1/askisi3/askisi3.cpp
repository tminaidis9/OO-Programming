#include <iostream>
#include <string>
#include "askisi3.h"               

using namespace std;

void Inschool::enter_inschool(Student& s){
      cout << s.get_name() << " Enters " << name << endl;
      s.set_where(name);
      cout << s.get_name() << " Exit " << name << endl;      
}

Cor_Class::Cor_Class(string nm){
      name = nm;
      students_in = new Student*[1];
      ppl_in = new int(0);
      teacher_in = new int(0);
}

void Cor_Class::enter_Class(Teacher& t){
      if(*teacher_in == 0){
            *teacher_in = 1;
            class_teacher = t.get_name();
            teacher = &t;
            cout << "teacher " << t.get_name() << " is in class" << endl;
      }
      else{
            cout << "This class has already a teacher" << endl;
      }
}

void Cor_Class::exit_Corridor(Student& s){
      *ppl_in -= 1;
      students_in[*ppl_in] = NULL;
}

void Cor_Class::print(){
      if(*ppl_in > 0){
            cout << "People in " << name << " are:" << endl;
            for(int i = 0 ; i < *ppl_in ; i++)
                  cout << students_in[i]->get_name() << "\nBk = " << students_in[i]->get_bk() << "\n" << endl;
            
            if(this->name == "Class")
                  cout << "Teacher " << teacher->get_name() << "\nBk = " << teacher->get_bk() << "\n" << endl;
      }
}

int Cor_Class::enter_Class(Student& s){
      if(name == "Class"){
            if (C_class > *ppl_in){
                  
                  Student** new_stud_in = new Student*[*ppl_in + 1];
                  for(int i = 0 ; i < *ppl_in ; i++)
                        new_stud_in[i] = students_in[i];
                  
                  new_stud_in[*ppl_in] = &s;
                  students_in = new Student*[*ppl_in + 1];
                  students_in = new_stud_in;
                  
                  *ppl_in += 1;

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
            cout << "Class is full. You can't go in" << endl;
      }
      else{
            cout << s.get_name() << " Enters " << name << endl;
            Student** new_stud_in = new Student*[*ppl_in + 1];
                  for(int i = 0 ; i < *ppl_in ; i++)
                        new_stud_in[i] = students_in[i];
                  
                  new_stud_in[*ppl_in] = &s;
                  students_in = new Student*[*ppl_in + 1];
                  students_in = new_stud_in;
                  
                  *ppl_in += 1;
      }
      return 1;
}

void Cor_Class::operate(){ 
      if(*ppl_in > 0){
             int hl = hours * L;
            for(int i = 0 ; i < *ppl_in ; i++){
                  students_in[i]->set_bk(hl);
            }
      }
      if(*teacher_in > 0){
             int hl = hours * Lt;
            teacher->set_bk(hl);
      }
}

int Floors::enter_floor(Student& s){
      
      cout << s.get_name() << " Enters Floor" << endl;

      int st_class = s.get_class();
      corridor.enter_Corridor(s);
      
      if (st_class == 1){
            if(cj1.enter_Class(s) == 1)
                  corridor.exit_Corridor(s);
      }
      else if(st_class == 2){
            if(cj2.enter_Class(s) == 1)
                  corridor.exit_Corridor(s);
      }
      else if(st_class == 3){
            if(cj3.enter_Class(s) == 1)
                  corridor.exit_Corridor(s);
      }
      else if(st_class == 4){
            if(cs1.enter_Class(s) == 1)
                  corridor.exit_Corridor(s);
      }
      else if(st_class == 5){
            if(cs2.enter_Class(s) == 1)
                  corridor.exit_Corridor(s);
      }
      else{
            if(cs3.enter_Class(s) == 1)
                  corridor.exit_Corridor(s);
      }

      return 1;
}

void Floors::enter_floor(Teacher& t){
      int cl = t.get_class();

      if(cl == 1){
            cj1.enter_Class(t);
      }
      else if( cl == 2){
            cj2.enter_Class(t);
      }
      else if(cl == 3){
            cj3.enter_Class(t);
      }
      else if(cl == 4){
            cs1.enter_Class(t);
      }
      else if(cl == 5){
            cs2.enter_Class(t);
      }
      else if( cl == 6){
            cs3.enter_Class(t);
      }
      
}

void Floors::print(){
      cout << name << " Floor\n" << endl;
      corridor.print();
      cj1.print();
      cj2.print();
      cj3.print();
      cs1.print();
      cs2.print();
      cs3.print();

}

int Floors::floor_is_full(){
      if ( cj1.class_is_full() == 0 || cj2.class_is_full() == 0)
            return 0;
      if ( cs1.class_is_full() == 0 || cs2.class_is_full() == 0)
            return 0;
      if ( cs3.class_is_full() == 0 || cj3.class_is_full() == 0)
            return 0;
      return 1;
      
}

void Floors::set_all(){
      cj1.set_all(C_class,Lj,Lt,N);
      cj2.set_all(C_class,Lj,Lt,N);
      cj3.set_all(C_class,Lj,Lt,N);
      cs1.set_all(C_class,Ls,Lt,N);
      cs2.set_all(C_class,Ls,Lt,N);
      cs3.set_all(C_class,Ls,Lt,N);
}

void Floors::operate(){
      cj1.operate();
      cj2.operate();
      cj3.operate();
      cs1.operate();
      cs2.operate();
      cs3.operate();
}

School::School(){     
      
      cout << "A New School Has Been Created" << endl;
      st = new Student;   
      first = new Floors;
      second = new Floors;
      third = new Floors;
      stair = new Stairs;
      yard = new Yard;
	int c;
	cout << "Please write the C class" << endl;
	cin >> c;
      first->set_C_class(c);
      second->set_C_class(c);
      third->set_C_class(c);


	cout << "Please write the Lj" << endl;
	cin >> c;
      first->set_Lj(c);
      second->set_Lj(c);
      third->set_Lj(c);

      cout << "Please write the  Ls" << endl;
	cin >> c;
      first->set_Ls(c);
      second->set_Ls(c);
      third->set_Ls(c);

      cout << "Please write the Lt" << endl;
      cin >> c;
      first->set_Lt(c);
      second->set_Lt(c);
      third->set_Lt(c);

      cout << "Please write the N" << endl;
      cin >> c;
      N = c;
      first->set_N(c);
      second->set_N(c);
      third->set_N(c);

      first->set_all();
      second->set_all();
      third->set_all();
      cout << "\n";
}

void School::enter(Student& s){
      
      s.set_where("School");
      st = &s;
      cout << s.get_name() << " Enters School" << endl;
      
      yard->enter_Yard(s);
      stair->enter_Stairs(s);

      int student_floor = s.get_floor(); 
      cout << student_floor << endl;

      if (student_floor == 1)
            first->enter_floor(s);
      else if (student_floor == 2)
            second->enter_floor(s);
      else if (student_floor == 3)
            third->enter_floor(s);
      else
            cout << "Student's floor is wrong. End of program" << endl;
      
}

void School::enter(Teacher& t){
      int fl = t.get_floor();

      if( fl == 1){
            first->enter_floor(t);
      }
      else if(fl == 2){
            second->enter_floor(t);
      }
      else if(fl == 3){
            third->enter_floor(t);
      }

}

void School::print(){
      cout << " 1st " ;
      first->print();
      cout << " 2nd ";
      second->print();
      cout << " 3rd ";
      third->print();
}

int School::school_is_full(){
      if(first->floor_is_full() == 0 ||second->floor_is_full() == 0 || third->floor_is_full() == 0)
            return 0;
      
      return 1;
}

void School::operate(){
      cout << "School operate for " << N << " hours\n" << endl;
      first->operate();
      second->operate();
      third->operate();

}


int main(){
      
      School new_school;

      string f,l,x;
      int fl,cl;
      Student* stud;
      Teacher* teach; 


      cout << "Enter student or teacher?" << endl;
      cin >> x;
      cout << "Enter his name" << endl;    // mexri to yard na gemisei kai na einai iso CYard me toplithos sto yard
      cin >> f;
      cin >> l;
      cout << "His/Her floor" << endl;
      cin >> fl;
      cout << "His/Her class" << endl;
      cin >> cl;

      while (new_school.school_is_full() == 0){
            if(x == "s"){
                  stud = new Student(f,l,fl,cl);
                  stud->print();
                  new_school.enter(*stud);
            }
            else if(x == "t"){
                  teach = new Teacher(f,l,fl,cl);
                  new_school.enter(*teach);
            }
            else {
                  cout << "wrong type of people" << endl;
            }

            if(new_school.school_is_full() != 0)
                  break;
            
            cout << "Enter student or teacher?" << endl;
            cin >> x;
            cout << "Enter his name" << endl;
            cin >> f;
            cin >> l;
            cout << "His/Her floor" << endl;
            cin >> fl;
            cout << "His/Her class" << endl;
            cin >> cl;
      }
      
      cout << "\n";
      new_school.operate();
      new_school.print();



}

