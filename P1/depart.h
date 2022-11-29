//
// Created by Lucas Vas on 11/29/2022.
//

#ifndef CS_221_ASSIGNMENT2_DEPART_H
#define CS_221_ASSIGNMENT2_DEPART_H

#include "event.h"

class Depart : Event {
public:
    explicit Depart(double time=0);
    void act();
};


#endif //CS_221_ASSIGNMENT2_DEPART_H
