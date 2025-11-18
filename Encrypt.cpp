#include <bits/stdc++.h>
using namespace std;

int main(void)
    {
        char a[26];
        char b[26];
        int key = 4;
        key = key % 26;
        int idx = key;
        for(int i = 0 ; i < 26 ; i++)
            {
                a[i] = i + 'a';
            }

        for(int i = 0 ; i < 26 - idx ; i++)
            {
                b[i] = a[i + idx];
            }
        int ptr = 0;
        for(int i = 26 - idx ; i < 26 ; i++)
            {
                b[i] = a[ptr++];
            }
        for(int i = 0 ; i < 26 ;i++)
            {
                cout << a[i] << "   " << b[i] << endl;
            }
        
        



        string original = "arusha";
        cout << "The plain is " << original << endl;
        char a1[original.size()];
        for(int i = 0 ; i < original.size() ; i++)
            {
                a1[i] = original[i];
            }

        char cypher[original.size()];
        
        for(int i = 0 ; i < original.size() ; i++)
        {
            char x = original[i];
            cypher[i] = b[x - 'a'];
        }
    
        cout << "The encryptedd  ";

        for(int i = 0 ; i < original.size() ; i++)
            {
                cout << cypher[i] ;
            }
        cout << endl;
        return 0;
    }
