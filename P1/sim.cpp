//
// Created by Lucas Vas on 12/6/2022.
//

#include "sim.h"

void Simulation::schedule_event(event* new_event) {
    queue.push(new_event);
}

void Simulation::run() {
    while (!queue.empty()) {
        event *next = queue.top();
        queue.pop();
        current_time = next->get_time();
        next->process_event(this);
        delete next;
    }
}

bool Simulation::seat() {
    cout << "Time: " << current_time << " minutes. ";
    cout << "Customer arrives. ";
    if (num_seats_free < 1) {
        cout << "There is no room; customer leaves." << endl;
        return false;
    } else {
        cout << "Customer is seated. ";
        num_seats_free--;
        cout << num_seats_free << " seats left." << endl;
        return true;
    }
}

void Simulation::leave() {
    cout << "Time: " << current_time << " minutes. ";
    cout << "Customer leaves." << endl;
    num_seats_free++;
}