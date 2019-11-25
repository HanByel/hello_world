#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main(){

    map<string,int> v;

//    v.push_back(10);
//    v.push_back(20);
//    v.push_back(30);
//    v.push_back(40);
//    v.push_back(50);

    v.emplace("a",10);
    v.emplace("b",20);
    v.emplace("c",30);
    v.emplace("d",40);
    v.emplace("e",25);

    cout << v.find("a")->second << endl;  // 임의접근
    v.erase("a");

//    vector<int>::iterator iter=v.begin();  // 벡터 반복자 시작지점


    cout << v.find("a")->second << endl;  // 임의접근


    cout << v.find("z")->second << endl;  // 임의접근
//    iter += 2;  // += 연산
//    cout << *iter << endl;
//    cout << endl;


//    // 반복
//    for (iter = v.begin(); iter != v.end(); ++iter){
//        cout << *iter << endl;
//    }

    return 0;
}
