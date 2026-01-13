#include <iostream>
#include <thread> 
#include "../include/citizen.h"

int main()
{
    Citizen c;
    while(Citizen::_count_day < 200)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        c.update_tick();
        c.show_info();
    }

}