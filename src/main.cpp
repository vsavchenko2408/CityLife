#include <iostream>
#include <thread> 
#include "../include/citizen.h"
#include "../include/city.h"

int main()
{
    srand(time(NULL));
    City c;
    c.run(200);

    //c.print_report();

}