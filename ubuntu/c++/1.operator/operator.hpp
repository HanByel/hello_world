#ifndef TERMINALCLEAR_HPP
#define TERMINALCLEAR_HPP

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

class ControlIO {
private:
    static ControlIO* mp_Instance;

public:
    ControlIO();
    ~ControlIO();
    static ControlIO &getinstance();

    int getch();

};

#endif // TERMINALCLEAR
