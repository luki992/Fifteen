#include "Logic.hpp"
#include <iostream>
void Logic::losuj() // bedzie luka
{
srand(time(NULL));
x=rand()%4;
y=rand()%4;
}
void Logic::losuj_elementy()
{
 srand(time(NULL));

 for(int i=1; i <=15; i ++) n.push_back(i);
  tablica[x][y]=-1;
 random_shuffle(n.begin(),n.end());
 int p=0;
  for(int i=0; i < ile; i ++)
  {
      for(int j=0; j < ile; j ++) {

        if(i == x &&  j == y ) {
            continue;
        }
        else {
            tablica[i][j]=n[p];
            p ++;

        }

      }
  }
  /*for(int i=0; i < ile; i ++)
  {
      for(int j=0; j < ile; j ++) {

       std:: cout << tablica[i][j] <<" ";
      }
    std:: cout <<"\n";
  } */



}
vector<string> Logic :: tablica_elementow()
{
vector<string>elements;
char buffer[16];
const int ile=4;
for(int i=0; i < n.size(); i ++) {
    sprintf(buffer,"%d",n[i]);
    elements.push_back(buffer);

}

return elements;
}
pomocnicza Logic:: get_wylosowane()
{
pomocnicza pt;
pt.x=x;
pt.y=y;
return pt;

}
bool Logic :: get_(pomocnicza p,zamiana & res)
{
    bool zmienna=false;
if(p.x == 0 && p.y == 0) // sprawdzanie rogow
{
if(tablica[p.x][p.y + 1]  == -1) {
    zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y+1;
   res.docelowa.liczba=tablica[p.x][p.y+1];
}
else if(tablica[p.x+1][p.y]  == -1)
{
     zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x+1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x+1][p.y];

}
else
{
    zmienna=false;
}

}
else if(p.x == 0 && p.y == 3) // z prawej strony
{
if(tablica[p.x][p.y-1]  ==  -1)
{
        zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y-1;
   res.docelowa.liczba=tablica[p.x][p.y-1];
}
else if(tablica[p.x+1][p.y] == - 1)
{
    zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x+1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x+1][p.y];
}
else
{
    zmienna=false;
}

}
else if(p.x == 3 && p.y == 0)
{
if(tablica[p.x-1][p.y] == - 1)
{
        zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x-1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x-1][p.y];
}
else if(tablica[p.x][p.y+1] == - 1)
{

    zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y+1;
   res.docelowa.liczba=tablica[p.x][p.y+1];

}
else
{
zmienna=false;
}

}
else if(p.x == 3 && p.y == 3)
{
if(tablica[p.x-1][p.y] == - 1)
{

zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x-1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x-1][p.y];

}
else if(tablica[p.x][p.y - 1] == - 1)
{
zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y-1;
   res.docelowa.liczba=tablica[p.x][p.y-1];
}
else zmienna=false;

}
else if(p.y == 0 && (p.x >=1 || p.x <= 2))
{
if(tablica[p.x+1][p.y] == - 1)
{
        zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x+1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x+1][p.y];
}
else if(tablica[p.x][p.y+1] == - 1)
{
            zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y+1;
   res.docelowa.liczba=tablica[p.x][p.y+1];


}
else if(tablica[p.x-1][p.y] == - 1)
{
        zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x-1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x-1][p.y];


}
else  zmienna=false;

}
else if(p.y == 3 && (p.x >=1 || p.x <=2))
{
if(tablica[p.x+1][p.y]== -1)
{
        zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x+1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x+1][p.y];

}
else if(tablica[p.x - 1][p.y] == -1) {
        zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x-1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x-1][p.y];


}
else if(tablica[p.x][p.y-1] == -1)
{
       zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y-1;
   res.docelowa.liczba=tablica[p.x][p.y-1];
}
else zmienna=false;


}
else if(p.x == 0 && (p.y >=1 || p.y <=2))
{
  if(tablica[p.x][p.y-1]  == - 1)
  {
       zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y-1;
   res.docelowa.liczba=tablica[p.x][p.y-1];
  }
  else if(tablica[p.x][p.y+1] == -1)
  {
       zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y+1;
   res.docelowa.liczba=tablica[p.x][p.y+1];
  }
  else if(tablica[p.x+1][p.y] == -1)
  {
       zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x+1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x+1][p.y];
  }
  else zmienna=false;
}
else if(p.x == 3 && (p.y >=1 || p.y <=2))
{
 if(tablica[p.x][p.y+1] == - 1)
 {
       zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y+1;
   res.docelowa.liczba=tablica[p.x][p.y+1];
 }
 else if(tablica[p.x][p.y-1] == -1)
 {
        zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y-1;
   res.docelowa.liczba=tablica[p.x][p.y-1];
 }
 else if(tablica[p.x-1][p.y] == -1 )
 {
        zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x-1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x-1][p.y];
 }
 else zmienna=false;

}
else
{
if(tablica[p.x+1][p.y] == - 1)
{
       zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x+1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x+1][p.y];
}
else if(tablica[p.x-1][p.y] == -1)
{
       zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x-1;
   res.docelowa.y=p.y;
   res.docelowa.liczba=tablica[p.x-1][p.y];
}
else if(tablica[p.x][p.y+1] == -1)
{
       zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y+1;
   res.docelowa.liczba=tablica[p.x][p.y+1];
}
else if(tablica[p.x][p.y-1] == -1)
{
   zmienna=true;
   res.zrodlo.x=p.x;
   res.zrodlo.y=p.y;
   res.zrodlo.liczba=tablica[p.x][p.y];

   res.docelowa.x=p.x;
   res.docelowa.y=p.y-1;
   res.docelowa.liczba=tablica[p.x][p.y-1];
}
else zmienna=false;


}

return zmienna;
}
void Logic :: zamien(zamiana &s)
{
swap(tablica[s.zrodlo.x][s.zrodlo.y],tablica[s.docelowa.x][s.docelowa.y]);
for(int i=0; i < ile; i ++ )
{
    for(int j=0; j < ile; j++)
    {
        cout << tablica[i][j]<<"  ";
    }
    cout <<"\n";
}

cout <<"\n\n";
}

