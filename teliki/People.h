#include <iostream>
#include <string>
#include "Items.h"


using namespace std;

class Living{
      private:
            string name;
            int Level;
            int uphealth;
            int HealthPower;
            int points_to_levelup;
            int points;
      public:
            Living(string nm,int lvl,int health):name(nm),Level(lvl),HealthPower(health) { uphealth = 3; points_to_levelup = 25; points = 0;}
            Living(string nm,int health):name(nm),HealthPower(health) {}
            Living() {HealthPower = 25;}
            ~Living() {}
            
            virtual void onelevelup() { Level += 1; }
            virtual void healthup() {HealthPower += uphealth; uphealth += 1;}
            
            int get_uphealth() { return uphealth; }
            virtual int get_p() { return points; }
            virtual int get_ptl() { return points_to_levelup; }
            int get_level() { return Level; }
            int get_health() { return HealthPower; }

            virtual void set_ptl(int n) {points_to_levelup = n; }
            virtual void set_p(int num) { points = num; }
            void set_health(int num) { HealthPower += num; }
};

class Hero: public Living{
      private:
            Item index[36];
            int* items_in;
            int MagicPower;
            int strength;
            int dexterity;
            int agility;
            int money;
            int experience;
            int free_hands;
            
            int levelupMP;
            int levelupST;
            int levelupDE;
            int levelupAG;
            int levelupEX;

            

      public:
            Hero(int lvl,int health):Living("Hero",lvl,health) { /*index = new Item[36];*/ items_in = new int(0); MagicPower = 50; strength = 4; dexterity = 5; agility = 6; money = 120; experience = 1; free_hands = 2; levelupMP = 3; levelupST = 1; levelupDE = 2; levelupAG = 3; levelupEX = 1;}
            Hero() { }
            ~Hero() {}

            virtual void set_magicpower(int num) { MagicPower = MagicPower + num; }
            virtual void set_strength(int num) { strength = strength + num; }
            virtual void set_dexterity(int num) { dexterity = dexterity + num; }
            virtual void set_agility(int num) { agility = agility + num; }
            virtual void set_experience(int num) { experience = experience + num; }

            void LevelUp();
            
            void set_money(int num) { money -= num; }
            virtual void set_mp() { MagicPower += levelupMP++; }
            virtual void set_st() { strength += levelupST++; }
            virtual void set_de() { dexterity += levelupDE++; }
            virtual void set_ag() { agility += levelupAG++; }
            virtual void set_ex() { experience += levelupEX++; }

            int get_money() { return money; }
            int get_de() { return dexterity; }
            int get_st() { return strength; }
            int get_ag() { return agility; }
            int get_ex() { return experience; }
            int get_free_hands() { return free_hands; }

            void use_hand(int num) { free_hands -= num; }
            void use_weapon(int num) { strength += num; }

            void printInv();
            void printequip();
            void printtosell();
            int checkinv(string nm);
            void money_plus(int n) { money += n; } // Cheat Code
            
            void insert_item(Item itm);
            void out_item(Item itm);
            // virtual int war(Monster mon, Hero myhero);  /*if(get_p() == get_ptl()) LevelUp();*/
            
            // quitGame();
};

class Warrior: public Hero{
      public:
            Warrior(int lvl,int health):Hero(lvl,health) { set_agility(2); set_strength(1); }
            ~Warrior() {}

            void Warrior_levelup() { LevelUp(); set_st(); set_ag(); }
}; 

class Soncerer: public Hero{
      public:
            Soncerer(int lvl,int health):Hero(lvl,health) { set_dexterity(1); set_agility(2); }
            ~Soncerer() {}

            void Soncerer_levelup() { LevelUp(); set_de(); set_ag(); }

};

class Paladin: public Hero{
      public:
            Paladin(int lvl,int health):Hero(lvl,health) { set_strength(1); set_dexterity(1); }
            ~Paladin() {}

            void Paladin_levelup() { LevelUp(); set_st(); set_de(); }
};

class Monster: public Living{
      private:
            string name;
            int attack;
            int defence;
            double possibility;
      public:
            Monster(string nm);
            Monster() {}
            ~Monster() {}
};

class Dragon: public Monster{
      public:
            Dragon():Monster("Dragon") {}
            ~Dragon() {}
};

class Exoskeleton: public Monster{
      public:
            Exoskeleton():Monster("Exoseleton") {}
            ~Exoskeleton() {}
};

class Spirit: public Monster{
      public:
            Spirit():Monster("Spirit") {}
            ~Spirit() {}
};