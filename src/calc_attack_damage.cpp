#include "calc_attack_damage.hpp"

//与ダメージ=ROUND((武器攻撃力*ダメージ補正+基礎攻撃力-敵防御力)*(PA威力倍率、部位倍率、クラススキル倍率などを含む各種倍率)/5)

double calc_lowest_damage(Player player, Weapon weapon, Enemy enemy, Option option,
                          double extra_dmg = 0, double extra_lower_limit = 0
                          ){

    return (weapon.get_attack() * (weapon.get_lower_limit() + option.get_lower_limit() + extra_lower_limit) + player.get_attack() - enemy.get_defense())
           * (1.0 + weapon.get_dmg()) * (1.0 + weapon.get_preset().get_dmg()) * (1.0 + option.get_dmg()) * (1.0 + extra_dmg) / 5.0;

}

double calc_critical_damage(Player player, Weapon weapon, Enemy enemy, Option option,
                          double extra_dmg = 0, double extra_crit_dmg = 0
                          ){

    return (weapon.get_attack() + player.get_attack() - enemy.get_defense())
           * (1.0 + weapon.get_dmg()) * (1.0 + weapon.get_preset().get_dmg()) * (1.0 + option.get_dmg() ) * (1.0 + extra_dmg)
           * player.get_crit_dmg() * (1.0 + weapon.get_crit_dmg()) * (1.0 + weapon.get_preset().get_crit_dmg()) * (1.0 + option.get_crit_dmg()) * (1.0 + extra_crit_dmg) / 5.0;

}

double calc_average_damage(Player player, Weapon weapon, Enemy enemy, Option option,
                          double extra_dmg = 0, double extra_crit_dmg = 0, double extra_crit_rate = 0, double extra_lower_limit = 0
                          ){

    double not_crit_damage, crit_damage;
    double crit_rate = player.get_crit_rate() + weapon.get_crit_rate() + weapon.get_preset().get_crit_rate() + extra_crit_rate;

    not_crit_damage = (weapon.get_attack() * (1.0 + weapon.get_lower_limit() + option.get_lower_limit() + extra_lower_limit) / 2.0 + player.get_attack() - enemy.get_defense())
                      * (1.0 + weapon.get_dmg()) * (1.0 + weapon.get_preset().get_dmg()) * (1.0 + option.get_dmg()) * (1.0 + extra_dmg) / 5.0;

    crit_damage = calc_critical_damage(player, weapon, enemy, option, extra_dmg, extra_crit_dmg);

    return not_crit_damage * (1.0 - crit_rate) + crit_damage * crit_rate;

}