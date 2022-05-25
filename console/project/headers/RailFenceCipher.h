#include <bits/stdc++.h>
using namespace std;
#ifndef RailFenceCipher_LIBRARY_H
#define RailFenceCipher_LIBRARY_H

string message_RailFenceCipher;
int key_RailFenceCipher,user_choice_RailFenceCipher;
vector<vector<char>>result_RailFenceCipher;

void take_message_RailFenceCipher(){
    if(user_choice_RailFenceCipher == 1){
        cout<<"Please enter the message to cipher: ";
    }else{
        cout<<"Please enter the message to decipher: ";
    }
    message_RailFenceCipher = "";
    while (message_RailFenceCipher.empty()){
        getline(cin,message_RailFenceCipher);
    }
    message_RailFenceCipher.erase(remove(message_RailFenceCipher.begin(), message_RailFenceCipher.end(), ' '),message_RailFenceCipher.end());
    transform(message_RailFenceCipher.begin(),message_RailFenceCipher.end(),message_RailFenceCipher.begin(),::tolower);
}

void take_key_RailFenceCipher(){
    cout<<"Enter Key: ";
    cin>>key_RailFenceCipher;
}

void take_choice_RailFenceCipher(){
    cout<<"What do you want to do today?\n";
    cout<<"1- Cipher \n";
    cout<<"2- Decipher \n";
    cout<<"3- End \n";
    cin>>user_choice_RailFenceCipher;
    while (user_choice_RailFenceCipher>3 || user_choice_RailFenceCipher<1){
        cout<<"Enter correct number/\n";
        take_choice_RailFenceCipher();
    }
}

void cipher_RailFenceCipher(){
    result_RailFenceCipher.clear();
    result_RailFenceCipher.resize(key_RailFenceCipher);
    string tmp="";
    bool check = true;
    int position = 0;
    for (int i = 0; i < message_RailFenceCipher.size(); ++i) {
        result_RailFenceCipher[position].push_back(message_RailFenceCipher[i]);
        if(check) position++;
        else position--;
        if(!position || position==(key_RailFenceCipher-1)){
            check=!check;
        }
    }
    for (int i = 0; i < key_RailFenceCipher; ++i) {
        for(auto j : result_RailFenceCipher[i]){
            tmp.push_back(j);
        }
    }
    cout << "Ciphered message: " << tmp << '\n';
}

void decipher_RailFenceCipher(){
    result_RailFenceCipher.clear();
    result_RailFenceCipher.resize(key_RailFenceCipher,vector<char>(message_RailFenceCipher.size(),'.'));
    string tmp=message_RailFenceCipher;
    bool check = true;
    int position = 0;
    for (int i = 0; i < message_RailFenceCipher.size(); ++i) {
        result_RailFenceCipher[position][i]='-';
        if(check) position++;
        else position--;
        if(!position || position==(key_RailFenceCipher-1)){
            check=!check;
        }
    }
    position=0;
    for (int i = 0; i < key_RailFenceCipher; ++i) {
        for (int j = 0; j < message_RailFenceCipher.size(); ++j) {
            if(result_RailFenceCipher[i][j]=='-' && position < message_RailFenceCipher.size()){
                tmp[j] = message_RailFenceCipher[position];
                position++;
            }
        }
    }
    cout << "Deciphered message: " << tmp << '\n';
}

void start_Rail_Fence_cipher(){
    take_choice_RailFenceCipher();
    if(user_choice_RailFenceCipher==3){
        return;
    }
    take_message_RailFenceCipher();
    take_key_RailFenceCipher();
    if(user_choice_RailFenceCipher==1){
        cipher_RailFenceCipher();
    }else{
        decipher_RailFenceCipher();
    }
    start_Rail_Fence_cipher();
}

#endif //CIPHERANDDECIPHER_LIBRARY_H
