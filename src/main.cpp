#include <iostream>
#include <thread> 
#include "../include/citizen.h"
#include "../include/city.h"

int main()
{
    srand(time(NULL));
    City c;
    for(int i = 0; i < 12; i++)
    {
    c.add_citizen();
    c.add_citizen();
    }
    c.run(200);
    //c.print_report();

}