#ifndef __File_RW_HPP__
#define __File_RW_HPP__

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>


using namespace std;

class File_RW{
public:
    typedef struct File_Profile{
        string File_Name = "Byel";
        string File_Path;
        string File_Extension = ".txt";
        int32_t File_Authority = 00700;
    }MakeFileProfile;

private:
    static File_RW* mp_Instance;

public:
    File_RW();
    ~File_RW();
    static File_RW& getInstance();
    void File_Write(MakeFileProfile _MFP);
    void File_Read(MakeFileProfile _MFP);
    static void Dir_List(MakeFileProfile _MFP);
    void Dir_Find_File(MakeFileProfile _MFP);

};

#endif //__File_RW_HPP__


/*

flag
파일을 어떤 목적으로 open할 것이며, open시 파일의 초기화할 지 여부등을 지정합니다.
fag값은 O_RDONLY, O_WRONLY, ORDWR 중에서 하나는 반드시 설정되어야 합니다.

O_RDONLY : 파일을 읽기 전용으로 open합니다.
O_WRONLY : 파일을 쓰기 전용으로 open합니다.
O_RDWR : 파일을 읽고 쓰기를 모두 할 수 있도록 open합니다.

아래의 상수들은 추가적으로 bit or 연산으로 여러개 설정할 수 있습니다.
O_APPEND : 파일을 append mode로 open합니다. write(2)함수를 통하여 파일쓰기를 수행하면,
   파일 쓰기 위치에 관계없이 자동으로 파일의 끝에 쓰기를 합니다. 즉, 파일의 중간에 쓰기를 할 수 없게 합니다.
   만약 여러개의 프로세스가 동시에 하나의 파일을 O_APPEND로 열었다면, 이 프로세스간에도 중복쓰기를
   하지 않고 오로지 파일의 끝에만 write하게 됩니다.

O_ASYNC : 이 옵션은 파일이 읽거나 쓰기를 할 수 있는 상태가 되면, SIGIO signal을 발생시킵니다.
   signal-driven I/O를 할 수 있게 하며, terminal, socket, pipe, FIFO 등에서만 사용가능합니다.
   파일을 open시에 설정하지 않더라도 fcntl(2)를 통하여 flag를 추가할 수도 있습니다.

O_CLOEXEC : (LINUX only)
   fork(2) + exec계열함수 호출시 자동으로 이 파일을 close합니다. 즉, fork(2)후에 exec계열함수를
   호출하기 직전에 close(2)하는 것과 같습니다.
   이 옵션이 설정되어 있지 않으면 execve에 의하여 process의 내용이 완전히 다른 바이너리로 교체되어도
   파일은 close되지 않습니다. 이 옵션을 설정하지 않아도 fork() + exec 계열함수를 호출하면
   당연히 open된 close되어야 되는 것 아니야? 라고 생각할 수도 있습니다만,
   자동으로 파일을 close하지 않기 때문에 자식 프로세스는 file descriptor 0(표준입력), 1(표준출력), 2(표준오류)을
   open하지 않아도 open된 채로 사용할 수 있는 장점이 있습니다.

O_CREAT : 이 옵션은 파일이 존재하지 않으면 파일을 새로 만들어라는 설정입니다.
   이 option이 설정되면 mode를 입력받는 open(const char *pathname, int flags, mode_t mode);를 호출해야 합니다.

O_DIRECT : (Linux only) I/O시 kernel buffer에 caching하지 않고 바로 disk에 read/write하라는 설정입니다.
   이 option이 설정되면 성능이 많이 떨어질 수 있습니다.
   이 옵션이 설정되지 않으면, 프로그램에서 write(2)를 하면 kernel이 데이터를 받아서 바로 정상 return하고 disk write는 kernel이 여유가 있거나 kernel buffer 최대 지연 시간이 도래하게되면 disk에 write합니다.
   그러나 파일의 meta 정보(최종파일 access 시간 등)는 동기화를 바로 하지 않습니다.

O_DIRECTORY : (LINUX only) pathname이 directory가 아니면 오류가 발생합니다.
   이 옵션으로 open된 fd는 opendir(3) 등에서 사용가능합니다.

O_EXCL : O_CREAT와 함께 사용되며, 이미 파일이 존재하면 오류(-1)를 return합니다.

O_LARGEFILE : 32bit OS에서 2기가 이상의 큰 파일을 생성가능하도록 합니다.
   이 옵션을 사용하기 위해서는 #define _LARGEFILE64_SOURCE 를 include문이 시작하기 전에 적어 두어야 합니다.

O_NOATIME : (LINUX only) 파일을 읽더라도 파일의 meta정보에 last access time을 변경하지 말라는 설정입니다.

O_NOCTTY : pathname이 terminal device라도 이 프로세스에 terminal 할당이 되어 있지 않더라도 terminal 제어를 못하게 합니다.

O_NOFOLLOW : 만약 symbloc link이면 file open을 실패하도록 합니다.

O_NONBLOCK 또는 O_NODELAY : 파일을 nonblocking mode로 open합니다.
   read(2)함수를 호출해서 읽을 내용이 없으면 바로 return됩니다. 만약 이 옵션이 설정되지않아다면 데이터 읽을 때까지 대기합니다. write(2)도 마찬가지입니다.

O_PATH : (LINUX only) 파일을 open하는 목적이 파일을 읽거나 쓰기 위한 목적이 아니라 단지 file descriptor를 얻기 위한 목적입니다. 따라서 read(2), write(2), chmod(2) 등의 함수에 사용하면 오류가 발생합니다.
   사용할 수 있는 함수는 close(2), fchdir(2), fstat(2), dup2(2), fcntl(2) 등입니다. O_PATH가 설정되면, O_DIRECTORY, O_NOTFOLOW 이외의 flag는 무시됩니다.

O_SYNC : I/O시 kernel buffer에 caching하지 않고 바로 disk에 read/write하라는 설정입니다.
   이 option이 설정되면 성능이 많이 떨어질 수 있습니다. 이 옵션이 설정되지 않으면, 프로그램에서 write(2)를 하면 kernel이 데이터를 받아서 바로 정상 return하고 disk write는 kernel이 여유가 있거나 kernel buffer 최대 지연 시간이 도래하게되면 disk에 write합니다. O_DIRECT와 다른점은 파일의 meta 정보(최종파일 access 시간 등)도 동기화를 바로 합니다.

O_TRUNC : O_WRONLY 또는 O_RDWR로 open시에 이미 존재하는 파일이면 파일의 내용을 삭제하여 파일의 크기를 0으로 만듭니다.




  mode

  mode: 파일에 대한 access 권한을 설정합니다.
      파일 acces 권한은 umask(2)값의 영향을 받으며, (mode & ~umask) 값으로 권한이 설정됩니다.
      mode의 값은 아래의 상수들을 bit-or 연산으로 설정가능합니다.

  S_IRWXU : (00700) - owner에 대한 읽기, 쓰기, 실행권한 모두 설정
  S_IRUSR : (00400) - owner에 대한 읽기 권한
  S_IWUSR : (00200) - owner에 대한 쓰기 권한
  S_IXUSR : (00100) - owner에 대한 실행 권한
  S_IRWXG : (00070) - group에 대한 읽기, 쓰기, 실행권한 모두 설정
  S_IRGRP : (00040) - Group에 대한 읽기 권한
  S_IWGRP : (00020) - Group에 대한 쓰기 권한
  S_IXGRP : (00010) - Group에 대한 실행 권한
  S_IRWXO : (00007) - Other에 대한 읽기, 쓰기, 실행권한 모두 설정
  S_IROTH : (00004) - Other에 대한 읽기 권한
  S_IWOTH : (00002) - Other에 대한 쓰기 권한
  S_IXOTH : (00001) - Other에 대한 실행 권한



   RETURN

  0 이상
   정상적으로 파일을 열었으며, 열려진 파일의 file descriptor입니다.

  -1
   오류가 발생하였으며, 상세한 오류 내용은 errno에 설정됩니다.

   EACCES : 파일 access 권한이 없음.
   EDQUOT : O_CREAT일 때, 사용자별 할당된 disk용량이 없거나 inode가 고갈되어 생성할 수 없음.
   EEXIST : O_CREAT | O_EXCL 일 때 이미 파일이 존재함.
   EFAULT : pathname 변수의 pointer가 access가능한 메모리 영역이 아님.
   EFBIG : 32bit OS에서 2GB이상의 파일을 생성한 경우
   EINTR : signal이 발생함.
   EISDIR : pathname가 directory라서 O_WRONLY 또는 O_RDWR 로 열지 못함.
   ELOOP : path를 찾는 중에 symbolic link가 중첩되어 있거나 O_NOFOLLOW로 open했는 데, pathname이 symbolic link임.
   EMFILE : 파일이 너무 많이 open되어 더 open할 수 없음.
   ENAMETOOLONG : pathname이 너무 긴 문자열임(즉, 파일명 또는 fullpath 최대 문자수를 초과함)
   ENFILE : 시스템에서 열 수 있는 최대 파일 open 갯수를 초과함.
   ENODEV : pathname가 특수 파일이라서 열 수 없음
   ENOENT : 없는 파일인데, O_CREAT 설정이 없거나 symbolic link에 연결된 파일이 없음.
   ENOMEM : 할당할 메모리 부족
   ENOSPC : pathname 새로운 파일을 생성할 공간이 없음.
   ENOTDIR : pathname에 없는 디렉토리 구성이 있거나 O_DIRECTORY가 설정되었는 데, pathname이 디렉토리가 아닌 경우
   ENXIO : O_NONBLOCK | O_WRONLY 설정해놓고 읽기를 하는 경우
   EOVERFLOW : 32bit OS에서 2GB이상의 파일을 생성한 경우
   EPERM : O_NOATIME flag가 설정되었는 데, 권한이 없음.
   EROFS : pathname이 readonly device에 O_WRONLY 또는 O_RDWR가 설정됨.
   ETXTBSY : pathname가 실행하고 있는 실행파일에 대해서 write하려고 함.
   EWOULDBLOCK : O_NONBLOCK flag가 설정되어 읽기/쓰기할 상태가 아님.
*/
