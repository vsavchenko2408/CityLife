#include "../../include/city.h"

    //private
    void City::_update_tick()
    {
        _count_day++;
        for( auto i : citizens)
        {
            i.update_tick(_count_day);
        }
    }
    unsigned int City::_average_happiness()
    {
        unsigned int happiness = 0;
        for(auto i : citizens)
        {
            happiness += i.get_happiness();
        }
        return happiness / citizens.size();
    }
    //public
    unsigned int City::_count_day = 0;
    void City::add_citizen()
    {
        citizens.push_back(Citizen());
    }
    void City::run(unsigned int days_for_run)
    {
        for(size_t i = 0; i < days_for_run; ++i)
        {
            _update_tick();
        }
    }
    void City::print_report()
    {
        std::cout << "++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "City report: " << std::endl;
        std::cout << "Days life: " << _count_day << std::endl;
        std::cout << "Population: " << citizens.size() << std::endl;
        std::cout << "Average happiness: " << _average_happiness() << std::endl;
        std::cout << "++++++++++++++++++++++++++++++++++++" << std::endl;
    }