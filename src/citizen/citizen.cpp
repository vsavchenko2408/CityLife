#include "../../include/citizen.h"
#include <iostream>
unsigned int Citizen::_counter = 0;
unsigned int Citizen::_count_day = 0;
        void Citizen::update_tick()
        {
            _count_day++;
            if(!_job)
            {
                if(_count_day%30 == 0)
                {
                    _happiness -= 5;
                }
            }
            if(_job)
            {
                if(_count_day%30 == 0)
                {
                    receive_salary(1000);
                }
            }  
            if(!_home && _money>1500)
            {
                buy_home();
            }
            
            pay_daily_expenses();

        }


        void Citizen::apply_event_effect()
        {

        }
    //job
        void Citizen::assign_job(short job_id)
        {
            _job = true;
        }
        void Citizen::remove_job()
        {
            _job = false;
        }
        bool Citizen::is_employed() const
        {
            if(_job == true)
            {
                return true;
            }
            return false;
        }
    //home

        bool Citizen::has_home() const
        {
            if(_home == true)
            {
                return true;
            }
            return false;
        }
        void Citizen::buy_home()
        {
            _money -= 1000;
            _home = true;
        }

    //money
        void Citizen::receive_salary(int money)
        {
            _money += money;
        }
        void Citizen::pay_daily_expenses()
        {
            if(_home)
            {
                _money -= 5;
            }
            if(!_home)
            {
                _money -= 2;
            }
            
        }
        int Citizen::get_money() const
        {
            return _money;
        }
    //status
        short Citizen::get_happiness() const
        {
           return _happiness; 
        }
        Profession Citizen::get_profession() const
        {
            return _profession;
        }
        void Citizen::show_info() const
        {   
            #ifdef WIN32
            system("cls");
            #endif
            #ifdef linux
            system("clear");
            #endif
            std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "Day: " << _count_day << std::endl;
            std::cout << "Id: " << _id << std::endl;
            std::cout << "Profession: " << get_profession() << std::endl;
            std::cout << "Home: " << has_home() << std::endl;
            std::cout << "Job: " << is_employed() << std::endl;
            std::cout << "Happy: " << get_happiness() << std::endl;
            std::cout << "Money: " << get_money() << std::endl;
            std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
        }


    //constr
        Citizen::Citizen() : _id(_counter + 1), _age(18), _money(100), _happiness(50), _profession(engeneer), _job(true), _home(false)
        {
            ++_counter;
        }

        Citizen::~Citizen()
        {
            // nothing to destroy for now
        }