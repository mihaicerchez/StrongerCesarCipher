//
//  main.cpp
//  lab2MCPI
//
//  Created by Mihai Cerchez on 1/25/21.
//  Copyright © 2021 Mihai. All rights reserved.
//

#include<iostream>
#include<string>
#include<algorithm>

using  std::cout;
using  std::cin;
using  std::endl;
using  std::string;

char dset[] = " ";
  
string text;
int key;
string s;
string Encrypt(string Source, int c);
string Decrypt(string Source, int c);
void encrypted();
void decrypted();

int main()
{
       int n;
       string text;
       
       
start: cout << "\nEnter 1 for Encryption or 2 for Decryption: "<<endl;
       cin >> n;
       if (cin.fail())
       {
          cout <<endl<< "ERROR - You didn't enter a digit."<<endl;
          cin.clear();

          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

       }
       switch(n) {
          case 1:
            encrypted();
            break;
          case 2:
            decrypted();
            break;
          default:
            goto start;
        }
    goto start;
}

void encrypted ()
{       std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
label1:        cout << "Enter the plain text: ";
        getline(cin, text);
        transform(text.begin(), text.end(), text.begin(), ::toupper);
        
        for (int i = 0; i < text.size(); i++)
            {
                int uppercaseChar = (text[i]);
                if (uppercaseChar != ' ' & uppercaseChar < '@' || uppercaseChar > '[' & uppercaseChar < '_' || uppercaseChar > '}') //If character is not A-Z
                {
                    cout <<endl<< "ERROR, Enter values from A to Z or from a to z: "<<endl<<endl;
                    goto label1;
                }
            }
        goto label2;
label2: cout << "Enter the k1 key: ";
        
        cin >> key;
        if (key > 0 && key < 26) {
                    
                goto label3;}
            
                else {
                cout <<endl<< "Only 1 to 25 digits allowed as the k1 key."<<endl<<endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
                goto label2;
            }
label3:      cout<<"Enter the k2 key (word): ";
    
             cin >> s;
             transform(s.begin(), s.end(), s.begin(), ::toupper);
             int a = s.length();
             //cout <<a;
             if (a<7){
                 cout <<endl<< "ERROR, the k2's length can't be less than 7."<<endl;;
                 goto label3;
    }
             for (int i = 0; i < s.size(); i++)
             {
                 int uppercaseChar = (s[i]);
                 if (uppercaseChar != ' ' & uppercaseChar < '@' || uppercaseChar > '[' & uppercaseChar < '_' || uppercaseChar > '}') //If character is not A-Z
                 {
                     cout <<endl<< "ERROR, Enter values from A to Z or from a to z: "<<endl<<endl;
                     goto label3;
                 }
             }
       
        cout << "Obtained alphabet: " << Encrypt(text, key) << endl<<endl;
}

void decrypted (){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
label1:        cout << "Enter the Encrypted message: ";
        getline(cin, text);
        for (int i = 0; i < text.size(); i++)
        {
            int uppercaseChar = (text[i]);
            if (uppercaseChar < '@' && uppercaseChar > '[') //If character is not A-Z
            {
                cout << "ERROR, Enter values from A to Z or from a to z: "<<endl<<endl;
                goto label1;
            }
        }
    goto label2;
        
label2: cout << "Enter the k1 key used for Encryption: ";
        cin >> key;
            if (key > 0 && key < 26) {
            
            goto label3;}
    
        else {
        cout <<endl<< "Only 1 to 25 digits allowed as the k1 key."<<endl<<endl;
        cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    
        goto label2;
    }
    
label3: cout<<"Enter the k2 key (word) used for Encryption: ";
    
             cin >> s;
             transform(s.begin(), s.end(), s.begin(), ::toupper);
             int a = s.length();
             //cout <<a;
             if (a<7){
                 cout <<endl<< "ERROR, the k2's length can't be less than 7."<<endl;;
                 goto label3;
    }
             for (int i = 0; i < s.size(); i++)
             {
                 int uppercaseChar = (s[i]);
                 if (uppercaseChar != ' ' & uppercaseChar < '@' || uppercaseChar > '[' & uppercaseChar < '_' || uppercaseChar > '}') //If character is not A-Z
                 {
                     cout <<endl<< "ERROR, Enter values from A to Z or from a to z:"<<endl<<endl;
                     goto label3;
                 }
             }
       
      cout << "Obtained alphabet: " << Decrypt(text, key) << endl<<endl;

}

string Encrypt(string Source, int c)
{
    
    //char zero = '\0';
    int i, j,letter;
    char fUpperCase[40] = {'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
    
    char experiment[26];

    char fLowerCase[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string cipher = "";
    unsigned long z = Source.length();
       int nn = s.length();
       
      
       char char_array[15];
    
       strcpy(char_array, s.c_str());
    
    //cout <<endl;
    
    char elem=' ';
    for(i=0; i<nn; i++)
    {
        if(char_array[i]==elem)
        {
            for(j=i; j<(nn-1); j++)
                char_array[j] = char_array[j+1];
            i--;
        }
    }
    strcpy(fUpperCase, char_array);
    

   for (int i=0; i<40; i++)
    {
        char c = fUpperCase[i];
        for(int j = i+1; j<40; j++)
           {
               if(c==fUpperCase[j])
                   fUpperCase[j]='\0';
            }
      }
  
    string M = "";
    for (i = 0; i < 40; i++) {
        M = M + fUpperCase[i];
    }
    M.erase(remove(M.begin(), M.end(), '\0'), M.end());
    //return s;
    /*for (int i = 0 ; i < 40 ; i ++ ){
          cout << fUpperCase[i];
    }*/
    //cout << M;
    strcpy(experiment, M.c_str());
    for (int i = 0 ; i < 26 ; i ++ ){
          cout << experiment[i];
    }
    
    cout <<endl<<"Encrypted Message: ";
    for (i = 0; i < z; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (Source[i] == fLowerCase[j])
            {
                letter = j + c;
                if (letter > 25)
                        letter -= 26;
                if (letter < 0)
                        letter += 26;
                
                cipher += experiment[letter];
            }
            else if (Source[i] == experiment[j])
            {
                letter = j + c;
                if (letter > 25)
                        letter -= 26;
                if (letter < 0)
                        letter += 26;
            
                cipher += experiment[letter];
            }
        }
    }
   /* for (int i=0; i<strlen(cipher); i++)
    putchar(toupper(cipher[i]));*/
    return cipher;
}

string Decrypt(string Source, int c)
{
    //char zero = '\0';
    int i, j,letter;
    char fUpperCase[40] = {'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};

    char experiment[26];
    
    string cipher = "";
    unsigned long z = Source.length();
    
    int nn = s.length();
         
        
         char char_array[15];
      
         strcpy(char_array, s.c_str());
      
      
      char elem=' ';
      for(i=0; i<nn; i++)
      {
          if(char_array[i]==elem)
          {
              for(j=i; j<(nn-1); j++)
                  char_array[j] = char_array[j+1];
              i--;
          }
      }
      strcpy(fUpperCase, char_array);
      
    
     for (int i=0; i<40; i++)
      {
          char c = fUpperCase[i];
          for(int j = i+1; j<40; j++)
             {
                 if(c==fUpperCase[j])
                     fUpperCase[j]='\0';
              }
        }
      
      string M = "";
      for (i = 0; i < 40; i++) {
          M = M + fUpperCase[i];
      }
      M.erase(remove(M.begin(), M.end(), '\0'), M.end());
      //return s;
      /*for (int i = 0 ; i < 40 ; i ++ ){
            cout << fUpperCase[i];
      }*/
      //cout << M;
      strcpy(experiment, M.c_str());
      for (int i = 0 ; i < 26 ; i ++ ){
            cout << experiment[i];
      }
      
      cout <<endl<<"Decrypted Message: ";
    
    for (i = 0; i < z; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (Source[i] == experiment[j])
            {
                letter = j - c;
                if (letter > 25)
                        letter -= 26;
                if (letter < 0)
                        letter += 26;
                
                cipher += experiment[letter];
            }
        }
    }

    return cipher;
}

//xoxoxo ;))
