#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Preset.hpp"
#include <ostream>
#include <string>

class Weapon{
    private:
        std::string __name;
        int __attack;
        double __add_dmg;
        double __add_crit_rate;
        double __add_crit_dmg;
        double __lower_limit;
        Preset __preset;

    public:
        Weapon(std::string name = "No name", int attack = 200,
               double add_dmg = 0, double add_crit_dmg = 0, double add_crit_rate = 0,
               double lower_limit = 0.7, Preset preset = Preset()
               ){
            __name = name;
            __attack = attack;
            __add_dmg = add_dmg;
            __add_crit_rate = add_crit_rate;
            __add_crit_dmg = add_crit_dmg;
            __lower_limit = lower_limit;
            __preset = preset;
        }

        std::string get_name(){
            return __name;
        }
        double get_attack(){
            return __attack;
        }
        double get_dmg(){
            return __add_dmg;
        }
        double get_crit_rate(){
            return __add_crit_rate;
        }
        double get_crit_dmg(){
            return __add_crit_dmg;
        }
        double get_lower_limit(){
            return __lower_limit;
        }
        Preset get_preset(){
            return __preset;
        }
 
        friend std::ostream& operator << (std::ostream& os, const Weapon& weapon);

};

#endif