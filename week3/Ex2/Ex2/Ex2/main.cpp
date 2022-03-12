#include <iostream>
#include "Canvas.h"

int main()
{
    Canvas canvas(30, 30);
    canvas.Clear();

    //  Circle Example
    /* canvas.DrawCircle(10, 10, 7, '*');
     canvas.FillCircle(10, 10, 7, '*');
     canvas.Print();
    */

    // Reactangle Example
    /* canvas.DrawRect(5, 7, 20, 15, '+');
    canvas.FillRect(5, 7, 20, 15, '+');
    canvas.Print();
    */

    // Line and Point example
    /* canvas.DrawLine(5, 4, 15, 14, '-');
    canvas.SetPoint(1, 1, '*');
    canvas.Print();
    */

    return 0;
}