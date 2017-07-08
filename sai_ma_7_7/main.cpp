/*dianwenjiami
输入
第一行是一个整数n（<100），表示输入n组数据；
时间限制：C/C++语言 2000MS；其他语言 4000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
在二战时期，为了防止电文被敌方破译，需要将电文进行加密，现让你编程实现一种加密算法，可以将一串字母转换为6位数字。加密过程如下：
1.把字符串6个一组折叠起来，比如withdraw则变为：
 withdr
 aw
2.把所有垂直在同一个位置的字符的ASCII码值相加，得出6个数字，如上面的例子，则得出：216 224 116 104 100 114
3. 再把每个数字“缩位”处理：就是把每个位的数字相加，得出的数字如果不是一位数字，就再缩位，直到变成一位数字为止。例如: 216=>2+1+6=9上面的数字缩位后变为：988516, 这就是程序最终的输出结果！接下来是n行字符串，就是需要加密的字符串(长度小于100)。
输出
6位密码

样例输入
5
gameover
runaway
becarefull
yuantao
zhaojuan
样例输出
641231
192727
229762
797287
377379
*/
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
