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

void findWay(char oop, int oped);

void op(char s);

bool isOK();

void opcz(char xop);

void startFindWay();

CUBE x;

string allop[100];

int cnt = 16;
bool flag;
int maxStep;
/*debug*/long long int debugNum = 0;


int main(){
	IOS;
	
	printf("F:");
    cin >> x.f.a >> x.f.b >> x.f.c >> x.f.d;

    printf("U:");
    cin >> x.u.a >> x.u.b >> x.u.c >> x.u.d;

    printf("R:");
    cin >> x.r.a >> x.r.b >> x.r.c >> x.r.d;

    printf("L:");
    cin >> x.l.a >> x.l.b >> x.l.c >> x.l.d;

    printf("B:");
    cin >> x.b.a >> x.b.b >> x.b.c >> x.b.d;

    printf("D:");
    cin >> x.d.a >> x.d.b >> x.d.c >> x.d.d;

    flag = false;

    cout << "Start to find the answer..." << endl;
	startFindWay();

    cout << "Found one possible answer: ";
    for(int i = 1; i <= cnt; i++)
    {
        cout << allop[i] << ' ';
    }
	
	return 0;
}

void startFindWay()  // 程序入口
{
    for(maxStep = 1; maxStep <= 14; maxStep++)
    {
        for(char i : canOp)
        {
            findWay(i, 1);
            if(flag) return;
        }
    }
}

void findWay(char oop, int oped)  // 用来递归的函数
{
//    if(isOK())
//    {
//        flag = true;
//        cnt = oped-1;
//        return;
//    }  // 重复判定，不确定能不能直接删，注释掉先~

    if(oped >= 3 && allop[oped] == allop[oped-1] && allop[oped] == allop[oped-2]) return;  // 当有三个连续一样的转动操作后直接退出，即剪枝，减少运算量

    allop[oped] = oop;
    op(oop);

    if(isOK())
    {
        flag = true;
        cnt = oped;
        return;
    }

    for(char i : canOp)
    {
        if(abs(i - oop) != 32 && oped+1 <=maxStep)
        {
            findWay(i, oped+1);
            if(flag) return;
        }
    }

    /*debug*/if(oped+1>maxStep)  // Debug用来输出此时程序运算到哪里了，减缓焦虑（bushi
    {
        cout << ++debugNum << ": ";
        for(int j = 0; j <= oped; j++)
        {
            cout << allop[j] << ' ';
        }
        cout << endl;
    }

    opcz(oop);

}

void opcz(char xop){  // 撤销旋转操作

    if(xop >= 65 && xop <= 90)
    {
        op(xop + 32);
    }
    if(xop >= 97 && xop <= 122)
    {
        op(xop - 32);
    }

}

bool isOK()
{
    if(not(x.f.a == x.f.b && x.f.b == x.f.c && x.f.c == x.f.d)) return false;
    if(not(x.u.a == x.u.b && x.u.b == x.u.c && x.u.c == x.u.d)) return false;
    if(not(x.r.a == x.r.b && x.r.b == x.r.c && x.r.c == x.r.d)) return false;
    if(not(x.d.a == x.d.b && x.d.b == x.d.c && x.d.c == x.d.d)) return false;
    if(not(x.l.a == x.l.b && x.l.b == x.l.c && x.l.c == x.l.d)) return false;
    if(not(x.b.a == x.b.b && x.b.b == x.b.c && x.b.c == x.b.d)) return false;
    return true;
}

void op(char s)  // 转动魔方的具体实现
{

    char t;
    if(s == 'R')
    {
        t = x.r.a; x.r.a = x.r.d; x.r.d = x.r.c; x.r.c = x.r.b; x.r.b = t;
        t = x.f.b; x.f.b = x.d.b; x.d.b = x.b.b; x.b.b = x.u.b; x.u.b = t;
        t = x.f.c; x.f.c = x.d.c; x.d.c = x.b.c; x.b.c = x.u.c; x.u.c = t;
        return;
    }
    if(s == 'r')
    {
        t = x.r.a; x.r.a = x.r.b; x.r.b = x.r.c; x.r.c = x.r.d; x.r.d = t;
        t = x.f.b; x.f.b = x.u.b; x.u.b = x.b.b; x.b.b = x.d.b; x.d.b = t;
        t = x.f.c; x.f.c = x.u.c; x.u.c = x.b.c; x.b.c = x.d.c; x.d.c = t;
        return;
    }
    if(s == 'L')
    {
        t = x.l.a; x.l.a = x.l.d; x.l.d = x.l.c; x.l.c = x.l.b; x.l.b = t;
        t = x.f.a; x.f.a = x.u.a; x.u.a = x.b.a; x.b.a = x.d.a; x.d.a = t;
        t = x.f.d; x.f.d = x.u.d; x.u.d = x.b.d; x.b.d = x.d.d; x.d.d = t;
        return;
    }
    if(s == 'l')
    {
        t = x.l.a; x.l.a = x.l.b; x.l.b = x.l.c; x.l.c = x.l.d; x.l.d = t;
        t = x.f.a; x.f.a = x.d.a; x.d.a = x.b.a; x.b.a = x.u.a; x.u.a = t;
        t = x.f.d; x.f.d = x.d.d; x.d.d = x.b.d; x.b.d = x.u.d; x.u.d = t;
        return;
    }
    if(s == 'U')
    {
        t = x.u.a; x.u.a = x.u.d; x.u.d = x.u.c; x.u.c = x.u.b; x.u.b = t;
        t = x.f.a; x.f.a = x.r.a; x.r.a = x.b.c; x.b.c = x.l.a; x.l.a = t;
        t = x.f.b; x.f.b = x.r.b; x.r.b = x.b.d; x.b.d = x.l.b; x.l.b = t;
        return;
    }
    if(s == 'u')
    {
        t = x.u.a; x.u.a = x.u.b; x.u.b = x.u.c; x.u.c = x.u.d; x.u.d = t;
        t = x.f.a; x.f.a = x.l.a; x.l.a = x.b.c; x.b.c = x.r.a; x.r.a = t;
        t = x.f.b; x.f.b = x.l.b; x.l.b = x.b.d; x.b.d = x.r.b; x.r.b = t;
        return;
    }
    if(s == 'D')
    {
        t = x.d.a; x.d.a = x.d.d; x.d.d = x.d.c; x.d.c = x.d.b; x.d.b = t;
        t = x.f.d; x.f.d = x.l.d; x.l.d = x.b.b; x.b.b = x.r.d; x.r.d = t;
        t = x.f.c; x.f.c = x.l.c; x.l.c = x.b.a; x.b.a = x.r.c; x.r.c = t;
        return;
    }
    if(s == 'd')
    {
        t = x.d.a; x.d.a = x.d.b; x.d.b = x.d.c; x.d.c = x.d.d; x.d.d = t;
        t = x.f.d; x.f.d = x.r.d; x.r.d = x.b.b; x.b.b = x.l.d; x.l.d = t;
        t = x.f.c; x.f.c = x.r.c; x.r.c = x.b.a; x.b.a = x.l.c; x.l.c = t;
        return;
    }
    if(s == 'F')
    {
        t = x.f.a; x.f.a = x.f.d; x.f.d = x.f.c; x.f.c = x.f.b; x.f.b = t;
        t = x.u.d; x.u.d = x.l.c; x.l.c = x.d.b; x.d.b = x.r.a; x.r.a = t;
        t = x.u.c; x.u.c = x.l.b; x.l.b = x.d.a; x.d.a = x.r.d; x.r.d = t;
        return;
    }
    if(s == 'f')
    {
        t = x.f.a; x.f.a = x.f.b; x.f.b = x.f.c; x.f.c = x.f.d; x.f.d = t;
        t = x.u.d; x.u.d = x.r.a; x.r.a = x.d.b; x.d.b = x.l.c; x.l.c = t;
        t = x.u.c; x.u.c = x.r.d; x.r.d = x.d.a; x.d.a = x.l.b; x.l.b = t;
        return;
    }
    if(s == 'B')
    {
        t = x.b.a; x.b.a = x.b.d; x.b.d = x.b.c; x.b.c = x.b.b; x.b.b = t;
        t = x.u.a; x.u.a = x.r.b; x.r.b = x.d.c; x.d.c = x.l.d; x.l.d = t;
        t = x.u.b; x.u.b = x.r.c; x.r.c = x.d.d; x.d.d = x.l.a; x.l.a = t;
        return;
    }
    if(s == 'b')
    {
        t = x.b.a; x.b.a = x.b.b; x.b.b = x.b.c; x.b.c = x.b.d; x.b.d = t;
        t = x.u.a; x.u.a = x.l.d; x.l.d = x.d.c; x.d.c = x.r.b; x.r.b = t;
        t = x.u.b; x.u.b = x.l.a; x.l.a = x.d.d; x.d.d = x.r.c; x.r.c = t;
        return;
    }

}

