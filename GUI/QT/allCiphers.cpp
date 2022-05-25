#include <bits/stdc++.h>
#include "allCiphers.h"
using namespace std;
vector<string>encoded_characters_BaconianCipher(26);
vector<string>morse_code{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
vector<vector<char>>result_RailFenceCipher;
vector<bool>taken_alphabets_SimpleSubstitutionCipher;
vector<int>alphabetic_map_SimpleSubstitutionCipher;


int affine_cipher_equation(int a, int b, char tmp){
    return (a*(tmp-'A')+b)%26;
}

int affine_decipher_equation(int b,int c, char tmp){
    return c*((tmp-'A') -b +26)%26;
}

void affine_cipher(int a, int b, string& text){
    for (int i = 0; i < (int)text.size(); ++i) {
        if(text[i] < 65 || text[i] > 90){
            continue;
        }
        text[i]= char(affine_cipher_equation(a,b,text[i])+'A');
    }
}

void affine_decipher(int b,int c, string& text){
    for (int i = 0; i < (int)text.size(); ++i) {
        if(text[i] < 65 || text[i] > 90){
            continue;
        }
        text[i] = char(affine_decipher_equation(b,c,text[i])+'A');
    }
}


void atbash(string& text){
    for (int i = 0; i < (int)text.size(); ++i) {
        if(text[i] < 65 || text[i] > 90){
            continue;
        }
        text[i] =  char(25 - (text[i] -'A') +'A');
    }
}


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

void baconianCipher(string& text){
    create_cipher_characters_BaconianCipher();
    // this function cipher a user message
    string  result="";
    for (int i = 0; i < (int)text.size(); ++i) {
        if(text[i] == ' '){
            result.push_back(' ');
            continue;
        }
        // append a cipher character in the result string that stored in encoded_characters array
        result += encoded_characters_BaconianCipher[text[i] - 'A'];
    }
    text = result;
}

void baconianDecipher(string& text){
    create_cipher_characters_BaconianCipher();
    // decipher each (5)characters to an alphabetic character
    string tmp = "",result = "";
    for (int i = 0; i < (int)text.size(); ++i) {
        if(tmp.size()==5){
            result += string_to_binary_BaconianCipher(tmp);
            tmp = "";
        }
        if(text[i] == ' '){
            result.push_back(' ');
            continue;
        }
        tmp+=text[i];
    }
    result += string_to_binary_BaconianCipher(tmp);
    text = result;
}


void morceCodeCipher(string& text){
    string tmp = "";
    for (int i = 0; i < (int)text.size(); ++i) {
        if(text[i] == ' '){
            tmp.push_back(text[i]);
            continue;
        }
        tmp += morse_code[text[i]-'A'];
        tmp.push_back(' ');
    }
    text = tmp;
}

void morceCodeDecipher(string& text)
{
    string result = "";
    string tar="";
    for (int i = 0; i <= (int)text.size(); ++i) {
        if(text[i]==' ' || i == (int)text.size()){
            if(text[i-1]==' '){
                result.push_back(' ');
            }
            if(tar.size()){
                int x = find(morse_code.begin(),morse_code.end(),tar) - morse_code.begin();
                result.push_back(x+'A');
            }
            tar="";
        }else{
            tar+=text[i];
        }
    }
    text = result;
}

void polybiusSquareCipher(string& text, string& key){
    int tmp_pointer;
    string result = "";
    for(auto i : text){
        if(i>=65 && i<= 90){
            tmp_pointer= (i - 'A'  -(i-'A'>=9));
            result.push_back(char(key[tmp_pointer/5]));
            result.push_back(char(key[tmp_pointer%5]));
        }else{
            result.push_back(i);
        }
    }
    text = result;
}

void polybiusSquareDecipher(string& text, string& key){
    string result = "";
    string tmp_string = "";
    int tmp_ascii;
    for (int i = 0; i <= (int)text.size(); ++i) {
        if(tmp_string.size() == 2){
            int x = find(key.begin(),key.end(),tmp_string[0]) - key.begin();
            int y = (find(key.begin(),key.end(),tmp_string[1]) - key.begin());
            tmp_ascii = x*5 + y +1;
            tmp_ascii += (tmp_ascii>=10);
            result.push_back(tmp_ascii-1 + 'A');
            tmp_string="";
        }
        if(i == (int)text.size()){
            break;
        }
        if(text[i]<48 || text[i]>57){
            result.push_back(text[i]);
            continue;
        }
        tmp_string += text[i];
    }
    text = result;
}


void railFenceCipher(string& text, int& key){
    text.erase(remove(text.begin(),text.end(),' '), text.end());
    result_RailFenceCipher.clear();
    result_RailFenceCipher.resize(key);
    string tmp="";
    bool check = true;
    int position = 0;
    for (int i = 0; i < (int)text.size(); ++i) {
        result_RailFenceCipher[position].push_back(text[i]);
        if(check) position++;
        else position--;
        if(!position || position==(key-1)){
            check=!check;
        }
    }
    for (int i = 0; i < key; ++i) {
        for(auto j : result_RailFenceCipher[i]){
            tmp.push_back(j);
        }
    }
    text = tmp;
}

void railFenceDecipher(string& text, int& key){
    result_RailFenceCipher.clear();
    result_RailFenceCipher.resize(key,vector<char>(text.size(),'.'));
    string tmp = text;
    bool check = true;
    int position = 0;
    for (int i = 0; i < (int)text.size(); ++i) {
        result_RailFenceCipher[position][i]='-';
        if(check) position++;
        else position--;
        if(!position || position==(key-1)){
            check=!check;
        }
    }
    position=0;
    for (int i = 0; i < key; ++i) {
        for (int j = 0; j < (int)text.size(); ++j) {
            if(result_RailFenceCipher[i][j]=='-' && position < (int)text.size()){
                tmp[j] = text[position];
                position++;
            }
        }
    }
    text = tmp;
}


void create_alphabetic_map_SimpleSubstitutionCipher(string& key){
    transform(key.begin(),key.end(),key.begin(), ::toupper);
    taken_alphabets_SimpleSubstitutionCipher.clear();
    taken_alphabets_SimpleSubstitutionCipher.resize(26);
    alphabetic_map_SimpleSubstitutionCipher.clear();
    alphabetic_map_SimpleSubstitutionCipher.resize(26);
    int i = 0;
    for (; i < 5; ++i) {
        taken_alphabets_SimpleSubstitutionCipher[key[i]-'A'] = true;
        alphabetic_map_SimpleSubstitutionCipher[i]= key[i] - 'A';
    }
    for(int j = 0; j < 26; ++j){
        if(!taken_alphabets_SimpleSubstitutionCipher[j]) {
            alphabetic_map_SimpleSubstitutionCipher[i] = j;
            i++;
        }
    }
}

void simpleSubstitutionCipher(string& text, string& key){
    create_alphabetic_map_SimpleSubstitutionCipher(key);
    for (int i = 0; i < (int)text.size(); ++i) {
        if(text[i] >= 65 && text[i] <= 90) {
            text[i] = char(alphabetic_map_SimpleSubstitutionCipher[text[i] - 'A'] + 'A');
        }
    }
}

void simpleSubstitutionDecipher(string& text, string& key){
    create_alphabetic_map_SimpleSubstitutionCipher(key);
    for (int i = 0; i < (int)text.size(); ++i) {
        if(text[i] >= 65 && text[i] <= 90) {
            auto tmp = find(alphabetic_map_SimpleSubstitutionCipher.begin(), alphabetic_map_SimpleSubstitutionCipher.end(), text[i]-'A') - alphabetic_map_SimpleSubstitutionCipher.begin();
            text[i] = char(tmp+'A');
        }
    }
}


char cipher_character_VignereCipher(char c_letter,char c_keyword){
    return char((c_keyword + c_letter)%26 + 'A');
}

char decipher_character_VignereCipher(char c_letter,char c_keyword){
    return char((c_letter-c_keyword+26)%26 + 'A');
}

void vignereCipher(string& text, string& key){
    transform(key.begin(),key.end(),key.begin(), ::toupper);
    int pointer = 0;
    for(int i = 0;i < (int)text.size();++i){
        if(text[i]!=' ' && (text[i] >=65 && text[i] <= 90)){
            text[i] = cipher_character_VignereCipher(text[i],key[pointer%5]);
        }
        pointer++;
    }
}

void vignereDecipher(string& text, string& key){
    transform(key.begin(),key.end(),key.begin(), ::toupper);
    int pointer = 0;
    for(int i = 0;i < (int)text.size();++i){
        if(text[i]!=' ' && (text[i] >=65 && text[i] <= 90)){
            text[i] = decipher_character_VignereCipher(text[i],key[pointer%5]);
        }
        pointer++;
    }
}


void xorCipher(string& text, char& key){
    for (int i = 0; i < (int)text.size(); ++i) {
        if(text[i] == ' '){
            continue;
        }
        text[i] = char((key ^ text[i])-1+'A');
    }
}

void xorDecipher(string& text, char& key){
    for (int i = 0; i < (int)text.size(); ++i) {
        if(text[i] == ' '){
            continue;
        }
        text[i] = char((key ^ text[i])-1+'A');
    }
}


void caesarCipher(string& text, int& n_shifts){
    for (int i = 0; i <  (int)text.size(); ++i) {
        if(text[i] < 65 || text[i] > 90){
            continue;
        }
        text[i] = char(((text[i] - 'A' + n_shifts + 26)%26)+'A');
    }
}
void caesarDecipher(string& text, int& n_shifts){
    for (int i = 0; i < (int)text.size(); ++i) {
        if(text[i] < 65 || text[i] > 90){
            continue;
        }
        text[i] = char(((text[i] - 'A' - n_shifts + 26)%26)+'A');
    }
}
