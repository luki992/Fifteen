#ifndef KWADRATY_HPP_INCLUDED
#define KWADRATY_HPP_INCLUDED
#include <iostream>
#include <gdiplus.h>
#include <windows.h>
#include <vector>
#include <stdio.h>
#include "pomoc.hpp"
using namespace Gdiplus;
using  namespace std;
class Kwadraty
{
 private:
     RectF rect[4][4];
     int height;
     int width;
      int pos_x;
      int pos_y;
      int X;  // klikniety;
      int Y;
      pomocnicza wylosowane;

 public :
    Kwadraty(): height(50), width(50), pos_x(20), pos_y(20){}

    Kwadraty(int position_x,int position_y): pos_x(position_x), pos_y(position_y), height(50), width(50) {}
    ~Kwadraty() {
    }


// hermatyzacja -- same gety bez setow
 int get_height();
 int get_width();
 int get_pos_x();
 int get_pos_y();
 void Rysuj(HDC);
 void Rysuj(HDC,vector<string>);
 void Fill_Rectangle(HDC, int x,int y); // odpowiada za odmalowanie kwadrata
 void Fill_Rectangle(HDC,int x,int y,bool zamaluj);
 void Draw_String(HDC); // odpowiada za odrysowanie liczby
 void Draw_String(HDC,zamiana);
 void wylosowane_kwadrat(pomocnicza );
 pomocnicza click();
};



#endif // KWADRATY_HPP_INCLUDED
