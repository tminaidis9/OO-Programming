#include <iostream>
#include <string>

using namespace std;

class People{
      private:
            string first;
            string last;
            int floor;
            int his_class;
            string where;
            int bk;
            int in;
      public:
            People(string f,string L,int fl,int cl):first(f),last(L),floor(fl),his_class(cl){ where = "Nowhere"; in = 0;}
            People() {}
            virtual ~People() {}
            virtual int get_floor() { return floor; }
            virtual int get_class() { return his_class; }
            virtual string get_name() { return last; }
            virtual string get_where() { return where; }
            virtual int get_bk() { return bk; }
            virtual void set_bk(int num) { bk = num; }
            virtual void set_where(string wh) { where = wh; }
};

class Teacher: public People{
      public:
            Teacher(string f,string l,int fl,int cl): People(f,l,fl,cl) { cout << "New Teacher has been created" << endl; }
            Teacher() {}
            ~Teacher() {cout << People::get_name() << "destroyed" << endl; }
            void print() {cout << "Teacher name is " << People::get_name() << endl; }

            
};

class Student: public People{
      public:
            Student(string f,string l,int fl,int cl):People(f,l,fl,cl) {  cout << People::get_name() << " Is our new Student" << endl;}
            Student() {}
            ~Student(){ cout << People::get_name() << " Destroyed" << endl; }
            void print() { cout << "Student name is " << People::get_name() << endl; }

};

class Inschool{
      private:
            string name;
      public:
            Inschool(string nm) { name = nm; cout << name << " Created" << endl;}
            void set_name(string newname) { name = newname; if(name != "NULL") cout << name <<  " Just Created" << endl;}
            ~Inschool() {if (name != "NULL") cout << name << " destroyed" << endl;}
            void enter_inschool(Student& s);
};

class Yard: public Inschool{
      public:
            Yard():Inschool("Yard") {}
            ~Yard() {cout << "Yard destroyed" << endl; }
            void enter_Yard(Student& s){ Inschool::enter_inschool(s); }
};

class Stairs: public Inschool{
      public:
            Stairs():Inschool("Stairs") {}
            ~Stairs() {cout << "Stairs destroyed" << endl; }
            void enter_Stairs(Student& s){ Inschool::enter_inschool(s); }
};

class Cor_Class{
      private:
            Student** students_in;
            string name;
            int* teacher_in;
            Teacher* teacher;
            string class_teacher; 
            int C_class;
            int L,Lt;
            int hours;
            int* ppl_in;
      public:
            Cor_Class(string nm);
            void set_name(string newname) { name = newname; if(name != "NULL") cout << name <<  " Just Created" << endl;}
            virtual ~Cor_Class() { if (name != "NULL") cout << name << " destroyed" << endl; delete ppl_in; delete teacher_in; delete students_in;}
            virtual void set_all(int C, int l,int t,int N) { C_class = C; L = l; Lt = t; hours = N; }
            virtual int get_ppl_in() { return *ppl_in; }
            virtual int get_C_class() { return C_class; }
            virtual int get_teacher_in() { return *teacher_in; }
            virtual int* pointer_get_ppl_in() { return ppl_in; }
            virtual int enter_Class(Student& s);
            virtual void enter_Class(Teacher& t);
            virtual void exit_Corridor(Student& s);
            virtual void print();
            virtual void operate();
};

class Corridor: public Cor_Class{
      public:
            Corridor():Cor_Class("Corridor") {}
            ~Corridor() {cout << "Corridor destroyed" << endl; }
            void enter_Corridor(Student& s){ Cor_Class::enter_Class(s); }

};

class ClassJ: public Cor_Class{
      public:
            ClassJ():Cor_Class("Class") {}
            ~ClassJ() {cout << "Class destroyed" << endl; }
            int class_is_full(){ if (Cor_Class::get_C_class() == Cor_Class::get_ppl_in() && Cor_Class::get_teacher_in() == 1) return 1; return 0; }
};

class ClassS: public Cor_Class{
      public:
            ClassS():Cor_Class("Class") {}
            ~ClassS() {cout << "Class destroyed" << endl; }
            int class_is_full(){  if ((Cor_Class::get_C_class() == Cor_Class::get_ppl_in()) && Cor_Class::get_teacher_in() == 1) return 1; return 0; }
};

class Floors{
      private:
            int C_class;
            Corridor corridor;
            ClassJ cj1,cj2,cj3;
            ClassS cs1,cs2,cs3;
            int Lt,Ls,Lj,N;
            string name;
      public:
            Floors() {cout << "Floor created" << endl;}
            void set_name(string newname) { name = newname; if(name != "NULL") cout << name <<  " Floor Just Created" << endl;}
            ~Floors() { cout << name << " floor destroyed" << endl;}
            void set_C_class(int num) { C_class = num; }
            void set_all();
            void set_Lt(int num) { Lt = num; }
            void set_Ls(int num) { Ls = num; }
            void set_Lj(int num) { Lj = num; }
            void set_N(int num) { N = num; }
            int get_C_class() { return C_class; }
            int enter_floor(Student& s);
            void enter_floor(Teacher& t);
            void print();
            int floor_is_full();
            void operate();

};


class School{
      private:
            Floors* first ;
            Floors* second;
            Floors* third;
            Yard* yard;
            Stairs* stair;
            Student* st;
            int N;
      public:
            School();
            ~School() { cout << " School Destroyed" << endl; delete first; delete second; delete third; delete yard; delete stair; delete st;}
            void enter(Student& s);
            void enter(Teacher& t);
            void exit_school() {  cout << "Exit from School" << endl;}
            void print();
            int school_is_full();
            void operate();

};