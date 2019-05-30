#include "File_RW.hpp"

int main(){
    File_RW::File_Profile *MFP1 = new File_RW::File_Profile;
    MFP1->File_Authority = 0777;
    MFP1->File_Extension = ".txt";
    MFP1->File_Name = "test222";
    MFP1->File_Path = "/srv/extHd/projects/test/hello_world/ubuntu/c++/12.File_RW/aaaa";
    File_RW::getInstance().File_Write(*MFP1);
    delete MFP1;

    File_RW::File_Profile *MFP2 = new File_RW::File_Profile;
    MFP2->File_Name = "test222";
    MFP2->File_Path = "/srv/extHd/projects/test/hello_world/ubuntu/c++/12.File_RW/aaaa";
    MFP2->File_Extension = ".txt";
    File_RW::getInstance().Dir_List(*MFP2);
    File_RW::getInstance().File_Read(*MFP2);
    delete MFP2;

    File_RW::File_Profile *MFP3 = new File_RW::File_Profile;
    MFP3->File_Name = "es";
    MFP3->File_Path = "/srv/extHd/projects/test/hello_world/ubuntu/c++/12.File_RW/aaaa";
    File_RW::getInstance().Dir_Find_File(*MFP3);
    delete MFP3;

    return 0;
}
