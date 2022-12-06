//
// Created by Lucas Vas on 12/6/2022.
//

#include <iostream>
#include "sim.h"
using namespace std;

int main() {
    Simulation hotdogs {5};
    int time{};
    while (time < 20)
        hotdogs.schedule_event(new arrival(time++));
    // Run simulation
    hotdogs.run();
    return 0;
}