#include "text_RW.hpp"

int main(){
    text_RW *ptext_RW = new text_RW();
/*    text_RW::File_Profile MFP;
    MFP.File_Authority = 0777;
    MFP.File_Extension = ".txt";
    MFP.File_Name = "test";*/
//    ptext_RW->text_write(MFP);
    ptext_RW->text_write();
    ptext_RW->text_read();
    return 0;
}
