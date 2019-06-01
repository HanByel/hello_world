#include "text_RW.hpp"

text_RW* text_RW::mp_Instance = NULL;


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

void text_RW::text_write(){
	FILE * wf;

    unsigned int lWriten;
	wf = ofstream("asdf.txt");

    char buf2[] = "Write Example\n\n\nlinefeed";
	fwrite(
    lWriten = fwrite(wf, buf2, sizeof(buf2)-1);
}

void text_RW::text_read(){
    FILE * rf;

    //Open File and Get File Descripter//
    rf = fopen("bb.txt" , "w+");

    if (rf == NULL)       printf ("test_read fail\n");
    else                printf("test_read success\n");

    int lRead;
    char buff[1024]={0,};

    lRead = fread(buff, 1024, NUM_ALPHA, rf);

    printf ("text_read lRead : %d\n", lRead);
    printf ("text_read text : %s\n", buff);

    fclose(rf);
}
