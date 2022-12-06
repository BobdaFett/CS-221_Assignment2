//
// Created by Lucas Vas on 12/6/2022.
//

#include "sim.h"

departure::departure(int time) : event(time) {}

void departure::process_event(Simulation *simulation) {
    simulation->leave();
}