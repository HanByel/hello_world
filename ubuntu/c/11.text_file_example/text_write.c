#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void text_write();
void text_read();


void main() {
    text_write();
    text_read();
}

void text_write(){
    int wf;
    int lWriten;

    wf = creat("bb.txt", 0777);

    if (wf == -1)        printf ("text_write fail\n");
    else                printf("text_write success");
    char buf2[] = "Write Example\n\n\nlinefeed";

    lWriten = write(wf, buf2, sizeof(buf2)-1);

}

void text_read(){
    int rf;

    //Open File and Get File Descripter//
    rf = open ("bb.txt" , O_RDWR);

    if (rf == -1)       printf ("test_read fail\n");
    else                printf("test_read success\n");

    int lRead;
    char buff[1024]={0,};

    lRead = read(rf, buff, 1024);

    printf ("text_read lRead : %d\n", lRead);
    printf ("text_read text : %s\n", buff);

    close(rf);
}


//# define SEEK_SET	0	/* Seek from beginning of file.  */
//# define SEEK_CUR	1	/* Seek from current position.  */
//# define SEEK_END	2	/* Seek from end of file.  */
//  lseek(wf, 0, SEEK_SET);
//  lseek (int __fd, __off_t __offset, int __whence)
