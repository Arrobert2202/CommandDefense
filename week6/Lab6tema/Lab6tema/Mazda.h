#pragma once
#include "Car.h"

class Mazda : public Car
{
  public:
    Mazda(){};
    ~Mazda(){};

    float getFuelCapacity() override;
    float getAverageSpeed() override;
    float getFuelConsumption() override;
};

