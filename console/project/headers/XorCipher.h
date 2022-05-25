#include <bits/stdc++.h>
using namespace std;
#ifndef XorCipher_LIBRARY_H
#define XorCipher_LIBRARY_H

char secret_key_XorCipher;
int user_choice_XorCipher;
string message_XorCipher;

void take_secret_key_XorCipher(){
    cout<<"Enter secret Key: ";
    cin>>secret_key_XorCipher;
}

 void take_message_XorCipher(){
     if(user_choice_XorCipher == 1){
         cout<<"Please enter the message to cipher: ";
     }else{
         cout<<"Please enter the message to decipher: ";
     }
     message_XorCipher = "";
     while (message_XorCipher.empty()){
         getline(cin,message_XorCipher);
     }
 }

 void take_choice_XorCipher(){
     cout<<"What do you want to do today?\n";
     cout<<"1- Cipher \n";
     cout<<"2- Decipher \n";
     cout<<"3- End \n";
     cin>>user_choice_XorCipher;
     while (user_choice_XorCipher>3 || user_choice_XorCipher<1){
         cout<<"Enter correct number/\n";
         take_choice_XorCipher();
     }
 }

 void cipher_XorCipher(){
     transform(message_XorCipher.begin(),message_XorCipher.end(),message_XorCipher.begin(),::toupper);
     string tmp=message_XorCipher;
     for (int i = 0; i < message_XorCipher.size(); ++i) {
         if(message_XorCipher[i] == ' '){
             continue;
         }
         message_XorCipher[i] = char((secret_key_XorCipher ^ message_XorCipher[i])-1+'A');
     }
     cout << "Ciphered message: " << message_XorCipher << '\n';
     message_XorCipher = tmp;
     tmp = "";
     for (int i = 0; i < message_XorCipher.size(); ++i) {
         if(message_XorCipher[i] == ' '){
             continue;
         }
         ostringstream to_hex;
         to_hex<<hex<<stoi(to_string(message_XorCipher[i]));
         tmp+= to_hex.str();
     }
     cout<<"Hexa message: "<<tmp<<'\n';
 }

 void decipher_XorCipher(){
     for (int i = 0; i < message_XorCipher.size(); ++i) {
         if(message_XorCipher[i] == ' '){
             continue;
         }
         message_XorCipher[i] = char((secret_key_XorCipher ^ message_XorCipher[i])-1+'A');
     }
     cout << "Deciphered message: " << message_XorCipher << '\n';
 }

 void start_Xor_cipher(){
     take_choice_XorCipher();
     if(user_choice_XorCipher==3){
         return;
     }
     take_secret_key_XorCipher();
     take_message_XorCipher();
     if(user_choice_XorCipher==1){
         cipher_XorCipher();
     }else{
         decipher_XorCipher();
     }
     start_Xor_cipher();
 }

#endif //CIPHERANDDECIPHER_LIBRARY_H
