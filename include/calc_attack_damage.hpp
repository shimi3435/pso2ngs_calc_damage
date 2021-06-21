#ifndef CALC_ATTACK_DAMAGE_HPP
#define CALC_ATTACK_DAMAGE_HPP

#include "Preset.hpp"
#include "Weapon.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Option.hpp"

double calc_lowest_damage(Player player, Weapon weapon, Enemy enemy, Option option,
                          double extra_dmg, double extra_lower_limit
                          );

double calc_critical_damage(Player player, Weapon weapon, Enemy enemy, Option option,
                          double extra_dmg, double extra_crit_dmg
                          );

double calc_average_damage(Player player, Weapon weapon, Enemy enemy, Option option,
                          double extra_dmg, double extra_crit_dmg, double extra_crit_rate, double extra_lower_limit
                          );
#endif