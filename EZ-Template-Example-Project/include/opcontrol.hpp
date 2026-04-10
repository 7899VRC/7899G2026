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

void subsystemcontrol(){
    if(master.get_digital(DIGITAL_L1) || master.get_digital(DIGITAL_L2)){
      intlift.set(false);
      fintake.move(127);
    }else if (master.get_digital(DIGITAL_R1)){
      intlift.set(false);
      fintake.move(127);
    }else if(master.get_digital(DIGITAL_R2)){
      intlift.set(true);
      fintake.move(-127);
    }else{
      fintake.move(0);
    }

    if(master.get_digital(DIGITAL_L1) || master.get_digital(DIGITAL_L2)){
      mintake.move(127);
    }else if(master.get_digital(DIGITAL_R1)){
      mintake.move(127);
    }else if(master.get_digital(DIGITAL_R2)){
      mintake.move(-127);
    }else{
      mintake.move(0);
    }

    if(master.get_digital(DIGITAL_L1)){
      tintake.move(127);
      hood.set(true);
    }else if(master.get_digital(DIGITAL_R1)){
      tintake.move(-127);
    }else if(master.get_digital(DIGITAL_R2)){
      tintake.move(-127);
    }else if(master.get_digital(DIGITAL_L2)){
      hood.set(false);
      if(hoodd.get() > 125){
        tintake.move(127);
      }else{
        double hoodtimer = pros::millis();
        while(((pros::millis()-hoodtimer) < 2000) && master.get_digital(DIGITAL_L2)){

          chassis.opcontrol_arcade_standard(ez::SPLIT);

          hood.button_toggle(master.get_digital(DIGITAL_RIGHT));
          descore.button_toggle(master.get_digital( DIGITAL_B));
          scraper.button_toggle(master.get_digital(DIGITAL_DOWN));
          intlift.button_toggle(master.get_digital(DIGITAL_Y));
          midesc.button_toggle(master.get_digital(DIGITAL_UP));

          pros::delay(ez::util::DELAY_TIME);
        }
        tintake.move(0);
      }
    }else{
      tintake.move(0);
    }

    hood.button_toggle(master.get_digital(DIGITAL_RIGHT));
    descore.button_toggle(master.get_digital(DIGITAL_B));
    scraper.button_toggle(master.get_digital(DIGITAL_DOWN));
    intlift.button_toggle(master.get_digital(DIGITAL_Y));
    midesc.button_toggle(master.get_digital(DIGITAL_UP));
}