#include <bits/stdc++.h>
using namespace std;
#ifndef SimpleSubstitutionCipher_LIBRARY_H
#define SimpleSubstitutionCipher_LIBRARY_H

vector<bool>taken_alphabets_SimpleSubstitutionCipher;
vector<int>alphabetic_map_SimpleSubstitutionCipher;
string message_SimpleSubstitutionCipher="",keyword_SimpleSubstitutionCipher;
int user_choice_SimpleSubstitutionCipher;

void take_message_SimpleSubstitutionCipher(){
    if(user_choice_SimpleSubstitutionCipher == 1){
        cout<<"Please enter the message to cipher: ";
    }else{
        cout<<"Please enter the message to decipher: ";
    }
    message_SimpleSubstitutionCipher = "";
    while (message_SimpleSubstitutionCipher.empty()){
        getline(cin,message_SimpleSubstitutionCipher);
    }
    transform(message_SimpleSubstitutionCipher.begin(),message_SimpleSubstitutionCipher.end(),message_SimpleSubstitutionCipher.begin(),::toupper);
}

void take_keyword_SimpleSubstitutionCipher(){
    cout<<"Enter your keyword: ";
    cin>>keyword_SimpleSubstitutionCipher;
    transform(keyword_SimpleSubstitutionCipher.begin(),keyword_SimpleSubstitutionCipher.end(),keyword_SimpleSubstitutionCipher.begin(),::toupper);
    while (keyword_SimpleSubstitutionCipher.size()!=5){
        cout<<"Size of keyword should be 5.\n";
        take_keyword_SimpleSubstitutionCipher();
        return;
    }
    for(auto i : keyword_SimpleSubstitutionCipher){
        if(i<65 || i>90){
            cout<<"Please enter only alphabetic characters.\n";
            take_keyword_SimpleSubstitutionCipher();
            return;
        }
    }
}

void create_alphabetic_map_SimpleSubstitutionCipher(){
    taken_alphabets_SimpleSubstitutionCipher.clear();
    taken_alphabets_SimpleSubstitutionCipher.resize(26);
    alphabetic_map_SimpleSubstitutionCipher.clear();
    alphabetic_map_SimpleSubstitutionCipher.resize(26);
    int i = 0;
    for (; i < 5; ++i) {
        taken_alphabets_SimpleSubstitutionCipher[keyword_SimpleSubstitutionCipher[i]-'A'] = true;
        alphabetic_map_SimpleSubstitutionCipher[i]= keyword_SimpleSubstitutionCipher[i] - 'A';
    }
    for(int j = 0; j < 26; ++j){
        if(!taken_alphabets_SimpleSubstitutionCipher[j]) {
            alphabetic_map_SimpleSubstitutionCipher[i] = j;
            i++;
        }
    }
}

void take_choice_SimpleSubstitutionCipher(){
    cout<<"What do you want to do today?\n";
    cout<<"1- Cipher \n";
    cout<<"2- Decipher \n";
    cout<<"3- End \n";
    cin>>user_choice_SimpleSubstitutionCipher;
    while (user_choice_SimpleSubstitutionCipher>3 || user_choice_SimpleSubstitutionCipher<1){
        cout<<"Enter correct number/\n";
        take_choice_SimpleSubstitutionCipher();
    }
}

void cipher_SimpleSubstitutionCipher(){
    for (int i = 0; i < message_SimpleSubstitutionCipher.size(); ++i) {
        if(message_SimpleSubstitutionCipher[i] >= 65 && message_SimpleSubstitutionCipher[i] <= 90) {
            message_SimpleSubstitutionCipher[i] = char(alphabetic_map_SimpleSubstitutionCipher[message_SimpleSubstitutionCipher[i] - 'A'] + 'A');
        }
    }
    cout << "Ciphered message: " << message_SimpleSubstitutionCipher << '\n';
}

void decipher_SimpleSubstitutionCipher(){
    for (int i = 0; i < message_SimpleSubstitutionCipher.size(); ++i) {
        if(message_SimpleSubstitutionCipher[i] >= 65 && message_SimpleSubstitutionCipher[i] <= 90) {
            auto tmp = find(alphabetic_map_SimpleSubstitutionCipher.begin(), alphabetic_map_SimpleSubstitutionCipher.end(), message_SimpleSubstitutionCipher[i]-'A') - alphabetic_map_SimpleSubstitutionCipher.begin();
            message_SimpleSubstitutionCipher[i] = char(tmp+'A');
        }
    }
    cout << "Deciphered message: " << message_SimpleSubstitutionCipher << '\n';
}

void start_Simple_Substitution_cipher(){
    take_choice_SimpleSubstitutionCipher();
    if(user_choice_SimpleSubstitutionCipher==3){
        return;
    }
    take_message_SimpleSubstitutionCipher();
    take_keyword_SimpleSubstitutionCipher();
    create_alphabetic_map_SimpleSubstitutionCipher();
    if(user_choice_SimpleSubstitutionCipher==1){
        cipher_SimpleSubstitutionCipher();
    }else{
        decipher_SimpleSubstitutionCipher();
    }
    start_Simple_Substitution_cipher();
}

#endif //CIPHERANDDECIPHER_LIBRARY_H
