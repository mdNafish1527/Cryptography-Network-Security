#include <bits/stdc++.h>
using namespace std;

int main(void)
    {
        long long int plain_text = 10101111;
        vector<int> array;
        while(plain_text != 0)
            {
                array.push_back(plain_text % 10);
                plain_text /= 10;
            }
        int i = 0 , j = array.size() - 1;
        while(i < j)
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        cout << "The plain text is  ";
        for(int i = 0 ; i < array.size() ; i++)
            {
                cout << array[i];
            }
        cout << endl;

        vector<int> left_half;
        vector<int> right_half;
        for(int i = 0 ;i < array.size() ; i++)
            {
                if(i < array.size() / 2)
                    {
                        left_half.push_back(array[i]);
                    }
                else
                    {
                        right_half.push_back(array[i]);
                    }
            }

        int key = 1001;
        vector<int> the_key;
        while(key != 0)
            {
                the_key.push_back(key % 10);
                key /= 10;
            }
        i = 0 , j = the_key.size() - 1;
        while(i < j)
            {
                int temp = the_key[i];
                the_key[i] = the_key[j];
                the_key[j] = temp;
                i++;
                j--;
            }

        for (int i = 0; i < the_key.size() ; i++)
            {
                left_half[i] = left_half[i] ^ the_key[i];
                right_half[i] = right_half[i] ^ the_key[i];
            }
        // for(int i = 0 ; i < left_half.size() ; i++)
        //     {
        //         cout << left_half[i];
        //     }
        // cout << endl;
        // for(int i = 0 ; i < right_half.size() ; i++)
        //     {
        //         cout << right_half[i];
        //     }
        // cout << endl;
        vector<int> cipher_text_okay;
        for(int i = 0 ; i < left_half.size() ; i++)
            {
                cipher_text_okay.push_back(left_half[i]);
            }
        for(int i = 0 ; i < right_half.size() ; i++)
            {
                cipher_text_okay.push_back(right_half[i]);
            }
        int first_idx = 0 , last_idx = cipher_text_okay.size() - 1;
        while(first_idx < last_idx)
            {
                int temp = cipher_text_okay[first_idx];
                cipher_text_okay[first_idx] = cipher_text_okay[last_idx];
                cipher_text_okay[last_idx] = temp;
                first_idx++;
                last_idx--;
            }
        cout << "the encrypted text ";

        for(int i = 0 ; i < cipher_text_okay.size() ; i++)
            {
                cout << cipher_text_okay[i];
            }
        cout << endl;


        first_idx = 0 , last_idx = cipher_text_okay.size() - 1;
        while(first_idx < last_idx)
            {
                int temp = cipher_text_okay[first_idx];
                cipher_text_okay[first_idx] = cipher_text_okay[last_idx];
                cipher_text_okay[last_idx] = temp;
                first_idx++;
                last_idx--;
            }

        left_half.clear();
        right_half.clear();

        for(int i = 0 ;i < cipher_text_okay.size() ; i++)
            {
                if(i < cipher_text_okay.size() / 2)
                    {
                        left_half.push_back(cipher_text_okay[i]);
                    }
                else
                    {
                        right_half.push_back(cipher_text_okay[i]);
                    }
            }
        
        for (int i = 0; i < the_key.size() ; i++)
            {
                left_half[i] = left_half[i] ^ the_key[i];
                right_half[i] = right_half[i] ^ the_key[i];
            }
        cout << "The decrypted      ";
        for(int i = 0 ; i < left_half.size() ; i++)
            {
                cout << left_half[i];
            }
        for(int i = 0 ; i < right_half.size() ; i++)
            {
                cout << right_half[i];
            }
        cout << endl;
        

        return 0;
    }