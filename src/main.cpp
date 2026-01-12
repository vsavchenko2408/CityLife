#include <iostream>
#include "../include/citizen.h"
#include <ctype.h> //for size_t
int main()
{
    Citizen c;
    while(Citizen::_count_day < 100)
    {
        c.update_tick();
        c.show_info();
    }

}