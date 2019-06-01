#if !defined(__TEXT_RW_HPP__)
#define __TEXT_RW_HPP__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define File_Path_Max   255
#define File_Name_Max   255
#define NUM_ALPHA  26


class text_RW{
private:
    static text_RW* mp_Instance;

public:
    text_RW();
    ~text_RW();
    static text_RW& getInstance();
    void text_write();
    void text_read();

};

#endif //__TEXT_RW_HPP__
