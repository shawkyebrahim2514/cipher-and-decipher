#include <bits/stdc++.h>
using namespace std;
#ifndef CaesarCipher_LIBRARY_H
#define CaesarCipher_LIBRARY_H

string message_CaesarCipher;
int number_of_shifts_CaesarCipher,user_choice_CaesarCipher;
void take_input_CaesarCipher(){
    if(user_choice_CaesarCipher == 1){
        cout<<"Please enter the message to cipher: ";
    }else{
        cout<<"Please enter the message to decipher: ";
    }
    message_CaesarCipher = "";
    while (message_CaesarCipher.empty()){
        getline(cin,message_CaesarCipher);
    }
    transform(message_CaesarCipher.begin(),message_CaesarCipher.end(),message_CaesarCipher.begin(),::toupper);
    cout<<"Enter number of shifts: ";
    cin>>number_of_shifts_CaesarCipher;
}

void take_choice_CaesarCipher(){
    cout<<"What do you want to do today?\n";
    cout<<"1- Cipher \n";
    cout<<"2- Decipher \n";
    cout<<"3- End \n";
    cin>>user_choice_CaesarCipher;
    while (user_choice_CaesarCipher>3 || user_choice_CaesarCipher<1){
        cout<<"Enter correct number/\n";
        take_choice_CaesarCipher();
    }
}

void cipher_CaesarCipher(){
    for (int i = 0; i <  message_CaesarCipher.size(); ++i) {
        if(message_CaesarCipher[i] < 65 || message_CaesarCipher[i] > 90){
            continue;
        }
        message_CaesarCipher[i] = char(((message_CaesarCipher[i] - 'A' + number_of_shifts_CaesarCipher + 26)%26)+'A');
    }
    cout << "Ciphered message: " << message_CaesarCipher << '\n';
}

void decipher_CaesarCipher(){
    for (int i = 0; i < message_CaesarCipher.size(); ++i) {
        if(message_CaesarCipher[i] < 65 || message_CaesarCipher[i] > 90){
            continue;
        }
        message_CaesarCipher[i] = char(((message_CaesarCipher[i] - 'A' - number_of_shifts_CaesarCipher + 26)%26)+'A');
    }
    cout << "Deciphered message: " << message_CaesarCipher << '\n';
}

void start_Caesar_cipher(){
    take_choice_CaesarCipher();
    if(user_choice_CaesarCipher==3){
        return;
    }
    take_input_CaesarCipher();
    if(user_choice_CaesarCipher==1){
        cipher_CaesarCipher();
    }else{
        decipher_CaesarCipher();
    }
    start_Caesar_cipher();
}

#endif //CaesarCipher_LIBRARY_H
