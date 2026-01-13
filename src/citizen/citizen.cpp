#include "../../include/citizen.h"
#include <iostream>
unsigned int Citizen::_counter = 0;

        void Citizen::update_tick(const int& _count_day)
        {

            if(!_job)
            {
                if(_count_day%30 == 0)
                {
                    _decrease_happiness(5);
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
            
            pay_daily_expenses(_count_day);

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
            _spend_money(1000);
            _home = true;
            _increase_happiness(20);
        }

    //money
        void Citizen::receive_salary(int money)
        {
            _add_money(money);
            _increase_happiness(20);
        }
        void Citizen::pay_daily_expenses(const int& _count_day)
        {
            if(_home)
            {
                _spend_money(5);
                if(_count_day%7 == 0)
                {
                _decrease_happiness(1);
                }
            }
            if(!_home)
            {
                _spend_money(2);
                if(_count_day%7 == 0)
                _decrease_happiness(2);
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
        void Citizen::show_info(const int& _count_day) const
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
        //private
        void Citizen::_decrease_happiness(short int decrease)
        {
            if((_happiness - decrease) > 0)
            {
                _happiness -= decrease;
            }
        }
        void Citizen::_increase_happiness(short int increase)
        {
            if((increase + _happiness) <= 100)
            {
                _happiness +=increase;
            }
        }
        void Citizen::_add_money(short int add_money)
        {
            _money += add_money;
        }
        void Citizen::_spend_money(short int spend_money)
        {
            if((_money - spend_money) > 0)
            {
                _money -= spend_money;
            }
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