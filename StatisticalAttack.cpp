#include <bits/stdc++.h>
using namespace std;

int main(void)
    {
        cout << "Enter the text ";
        string text;
        getline(cin,text);

        vector<char> letter(26);
        for(int i = 0 ; i < 26 ; i++)
            {
                letter[i] = i + 'a';
            }

        vector<int> cnt(26,0);
        for(int i = 0 ; i < 26 ; i++)  
            {
                int cur_cnt = 0;
                for(int j = 0 ; j < text.size() ; j++)
                    {
                        if(text[j] == (i+'a'))
                            {
                                cur_cnt++;
                            }
                    }
                cnt[i] = cur_cnt;
            }
        cout << "Character    frequency " << endl;

        for(int i = 0 ; i  < 26 ; i++)
            {
                cout << (char)(i + 'a') << "              " << cnt[i] << endl;
            }

        int max_freqn = -1;
        int idx;
        for(int i = 0 ; i < 26 ; i++)
            {
                if(cnt[i] > max_freqn)
                    {
                        max_freqn = max(cnt[i],max_freqn);
                        idx = i;
                    }
            }
        cout << "The max frequency is " << max_freqn << "   " << (char)(cnt[idx] + 'a' + 1) << endl ;
        int key = idx + 1;
        cout << key << endl;
        
        for(int i = 0 ; i < text.size() ; i++)
            {
                char ch = text[i] + key;
                if(ch > 'z')
                    {
                        ch -= 'z';
                        ch += 'a';
                    }
                cout << ch;
            }
        cout << endl;

        for(int i = 0 ; i < text.size() ; i++)
            {
                cout << text[i];
            }
        cout << endl;
        return 0;
    }
