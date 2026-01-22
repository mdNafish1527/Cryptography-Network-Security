#include <bits/stdc++.h>
using namespace std;

class Rotor{
    public:
        char first;
        char second;
        char third;
        char fourth;

    Rotor()
        {

        }
    Rotor(char first,char second,char third,char fourth)
        {
            this -> first = first;
            this -> second = second;
            this -> third = third;
            this -> fourth = fourth;
        }

    void Print_Rotor()
        {
            cout << this -> first << "               " << this -> second << "               " << this -> third << "             " << this -> fourth << endl;
            return;
        }
};


int main(void)
    {
        string first_data = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string second_data = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        string third_data = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        string fourth_data = "BDFHJLCPRTXVZNYEIWGAKMUSQO";

        vector<Rotor> Collection;
        cout << "ZeroRotation " << "FirstRotation " << "SecondRotation  ThirdRotation" << endl ;
        for(int i = 0 ; i < 26 ; i++)
            {
                Rotor new_Rotor = Rotor(first_data[i],second_data[i],third_data[i],fourth_data[i]);
                Collection.push_back(new_Rotor);
            }

        for(int i = 0 ; i < 26 ; i++)
            {
                Collection[i].Print_Rotor();
            }

        string input_text;
        cin >> input_text;
        vector<char> second_cipher;
        vector<char> third_cipher;
        vector<char> fourth_cipher;

        for(int i = 0 ; i < input_text.size() ; i++)
            {
                bool got = false;
                for(int j = 0 ; j < 26 && !got ; j++)
                    {
                        if(Collection[j].first == input_text[i])
                            {
                                got = true;
                                second_cipher.push_back(Collection[j].second);
                            }
                    }
            }
        cout << "The original is " << input_text << endl;
        cout << "After first cycle Encryption " ;
        for(int i = 0 ; i < second_cipher.size() ; i++)
            {
                cout << second_cipher[i];
            }
        cout << endl;


        for(int i = 0 ; i < second_cipher.size() ; i++)
            {
                bool got = false;
                for(int j = 0 ; j < 26 && !got ; j++)
                    {
                        if(Collection[j].second == second_cipher[i])
                            {
                                got = true;
                                third_cipher.push_back(Collection[j].third);
                            }
                    }
            }

        cout << "After second cycle Encryption ";
        for(int i = 0 ; i < third_cipher.size() ; i++)
            {
                cout << third_cipher[i];
            }
        cout << endl;

        for(int i = 0 ; i < third_cipher.size() ; i++)
            {
                bool got = false;
                for(int j = 0 ; j < 26 && !got ; j++)
                    {
                        if(Collection[j].third == third_cipher[i])
                            {
                                got = true;
                                fourth_cipher.push_back(Collection[j].fourth);
                            }
                    }
            }

        cout << "After third cycle Encryption ";
        for(int i = 0 ; i < fourth_cipher.size() ; i++)
            {
                cout << fourth_cipher[i];
            }
        cout << endl;

        


        //Decryption

        vector<char> Decrypt_Third_Cipher;
        vector<char> Decrypt_Second_Cipher;
        vector<char> Decrypt_First_Cipher;

        for(int i = 0 ; i < fourth_cipher.size() ; i++)
            {
                bool got = false;
                for(int j = 0 ; i < 26 && !got ; j++)
                    {
                        if(fourth_cipher[i] == Collection[j].fourth)
                            {
                                got = true;
                                Decrypt_Third_Cipher.push_back(Collection[j].third);
                            }
                    }
            }

        cout << endl << endl << "After first level Decryption ";
        for(int i = 0 ; i < Decrypt_Third_Cipher.size() ; i++)
            {
                cout << Decrypt_Third_Cipher[i];
            }
        cout << endl;


        for(int i = 0 ; i < Decrypt_Third_Cipher.size() ; i++)
            {
                bool got = false;
                for(int j = 0 ; i < 26 && !got ; j++)
                    {
                        if(Decrypt_Third_Cipher[i] == Collection[j].third)
                            {
                                got = true;
                                Decrypt_Second_Cipher.push_back(Collection[j].second);
                            }
                    }
            }
        
        cout << "After second Level Decryption ";
        for(int i = 0 ; i < Decrypt_Second_Cipher.size() ; i++)
            {
                cout << Decrypt_Second_Cipher[i];
            }
        cout << endl;



        for(int i = 0 ; i < Decrypt_Second_Cipher.size() ; i++)
            {
                bool got = false;
                for(int j = 0 ; i < 26 && !got ; j++)
                    {
                        if(Decrypt_Second_Cipher[i] == Collection[j].second)
                            {
                                got = true;
                                Decrypt_First_Cipher.push_back(Collection[j].first);
                            }
                    }
            }

        cout << "After third Level Decryption ";
        for(int i = 0 ; i < Decrypt_First_Cipher.size() ; i++)
            {
                cout << Decrypt_First_Cipher[i];
            }
        cout << endl;
        
        return 0;
    }
