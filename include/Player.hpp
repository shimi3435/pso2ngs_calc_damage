#ifndef PLAYER_HPP
#define PLAYER_HPP

enum job_class{
    Hunter,
    Fighter,
    Ranger,
    Gunner,
    Force,
    Tector
};

class Player{
    private:

        enum job_class __job;
        int __attack;
        double __crit_dmg;
        double __crit_rate;

    public:

        Player(enum job_class job = Hunter){
            __job = job;
            __crit_dmg = 1.2;
            __crit_rate = 0.05;

            //クラスレベル20における攻撃力
            switch(__job){
                case Hunter: __attack = 646; break;
                case Fighter: __attack = 650; break;
                case Ranger: __attack = 644; break;
                case Gunner: __attack = 647; break;
                case Force: __attack = 649; break;
                case Tector: __attack = 642; break;
                default: __attack = 646; break;
            }
        }

        int get_attack(){
            return __attack;
        }
        double get_crit_dmg(){
            return __crit_dmg;
        }
        double get_crit_rate(){
            return __crit_rate;
        }
};

#endif