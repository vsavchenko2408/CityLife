#ifndef CITY_H
#define CITY_H
#include <vector>
#include <iostream>
#include "citizen.h"
#include "event.h"


class City
{
    private:
        //unsigned int _day;
        std::vector <Citizen> citizens;
        std::vector <Event> events;
        void _update_tick();
        unsigned int _average_happiness();
        unsigned int _is_employed() const;
        unsigned int _has_home() const;
        unsigned long int _average_money() const;
    public:

    City()
    {
        events.push_back(Event("Festival", 3, 10, all, {3,0}));
        events.push_back(Event("Fire", 5,10, Percent, {-50, -50} ));
    }
    void add_citizen();
    void run(unsigned int);
    void print_report();

};

#endif