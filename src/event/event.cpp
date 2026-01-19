#include "../../include/event.h"



    const std::string& Event::get_name() const
    {
        return _event_name;
    }

    int Event::get_chance_percent() const
    {
        return _chance_percent;
    }
    Target Event::get_target() const
    {
        return _target;
    }
    int Event::get_target_percent() const
    {
        return _target_percent;
    }
    const EventEffect& Event::get_effect() const
    {
        return _effect;
    }