#include <bits/stdc++.h>
using namespace std;
#ifndef VignereCipher_LIBRARY_H
#define VignereCipher_LIBRARY_H

string message_VignereCipher,keyword_VignereCipher;
int user_choice_VignereCipher,keyword_pointer_VignereCipher;

void take_letter_VignereCipher(){
    if(user_choice_VignereCipher == 1){
        cout<<"Please enter the message to cipher: ";
    }else{
        cout<<"Please enter the message to decipher: ";
    }
    message_VignereCipher = "";
    while (message_VignereCipher.empty()){
        getline(cin,message_VignereCipher);
    }
    transform(message_VignereCipher.begin(),message_VignereCipher.end(),message_VignereCipher.begin(),::toupper);
    while (message_VignereCipher.size()>80){
        cout<<"Your letter should be at most 80 characters.\n";
        take_letter_VignereCipher();
    }
}

void take_keyword_VignereCipher(){
    cout<<"Enter the keyword: ";
    cin>>keyword_VignereCipher;
    transform(keyword_VignereCipher.begin(),keyword_VignereCipher.end(),keyword_VignereCipher.begin(),::toupper);
    while (keyword_VignereCipher.size()>8){
        cout<<"the keyword should be at most 8 characters.\n";
        take_keyword_VignereCipher();
    }
}

void take_choice_VignereCipher(){
    cout<<"What do you want to do today?\n";
    cout<<"1- Cipher \n";
    cout<<"2- Decipher \n";
    cout<<"3- End \n";
    cin>>user_choice_VignereCipher;
    while (user_choice_VignereCipher>3 || user_choice_VignereCipher<1){
        cout<<"Enter correct number/\n";
        take_choice_VignereCipher();
    }
}

char cipher_character_VignereCipher(char c_letter,char c_keyword){
    return char((c_keyword + c_letter)%26 + 'A');
}

char decipher_character_VignereCipher(char c_letter,char c_keyword){
    return char((c_letter-c_keyword+26)%26 + 'A');
}

void cipher_VignereCipher(){
    keyword_pointer_VignereCipher = 0;
    for(int i = 0;i < message_VignereCipher.size();++i){
        if(message_VignereCipher[i]!=' ' && (message_VignereCipher[i] >=65 && message_VignereCipher[i] <= 90)){
            message_VignereCipher[i] = cipher_character_VignereCipher(message_VignereCipher[i],keyword_VignereCipher[keyword_pointer_VignereCipher%5]);
        }
        keyword_pointer_VignereCipher++;
    }
    cout << "Ciphered message: " << message_VignereCipher << '\n';
}

void decipher_VignereCipher(){
    keyword_pointer_VignereCipher = 0;
    for(int i = 0;i < message_VignereCipher.size();++i){
        if(message_VignereCipher[i]!=' ' && (message_VignereCipher[i] >=65 && message_VignereCipher[i] <= 90)){
            message_VignereCipher[i] = decipher_character_VignereCipher(message_VignereCipher[i],keyword_VignereCipher[keyword_pointer_VignereCipher%5]);
        }
        keyword_pointer_VignereCipher++;
    }
    cout << "Deciphered message: " << message_VignereCipher << '\n';
}

void start_Vignere_cipher(){
    take_choice_VignereCipher();
    if(user_choice_VignereCipher==3){
        return;
    }
    take_letter_VignereCipher();
    take_keyword_VignereCipher();
    if(user_choice_VignereCipher==1){
        cipher_VignereCipher();
    }else{
        decipher_VignereCipher();
    }
    start_Vignere_cipher();
}

#endif //CIPHERANDDECIPHER_LIBRARY_H
