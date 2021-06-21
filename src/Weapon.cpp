#include "Weapon.hpp"

std::ostream& operator<<(std::ostream& os, const Weapon& weapon){
    os << weapon.__name << weapon.__preset;
    return os;
}