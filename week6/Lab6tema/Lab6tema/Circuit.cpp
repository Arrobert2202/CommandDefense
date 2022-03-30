#include "Circuit.h"

Circuit::Circuit()
{
    max_count = 10;
    count     = 0;
    length    = 0;
    this->weather   = Unspecified;
    for (int i = 0; i < max_count; i++)
        time[i] = -1;
}
void Circuit::SetLength(float new_lenght)
{
    this->length = new_lenght;
}
void Circuit::SetWeather(Weather new_weather)
{
    this->weather = new_weather;
}
bool Circuit::AddCar(Car* car)
{
    if (count < max_count)
    {
        cars[count++] = car;
        return true;
    }
    return false;
}
void Circuit::Race()
{
    for (int i = 0; i < count; i++)
        time[i] = cars[i]->GetTime(length, weather);
}
void Circuit::ShowFinalRanks()
{
    float firsttime=100,secondtime=100,thirdtime=100;
    int first = -1, second = -1, third = -1;
    for (int i=0;i<count;i++)
    {
        if (time[i]<=firsttime)
        {
            thirdtime = secondtime;
            secondtime = firsttime;
            firsttime = time[i];
            third     = second;
            second    = first;
            first     = i;
        }
        else if (time[i]<= secondtime)
        {
            thirdtime  = secondtime;
            secondtime = time[i];
            third      = second;
            second     = i;
        }
        else if (time[i] < thirdtime)
        {
            thirdtime  = time[i];
            third     = i;
        }
    }
    printf(
          "First: %s\n, Second: %s\n, Third: %s\n",
          cars[first]->GetName(),
          cars[second]->GetName(),
          cars[third]->GetName());
}
void Circuit::ShowWhoDidNotFinished()
{
    printf("Not finished:");
    for (int i = 0; i < count; i++)
        if (time[i] == -1)
            printf("%s ,", cars[i]->GetName());
}