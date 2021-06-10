#include <iostream>
#include <string>
#include "People.h"

using namespace std;

class Square{
      private:
            int type; // 0 == nonAccessible, 1 == market, 2 == common square
            Item* all_items;
            Hero* hero;
            Monster* monster;
            int monster_in;
      public:
            Square(int tp):type(tp){ monster_in = 0;}
            Square();
            ~Square() {}
            
            void create_market() { type = 1; }
            void create_nonAccessible() { type = 0; }

            void set_items(Item* itms) { all_items = itms; }
            void set_hero(Hero* h){ hero = h; }

            int get_type() { return type; }
            int get_if_monster_in() { return monster_in; }

};


class Grid{
      private:
            Square** grid;
            string name;
            Item* all_items;
            Armor* armor;
            Weapon* weapon;
            Potion* potion;
            int itms;
      public:
            Grid(string nm);
            ~Grid() {}
            Item* create_items();
            
            void set_hero_to(Hero* h,int num,int num2) {if(num <= 4 && num2 <= 4) grid[num][num2].set_hero(h); else cout << "this square doesn't exist " << endl;}
            
            Square get_square(int i,int j) { return grid[i][j]; }
            int get_type_of_square(int i,int j) { return grid[i][j].get_type(); }
            void CheckMap(int ii, int jj);
            Item* print_items(int lvl);
            Item get_item(string nm);
            Armor get_armor(string nm);
            Weapon get_weapon(string nm);
            Potion get_potion(string nm);
            int get_itms() { return itms; }

};

