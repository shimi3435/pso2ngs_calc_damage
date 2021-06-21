#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy{
    private:
        
        std::string __name;
        double __defense;

    public:
        
        Enemy(std::string name = "No name", double defense = 400){
            __name = name;
            __defense = defense;
        }

        std::string get_name(){
            return __name;
        }
        double get_defense(){
            return __defense;
        }
};

#endif