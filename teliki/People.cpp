#include <iostream>
#include <string>
#include "People.h"

using namespace std;

Monster::Monster(string nm):Living(nm,50),name(nm){ 
      if(name.compare("Dragon")){
            attack = 12;
            defence = 4;
            possibility = 0.1;
      }
      else if(name.compare("Exoskeleton")){
            attack = 9;
            defence = 7;
            possibility = 0.1;
      }
      else if(name.compare("Spirit")){
            attack = 9;
            defence = 4;
            possibility = 0.25;
      }
}

void  Hero::insert_item(Item it){
      // if(*items_in == 0){
      //       index[0] = &it;
      //       *items_in +=1;
      //       cout << "moike" << endl;
      // }
      // else{
      //       Item** itms = new Item*[*items_in + 1];

      //       for(int i = 0 ; i < *items_in ; i ++){
      //             itms[i] = index[i];
      //             cout << index[i]->get_name() << " correct " <<i << endl;
      //       }

      //       itms[*items_in] = &it;
      //       index = new Item*[*items_in + 1];
      //       index = itms;

      //       for(int i = 0 ; i<= *items_in ; i++)
      //             cout << index[i]->get_name() << " correct2" << endl;

      //       *items_in += 1;
      // }
      if(*items_in <= 35){
            index[*items_in] = it;
            *items_in += 1;
      }
      else {
            cout << "Your bag is full of orders" << endl;
      }


      // return index;

}

void Hero::printInv(){
      cout << *items_in << endl;
      for( int i = 0 ; i < *items_in ; i++){
            cout << index[i].get_name() << endl;
            // cout << "\n";
      }
}

void Hero::printtosell(){

      for( int i = 0 ; i < *items_in ; i++){
            cout << index[i].get_name() << " " << index[i].get_price()/2 << endl;
            // cout << "\n";
      }

}

int Hero::checkinv(string nm){
      
      for(int i = 0; i < *items_in ; i++)
            if(index[i].get_name() == nm){
                  cout << "I found it " <<  index[i].get_name() << endl;
                  return 1;
            }

      return 0;
}

void Hero::out_item(Item itm){
      
      for(int i = 0; i < *items_in ; i++)
            if(index[i].get_name() == itm.get_name()){
                  index[i] = index[*items_in - 1];
                  break;
            }

      *items_in -= 1;
}

void Hero::printequip(){


                  for(int i = 0 ; i < *items_in ; i++){
                        if(index[i].get_name() != "sword" && index[i].get_name() != "sword2" && index[i].get_name() != "sword3" && index[i].get_name() != "axe"){
                              cout << index[i].get_name() << endl;
                        }
                  }
}

void Hero::LevelUp() {
      
      if(get_level() == 10)
            return;
      
      int up = get_uphealth();
      onelevelup();
      
      MagicPower += (5 + up);
      strength += (up + up/2);
      dexterity += up;
      agility += up + 1;
      experience += (up / 2);
      
      healthup();
      set_p(0);
      set_ptl(up + 5);
      cout << "ok" << endl;
      }
