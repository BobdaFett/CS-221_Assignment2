//
// Created by Lucas Vas on 12/6/2022.
//

#include "sim.h"

arrival::arrival(int time) : event(time) {}

void arrival::process_event(Simulation* simulation) {
    if(simulation->seat()) {
        int new_time = rand() % t_max + t_min;
        simulation->schedule_event(new departure(new_time + get_time()));
    }
}