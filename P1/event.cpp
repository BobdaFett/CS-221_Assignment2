//
// Created by Lucas Vas on 11/29/2022.
//

#include "event.h"

Event::Event(double time) : time(time) {
    // Constructor - creates a new Event.
    // So far, this class isn't used and is simply a skeleton.
}

/// This will most likely create an instance of a derived class.
void Event::act() {
    // I don't think that we're using this current class, so nothing is here for now.
}

/**
 * @return The current timestamp of the Event.
 */
double Event::get_time() {
    return time;
}