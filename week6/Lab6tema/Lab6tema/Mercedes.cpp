#include "Mercedes.h"

Mercedes::Mercedes()
{
    fuelCapacity    = 30;
    fuelConsumption = 5;
    averageSpeed    = 70;
    char masina[]   = "Mercedes";
    name            = new char[strlen(masina) + 1];
    strcpy(name, masina);
    name[strlen(masina)] = '\0';
}
Mercedes::~Mercedes()
{
    delete name;
}

float Mercedes::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

float Mercedes::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

float Mercedes::GetSpeed(Weather conditions) const
{
    if (conditions == Snow)
        return this->averageSpeed - 10;
    if (conditions == Sunny)
        return this->averageSpeed + 10;
    return this->averageSpeed;
}

char* Mercedes::GetName() const
{
    return this->name;
}

float Mercedes::GetTime(float length, Weather current_conditions) const
{
    return length / GetSpeed(current_conditions);
}
