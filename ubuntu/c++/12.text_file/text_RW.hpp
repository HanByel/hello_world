#ifndef __TEXT_RW_HPP__
#define __TEXT_RW_HPP__

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define File_Path_Max   255
#define File_Name_Max   255


class text_RW{
public:
    typedef struct File_Profile{
        string File_Name[];
        string File_Path[];
        string File_Extension[];
        int32_t File_Authority = 0777;
    }MakeFileProfile;

private:
    static text_RW* mp_Instance;

public:
    text_RW();
    ~text_RW();
    static text_RW& getInstance();
    void text_write(MakeFileProfile _MFP);
    void text_read();




};

#endif //__TEXT_RW_HPP__
