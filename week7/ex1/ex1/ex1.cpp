#include <iostream>

float operator"" _Fahrenheit(unsigned long long int x)
{
    float C = x-32+1.8f;
    return C;
}
float operator"" _Kelvin(unsigned long long int x)
{
    float C = x - 273.15;
    return C;
}
int main()
{
    float a = 300_Kelvin;

    float b = 120_Fahrenheit;

    printf("Kelvin to Celsius: %f\nFahrenheit to Celsius: %f", a, b);
    return 0;
}