git@github.com:HanByel/simulator.git

git config --global user.name "HanByel"
git config --global user.email "깃허브 메일주소" // 매번 물어보는 귀찮음을 피하기 위해 설정.

mkdir ~/MyProject   // 로컬 디렉토리 만들고
cd ~/myproject      // 디렉토리로 들어가서
git init            // 깃 명령어를 사용할 수 있는 디렉토리로 만든다.
git status          // 현재 상태를 훑어보고
git add 화일명.확장자  // 깃 주목 리스트에 화일을 추가하고 or
git add .           // 이 명령은 현재 디렉토리의 모든 화일을 추가할 수 있다.
git commit -m “현재형으로 설명” // 커밋해서 스냅샷을 찍는다.

git remote add origin https://github.com/username/myproject.git // 로컬과 원격 저장소를 연결한다.
git remote -v // 연결상태를 확인한다.
git push origin master // 깃허브로 푸시한다.



Git 에서 비밀번호 물어보지 않게 하기
Git 를 사용할 때 git pull 등의 명령어를 실행할 때 비밀번호를 물어보게 될 때 매번 물어보지 않게 하는 방법을 안내한다.
두가지 방법이 있는데
1. repository url 에서 비밀번호는 입력하는 방법
2. 캐시를 설정하는 방법
이 있다.
git clone 을 할 때 다음과 같이 비밀번호를 미리 입력한다면 비밀번호를 물어보지 않는다. 이렇게 이용할 수도 있으나 추천 하지는 않는다.
git clone https://myid:mypassword@bitbucket.org/myid/myapp.git
캐시를 설정하여 특정시간동안 비밀번호를 다시 물어보지 않게끔 할 수 있다.
여기서 –global 옵션과 함께 명령어를 실행한다면 모든 계정에 대해서 캐싱을 한다는 의미이다. 만약 특정 git 디렉토리만 설정한다면 –global 옵션을 제거해 주면 된다.
git config --global credential.helper cache  
디폴트는 900초(15분) 동안 캐시를 저장하므로 15분이 지나고 다시 시도하면 비밀번호를 다시 물어보게 된다.
넉넉하게 타임아웃을 설정할 수 있는데 만약 10일간 캐시를 설정한다고 한다면 다음과 같이 입력하면 된다.
git config --global credential.helper 'cache --timeout=864000'
이제 더 이상 비밀번호를 물어보지 않는다. 야호!

