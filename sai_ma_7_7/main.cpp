#include <iostream>
#include <string>
#include <vector>
using namespace std;
int change_num(int num){

    int finalnum = num;
    while(finalnum/10 != 0){
        int temp = finalnum;
        finalnum = 0;
        while(temp != 0){
          finalnum += temp%10;
          temp = temp / 10;
        }
    }
    return finalnum;
}
int main()
{
    int n ;
    cin >>n;
    vector<string>a;
    a.reserve(n);
    for(int i =0; i< n; i++){
        string s;
        cin >> s;
        a.push_back(s);
    }

 /*   a.push_back("gameover") ;
    a.push_back("runaway");
    a.push_back("becarefull");
    a.push_back("yuantao");
    a.push_back("zhaojuan");*/

    for(int i =0; i < n; i++){
       int mima[6]={0,0,0,0,0,0};
        int j = 0;
        string s =a[i];
        while(s[j]!='\0'){
            int tmp = j%6;
            mima[tmp] += s[j++];
        }
        for(int i = 0; i < 6; i ++){
            cout<<change_num(mima[i]);
        }
        cout<<endl;
    }
    a.clear();
    return 0;
}
