//
// Created by Lucas Vas on 11/29/2022.
//

#ifndef CS_221_ASSIGNMENT2_EVENT_H
#define CS_221_ASSIGNMENT2_EVENT_H


class Event {
public:
    explicit Event(double time=0);
    virtual void act();
    double get_time();

private:
    double time;
};


#endif //CS_221_ASSIGNMENT2_EVENT_H
