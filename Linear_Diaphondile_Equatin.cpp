#include <bits/stdc++.h>
using namespace std;

int find_gcd(int a,int b);

int main(void)
    {
        int a = 14 , b = 21 ,c = 35;
        // ax + by = c
        // cout << find_gcd(21,14) << endl;
        if(c % find_gcd(a,b))
            {
                cout << "No integer solution" << endl;
            }
        else
            {
                int newa = a / find_gcd(a,b);
                int newb = b / find_gcd(a,b);
                int newc = c / find_gcd(a,b);


                // newa * s + newb * t = gcd(newa,newb)

                int q , r1 = max(newa,newb) , r2 = min(newa,newb) , r , s1 = 1 , s2 = 0 , s , t1 = 0 , t2 = 1 , t ;
                while(r1 != 0 && r2 != 0)
                    {
                        q = r1 / r2;
                        r = r1 % r2;
                        s = s1 - (s2 * q);
                        t = t1 - (t2 * q);
                        r1 = r2;
                        r2 = r;
                        s1 = s2;
                        s2 = s;
                        t1 = t2;
                        t2 = t;
                    }
                s = s1,t = t1;
                cout << "using the extended euclid algorithm the value of s,t = (" << s << "," << t << ")" << endl;

                int scale_up = newc / find_gcd(newa,newb);
                cout << "particular solution " << "("<< scale_up * s << "," << scale_up * t << ")" << endl;
                s *= scale_up;
                t *= scale_up;

                int x0 = s,y0 = t;
                cout << "General solution " << "(" << x0 << " + " << b/find_gcd(a,b) << "k , " << y0 << " - " << a/find_gcd(a,b) << "k)" << endl;


            }


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
        return find_gcd(b,a%b);
    }
