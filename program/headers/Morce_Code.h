#include <bits/stdc++.h>
using namespace std;
#ifndef Morce_Code_LIBRARY_H
#define Morce_Code_LIBRARY_H

vector<string>morse_code{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
string message_Morce_Code,cipher_string_Morce_Code,decipher_string_Morce_Code;
int user_choice_Morce_Code;

void take_message_Morce_Code(){
    if(user_choice_Morce_Code == 1){
        cout<<"Please enter the message to cipher: ";
    }else{
        cout<<"Please enter the message to decipher: ";
    }
    message_Morce_Code = "";
    while (message_Morce_Code.empty()){
        getline(cin,message_Morce_Code);
    }
    transform(message_Morce_Code.begin(),message_Morce_Code.end(),message_Morce_Code.begin(),::toupper);
}

void take_choice_Morce_Code(){
    cout<<"What do you want to do today?\n";
    cout<<"1- Cipher \n";
    cout<<"2- Decipher \n";
    cout<<"3- End \n";
    cin>>user_choice_Morce_Code;
    while (user_choice_Morce_Code>3 || user_choice_Morce_Code<1){
        cout<<"Enter correct number/\n";
        take_choice_Morce_Code();
    }
}

bool check_cipher_Morce_Code(){
    bool check = true;
    for (int i = 0; i < message_Morce_Code.size(); ++i) {
        if(message_Morce_Code[i] == ' '){
            continue;
        }
        if(message_Morce_Code[i] < 65 || message_Morce_Code[i] > 90){
            cout<<"Enter correct message.\n";
            check = false;
            break;
        }
    }
    return check;
}

bool check_decipher_Morce_Code(){
    bool check = true;
    for (int i = 0; i < message_Morce_Code.size(); ++i) {
        if(message_Morce_Code[i] != ' ' && message_Morce_Code[i] != '.' && message_Morce_Code[i] != '-'){
            cout<<"Enter correct message.\n";
            check = false;
            break;
        }
    }
    return check;
}

void cipher_Morce_Code(){
    cipher_string_Morce_Code = "";
    for (int i = 0; i < message_Morce_Code.size(); ++i) {
        if(message_Morce_Code[i] == ' '){
            cipher_string_Morce_Code.push_back(message_Morce_Code[i]);
            continue;
        }
        cipher_string_Morce_Code += morse_code[message_Morce_Code[i]-'A'];
        cipher_string_Morce_Code.push_back(' ');
    }
    cout << "Ciphered message: " << cipher_string_Morce_Code << '\n';
}

void decipher_Morce_Code(){
    decipher_string_Morce_Code = "";
    string tmp="";
    for (int i = 0; i <= message_Morce_Code.size(); ++i) {
        if(message_Morce_Code[i]==' ' || i == message_Morce_Code.size()){
            if(message_Morce_Code[i-1]==' '){
                decipher_string_Morce_Code.push_back(' ');
            }
            if(tmp.size()){
                int x = find(morse_code.begin(),morse_code.end(),tmp) - morse_code.begin();
                decipher_string_Morce_Code.push_back(x+'A');
            }
            tmp="";
        }else{
            tmp+=message_Morce_Code[i];
        }
    }
    cout << "Deciphered message: " << decipher_string_Morce_Code << '\n';
}

void start_Morce_code(){
    take_choice_Morce_Code();
    if(user_choice_Morce_Code==3){
        return;
    }
    take_message_Morce_Code();
    if(user_choice_Morce_Code==1){
        if(!check_cipher_Morce_Code()){
            start_Morce_code();
        }
        cipher_Morce_Code();
    }else{
        if(!check_decipher_Morce_Code()){
            start_Morce_code();
        }
        decipher_Morce_Code();
    }
    start_Morce_code();
}

#endif //CIPHERANDDECIPHER_LIBRARY_H
