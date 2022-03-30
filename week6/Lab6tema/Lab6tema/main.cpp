#include"Car.h"
#include"Circuit.h"
#include"Dacia.h"
#include"Mercedes.h"
#include"Ford.h"
#include <iostream>

int main()

{
    Circuit c;

    c.SetLength(100);

    c.SetWeather(Weather::Rain);

    c.AddCar(new Dacia());

    c.AddCar(new Mercedes());

    c.AddCar(new Ford());

    c.Race();

    c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to
                        // the   slowest.

    c.ShowWhoDidNotFinished(); // it is possible that some cars don't have enough fuel to finish the circuit

    return 0;
}