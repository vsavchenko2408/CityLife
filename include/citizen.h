#ifndef CITIZEN_H
#define CITIZEN_H

class Citizen
{
    static int _id;
    short _age;
    int _money;
    short _happiness;
    union _profession;
    union _state;
    public:
    void update_tick();
};

#endif