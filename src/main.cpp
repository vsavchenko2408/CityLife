#include <iostream>
#include <thread> 
#include "../include/citizen.h"
#include "../include/city.h"
#include "../include/event.h"
#define DEBUG
int main()
{
    srand(time(nullptr));
    City c;
    #ifdef WIN32
    system("cls");
    #endif
    #ifdef linux
    system("clear");
    #endif
    c.run(200);

    //c.print_report();

}