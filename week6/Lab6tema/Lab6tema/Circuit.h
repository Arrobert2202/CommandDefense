#pragma once
#include "Car.h"

class Circuit
{
    Car* cars[10];
    float length;
    Weather weather;
    int count,max_count;
    float time[10];
    public:
    Circuit();
    ~Circuit(){};

    void SetLength(float new_length);
    void SetWeather(Weather new_weather);
    bool AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinished();
};