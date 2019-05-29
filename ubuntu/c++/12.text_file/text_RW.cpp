#include "text_RW.hpp"

text_RW* text_RW::mp_Instance = nullptr;


text_RW::text_RW(){

}

text_RW::~text_RW(){

}

text_RW& text_RW::getInstance() {
    if (mp_Instance == NULL) {
        mp_Instance = new text_RW();
    }
    return *mp_Instance;
}

void text_RW::text_write(MakeFileProfile _MFP){
    int wf;
    int lWriten;
    char *pFN = new char[strlen(_MFP.File_Name)+1];
    char *pFE = new char[strlen(_MFP.File_Extension)+1];

    strcat(_MFP.File_Name,_MFP.File_Extension);
    wf = creat(_MFP.File_Name, 0777);

    if (wf == -1)        printf ("text_write fail\n");
    else                printf("text_write success");
    char buf2[] = "Write Example\n\n\nlinefeed";

    lWriten = write(wf, buf2, sizeof(buf2)-1);

}

void text_RW::text_read(){
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
