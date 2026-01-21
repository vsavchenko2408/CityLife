#ifndef EVENT_H
#define EVENT_H
#include <string>

enum Target
{
    all = 1,
    OneRandom,
    Percent
};

struct EventEffect
{
    int happiness_delta;
    int money_delta;
    EventEffect(int happy, int money) : happiness_delta(happy), money_delta(money)
    {
        
    }
};

class Event
{
    
    std::string _event_name;
    int _chance_percent;
    int _target_percent;
    Target _target;
    EventEffect _effect;

    public:

    Event(std::string name, int chance_percent, int target_percent,Target target, EventEffect effect ) 
    : _event_name(name), _chance_percent( chance_percent),
     _target_percent(target_percent), _target(target), _effect(effect)
    {

    }
    const std::string& get_name() const;
    int get_chance_percent() const;
    Target get_target() const;
    int get_target_percent() const;
    const EventEffect& get_effect() const;
    
};
#endif