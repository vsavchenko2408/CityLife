#ifndef CITY_H
#define CITY_H
#include <vector>
#include <iostream>
#include "citizen.h"

class City
{
    private:
        //unsigned int _day;
        std::vector <Citizen> citizens;
        void _update_tick();
        unsigned int _average_happiness();
        unsigned int _is_employed() const;
        unsigned int _has_home() const;
        unsigned long int _average_money() const;
    public:


    void add_citizen();
    void run(unsigned int);
    void print_report();

};

#endif