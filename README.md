# CityLife Simulator (C++)

CityLife is a simple **tick-based city life simulator** written in C++.  
The project simulates how citizens live day by day depending on their job,
home, money and happiness.

This project was created as a **pet-project** to practice:
- C++ OOP
- class design and responsibility separation
- simple simulation architecture

---

## 🏙️ Project Idea

The city lives in **days (ticks)**.

Each day:
- the city increases the day counter
- each citizen updates their internal state
- money, happiness, job and housing are updated
- city statistics are recalculated

The **City** controls time and simulation flow.  
Each **Citizen** controls only their own life logic.

---

## 🧍 Citizen

Each citizen has:
- age
- money
- happiness (0–100)
- profession
- job status
- home status

Citizen logic includes:
- receiving salary (monthly)
- paying daily expenses
- buying a home if enough money
- happiness changes based on life conditions

All limits (money ≥ 0, happiness 0–100) are handled **inside the Citizen class**.

---

## 🏛️ City

The City class:
- stores a list of citizens
- controls the current day
- updates all citizens each day
- prints city statistics

City statistics:
- population
- employed citizens
- citizens with homes
- average happiness
- average money

The city prints a report every **30 days**.

---

## ⏱️ Simulation Model

- 1 tick = 1 day
- salary is paid every 30 days
- happiness changes weekly and monthly
- simulation speed can be adjusted

---

## 🛠️ Technologies

- Language: **C++**
- Standard Library (`vector`, `iostream`, etc.)
- Build system: **CMake**

---

## ▶️ How to Build and Run

```bash
mkdir build
cd build
cmake ..
make
./CityLife

## UML
main.cpp
   |
   v
 City
   |
   +--> citizens : vector<Citizen>
   |
   +--> events   : vector<Event>
   |
   +--> run(days)
          |
          +--> _update_tick()
          |      |
          |      +--> _process_event_for_day()
          |      +--> Citizen::update_tick(...)
          |
          +--> print_report()