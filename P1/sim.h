//
// Created by Lucas Vas on 12/6/2022.
//

#ifndef CS_221_ASSIGNMENT2_SIM_H
#define CS_221_ASSIGNMENT2_SIM_H

#include <queue>
#include <iostream>
#include <cmath>
using std::priority_queue;
using std::vector;
using std::cout;
using std::endl;

class Simulation {
public:
    class event {
    public:
        explicit event(int t);
        int get_time() const;
        virtual void process_event(Simulation* simulation);
    private:
        int timestamp;
    };
    explicit Simulation(int total_seats) : queue(), current_time(0), num_seats_free(total_seats) {}
    void schedule_event(event* new_event);
    void run();

    bool seat();
    void leave();

private:
    struct event_less {
        bool operator() (const event* a, const event* b) const {
            return a->get_time() > b->get_time();
        }
    };
    priority_queue<event*, vector<event*>, event_less> queue;
    int current_time;
    int num_seats_free;
};

class departure : public Simulation::event {
public:
    explicit departure(int time);
    void process_event(Simulation* simulation) override;
};

class arrival : public Simulation::event {
public:
    explicit arrival(int time);
    void process_event(Simulation* simulation) override;
private:
    int t_min = 3, t_max = 15;
};

#endif //CS_221_ASSIGNMENT2_SIM_H
