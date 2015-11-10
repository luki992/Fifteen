#include <windows.h>
#include <gdiplus.h>
#include <windowsx.h>
#include "Logic.hpp"
#include "Kwadraty.hpp"
#include "pomoc.hpp"
#include "resour.hpp"
using namespace Gdiplus;
/*
Author : Lukasz Laska
 The licenses for most software are designed to take away your freedom to share and change it. By contrast, the GNU General Public License is intended to guarantee your freedom to share and change free software--to make sure the software is free for all its users. This General Public License applies to most of the Free Software Foundation's software and to any other program whose authors commit to using it. (Some other Free Software Foundation software is covered by the GNU Lesser General Public License instead.) You can apply it to your programs, too.

When we speak of free software, we are referring to freedom, not price. Our General Public Licenses are designed to make sure that you have the freedom to distribute copies of free software (and charge for this service if you wish), that you receive source code or can get it if you want it, that you can change the software or use pieces of it in new free programs; and that you know you can do these things.

To protect your rights, we need to make restrictions that forbid anyone to deny you these rights or to ask you to surrender the rights. These restrictions translate to certain responsibilities for you if you distribute copies of the software, or if you modify it.

For example, if you distribute copies of such a program, whether gratis or for a fee, you must give the recipients all the rights that you have. You must make sure that they, too, receive or can get the source code. And you must show them these terms so they know their rights.

We protect your rights with two steps: (1) copyright the software, and (2) offer you this license which gives you legal permission to copy, distribute and/or modify the software.

Also, for each author's protection and ours, we want to make certain that everyone understands that there is no warranty for this free software. If the software is modified by someone else and passed on, we want its recipients to know that what they have is not the original, so that any problems introduced by others will not reflect on the original authors' reputations.

Finally, any free program is threatened constantly by software patents. We wish to avoid the danger that redistributors of a free program will individually obtain patent licenses, in effect making the program proprietary. To prevent this, we have made it clear that any patent must be licensed for everyone's free use or not licensed at all.

The precise terms and conditions for copying, distribution and modification follow. */


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "CodeBlocksWindowsApp";
GdiplusStartupInput input;
ULONG_PTR ptr;
PAINTSTRUCT ps;
HDC hdc;
Kwadraty kwadraty; // widok 1
Kwadraty square(300,20); // widok 2
Logic logiczne; // model

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    bool zmienna=false;
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS ;              /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    GdiplusStartup(&ptr,&input,NULL);
    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;
    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Pietnastka",       /* Title Text */
            WS_OVERLAPPEDWINDOW  , /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           LoadMenu(hThisInstance,MAKEINTRESOURCE(MEN)),                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);
      logiczne.losuj();
   logiczne.losuj_elementy();

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while(!zmienna) {
    if (PeekMessage (&messages, NULL, 0, 0,PM_REMOVE))
    {
       if(messages.message == WM_QUIT) {
            zmienna=true;
       }
       else if(messages.message == WM_PAINT) {
        hdc=GetDC(hwnd);
        BeginPaint(hwnd,&ps);
        kwadraty.Rysuj(hdc);
        square.wylosowane_kwadrat(logiczne.get_wylosowane());
        square.Rysuj(hdc,logiczne.tablica_elementow());

        SolidBrush bru(Color(0,0,0));
        EndPaint(hwnd,&ps);

        ReleaseDC(hwnd,hdc);

       }
       else {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
       }


    }


    }
    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {


        case WM_LBUTTONUP:
    {
    hdc=GetDC(hwnd);
        int X=GET_X_LPARAM(lParam);
int Y=GET_Y_LPARAM(lParam);
pomocnicza punkt;
zamiana res;

 square.Fill_Rectangle(hdc,X,Y);
 punkt=square.click();
 bool zmienna=logiczne.get_(punkt,res);
if(zmienna == true) {
        square.Fill_Rectangle(hdc,res.zrodlo.x,res.zrodlo.y,true);
        logiczne.zamien(res);
        square.Draw_String(hdc,res);
}
    ReleaseDC(hwnd,hdc);
    }
        break;
        case WM_PAINT:
        {
        hdc=GetDC(hwnd);
        BeginPaint(hwnd,&ps);
        kwadraty.Rysuj(hdc);
        square.wylosowane_kwadrat(logiczne.get_wylosowane());
        square.Rysuj(hdc,logiczne.tablica_elementow());

        SolidBrush bru(Color(0,0,0));
        EndPaint(hwnd,&ps);

        ReleaseDC(hwnd,hdc);
        }
        break;

        case WM_DESTROY:
            PostQuitMessage (0);
            GdiplusShutdown(ptr);
            kwadraty.~Kwadraty();
        /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
