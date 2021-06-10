#include <iostream>
#include <string>
// 
// #include "Outside.h"

using namespace std;

class Item{
      private:
            string type;
            string name;
            int price;
            int level;
      public:
            Item(string tp,string nm,int pr,int lvl):type(tp),name(nm),price(pr),level(lvl) {/*cout << "A " << name << " Created" << endl;*/}
            Item() {}
            ~Item() {}
            
            string get_name() { return name; }
            string get_type() { return type; }
            int get_price() { return price; }
            int get_level() { return level; }

            // int get_protection(){ cout << "ok" << endl; return 1;}

};

class Weapon: public Item{
      private:
            string name;
            int damage;
            int hands_needed;
      public:
            Weapon(string nm,int pr,int lvl,int dmg,int hand):Item("Weapon",nm,pr,lvl),name(nm),damage(dmg),hands_needed(hand){}
            Weapon() {}
            ~Weapon() {}

            int get_damage() { return damage; }
            int get_hands_needed() { return hands_needed; }
};

class Armor: public Item{
      private:
            string name;
            int protection;
      public:
            Armor(string nm,int pr,int lvl,int prot):Item("Armor",nm,pr,lvl), name(nm), protection(pr) {}
            Armor() {}
            ~Armor() {}

            virtual int get_protection() { return protection; }
};

class Potion: public Item{
      private:
            string name;
            int better;
      public:
            Potion(string nm,int pr,int lvl,int btr):Item("Potion",nm,pr,lvl),name(nm),better(btr) {}
            Potion() {}
            ~Potion() {}

            int get_hp() { return better; }
      
};