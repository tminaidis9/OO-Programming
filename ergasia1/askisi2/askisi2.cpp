#include <iostream>
#include <string>
#include "askisi2.h"

using namespace std;

int Class::num = 0;
List_of_Classes AList;

Student::Student(string nm,int gen):name(nm),gender(gen){
      make_noise = 0;
      cout << "student " << name << " just created" << endl;
}

List::List(){
      size = 0;
      first = new Pair;
      last = new Pair;
}

void List::insert_pair(Pair* p){
      if ( size == 0){
            first = p;
            last = p;
            last->next = NULL;
            size++;
            int* one = new int(1);
            p->thesi_stin_lista = one;
      }
      else{
            last->next = p;
            last = p;
            last->next = NULL;
            size++;
            int* s = new int(size);
            p->thesi_stin_lista = s;

      }           
}

void List::print(){
      if(size == 0){
            cout << "We havent any student " << endl;
            return;
      }
      for(Pair* p = first ; p != NULL; p = p->next){
            cout << *p->thesi_stin_lista << endl;
            cout << p->s1->get_name() << endl;
            cout << p->s2->get_name() << endl;
      }
}


Class::Class(string nm,int q,int m):name(nm),T_quiet(q),T_messy(m){
      num++ ;
      bathmos_ataksias = 0;
      list = new List;
      boys = new Student*[1];
      girls = new Student*[1];
      boys_in = new int(0);
      girls_in = new int(0);
      AList.insert(this);

      cout << "Class created" << endl;
}

void Class::enter_class(Student& s){
      int gender = s.get_gender();
      if( gender == 1){
            if( *boys_in == 0 ){
                  boys[0] = &s;
                  *boys_in += 1;
            }
            else{
                  *boys_in += 1;
                  Student** new_boys_in = new Student*[*boys_in];
                  for(int i = 0 ; i < (*boys_in - 1); i++ ){
                        new_boys_in[i] = boys[i];
                  }
                  new_boys_in[*boys_in - 1] = &s;
                  boys = new Student*[*boys_in];
                  boys = new_boys_in;
            }
      }
      else {
            if( *girls_in == 0 ){
                  girls[0] = &s;
                  *girls_in += 1;
            }
            else{
                  *girls_in += 1;
                  Student** new_girls_in = new Student*[*girls_in];
                  for(int i = 0 ; i < (*girls_in - 1); i++ ){
                        new_girls_in[i] = girls[i];
                  }
                  new_girls_in[*girls_in - 1] = &s;
                  girls = new Student*[*girls_in];
                  girls = new_girls_in;
            }
      }
}

void Class::print(){
      cout << "Boys in class are" << endl;
      for(int i = 0 ; i < (*boys_in) ; i++)
            cout << boys[i]->get_name() << endl;

      cout << "Girls in class are" << endl;
      for(int i = 0 ; i < (*girls_in) ; i++)
            cout << girls[i]->get_name() << endl;
}

void Class::create_pairs(){
      int students = (*boys_in) + (*girls_in);
      int num_of_pairs = (students / 2) + (students % 2);

      // zeugari = new Pair*[num_of_pairs];
      for(int i = 0; i < (students / 2) ; i++){
            Pair* zeugos = new Pair;
            zeugos->thesi_stin_lista = new int;
            
            if(i % 2 == 0){
                  zeugos->s1 = boys[i];
                  zeugos->s2 = girls[i];
            }
            else{
                  zeugos->s2 = boys[i];
                  zeugos->s1 = girls[i];
            }
            list->insert_pair(zeugos);

      }
      if(students % 2 == 1){
            Pair* zeugos = new Pair;
            zeugos->thesi_stin_lista = new int;

            Student none("NONE",2);
            

            if(*boys_in > *girls_in){
                  zeugos->s1 = boys[num_of_pairs - 1];
                  zeugos->s2 = &none;
            }
            else{
                  zeugos->s1 = &none;
                  zeugos->s2 = girls[num_of_pairs - 1];
            }

            list->insert_pair(zeugos);

      }
}

void Class::print_pairs(){
      cout << "Print Pairs" << endl;
      list->print();
}

Student* Class::get_student(string name){
      string nm;
      
      for(int i = 0 ; i < *boys_in ; i++){
            nm = boys[i]->get_name();
            if(nm == name)
                  return boys[i];
      }

      for(int i = 0 ; i < *girls_in ; i++){
            nm = girls[i]->get_name();
            if(nm == name)
                  return girls[i];
      }
      
      cout << "Wrong name" << endl;
      return NULL;
}

List_of_Classes::List_of_Classes(){
      size = 0;
}



void List_of_Classes::insert(Class* c){
      if(size == 0){
            first = c;
            last = c;
            size++;
            c->set_next(NULL);
      }
      else{
            last->set_next(c);
            c->set_next(NULL);
            last = c;
            size++;
      }
}

void List_of_Classes::print(){
      if(size == 0){
            cout << "There doesnt exist any class" << endl;
            return;
      }
      for(Class* cl = first ; cl != NULL ; cl = cl->get_next()){
            cout << cl->get_name() << endl;
      }
}

Class* List_of_Classes::find_class(string name){
      
      for(Class* cl = first ; cl != NULL ; cl = cl->get_next()){
            if(cl->get_name() == name){
                  return cl;
            }
      }

      cout << "ERROR" << endl;
      return NULL;
      
}

void make_noise(){
      int noisy_pairs = 0 ;
      int num_of_students;
      string names; 

      cout << "Which class makes noise?" << endl;
      string cl;
      cin >> cl;
      Class* our_class = AList.find_class(cl);

      
      cout << "Wow many kids make noise inside?" << endl;
      cin >> num_of_students;
      Student** pinakas = new Student*[num_of_students];

      cout << "And who are they?" << endl;
      for(int i = 0 ; i < num_of_students ; i++){
            cin >> names;
            while(our_class->get_student(names) == NULL){
                  cin >> names;
            }
            pinakas[i] = our_class->get_student(names);
            our_class->get_student(names)->set_make_noise();
      }
      
      List* our_list = our_class->get_list();
      Pair** n_p = new Pair*[our_list->get_size()];
      int counter = 0;
      
      for(Pair* pairs = our_list->get_first_pair() ; pairs != NULL ; pairs = our_list->get_next_pair(pairs)){
            if(pairs->s1->get_noise() == 1 && pairs->s2->get_noise() == 1){
                  noisy_pairs++;
                  n_p[counter] = pairs;
                  counter++;
            }
      }
      
      if(noisy_pairs == 0){
            if(num_of_students == 1){
                  Student* stchange = pinakas[0];
                  Student* astudent;
                  int gen = stchange->get_gender();
                  for(Pair* pairs = our_list->get_first_pair() ; pairs != NULL ; pairs = our_list->get_next_pair(pairs)){
                        if((pairs->s1->get_name() != stchange->get_name()) &&(pairs->s2->get_name() != stchange->get_name())){
                              if(pairs->s1->get_gender() == gen){
                                    astudent = pairs->s1;
                                    pairs->s1 = stchange;
                                    break;
                              }
                              else{
                                    astudent = pairs->s2;
                                    pairs->s2 = stchange;
                                    break;
                              }
                        }
                  }
                  for(Pair* pairs = our_list->get_first_pair() ; pairs != NULL ; pairs = our_list->get_next_pair(pairs)){
                        if(pairs->s1->get_name() == stchange->get_name() )
                              pairs->s1 = astudent;
                        else if (pairs->s2->get_name() == stchange->get_name())
                              pairs->s2 = astudent; 
                  }
            }
            else{
                  Student* stchange = pinakas[0];
                  Student astudent;
                  int gen = stchange->get_gender();
                  int bothnoisy = 0;
                  for(Pair* pairs = our_list->get_first_pair() ; pairs != NULL ; pairs = our_list->get_next_pair(pairs)){
                        if((pairs->s1->get_name() != stchange->get_name()) &&(pairs->s2->get_name() != stchange->get_name())){
                              if(pairs->s1->get_gender() == gen){
                                    astudent = *pairs->s1;
                                    pairs->s1 = stchange;
                                    cout << astudent.get_name() << "kk" << endl;
                                    if(astudent.get_noise() == 1)
                                          bothnoisy++;
                                    break;
                              }
                              else{
                                    astudent = *pairs->s2;
                                    pairs->s2 = stchange;
                                    // stchange = astudent;
                                    cout << astudent.get_name() << "kk" << endl;

                                    if(astudent.get_noise() == 1)
                                          bothnoisy++;
                                    break;
                              }
                        }
                  }
                  // for(Pair* pairs = our_list->get_first_pair() ; pairs != NULL ; pairs = our_list->get_next_pair(pairs)){
                  //       if(pairs->s1->get_name() == stchange->get_name() )
                  //             pairs->s1 = &astudent;
                  //       else if (pairs->s2 == stchange)
                  //             pairs->s2 = &astudent; 
                  // }
                  
                  if(bothnoisy == 0){
                        Student* stchange = pinakas[1];
                        Student* astudent;
                        int gen = stchange->get_gender();
                        for(Pair* pairs = our_list->get_first_pair() ; pairs != NULL ; pairs = our_list->get_next_pair(pairs)){
                              if((pairs->s1 != stchange) &&(pairs->s2 != stchange)){
                                    if(pairs->s1->get_gender() == gen){
                                                astudent = pairs->s1;
                                                pairs->s1 = stchange;
                                                break;
                                    }
                              }
                        }
                        for(Pair* pairs = our_list->get_first_pair() ; pairs != NULL ; pairs = our_list->get_next_pair(pairs)){
                              if(pairs->s1 == stchange )
                                    pairs->s1 = astudent;
                              else if (pairs->s2 == stchange)
                                    pairs->s2 = astudent; 
                        }
                  }
            }
      }
      else {
            if(noisy_pairs <= 2){
                  for(int j = 0 ; j < noisy_pairs; j++){
                        Student* stchange = n_p[j]->s1;
                        Student* stchange2 = n_p[j]->s2;
                        Student* astudent;
                        Student* astudent2;
                        int ppl = 2;
                        int gen = stchange->get_gender();
                        for(Pair* pairs = our_list->get_first_pair() ; pairs != NULL ; pairs = our_list->get_next_pair(pairs)){
                              if(ppl == 2){
                                    if((pairs->s1->get_name() != stchange->get_name()) &&(pairs->s2->get_name() != stchange->get_name())){
                                          if(pairs->s1->get_gender() == gen){
                                                astudent = pairs->s1;
                                                pairs->s1 = stchange;
                                                ppl--;
                                                continue;
                                          }
                                          else{
                                                astudent = pairs->s2;
                                                pairs->s2 = stchange;
                                                ppl--;
                                                continue;
                                          }
                                    }
                              }
                              if(ppl == 1){
                                    if((pairs->s1->get_name() != stchange2->get_name()) &&(pairs->s2->get_name() != stchange2->get_name())){
                                          if(pairs->s1->get_gender() != gen){
                                                astudent2 = pairs->s1;
                                                pairs->s1 = stchange;
                                                break;
                                          }
                                          else{
                                                astudent2 = pairs->s2;
                                                pairs->s2 = stchange2;
                                                break;
                                          }
                                    }
                              }
                        }
                        for(Pair* pairs = our_list->get_first_pair() ; pairs != NULL ; pairs = our_list->get_next_pair(pairs)){
                              if(pairs->s1->get_name() == stchange->get_name() ){
                                    pairs->s1 = astudent;
                                    pairs->s2 = astudent2;
                              }
                              else if (pairs->s2->get_name() == stchange->get_name()){
                                    pairs->s2 = astudent; 
                                    pairs->s1 = astudent2;
                              }
                        }  
                  }  
            }
            else {
                  int c = our_class->num;
                  int x = num_of_students/c;
                  int y = num_of_students%c;
                  //n_p o pinakas me ta pairs
                  int i = 0;
                  int counter = 0;
                  int gen;
                  Student* stchange;
                  Student* astudent;

                  if (x != 0 && y != 0){
                        for(Class* aclass = AList.get_first(); aclass != NULL ; aclass = AList.get_next(aclass)){
                              for(int k = 0 ; k < x ; k++){
                                    if (i == 0){
                                          i++;
                                          gen = n_p[counter]->s1->get_gender();
                                          stchange = n_p[counter]->s1;

                                    }  
                                    else{
                                          i--;
                                          gen = n_p[counter]->s2->get_gender();
                                          stchange = n_p[counter]->s1;
                                          
                                          counter++;  
                                    }
                                          
                                    List* list = aclass->get_list();
                                    for(Pair* pairs = list->get_first_pair() ; pairs != NULL ; pairs = list->get_next_pair(pairs)){
                                          if((pairs->s1->get_name() != stchange->get_name()) &&(pairs->s2->get_name() != stchange->get_name())){
                                                if(pairs->s1->get_gender() == gen){
                                                      astudent = pairs->s1;
                                                      pairs->s1 = stchange;
                                                      break;
                                                }
                                                else{
                                                      astudent = pairs->s2;
                                                      pairs->s2 = stchange;
                                                      break;
                                                }
                                          }
                                    }

                                    for(Pair* pairs = our_list->get_first_pair() ; pairs != NULL ; pairs = our_list->get_next_pair(pairs)){
                                          if(pairs->s1 == stchange )
                                                pairs->s1 = astudent;
                                          else if (pairs->s2 == stchange)
                                                pairs->s2 = astudent; 
                                    }
                              }
                        }
                  }
            }  
      }   
}

int main(){

      int Tmessy,Tquiet;
      cout << "T_messy is " << endl;
      cin >> Tmessy;
      cout << "T_quiet is " << endl;
      cin >> Tquiet;


      Student student1("mina",1);
      Student student2("minaidis",1);
      Student student3("fenia",0);
      Student student4("katerina",0);
      
      Class class1("Class1",Tquiet,Tmessy);
      class1.enter_class(student1);
      class1.enter_class(student2);
      class1.enter_class(student3);
      class1.enter_class(student4);

      class1.print();
      class1.create_pairs();
      class1.print_pairs();

      class1.print_n();
      Class class2("Class2",Tquiet,Tmessy);
      class1.print_n();
      class2.print_n();
      AList.print();
      make_noise();
      class1.print_pairs();



}
