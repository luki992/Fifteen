#include "Kwadraty.hpp"
#include <iostream>
int Kwadraty::get_height()
{
    return height;
}
int Kwadraty::get_width()
{
    return width;
}
int Kwadraty::get_pos_x()
{
    return pos_x;
}
int Kwadraty::get_pos_y()
{
    return pos_y;
}
void Kwadraty::Rysuj(HDC hdc) // rysuje wzorczec
{

 wchar_t* tablica[]={L"1",L"2",L"3",L"4",L"5",L"6",L"7",L"8",L"9",L"10",L"11",L"12",L"13",L"14",L"15",NULL};
// duzy kwadrat
const int ile=4;
int WIDTH=ile*width;
SolidBrush b(Color(255,255,0));
Pen pen(Color(0,0,0),1);
int temp=pos_x;
Font font(L"Arial",15);
int temp_y=pos_y;
int value=-1;
Graphics g(hdc);
Rect rects(pos_x,pos_y,WIDTH,WIDTH);
g.FillRectangle(&b,pos_x,pos_y,WIDTH,WIDTH);
StringFormat format;
 format.SetAlignment(StringAlignmentCenter);
   SolidBrush blackBrush(Color(255, 0, 0, 0));
 wchar_t* wsk;
g.DrawRectangle(&pen,rects);
for(int i=0; i < ile; i ++)
{
    for(int j=0; j< ile; j ++)
    {
        rect[i][j]=RectF(temp,temp_y,width,height);
    temp+=width;
    }
    temp=pos_x;
    temp_y+=height;
}

for(int i=0; i < ile; i ++)
{
    for(int j=0; j < ile; j ++) {
      value=value +1;
      wsk=tablica[value];

        g.DrawString(wsk,-1,&font,rect[i][j],&format,&blackBrush);
        g.DrawRectangle(&pen,rect[i][j]);
    }
}



}

void Kwadraty :: Fill_Rectangle(HDC hdc, int x,int y)
{
    const int ile=4;

      for(int i=0; i < ile; i ++)
  {
      for(int j=0; j < ile; j ++)
      {
          if(rect[i][j].Contains(x,y)) {
           X=i;
           Y=j;
          }

      }
  }

    Graphics g(hdc);
    SolidBrush Brush(Color(255,255,0));
   // g.FillRectangle(&Brush,rect[X][Y]);
  Pen pen(Color(0,0,0),1);
  for(int i=0; i < ile; i ++)
  {
      for(int j=0; j < ile; j ++)
      {
          g.DrawRectangle(&pen,rect[i][j]);
      }
  }
}
void Kwadraty :: Fill_Rectangle(HDC hdc, int x,int y,bool zamaluj)
{
    const int ile=4;


    Graphics g(hdc);
    SolidBrush Brush(Color(255,255,0));
   if(zamaluj == true) g.FillRectangle(&Brush,rect[x][y]);
  Pen pen(Color(0,0,0),1);
  for(int i=0; i < ile; i ++)
  {
      for(int j=0; j < ile; j ++)
      {
          g.DrawRectangle(&pen,rect[i][j]);
      }
  }
}

void Kwadraty :: Rysuj(HDC hdc, vector<string>element) {
const int ile=4;
int WIDTH=ile*width;
SolidBrush b(Color(255,255,0));
Pen pen(Color(0,0,0),1);
int temp=pos_x;
Font font(L"Arial",15);
int temp_y=pos_y;
int value=0;
Graphics g(hdc);
Rect rects(pos_x,pos_y,WIDTH,WIDTH);
g.FillRectangle(&b,pos_x,pos_y,WIDTH,WIDTH);

StringFormat format;
SetBkColor(hdc,RGB(255,255,0));

 format.SetAlignment(StringAlignmentCenter);
   SolidBrush blackBrush(Color(255, 0, 0, 0));
RECT obszar;
g.DrawRectangle(&pen,rects);
for(int i=0; i < ile; i ++)
{
    for(int j=0; j< ile; j ++)
    {
        rect[i][j]=RectF(temp,temp_y,width,height);
    temp+=width;
    }
    temp=pos_x;
    temp_y+=height;
}
for(int i=0; i < ile; i ++)
{
    for(int j=0; j < ile; j ++) {
        if(wylosowane.x == i && wylosowane.y == j)
        {
            continue;
        }
         else
         {
        obszar.bottom=rect[i][j].GetBottom();
        obszar.left=rect[i][j].GetLeft();
        obszar.top=rect[i][j].GetTop();
        obszar.right=rect[i][j].GetRight();
        DrawText(hdc,element[value].c_str(),2,&obszar,DT_CENTER);
        g.DrawRectangle(&pen,rect[i][j]);
        value=value + 1;
        }
    }
}


}

void Kwadraty :: Draw_String(HDC hdc)
{
Graphics g(hdc);
Font font(L"Arial",15);
Pen pen(Color(0,0,0),1);
StringFormat format;
format.SetAlignment(StringAlignmentCenter);
SolidBrush blackBrush(Color(255, 0, 0, 0));
g.DrawString(L"12",-1,&font,rect[X+1][Y],&format,&blackBrush);
g.DrawRectangle(&pen,rect[X][Y]);
}
void Kwadraty :: Draw_String(HDC hdc,zamiana zam)
{
RECT dst;
Graphics g(hdc);
Pen pen(Color(0,0,0),1);
dst.bottom=rect[zam.docelowa.x][zam.docelowa.y].GetBottom();
dst.left=rect[zam.docelowa.x][zam.docelowa.y].GetLeft();
dst.right=rect[zam.docelowa.x][zam.docelowa.y].GetRight();
dst.top=rect[zam.docelowa.x][zam.docelowa.y].GetTop();
char buffer[16];
sprintf(buffer,"%d",zam.zrodlo.liczba);
SetBkColor(hdc,RGB(255,255,0));
DrawText(hdc,buffer,2,&dst,DT_CENTER);
g.DrawRectangle(&pen,rect[zam.docelowa.x][zam.docelowa.y]);
}

void Kwadraty :: wylosowane_kwadrat(pomocnicza p)
{
wylosowane.x=p.x;
wylosowane.y=p.y;
}
 pomocnicza Kwadraty :: click()
{
pomocnicza p;
p.x=X;
p.y=Y;
return p;
}
// to do logika


