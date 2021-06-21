#ifndef PRESET_HPP
#define PRESET_HPP

#include <ostream>

enum preset_type{
    None,
    Attack,
    Termina,
    Fatal
};

class Preset{
    private:
    
        enum preset_type __type;
        int __level;
        double __add_dmg;
        double __add_crit_dmg;
        double __add_crit_rate;
    
    public:

        Preset(enum preset_type type = None, int level = 0);

        const enum preset_type get_type(){
            return __type;
        }
        const int get_level(){
            return __level;
        }
        const double get_dmg(){
            return __add_dmg;
        }
        const double get_crit_dmg(){
            return __add_crit_dmg;
        }
        const double get_crit_rate(){
            return __add_crit_rate;
        }

        friend std::ostream& operator<<(std::ostream& os, const Preset& ps);
};

#endif