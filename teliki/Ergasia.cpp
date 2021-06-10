#include <iostream>
#include <string>
#include <sstream>
#include "Outside.h"
// #include "Items.h"

using namespace std;


int main(){
      Grid grid("New world");
      Hero* myhero;
      Square myplace;
      
      int end_game;
      int ok = 0;
      int i;
      int j;

      Armor new_armor;
      Weapon new_weapon;
      Potion new_potion;

      cout << "Please select a hero" << endl;
      cout << "Your choises are" << endl;
      cout << " Warrior \n Soncerer \n Paladin \n " ;
      string h;
      do{
            cin >> h;
            cout << "You selected " << h << endl;
            if( h == "Warrior"){
                  ok = 1;
                  Warrior mywar(1,25);
                  myhero = &mywar;

            }
            else if (h.compare("Soncerer") == 0){
                  ok = 1;
                  Soncerer myson(1,25);
                  myhero = &myson;

            }
            else if (h.compare("Paladin") == 0){
                  ok = 1;
                  Paladin mypal(1,25);
                  myhero = &mypal;
            
            }

            if(ok != 1)
                  cout << h << " character doesn't exist. Please select one." << endl;

      } while (ok < 1);

      // There game starts
      grid.set_hero_to(myhero,0,0);
      myplace = grid.get_square(0,0);
      i = 0; j = 0;
      ok = 0;
      
      do{ 
            if (myplace.get_type() == 1 || myplace.get_if_monster_in() == 0){
            
            if(myplace.get_type() == 1)
                  cout << "You re in a market. ";
            else
                  cout << "You re in a common square. ";

            cout << "What do you want to do?" << endl; // ChechInv Buy Sell Move ChechMap End game
            cin >> h;
            
            if(h == "CheckInv"){
                  cout << "Your items are:" << endl; 
                  myhero->printInv();
            }
            else if(h == "Buy"){

                  if(myplace.get_type() == 1){

                        if ( myhero->get_money() == 0){
                              cout << "You have 0$ you can't buy anything" << endl;
                              continue;
                        }

                        cout << "Your level is " << myhero->get_level() << endl;
                        /*Item* items_can_buy =*/ grid.print_items(myhero->get_level());
                        cout << "Do you want to buy something? If yes, what do you want?" << endl; // Nothing or an item
                        cin >> h;
                        
                        while(ok == 0){
                              if ( h == "Nothing")
                                    break;
                              else if ( (h == "sword" && myhero->get_level() >= 2 && myhero->get_money() >= 100) || (h == "sword2" && myhero->get_level() >= 4 && myhero->get_money() >= 150) ||(h == "sword3" && myhero->get_level() >= 7 && myhero->get_money() >= 300) || (h == "axe" && myhero->get_level() >= 10 && myhero->get_money() >= 500) ){
                                    cout << " " << endl;
                                    myhero->insert_item(grid.get_item(h));
                                    myhero->set_money(grid.get_item(h).get_price());
                                    cout << h << " inserted in index" << endl;
                                    ok = 1;
                              }
                              else if ( (h == "armor1" && myhero->get_level() >= 5 && myhero->get_money() >= 150) || (h == "armor2" && myhero->get_level() >= 8 && myhero->get_money() >= 300) ){
                                    myhero->insert_item(grid.get_item(h));
                                    myhero->set_money(grid.get_item(h).get_price());
                                    cout << h << " inserted in index" << endl;
                                    ok = 1;
                              }
                              else if( (h == "pot1" && myhero->get_level() >= 3 && myhero->get_money() >= 20) || (h == "pot2" && myhero->get_level() >= 5 && myhero->get_money() >= 40) || (h == "pot3" && myhero->get_level() >= 9 && myhero->get_money() >= 75) ){
                                    myhero->insert_item(grid.get_item(h));
                                    myhero->set_money(grid.get_item(h).get_price());
                                    cout << h << " inserted in index" << endl;
                                    ok = 1;
                              }

                              if( ok == 1 ) continue;
                              cin >> h;
                        }
                        cout << "Now you have " << myhero->get_money() << " $" << endl;
                        ok = 0;
                  }
                  else{
                        cout << "You aren't in a market to buy" << endl;
                  }
            }
            else if(h == "Sell"){
                  
                  if(myplace.get_type() == 1){
                        cout << "The items you have and you can sell are:" << endl;
                        myhero->printtosell();
                        cout << "Which one you want to sell?" << endl;
                        
                        cin >> h;
                        if (myhero->checkinv(h) == 1){
                              myhero->out_item(grid.get_item(h));
                              myhero->set_money(grid.get_item(h).get_price()/2);
                              cout << "Now you have " << myhero->get_money() << " $" << endl;
                        }
                        else {
                              cout << "Wrong name of item you wanna sell" << endl;
                        }
                  }
                  else 
                        cout << "You aren't in a shop to sell" << endl;

            }
            else if(h == "Move"){
                  int k = 0;
                  cout << "Select where you wanna go" << endl; //Up Down Right Left
                  cout << "You re in " << i << " " << j << " square" << endl;
                  while(k == 0){

                        cin >> h;
                        if (h == "Wrong"){
                              break;
                        }

                        if( (h == "Up" && i != 0) || (h == "Down" && i != 4) || (h == "Right" && j != 4) || (h == "Left" && j != 0) ){
                              if( (h == "Up" && grid.get_square(i-1,j).get_type() != 0) || (h == "Down" && grid.get_square(i+1,j).get_type() != 0) || (h == "Right" && grid.get_square(i,j+1).get_type() != 0) || (h == "Left" && grid.get_square(i,j-1).get_type() != 0) ){
                                    
                                    if(h == "Up")
                                          i -=1;                              
                                    else if (h == "Down")
                                          i += 1;
                                    else if (h == "Right")
                                          j += 1;
                                    else if (h == "Left")
                                          j -= 1;

                                    myplace = grid.get_square(i,j);
                                    k = 1;


                              }
                              else { 
                                    cout << " This square is NA (nonAccessible). Please select another one" << endl;
                              }

                        }
                        else if( h != "Up" && h != "Down" && h != "Right" && h != "Left"){
                              cout << "Wrong order" << endl;
                        }
                        else {
                              cout << "You re going out from map. Please select another choise" << endl;
                        }
                        
                  } 
            }
            else if(h == "CheckMap"){
                  grid.CheckMap(i,j);
            }
            else if(h == "Equip"){

                  cout << "The items that you can equip are:" << endl;
                  myhero->printInv();

                  cout << "Which do you want to equip?" << endl;
                  string h;
                  cin >> h;
                  
                  if(myhero->checkinv(h) == 1){
                        myhero->out_item(grid.get_item(h));
                                    
                        if(h == "armor1" || h == "armor2"){
                              new_armor = grid.get_armor(h);
                              myhero->set_health(new_armor.get_protection());  
                        }
                        else if( h == "pot1" || h == "pot2" || h == "pot3"){
                              new_potion = grid.get_potion(h);
                              myhero->set_health(new_potion.get_hp());  
                              if(myhero->get_health() <= (28 + myhero->get_level())){ // με τα potion το health δεν μπορει να ειναι πανω απο 
                                    myhero->set_health(28 + myhero->get_level());     // το health που εχει ο παικτης στην αρχη 
                              }
                        }
                        else if(h == "sword" || h == "sword2" || h == "sword3" || h == "axe" ){
                              if (myhero->get_free_hands() == 0){
                                    cout << "You haven't any free hand" << endl;
                                    continue;
                              }
                              else if(myhero->get_free_hands() >= grid.get_weapon(h).get_hands_needed()){
                                    myhero->use_weapon(grid.get_weapon(h).get_damage());
                                    myhero->use_hand(grid.get_weapon(h).get_hands_needed());
                              }
                              else{
                                    cout << "Our hero haven't free hands needed for this weapon" << endl;
                              }
                        }  
                  }
                  else
                  cout << "The item you give doesnt exist" << endl;

            }
            else if(h == "EndGame"){
                  end_game = 1;
            }
            else if( h == "LevelUp"){ // Cheat code για δοκιμαστικούς λόγους
                  
                  myhero->LevelUp();
                  cout << "ok" << endl;
                  myhero->money_plus(1000); // Cheat code
                  cout << "ok2" << endl;

                  cout << "Level Up\n" << "Health = " << myhero->get_health() << endl;
                  cout << "Level = " << myhero->get_level() << endl;
                  cout <<  "Dexterity = " << myhero->get_de() << endl;
                  cout <<  "Strength = " << myhero->get_st() << endl;
                  cout <<  "Agility = " << myhero->get_ag() << endl;
                  cout <<  "Experience = " << myhero->get_ex() << endl;
                  
                  
            }

            }
            else{ // εδω αν ειχε τερατα και ειχε υπολοιηθεί η war θα γινόταν η μάχη
                  
            }
      }
      while (end_game != 1);
}