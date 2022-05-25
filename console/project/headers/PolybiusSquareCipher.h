#include <bits/stdc++.h>
using namespace std;
#ifndef PolybiusSquareCipher_LIBRARY_H
#define PolybiusSquareCipher_LIBRARY_H

string message_PolybiusSquareCipher,keyword_PolybiusSquareCipher,ciphered_string_PolybiusSquareCipher,deciphered_string_PolybiusSquareCipher;
int user_choice_PolybiusSquareCipher;

void take_letter_PolybiusSquareCipher(){
    if(user_choice_PolybiusSquareCipher == 1){
        cout<<"Please enter the message to cipher: ";
    }else{
        cout<<"Please enter the message to decipher: ";
    }
    message_PolybiusSquareCipher = "";
    while (message_PolybiusSquareCipher.empty()){
        getline(cin,message_PolybiusSquareCipher);
    }
    transform(message_PolybiusSquareCipher.begin(),message_PolybiusSquareCipher.end(),message_PolybiusSquareCipher.begin(),::toupper);
}

bool check_decipher_PolybiusSquareCipher(){
    int n_digits=0;
    bool check = true;
    for (int i = 0; i < message_PolybiusSquareCipher.size(); ++i) {
        if((message_PolybiusSquareCipher[i] >= 48&& message_PolybiusSquareCipher[i] <= 57) || message_PolybiusSquareCipher[i]==' '){
            if(message_PolybiusSquareCipher[i] != ' '){
                n_digits++;
            }
            continue;
        }
        check = false;
    }
    if(n_digits%2){
        check = false;
    }
    if(!check){
        cout<<"Please enter valid letter (with only digits characters)\n";
    }
    return check;
}

void take_keyword_PolybiusSquareCipher(){
    cout<<"Enter the keyword: ";
    cin>>keyword_PolybiusSquareCipher;
    for(auto i : keyword_PolybiusSquareCipher){
        if(i<48 || i>57){
            cout<<"Please enter only numbers.\n";
            take_keyword_PolybiusSquareCipher();
            break;
        }
    }
    while (keyword_PolybiusSquareCipher.size()!=5){
        cout<<"Keyword must be 5 digits only.\n";
        take_keyword_PolybiusSquareCipher();
    }
}

void take_choice_PolybiusSquareCipher(){
    cout<<"What do you want to do today?\n";
    cout<<"1- Cipher \n";
    cout<<"2- Decipher \n";
    cout<<"3- End \n";
    cin>>user_choice_PolybiusSquareCipher;
    while (user_choice_PolybiusSquareCipher>3 || user_choice_PolybiusSquareCipher<1){
        cout<<"Enter correct number/\n";
        take_choice_PolybiusSquareCipher();
    }
}

void cipher_PolybiusSquareCipher(){
    int tmp_pointer;
    ciphered_string_PolybiusSquareCipher = "";
    for(auto i : message_PolybiusSquareCipher){
        if(i>=65 && i<= 90){
            tmp_pointer= (i - 'A'  -(i-'A'>=9));
            ciphered_string_PolybiusSquareCipher.push_back(char(keyword_PolybiusSquareCipher[tmp_pointer/5]));
            ciphered_string_PolybiusSquareCipher.push_back(char(keyword_PolybiusSquareCipher[tmp_pointer%5]));
        }else{
            ciphered_string_PolybiusSquareCipher.push_back(i);
        }
    }
    cout << "Ciphered message: " << ciphered_string_PolybiusSquareCipher << '\n';
}

void decipher_PolybiusSquareCipher(){
    deciphered_string_PolybiusSquareCipher = "";
    string tmp_string = "";
    int tmp_ascii;
    for (int i = 0; i <= message_PolybiusSquareCipher.size(); ++i) {
        if(tmp_string.size() == 2){
            int x = find(keyword_PolybiusSquareCipher.begin(),keyword_PolybiusSquareCipher.end(),tmp_string[0]) - keyword_PolybiusSquareCipher.begin();
            int y = (find(keyword_PolybiusSquareCipher.begin(),keyword_PolybiusSquareCipher.end(),tmp_string[1]) - keyword_PolybiusSquareCipher.begin());
            tmp_ascii = x*5 + y +1;
            tmp_ascii += (tmp_ascii>=10);
            deciphered_string_PolybiusSquareCipher.push_back(tmp_ascii-1 + 'A');
            tmp_string="";
        }
        if(i == message_PolybiusSquareCipher.size()){
            break;
        }
        if(message_PolybiusSquareCipher[i]<48 || message_PolybiusSquareCipher[i]>57){
            deciphered_string_PolybiusSquareCipher.push_back(message_PolybiusSquareCipher[i]);
            continue;
        }
        tmp_string += message_PolybiusSquareCipher[i];
    }
    cout << "Deciphered message: " << deciphered_string_PolybiusSquareCipher << '\n';
}

void start_Polybius_Square_cipher(){
    take_choice_PolybiusSquareCipher();
    if(user_choice_PolybiusSquareCipher==3){
        return;
    }
    take_letter_PolybiusSquareCipher();
    take_keyword_PolybiusSquareCipher();
    if(user_choice_PolybiusSquareCipher==1){
        cipher_PolybiusSquareCipher();
    }else{
        if(!check_decipher_PolybiusSquareCipher()){
            start_Polybius_Square_cipher();
            return;
        }
        decipher_PolybiusSquareCipher();
    }
    start_Polybius_Square_cipher();
}

#endif //CIPHERANDDECIPHER_LIBRARY_H
