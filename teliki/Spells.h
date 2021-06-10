#include <iostream>
#include <string>
#include "Outside.h"

using namespace std;

class Spell{
      private:
            string name;
            int price;
            int level;
            int damage;
            int magic_power;
      public:
};

class IceSpell: public Spell{
      private:
            int damage_per_round;
      public:
};

class FireSpell: public Spell{
      private:
            int damage_defence_per_round;
      public:
};

class LightningSpell: public Spell{
      private:
            int damage_possib_per_round;
      public:
};
