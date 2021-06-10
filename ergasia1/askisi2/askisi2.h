#include <iostream>
#include <string>

using namespace std;

class Student{
      private:
            string name;
            int gender; // 0 αν είναι κορίτσι , 1 αν είναι αγόρι
            int make_noise;
            // Pair* wherehebelong;
      public:
            Student(){}
            Student(string nm,int gen);
            ~Student() { cout << "student " << name << " destroyed" << endl; }
            int get_gender() { return gender; }
            string get_name() { return name; }
            void set_make_noise() {make_noise = 1;}
            int get_noise(){ return make_noise; }
};

struct Pair{
      Student* s1;
      Student* s2;
      Pair* next;
      int* thesi_stin_lista;
};

class List{
      private:
            int size;
            Pair* first;
            Pair* last;
      public:
            List();
            void set_first_pair(Pair* p){ first = p; }
            Pair* get_first_pair(){ return first; }
            Pair* get_next_pair(Pair* p) { return p->next; }
            int get_size() { return size; }
            void insert_pair(Pair* p);
            void print();
      
};

class Class{
      private:
           int bathmos_ataksias;
            string name;
            int T_quiet, T_messy;
            Student** boys;
            Student** girls;
            int* boys_in;
            int* girls_in;
            List* list;
            Class* next;
      public:
            static int num;
            Class(string nm,int q,int m);
            ~Class() { cout << "class " << name << " destroyed" << endl; }
            void enter_class(Student& s);
            void create_pairs();
            void print();
            void print_pairs();
            void print_n() { cout << num << endl; }
            List* get_list(){ return list; }
            Class* get_next(){ return next; }
            void set_next(Class* next) { this->next = next; }
            string get_name() { return name; }
            Student* get_student(string name); 
}; 

class List_of_Classes{
      private:
            int size;
            Class* first;
            Class* last;
      public:
            List_of_Classes();
            Class* get_first() { return first; }
            Class* get_next(Class* cl) { return cl->get_next(); }
            void insert(Class* c);
            void print();
            Class* find_class(string name);

};