#include <iostream>
#include <thread> 
#include "../include/citizen.h"
#include "../include/city.h"
#include "../include/event.h"
#define DEBUG
int main()
{
    srand(time(nullptr));
    City c; //main city
    #ifdef WIN32
    system("cls");
    #endif
    #ifdef linux
    system("clear");
    #endif
    c.run(2000); //run game

    //c.print_report();

}