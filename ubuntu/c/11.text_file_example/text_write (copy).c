#include "text_write.h"

int main (int argc, char ** argv) {
    int fd;
    fd = creat("bb.txt", 777);
    if (fd == -1)
            printf ("Creat function failed\n");
    return 0;
}
