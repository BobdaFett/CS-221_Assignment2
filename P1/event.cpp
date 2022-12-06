//
// Created by Lucas Vas on 12/6/2022.
//

#include "sim.h"

Simulation::event::event(int t) : timestamp(t) {}

int Simulation::event::get_time() const {
    return timestamp;
}

void Simulation::event::process_event(Simulation* simulation) {}