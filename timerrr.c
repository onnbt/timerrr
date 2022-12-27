#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "asciiHandler.h"

void mainLoop(unsigned int secondsToWait)
{
    unsigned int secondsLeft = secondsToWait;
    system("clear");
    printPrintable(secondsLeft);
    for (;;)
    {
        if (secondsLeft == 0)
            break;
        sleep(1);
        secondsLeft--;
        system("clear");
        printPrintable(secondsLeft);
    }
}

int main(int argc, char *argv[])
{
    loadPrintables();
    mainLoop(99);
    return 0;
}
