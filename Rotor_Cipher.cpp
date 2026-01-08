#include <bits/stdc++.h>
using namespace std;

class Rotor{
    public:
        char original;
        char changed;


    Rotor()
        {
            
        }
    Rotor(char original,char changed)
        {
            this->changed = changed;
            this->original = original;
        }

    void Print_Rotor()
        {
            cout << this->original << " -> " << this->changed << endl;
        }
};

int main(void)
    {
        vector<Rotor> All_Collection;
        string Original = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string Changed = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        for(int i = 0 ; i < 26 ; i++)
            {
                Rotor new_Rotor = Rotor(Original[i],Changed[i]);
                All_Collection.push_back(new_Rotor);
            }

        for(int i = 0 ; i < 26 ; i++)
            {
                All_Collection[i].Print_Rotor();
            }



        string input;
        cin >> input;

        vector<char> cipher_text;

        for(int i = 0 ; i < input.size() ; i++)
            {
                bool got = false;
                for(int j = 0 ; j < All_Collection.size() && !got ; j++)
                    {
                        if(All_Collection[j].original == input[i])
                            {
                                got = true;
                                cipher_text.push_back(All_Collection[j].changed);
                            }
                        
                    }
            }
        cout << "Encrypted : ";
        for(int i = 0 ; i < cipher_text.size() ; i++)
            {
                cout << cipher_text[i];
            }
        cout << endl;
        vector<char> Comeback;

        for(int i = 0 ; i < cipher_text.size() ; i++)
            {
                bool got = false;
                for(int j = 0 ; !got && j < All_Collection.size() ; j++)
                    {
                        if(All_Collection[j].changed == cipher_text[i])
                            {
                                got = true;
                                Comeback.push_back(All_Collection[j].original);

                            }
                    }
            }
        cout << "Decrypted : ";
        for(int i = 0 ; i < Comeback.size() ; i++)
            {
                cout << Comeback[i];
            }
        cout << endl;   
        
        return 0;
    }