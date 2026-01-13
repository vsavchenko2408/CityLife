#ifndef CITIZEN_H
#define CITIZEN_H


enum Profession
{
    smith,
    doctor, 
    engeneer
};

class Citizen
{
    private:
        int _id;
        short _age;
        int _money;
        Profession _profession;
        short _happiness;
        bool _job;
        bool _home;
        void _decrease_happiness(short int);
        void _increase_happiness(short int);
        void _add_money(short int);
        void _spend_money(short int);

    public:
        static unsigned int _counter;
        static unsigned int _count_day;  
        void update_tick();
        void apply_event_effect();
    //job
        void assign_job(short job_id);
        void remove_job();
        bool is_employed() const;
    //home
        bool has_home() const;
        void buy_home();
    //money
        void receive_salary(int money);
        void pay_daily_expenses();
        int get_money() const;
    //status
        short get_happiness() const;
        Profession get_profession() const;
        void show_info() const;
    //constr
        Citizen();
       // Citizen(...) = delete;
        ~Citizen();
};

#endif