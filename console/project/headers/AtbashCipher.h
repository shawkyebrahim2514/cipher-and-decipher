#include <bits/stdc++.h>
using namespace std;
#ifndef AtbashCipher_LIBRARY_H
#define AtbashCipher_LIBRARY_H

string message_AtbashCipher;
int user_choice_AtbashCipher;
void take_input_AtbashCipher(){
    if(user_choice_AtbashCipher == 1){
        cout<<"Please enter the message to cipher: ";
    }else{
        cout<<"Please enter the message to decipher: ";
    }
    message_AtbashCipher = "";
    while (message_AtbashCipher.empty()){
        getline(cin,message_AtbashCipher);
    }
    transform(message_AtbashCipher.begin(),message_AtbashCipher.end(),message_AtbashCipher.begin(),::toupper);
}

void take_choice_AtbashCipher(){
    cout<<"What do you want to do today?\n";
    cout<<"1- Cipher \n";
    cout<<"2- Decipher \n";
    cout<<"3- End \n";
    cin>>user_choice_AtbashCipher;
    while (user_choice_AtbashCipher>3 || user_choice_AtbashCipher<1){
        cout<<"Enter correct number/\n";
        take_choice_AtbashCipher();
    }
}

void change_characters_AtbashCipher(){
    for (int i = 0; i < message_AtbashCipher.size(); ++i) {
        if(message_AtbashCipher[i] < 65 || message_AtbashCipher[i] > 90){
            continue;
        }
        message_AtbashCipher[i] =  char(25 - (message_AtbashCipher[i] -'A') +'A');
    }
    if(user_choice_AtbashCipher == 1){
        cout << "Ciphered message: " << message_AtbashCipher << '\n';
    }else{
        cout << "Deciphered message: " << message_AtbashCipher << '\n';
    }
}

void start_Atbash_cipher(){
    take_choice_AtbashCipher();
    if(user_choice_AtbashCipher==3){
        return;
    }
    take_input_AtbashCipher();
    change_characters_AtbashCipher();
    start_Atbash_cipher();
}

#endif
