#include <bits/stdc++.h>
using namespace std;
#ifndef BaconianCipher_LIBRARY_H
#define BaconianCipher_LIBRARY_H

int user_choice_BaconianCipher;
string message_BaconianCipher;
vector<string>encoded_characters_BaconianCipher(26);

string binary_to_string_BaconianCipher(int num){
    // this function convert each alphabetic characters to cipher message and store it in its array
    string tmp = "AAAAA";
    int cnt=4;
    while (num>0){
        if(num&1) tmp[cnt]='B';
        num=(num>>1);
        cnt--;
    }
    return tmp;
}

char string_to_binary_BaconianCipher(string tmp){
    // this function convert each (5)character to a binary number that present an alphabetic order and then covert this number to the equivalent character
    int letter_index = find(encoded_characters_BaconianCipher.begin(),encoded_characters_BaconianCipher.end(),tmp) - encoded_characters_BaconianCipher.begin();
    return char(letter_index + 'A');
}

void create_cipher_characters_BaconianCipher(){
    // this function fill encoded_characters array with each cipher character
    for (int i = 0; i <= 25; ++i) {
        // change each character to cipher message with binary_to_string function
        encoded_characters_BaconianCipher[i]= binary_to_string_BaconianCipher(i);
    }
}

bool check_alphabets_BaconianCipher(){
    // check user message to only have an uppercase alphabet characters
    bool check = false;
    for (int i = 0; i < message_BaconianCipher.size(); ++i) {
        if(message_BaconianCipher[i] == ' '){
            continue;
        }
        if(message_BaconianCipher[i] < 65 || message_BaconianCipher[i] > 90) {
            // check = true when the message not only contain an uppercase alphabet characters
            check = true;
            break;
        }
    }
    return check;
}

void take_input_BaconianCipher(){
    // take user message
    if(user_choice_BaconianCipher == 1){
        cout<<"Please enter the message to cipher: ";
    }else{
        cout<<"Please enter the message to decipher: ";
    }
    message_BaconianCipher = "";
    while (message_BaconianCipher.empty()){
        getline(cin,message_BaconianCipher);
    }
    transform(message_BaconianCipher.begin(), message_BaconianCipher.end(), message_BaconianCipher.begin(), ::toupper);
}

void take_choice_BaconianCipher(){
    // print all user choices
    cout<<"What do you want to do today?\n";
    cout<<"1- Cipher \n";
    cout<<"2- Decipher \n";
    cout<<"3- End \n";
    cin>>user_choice_BaconianCipher;
}

void cipher_BaconianCipher(){
    // this function cipher a user message
    string  result="";
    for (int i = 0; i < message_BaconianCipher.size(); ++i) {
        if(message_BaconianCipher[i] == ' '){
            result.push_back(' ');
            continue;
        }
        // append a cipher character in the result string that stored in encoded_characters array
        result += encoded_characters_BaconianCipher[message_BaconianCipher[i] - 'A'];
    }
    cout << "Ciphered message: " << result << '\n';
}

void decipher_BaconianCipher(){
    // check if the message size can be deciphering or not (the size of the message should be divisible be 5)
    int cnt = 0;
    for(auto i : message_BaconianCipher){
        if(i>=65 && i <=90){
            cnt++;
        }
    }
    if(cnt % 5){
        cout<<"Please enter correct message!\n";
        take_input_BaconianCipher();
    }
    // decipher each (5)characters to an alphabetic character
    string tmp = "",result = "";
    for (int i = 0; i < message_BaconianCipher.size(); ++i) {
        if(tmp.size()==5){
            result += string_to_binary_BaconianCipher(tmp);
            tmp = "";
        }
        if(message_BaconianCipher[i] == ' '){
            result.push_back(' ');
            continue;
        }
        tmp+=message_BaconianCipher[i];
    }
    result += string_to_binary_BaconianCipher(tmp);
    cout << "Deciphered message: " << result << '\n';
}

void start_Baconian_cipher(){
    // show user choices to enter one of them
    take_choice_BaconianCipher();
    // check if user want to end
    if(user_choice_BaconianCipher==3){
        return;
    }
    // take user message
    take_input_BaconianCipher();
    // checking message validation
    if (check_alphabets_BaconianCipher()){
        cout<<"Enter correct message (only alphabetic characters)\n";
        take_input_BaconianCipher();
        return;
    }
    // use cipher or decipher function
    if(user_choice_BaconianCipher==1){
        cipher_BaconianCipher();
    }else{
        decipher_BaconianCipher();
    }
    // recall the programme (because user do not want to exit until now)
    start_Baconian_cipher();
}

#endif //CIPHERANDDECIPHER_LIBRARY_H
