#pragma once
#include "Car.h"

class Toyota : public Car
{
  public:
    Toyota(){};
    ~Toyota(){};

    float getFuelCapacity() override;
    float getAverageSpeed() override;
    float getFuelConsumption() override;
};
