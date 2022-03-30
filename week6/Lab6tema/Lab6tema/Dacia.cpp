#include "Dacia.h"

Dacia::Dacia()
{
    fuelCapacity = 20;
    fuelConsumption = 5;
    averageSpeed    = 40;
    char masina[]   = "Dacia";
    name            = new char[strlen(masina) + 1];
    strcpy(name, masina);
    name[strlen(masina)] = '\0';
}
Dacia::~Dacia()
{
    delete name;
}

float Dacia::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

float Dacia::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

float Dacia::GetSpeed(Weather conditions) const
{
    if (conditions == Snow)
        return this->averageSpeed - 10;
    if (conditions == Sunny)
        return this->averageSpeed + 10;
    return this->averageSpeed;
}

char* Dacia::GetName() const
{
    return this->name;
}

float Dacia::GetTime(float length, Weather current_conditions) const
{
    return length / GetSpeed(current_conditions);
}


