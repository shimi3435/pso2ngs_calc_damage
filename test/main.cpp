#include <iostream>
#include <string>
#include <cmath>
#include "Preset.hpp"
#include "Weapon.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Option.hpp"
#include "calc_attack_damage.hpp"

int main(void){

    //Player(ハンターorファイターorレンジャーorガンナーorフォースorテクター)
    Player fighter(Fighter);

    //Enemy(名前，防御値)
    Enemy enemy;

    //Preset(アタックorテルミナorフェタル，レベル1~5)
    Preset attack5(Attack, 5);
    Preset termina5(Termina, 5);
    Preset fatal5(Fatal, 5);

    //Weapon(名前，攻撃力，威力＋，クリ威力＋，クリ率＋，威力下限，プリセット)
    Weapon torowa_attack5_half("トロワーダガー(クリ率9%想定)", 270, 0.22, 0, 0.09, 0.7, attack5);
    Weapon torowa_termina5_half("トロワーダガー(クリ率9%想定)", 270, 0.22, 0, 0.09, 0.7, termina5);
    Weapon torowa_fatal5_half("トロワーダガー(クリ率9%想定)", 270, 0.22, 0, 0.09, 0.7, fatal5);

    Weapon torowa_attack5("トロワーダガー(クリ率18%想定)", 270, 0.22, 0, 0.18, 0.7, attack5);
    Weapon torowa_termina5("トロワーダガー(クリ率18%想定)", 270, 0.22, 0, 0.18, 0.7, termina5);
    Weapon torowa_fatal5("トロワーダガー(クリ率18%想定)", 270, 0.22, 0, 0.18, 0.7, fatal5);

    //Option(威力＋，クリ威力＋，クリ率＋，威力下限＋)
    Option option(std::pow(1.05, 4), 0, 0, std::pow(1.015, 4));

    //ダメージの期待値計算(Player, Weapon, Enemy, Option, どの他の威力＋，その他のクリ威力＋，その他のクリ率＋，その他の威力下限＋)
    double torowa_attack5_damage_half = calc_average_damage(fighter, torowa_attack5_half, enemy, option, 0, 0, 0, 0);
    double torowa_termina5_damage_half = calc_average_damage(fighter, torowa_termina5_half, enemy, option, 0, 0, 0, 0);
    double torowa_fatal5_damage_half = calc_average_damage(fighter, torowa_fatal5_half, enemy, option, 0, 0, 0, 0);

    double torowa_attack5_damage = calc_average_damage(fighter, torowa_attack5, enemy, option, 0, 0, 0, 0);
    double torowa_termina5_damage = calc_average_damage(fighter, torowa_termina5, enemy, option, 0, 0, 0, 0);
    double torowa_fatal5_damage = calc_average_damage(fighter, torowa_fatal5, enemy, option, 0, 0, 0, 0);

    std::cout << torowa_attack5_half << " のダメージ期待値：" << torowa_attack5_damage_half << "\n";
    std::cout << torowa_termina5_half << " のダメージ期待値：" << torowa_termina5_damage_half << "\n";
    std::cout << torowa_fatal5_half << " のダメージ期待値：" << torowa_fatal5_damage_half << "\n";

    std::cout << torowa_attack5 << " のダメージ期待値：" << torowa_attack5_damage << "\n";
    std::cout << torowa_termina5 << " のダメージ期待値：" << torowa_termina5_damage << "\n";
    std::cout << torowa_fatal5 << " のダメージ期待値：" << torowa_fatal5_damage << "\n";

    return 0;
}