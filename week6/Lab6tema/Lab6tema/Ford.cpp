#include "Ford.h"

Ford::Ford()
{
    fuelCapacity    = 20;
    fuelConsumption = 7;
    averageSpeed    = 50;
    char masina[]   = "Ford";
    name            = new char[strlen(masina) + 1];
    strcpy(name, masina);
    name[strlen(masina)] = '\0';
}
Ford::~Ford()
{
    delete name;
}

float Ford::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

float Ford::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

float Ford::GetSpeed(Weather conditions) const
{
    if (conditions == Snow)
        return this->averageSpeed - 10;
    if (conditions == Sunny)
        return this->averageSpeed + 10;
    return this->averageSpeed;
}

char* Ford::GetName() const
{
    return this->name;
}

float Ford::GetTime(float length, Weather current_conditions) const
{
    return length / GetSpeed(current_conditions);
}
