#include "File_RW.hpp"

#define S_FILE_LAST_WORD(x) x[strlen(x.c_str())-1]
#define S_SPLIT_SIZE_B     1 // 1KB
#define S_SPLIT_SIZE_KB    1024 // 1KB
#define S_SPLIT_SIZE_MB    1024 * 1000 // 1000KB
#define S_SPLIT_SIZE_GB    1024 * 1000 * 1000// 1000KB

File_RW* File_RW::mp_Instance = nullptr;

File_RW::File_RW(){
    printf ("File_RW()::File_RW()\n");

}

File_RW::~File_RW(){
    printf ("File_RW()::~File_RW()\n");

}

File_RW& File_RW::getInstance() {
    if (mp_Instance == NULL) {
        mp_Instance = new File_RW();
    }
    return *mp_Instance;
}

void File_RW::File_Write(MakeFileProfile _MFP){
    printf ("File_Write\n");
    int wf;

    if(_MFP.File_Path != "")
        _MFP.File_Name=_MFP.File_Path+"/"+_MFP.File_Name+_MFP.File_Extension;
    else if(S_FILE_LAST_WORD(_MFP.File_Path) == '/')
        _MFP.File_Name=_MFP.File_Path+_MFP.File_Name+_MFP.File_Extension;
    else
        _MFP.File_Name=_MFP.File_Name+_MFP.File_Extension;

    wf = creat(_MFP.File_Name.c_str(), _MFP.File_Authority);
    printf ("File_Write wf : %d\n", wf);

    char buf2[] = "Write asddddddddddddddddddddddddddddddddddfasfdExample\n\n\nlinefeed";
     write(wf, buf2, sizeof(buf2)-1);

}

void File_RW::File_Read(MakeFileProfile _MFP){
    printf ("File_Read\n");
    int rf;
    int lSplitSize=S_SPLIT_SIZE_MB;
    long int lFileSize = 0;
    int lCurrentPoint = 0;

    if(_MFP.File_Path != "")
        _MFP.File_Name=_MFP.File_Path+"/"+_MFP.File_Name+_MFP.File_Extension;
    else if(S_FILE_LAST_WORD(_MFP.File_Path) == '/')
        _MFP.File_Name=_MFP.File_Path+_MFP.File_Name+_MFP.File_Extension;
    else
        _MFP.File_Name=_MFP.File_Name+_MFP.File_Extension;

    rf = open (_MFP.File_Name.c_str(), O_RDWR);

    lFileSize = lseek(rf, 0, SEEK_END); //start line
    char *buff = (char*)malloc(sizeof(char)*lFileSize);
    lseek(rf, 0, SEEK_SET); //start line
    printf ("File_read lFileSize : %ld\n", lFileSize);

    while(1){
        lCurrentPoint = read(rf, buff, lSplitSize);

        printf ("File_read lCurrentPoint : %d\n", lCurrentPoint);
//        printf ("File_read File : %s\n", buff);
        if(lCurrentPoint < lSplitSize)
            break;
    }
    close(rf);
}

void File_RW::Dir_List(MakeFileProfile _MFP){
    printf ("Dir_List \n");

    printf ("\n%s \n", _MFP.File_Path.c_str());
    dirent *lFileProfile;

    DIR *dir = opendir(_MFP.File_Path.c_str());

    if (dir == NULL){
        printf ("\n No Directory Path \n");
        return;
    }

    while ((lFileProfile = readdir(dir)) != NULL) {
        printf("%s\n\n",lFileProfile->d_name);
    }
    closedir(dir);
}

void File_RW::Dir_Find_File(MakeFileProfile _MFP){
    printf ("Dir_Find_File \n");

    printf ("\n%s \n", _MFP.File_Path.c_str());
    dirent *lFileProfile;
    DIR *dir = opendir(_MFP.File_Path.c_str());

    if (dir == NULL){
        printf ("\n No Directory Path \n");
        return;
    }

    while ((lFileProfile = readdir(dir)) != NULL) {
        if(strstr(lFileProfile->d_name,_MFP.File_Name.c_str()) != NULL)
            printf("%s\n\n",lFileProfile->d_name);
    }
    closedir(dir);
}


//lseek(rf, 0, SEEK_SET); //start line
//lseek(rf, 15, SEEK_CUR); //current position
//lseek(rf, 0, SEEK_END); //end line

//# define SEEK_SET	0	/* Seek from beginning of file.  */
//# define SEEK_CUR	1	/* Seek from current position.  */
//# define SEEK_END	2	/* Seek from end of file.  */
//  lseek(wf, 0, SEEK_SET);
//  lseek (int __fd, __off_t __offset, int __whence)
