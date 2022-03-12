#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height)
{
    lines = height;
    columns = width;
    matrix  = new char*[lines];
    for (int i = 0; i < lines; i++)
        matrix[i] = new char[columns];
}

void Canvas::DrawCircle(int x,int y, int ray, char ch)
{
    for (int i = x - ray; i <= x + ray; i++)
        for (int j = y - ray; j <= y + ray; j++)
            if (((i - x) * (i - x) + (j - y) * (j - y)) == ray * ray)
                matrix[i][j] = ch;
}
void Canvas::FillCircle(int x,int y,int ray, char ch)
{
    for (int i = x - ray; i < x + ray; i++)
        for (int j = y - ray; j < y + ray; j++)
            if (((i - x) * (i - x) + (j - y) * (j - y)) <= ray * ray)
                matrix[i][j] = ch;
}
void Canvas::DrawRect(int left,int top,int right,int bottom,char ch)
{
    for (int i = left+1; i < right; i++)
        matrix[top][i] = matrix[bottom][i] = ch;
    for (int i = top+1; i < bottom; i++)
        matrix[i][left] = matrix[i][right] = ch;
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; i++)
        for (int j = left; j <= right; j++)
            matrix[i][j] = ch;
}
void Canvas::SetPoint(int x,int y,char ch)
{
    matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    for (int x=x1;x<=x2;x++)
    {
        int y = (y2 - y1) * (x - x1) / (x2 - x1) + y1;
        matrix[x][y]=ch;
    }
}
void Canvas::Print()
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
            std::cout << matrix[i][j];
        std::cout << "\n";
    }
    std::cout << lines;
}
void Canvas::Clear()
{
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] =' ';
}