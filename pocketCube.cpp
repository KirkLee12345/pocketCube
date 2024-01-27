#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


struct M{
    char a, b, c, d;
};

struct CUBE{
    M u, d, f, r, l, b;
};

char canOp[12] = {'R', 'r', 'L', 'l', 'F', 'f', 'B', 'b', 'U', 'u', 'D', 'd'};

void findWay(char oop, int oped, int num);

void op(char s, int num);

bool isOK(int num);

void opcz(char xop, int num);

void startFindWay();

CUBE x[168];

string allop[168][100];
thread th[168];

int cnt[168];
bool flag;
int doneNum;
int maxStep[168];
/*debug*/long long int debugnum[168];


int main(){
	IOS;

    for(int i = 0; i < 168; i++) cnt[i] = 16;

    int num = 0;
	
	printf("F:");
    cin >> x[num].f.a >> x[num].f.b >> x[num].f.c >> x[num].f.d;

    printf("U:");
    cin >> x[num].u.a >> x[num].u.b >> x[num].u.c >> x[num].u.d;

    printf("R:");
    cin >> x[num].r.a >> x[num].r.b >> x[num].r.c >> x[num].r.d;

    printf("L:");
    cin >> x[num].l.a >> x[num].l.b >> x[num].l.c >> x[num].l.d;

    printf("B:");
    cin >> x[num].b.a >> x[num].b.b >> x[num].b.c >> x[num].b.d;

    printf("D:");
    cin >> x[num].d.a >> x[num].d.b >> x[num].d.c >> x[num].d.d;

    for(int i = 1; i < 168; i++)
    {
        x[i].f.a = x[0].f.b ; x[i].f.b = x[0].f.d;
        x[i].u.a = x[0].u.b ; x[i].u.b = x[0].u.d;
        x[i].r.a = x[0].r.b ; x[i].r.b = x[0].r.d;
        x[i].l.a = x[0].l.b ; x[i].l.b = x[0].l.d;
        x[i].b.a = x[0].b.b ; x[i].b.b = x[0].b.d;
        x[i].d.a = x[0].d.b ; x[i].d.b = x[0].d.d;
        x[i].f.d = x[0].f.b ; x[i].f.c = x[0].f.d;
        x[i].u.d = x[0].u.b ; x[i].u.c = x[0].u.d;
        x[i].r.d = x[0].r.b ; x[i].r.c = x[0].r.d;
        x[i].l.d = x[0].l.b ; x[i].l.c = x[0].l.d;
        x[i].b.d = x[0].b.b ; x[i].b.c = x[0].b.d;
        x[i].d.d = x[0].d.b ; x[i].d.c = x[0].d.d;
    }

    flag = false;

    cout << "Start to find the answer..." << endl;
	startFindWay();

    cout << "Found one possible answer: ";
    for(int i = 1; i <= cnt[doneNum]; i++)
    {
        cout << allop[doneNum][i] << ' ';
    }
	
	return 0;
}

void startFindWay()  // 程序入口
{
    flag = false;
    int j = 0;
    for(int k = 1; k <= 14; k++)
    {
        for(char i : canOp)
        {
            maxStep[j] = k;
            th[j] = thread(findWay, i, 1, j);
            j++;
        }
    }
    for(int i = 0; i < 168; i++)
    {
        th[i].join();
    }
}

void findWay(char oop, int oped, int num)  // 用来递归的函数
{
//    if(isOK())
//    {
//        flag = true;
//        cnt[num] = oped-1;
//        return;
//    }  // 重复判定，不确定能不能直接删，注释掉先~
    if(flag) return;

    if(oped >= 3 && allop[num][oped] == allop[num][oped-1] && allop[num][oped] == allop[num][oped-2]) return;  // 当有三个连续一样的转动操作后直接退出，即剪枝，减少运算量

    allop[num][oped] = oop;
    op(oop, num);

    if(isOK(num))
    {
        flag = true;
        doneNum = num;
        cnt[num] = oped;
        return;
    }

    for(char i : canOp)
    {
        if(abs(i - oop) != 32 && oped+1 <= maxStep[num])
        {
            findWay(i, oped+1, num);
            if(flag) return;
        }
    }

//    /*debug*/if(oped+1>maxStep[num])  // Debug用来输出此时程序运算到哪里了，减缓焦虑（bushi
//    {
//        cout << '[' << num << '/' << ++debugnum[num] << ']' << ": ";
//        for(int j = 0; j <= oped; j++)
//        {
//            cout << allop[num][j] << ' ';
//        }
//        cout << endl;
//    }

    opcz(oop, num);

}

void opcz(char xop, int num){  // 撤销旋转操作

    if(xop >= 65 && xop <= 90)
    {
        op(xop + 32, num);
    }
    if(xop >= 97 && xop <= 122)
    {
        op(xop - 32, num);
    }

}

bool isOK(int num)
{
    if(not(x[num].f.a == x[num].f.b && x[num].f.b == x[num].f.c && x[num].f.c == x[num].f.d)) return false;
    if(not(x[num].u.a == x[num].u.b && x[num].u.b == x[num].u.c && x[num].u.c == x[num].u.d)) return false;
    if(not(x[num].r.a == x[num].r.b && x[num].r.b == x[num].r.c && x[num].r.c == x[num].r.d)) return false;
    if(not(x[num].d.a == x[num].d.b && x[num].d.b == x[num].d.c && x[num].d.c == x[num].d.d)) return false;
    if(not(x[num].l.a == x[num].l.b && x[num].l.b == x[num].l.c && x[num].l.c == x[num].l.d)) return false;
    if(not(x[num].b.a == x[num].b.b && x[num].b.b == x[num].b.c && x[num].b.c == x[num].b.d)) return false;
    return true;
}

void op(char s, int num)  // 转动魔方的具体实现
{

    char t;
    if(s == 'R')
    {
        t = x[num].r.a; x[num].r.a = x[num].r.d; x[num].r.d = x[num].r.c; x[num].r.c = x[num].r.b; x[num].r.b = t;
        t = x[num].f.b; x[num].f.b = x[num].d.b; x[num].d.b = x[num].b.b; x[num].b.b = x[num].u.b; x[num].u.b = t;
        t = x[num].f.c; x[num].f.c = x[num].d.c; x[num].d.c = x[num].b.c; x[num].b.c = x[num].u.c; x[num].u.c = t;
        return;
    }
    if(s == 'r')
    {
        t = x[num].r.a; x[num].r.a = x[num].r.b; x[num].r.b = x[num].r.c; x[num].r.c = x[num].r.d; x[num].r.d = t;
        t = x[num].f.b; x[num].f.b = x[num].u.b; x[num].u.b = x[num].b.b; x[num].b.b = x[num].d.b; x[num].d.b = t;
        t = x[num].f.c; x[num].f.c = x[num].u.c; x[num].u.c = x[num].b.c; x[num].b.c = x[num].d.c; x[num].d.c = t;
        return;
    }
    if(s == 'L')
    {
        t = x[num].l.a; x[num].l.a = x[num].l.d; x[num].l.d = x[num].l.c; x[num].l.c = x[num].l.b; x[num].l.b = t;
        t = x[num].f.a; x[num].f.a = x[num].u.a; x[num].u.a = x[num].b.a; x[num].b.a = x[num].d.a; x[num].d.a = t;
        t = x[num].f.d; x[num].f.d = x[num].u.d; x[num].u.d = x[num].b.d; x[num].b.d = x[num].d.d; x[num].d.d = t;
        return;
    }
    if(s == 'l')
    {
        t = x[num].l.a; x[num].l.a = x[num].l.b; x[num].l.b = x[num].l.c; x[num].l.c = x[num].l.d; x[num].l.d = t;
        t = x[num].f.a; x[num].f.a = x[num].d.a; x[num].d.a = x[num].b.a; x[num].b.a = x[num].u.a; x[num].u.a = t;
        t = x[num].f.d; x[num].f.d = x[num].d.d; x[num].d.d = x[num].b.d; x[num].b.d = x[num].u.d; x[num].u.d = t;
        return;
    }
    if(s == 'U')
    {
        t = x[num].u.a; x[num].u.a = x[num].u.d; x[num].u.d = x[num].u.c; x[num].u.c = x[num].u.b; x[num].u.b = t;
        t = x[num].f.a; x[num].f.a = x[num].r.a; x[num].r.a = x[num].b.c; x[num].b.c = x[num].l.a; x[num].l.a = t;
        t = x[num].f.b; x[num].f.b = x[num].r.b; x[num].r.b = x[num].b.d; x[num].b.d = x[num].l.b; x[num].l.b = t;
        return;
    }
    if(s == 'u')
    {
        t = x[num].u.a; x[num].u.a = x[num].u.b; x[num].u.b = x[num].u.c; x[num].u.c = x[num].u.d; x[num].u.d = t;
        t = x[num].f.a; x[num].f.a = x[num].l.a; x[num].l.a = x[num].b.c; x[num].b.c = x[num].r.a; x[num].r.a = t;
        t = x[num].f.b; x[num].f.b = x[num].l.b; x[num].l.b = x[num].b.d; x[num].b.d = x[num].r.b; x[num].r.b = t;
        return;
    }
    if(s == 'D')
    {
        t = x[num].d.a; x[num].d.a = x[num].d.d; x[num].d.d = x[num].d.c; x[num].d.c = x[num].d.b; x[num].d.b = t;
        t = x[num].f.d; x[num].f.d = x[num].l.d; x[num].l.d = x[num].b.b; x[num].b.b = x[num].r.d; x[num].r.d = t;
        t = x[num].f.c; x[num].f.c = x[num].l.c; x[num].l.c = x[num].b.a; x[num].b.a = x[num].r.c; x[num].r.c = t;
        return;
    }
    if(s == 'd')
    {
        t = x[num].d.a; x[num].d.a = x[num].d.b; x[num].d.b = x[num].d.c; x[num].d.c = x[num].d.d; x[num].d.d = t;
        t = x[num].f.d; x[num].f.d = x[num].r.d; x[num].r.d = x[num].b.b; x[num].b.b = x[num].l.d; x[num].l.d = t;
        t = x[num].f.c; x[num].f.c = x[num].r.c; x[num].r.c = x[num].b.a; x[num].b.a = x[num].l.c; x[num].l.c = t;
        return;
    }
    if(s == 'F')
    {
        t = x[num].f.a; x[num].f.a = x[num].f.d; x[num].f.d = x[num].f.c; x[num].f.c = x[num].f.b; x[num].f.b = t;
        t = x[num].u.d; x[num].u.d = x[num].l.c; x[num].l.c = x[num].d.b; x[num].d.b = x[num].r.a; x[num].r.a = t;
        t = x[num].u.c; x[num].u.c = x[num].l.b; x[num].l.b = x[num].d.a; x[num].d.a = x[num].r.d; x[num].r.d = t;
        return;
    }
    if(s == 'f')
    {
        t = x[num].f.a; x[num].f.a = x[num].f.b; x[num].f.b = x[num].f.c; x[num].f.c = x[num].f.d; x[num].f.d = t;
        t = x[num].u.d; x[num].u.d = x[num].r.a; x[num].r.a = x[num].d.b; x[num].d.b = x[num].l.c; x[num].l.c = t;
        t = x[num].u.c; x[num].u.c = x[num].r.d; x[num].r.d = x[num].d.a; x[num].d.a = x[num].l.b; x[num].l.b = t;
        return;
    }
    if(s == 'B')
    {
        t = x[num].b.a; x[num].b.a = x[num].b.d; x[num].b.d = x[num].b.c; x[num].b.c = x[num].b.b; x[num].b.b = t;
        t = x[num].u.a; x[num].u.a = x[num].r.b; x[num].r.b = x[num].d.c; x[num].d.c = x[num].l.d; x[num].l.d = t;
        t = x[num].u.b; x[num].u.b = x[num].r.c; x[num].r.c = x[num].d.d; x[num].d.d = x[num].l.a; x[num].l.a = t;
        return;
    }
    if(s == 'b')
    {
        t = x[num].b.a; x[num].b.a = x[num].b.b; x[num].b.b = x[num].b.c; x[num].b.c = x[num].b.d; x[num].b.d = t;
        t = x[num].u.a; x[num].u.a = x[num].l.d; x[num].l.d = x[num].d.c; x[num].d.c = x[num].r.b; x[num].r.b = t;
        t = x[num].u.b; x[num].u.b = x[num].l.a; x[num].l.a = x[num].d.d; x[num].d.d = x[num].r.c; x[num].r.c = t;
        return;
    }

}

