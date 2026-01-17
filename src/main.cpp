#include <iostream>
#include <thread> 
#include "../include/citizen.h"
#include "../include/city.h"
#include "../include/event.h"

int main()
{
    unsigned int _count_day = 0; 
    srand(time(NULL));
    City c;
    c.run(200);

    //c.print_report();

}