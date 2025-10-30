#include <bits/stdc++.h>
using namespace std;

int find_gcd(int a,int b);

int main(void)
    {
        int a = 4 , b = 43;
        cout << find_gcd(a,b) << endl;
        return 0;
    }

int find_gcd(int a,int b)
    {
        if(a == 0)
            {
                return b;
            }
        else if(b == 0)
            {
                return a;
            }
        else
            {
                return find_gcd(b,a%b);
            }
    }
