#include <bits/stdc++.h>
using namespace std;


int main(void)
    {
        char A[26];
        for(int i = 0 ; i < 26 ; i++)
            {
                A[i] = i + 'a';
            }
        
        char B[26];
        for(int key = 1 ; key < 26 ; key++)
            {
                for(int i = 0 ; i < 26 ; i++)
                    {
                        int idx = i + key;
                        idx %= 26;
                        B[i] = A[idx];
                    }
                string str = "tguxk";

                for(int i = 0 ; i < str.size() ; i++)
                    {
                        int idx = str[i] - 'a';
                        cout << B[idx];
                    }
                cout << endl;
            }
        return 0;
    }
