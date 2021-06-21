#ifndef OPTION_HPP
#define OPTION_HPP

class Option{
    private:

        double __add_dmg;
        double __add_crit_dmg;
        double __add_crit_rate;
        double __add_lower_limit;

    public:

        Option(double add_dmg = 0, double add_crit_dmg = 0, double add_crit_rate = 0, double add_lower_limit = 0){
            __add_dmg = add_dmg;
            __add_crit_dmg = add_crit_dmg;
            __add_crit_rate = add_crit_rate;
            __add_lower_limit = add_lower_limit;
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
            return __add_lower_limit;
        }
};

#endif