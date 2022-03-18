#include <bits/stdc++.h>
#include "headers/AffineCipher.h"
#include "headers/CaesarCipher.h"
#include "headers/AtbashCipher.h"
#include "headers/VignereCipher.h"
#include "headers/BaconianCipher.h"
#include "headers/SimpleSubstitutionCipher.h"
#include "headers/PolybiusSquareCipher.h"
#include "headers/Morce_Code.h"
#include "headers/XorCipher.h"
#include "headers/RailFenceCipher.h"
using namespace std;

void choice_cipher(){
    int choice;
    cout << "Which ciphered and deciphered programme you want to start?\n";
    cout << "0- Affine Cipher\n";
    cout << "1- Caesar Cipher\n";
    cout << "2- Atbash Cipher\n";
    cout << "3- Vignere Cipher\n";
    cout << "4- Baconian Cipher\n";
    cout << "5- Simple Substitution Cipher\n";
    cout << "6- Polybius Square Cipher\n";
    cout << "7- Morse Code\n";
    cout << "8- XOR Cipher\n";
    cout << "9- Rail-fence Cipher\n";
    cin >> choice;
    while (choice<0 || choice>9){
        cout << "Enter correct choice.\n";
        cin >> choice;
    }
    switch (choice) {
            case 0:
                start_Affine_cipher();
                break;
            case 1:
                start_Caesar_cipher();
                break;
            case 2:
                start_Atbash_cipher();
                break;
            case 3:
                start_Vignere_cipher();
                break;
            case 4:
                create_cipher_characters_BaconianCipher();
                start_Baconian_cipher();
                break;
            case 5:
                start_Simple_Substitution_cipher();
                break;
            case 6:
                start_Polybius_Square_cipher();
                break;
            case 7:
                start_Morce_code();
                break;
            case 8:
                start_Xor_cipher();
                break;
            case 9:
                start_Rail_Fence_cipher();
                break;
    }
}

bool check_state(){
    bool check = true;
    int tmp;
    cout<<"What do you want to do else?\n";
    cout<<"1- Continue\n";
    cout<<"2- exit\n";
    cin>>tmp;
    while (tmp!=1 && tmp!=2){
        cout<<"Please enter correct choice.\n";
        check_state();
    }
    if(tmp == 2){
        check = false;
    }
    return check;
}

void start(){
    choice_cipher();
    if(check_state()){
        start();
    }
}

int main() {
    start();
}
