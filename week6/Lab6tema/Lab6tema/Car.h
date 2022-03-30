#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Weather.h"
#include <iostream>
#include <cstring>
class Car
{
  protected:
    float fuelCapacity;
    float fuelConsumption;
    float averageSpeed;
    char *name;
  public:
    Car(){}
    ~Car(){}

    virtual float GetFuelCapacity() const= 0;
    virtual float GetFuelConsumption() const = 0;
    virtual float GetSpeed(Weather w = Weather::Sunny) const = 0;
    virtual char* GetName() const  = 0;
    virtual float GetTime(float lenght, Weather current_conditions) const = 0;
};