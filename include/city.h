#ifndef CITY_H
#define CITY_H
#include <vector>
#include <iostream>
#include "citizen.h"

class City
{
    private:
        unsigned int _day;
        std::vector <Citizen> citizens;
        void _update_tick();
        unsigned int _average_happiness();
    public:

    static unsigned int _count_day; 
    void add_citizen();
    void run(unsigned int);
    void print_report();

};

#endif