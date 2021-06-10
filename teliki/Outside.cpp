#include <iostream>
#include <string>
#include "Outside.h"

using namespace std;

Item* Grid::create_items(){

      Weapon sword("sword",100,2,10,1);
      Weapon axe("axe",500,10,45,2);
      Weapon sword2("sword2",150,4,21,1);
      Weapon sword3("sword3",300,7,35,1);

      Armor armor1("armor1",150,5,7);
      Armor armor2("armor2",300,8,18);

      Potion pot1("pot1",20,3,10);
      Potion pot2("pot2",40,5,25);
      Potion pot3("pot3",75,9,60);

      Item* all = new Item[9];
      weapon = new Weapon[4];
      armor = new Armor[2];
      potion = new Potion[3];

      weapon[0] = sword;
      weapon[1] = sword2;
      weapon[2] = sword3;
      weapon[3] = axe;

      armor[0] = armor1;
      armor[1] = armor2;

      potion[0] = pot1;
      potion[1] = pot2;
      potion[2] = pot3;

      all[0] = sword;
      all[1] = sword2;
      all[2] = sword3;
      all[3] = axe;
      all[4] = armor1;
      all[5] = armor2;
      all[6] = pot1;
      all[7] = pot2;
      all[8] = pot3;

      return all;
}

Square::Square(){ 
      type = 2;
}

Grid::Grid(string nm):name(nm){
      grid = new Square*[5];
      for(int i = 0 ; i < 5; i++){
            grid[i] = new Square[5];
      }
      
      Item* all = create_items();
      all_items = all;
      itms = 9;

      grid[0][4].create_market();
      grid[2][2].create_market();
      grid[3][4].create_market();
      grid[4][0].create_market();
      grid[0][4].set_items(all);
      grid[2][2].set_items(all);
      grid[3][4].set_items(all);
      grid[4][0].set_items(all);
      grid[4][4].create_nonAccessible();

      cout << "Grid " << name << " Has Been Created" << endl;
}

void Grid::CheckMap(int ii,int jj){
      Square sq;

      for(int i = 0 ; i <= 4 ; i++){
                  cout << "\n";
            for(int j = 0 ; j <= 4 ; j++){
                  sq = grid[i][j];
                  if(i == ii && j == jj)
                        cout << "H "; // You are Here
                  else 
                        cout << grid[i][j].get_type() << " ";
            }
      }
}

Item* Grid::print_items(int lvl){
      cout << "These are the items we have" << endl;
      int* pinakas = new int[9];
      int j = 0;

      for(int i = 0 ; i < itms ; i++){
            if(all_items[i].get_level() <= lvl){
                  cout << all_items[i].get_type() << " " << all_items[i].get_name() << " " << all_items[i].get_price() << endl;
                  pinakas[j] = i;
                  j++;
            }
      }

      // Item* items = new Item[j];
      // for(int i = 0 ; i < j ; i++)
      //       items[i] = all_items[i];
      
      return all_items;
}

Item Grid::get_item(string nm){
      for(int i = 0; i < itms; i++)
            if(all_items[i].get_name() == nm){
                  cout << "I found it " <<  all_items[i].get_name() << endl;
                  return all_items[i];
            }

      cout << " I never found it" << endl;
      return all_items[0];
}

Armor Grid::get_armor(string nm){
      for(int i = 0; i < 2; i++)
            if(armor[i].get_name() == nm){
                  cout << "I found it " <<  armor[i].get_name() << endl;
                  return armor[i];
            }

      cout << " I never found it" << endl;
      return armor[0];
}

Weapon Grid::get_weapon(string nm){
      for(int i = 0; i < 4; i++)
            if(weapon[i].get_name() == nm){
                  cout << "I found it " <<  weapon[i].get_name() << endl;
                  return weapon[i];
            }

      cout << " I never found it" << endl;
      return weapon[0];
}

Potion Grid::get_potion(string nm){
      for(int i = 0; i < 3; i++)
            if(potion[i].get_name() == nm){
                  cout << "I found it " <<  potion[i].get_name() << endl;
                  return potion[i];
            }

      cout << " I never found it" << endl;
      return potion[0];
}

