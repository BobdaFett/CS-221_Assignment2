//
// Created by Lucas Vas on 11/29/2022.
//

#ifndef CS_221_ASSIGNMENT2_ARRIVAL_H
#define CS_221_ASSIGNMENT2_ARRIVAL_H

#include "event.h"

class Arrival : Event {
public:
    explicit Arrival(double time=0);
    void act();
private:
    // Maximum 15 mins to eat a hotdog? I think that's reasonable.
    double t_max = 15, t_min = 3;
};


#endif //CS_221_ASSIGNMENT2_ARRIVAL_H
