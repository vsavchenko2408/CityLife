#include "../../include/city.h"
#include <thread>
    //global
    unsigned int _count_day = 0; 
    //private
    void City::_update_tick()
    {
        _count_day++;
        for( auto &i : citizens)
        {
            i.update_tick(_count_day);
        }
    }
    unsigned int City::_average_happiness()
    {
        unsigned int happiness = 0;
        for(auto &i : citizens)
        {
            happiness += i.get_happiness();
        }
        if(citizens.size() > 0)
        {
        return happiness / citizens.size();
        }
        else
        {
        return 0;
        }
    }
    unsigned int City::_is_employed() const
    {
        unsigned int is_employed = 0;
        for(auto &i: citizens)
        {
            if(i.is_employed())
            {
                is_employed++;
            }
        }
        return is_employed;
    }
    unsigned int City::_has_home() const
    {
        unsigned int has_home = 0;
        for(auto &i: citizens)
        {
            if(i.has_home())
            {
                has_home++;
            }
        }
        return has_home;
    }
        unsigned long int City::_average_money() const
        {
            unsigned long int money = 0;
            if(citizens.size() > 0)
            {
            for(auto &i : citizens)
            {
                money += i.get_money();
            }
            return money / citizens.size();
            }
            else
            {
                return 0;
            }
        }
    //public
    void City::add_citizen()
    {
        citizens.push_back(Citizen());
    }
    void City::run(unsigned int days_for_run)
    {
        for(size_t i = 0; i < days_for_run; i++)
        {
            _update_tick();
            if(_count_day%30 == 0)
            {
                print_report();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
    void City::print_report()
    {
        std::cout << "++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "City report: " << std::endl;
        std::cout << "Days life: " << _count_day << std::endl;
        std::cout << "Population: " << citizens.size() << std::endl;
        std::cout << "Employed: " << _is_employed() << std::endl;
        std::cout << "Haused: " << _has_home() << std::endl;
        std::cout << "Average happiness: " << _average_happiness() << std::endl;
        std::cout << "Average money: " << _average_money() << std::endl;
        std::cout << "++++++++++++++++++++++++++++++++++++" << std::endl;
    }