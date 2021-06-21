#include "Preset.hpp"
#include <string>

Preset::Preset(enum preset_type type, int level){
    __type = type;
    __level = level;
    if(__type == Attack){
        __add_crit_dmg = 0;
        __add_crit_rate = 0;
        switch (__level){
            case 1: __add_dmg = 0.02; break;
            case 2: __add_dmg = 0.03; break;
            case 3: __add_dmg = 0.04; break;
            case 4: __add_dmg = 0.045; break;
            case 5: __add_dmg = 0.05; break;
            default: __add_dmg = 0; break;
        }
    }else if(__type == Termina){
        __add_dmg = 0;
        __add_crit_rate = 0;
        switch (__level){
            case 1: __add_crit_dmg = 0.06; break;
            case 2: __add_crit_dmg = 0.09; break;
            case 3: __add_crit_dmg = 0.12; break;
            case 4: __add_crit_dmg = 0.14; break;
            case 5: __add_crit_dmg = 0.15; break;
            default: __add_crit_dmg = 0; break;
        }
    }else if(__type == Fatal){
        __add_dmg = 0;
        __add_crit_dmg = 0;
        switch (__level){
            case 1: __add_crit_rate = 0.05; break;
            case 2: __add_crit_rate = 0.08; break;
            case 3: __add_crit_rate = 0.10; break;
            case 4: __add_crit_rate = 0.12; break;
            case 5: __add_crit_rate = 0.13; break;
            default: __add_crit_rate = 0; break;
        }
    }else{
        __add_dmg = 0;
        __add_crit_dmg = 0;
        __add_crit_rate = 0;
    }
}

std::ostream& operator<<(std::ostream& os, const Preset& ps){
    std::string type;
    switch (ps.__type){
        case Attack: type = "アタック"; break;
        case Termina: type = "テルミナ"; break;
        case Fatal: type = "フェタル"; break;
        default: type = "プリセット無し"; break;
    }
    os << type << "lv" << ps.__level;
    return os;
}