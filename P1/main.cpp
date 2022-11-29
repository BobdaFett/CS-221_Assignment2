//
// Created by Lucas Vas on 11/28/2022.
//

// We are going to create an "event simulation" program. All of these events should be created and prioritized through
// their timestamp. The queue will act as a clock and will be loaded with some initial events.
// Refer to the "Discrete Event Simulation" section in the Class 11 slides.

// It is recommended that you store key-pair types of the form (timestamp, event)
// Then pop event E with the smallest timestamp, simulate what happened between t_last and t_current
// Simulate E, set t_last to t_current.

#include <iostream>
#include <ctime>
#include <queue>
#include "event.h"
#include "arrival.h"
#include "depart.h"
using namespace std;

bool event_less(Event* a, Event *b);

int main() {

    double t_current, t_last;
    priority_queue<Event*, vector<Event*>, bool (*)(Event*, Event*)> q(event_less);

    // The base of this program is the "event loop," which will keep track of and execute events in the order they should be done in.
    while(!q.empty()) {
        Event* next_event = q.top();
        t_current = next_event->get_time();
        next_event->act();
        delete next_event;
    }

    return 0;
}

bool event_less(Event* a, Event *b) {
    return a->get_time() > b->get_time();
}