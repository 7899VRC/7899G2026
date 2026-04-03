#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

inline pros::Motor fintake(-1);
inline pros::Motor mintake(-9);
inline pros::Motor tintake(3);

inline ez::Piston hood('B');
inline ez::Piston descore('A');
inline ez::Piston scraper('D');
inline ez::Piston intlift('E');
inline ez::Piston midesc('C');

inline pros::Distance hoodd(21);
// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');