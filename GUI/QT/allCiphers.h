#ifndef ALLCIPHERS_H
#define ALLCIPHERS_H
#include <string>
int affine_cipher_equation(int a, int b, char tmp);
int affine_decipher_equation(int b,int c, char tmp);
void affine_cipher(int a, int b, std::string& text);
void affine_decipher(int b,int c, std::string& text);
void atbash(std::string& text);

std::string binary_to_string_BaconianCipher(int num);
char string_to_binary_BaconianCipher(std::string tmp);
void create_cipher_characters_BaconianCipher();
void baconianCipher(std::string& text);
void baconianDecipher(std::string& text);

void morceCodeCipher(std::string& text);
void morceCodeDecipher(std::string& text)
;
void polybiusSquareCipher(std::string& text, std::string& key);
void polybiusSquareDecipher(std::string& text, std::string& key);

void railFenceCipher(std::string& text, int& key);
void railFenceDecipher(std::string& text, int& key);

void create_alphabetic_map_SimpleSubstitutionCipher(std::string& key);
void simpleSubstitutionCipher(std::string& text, std::string& key);
void simpleSubstitutionDecipher(std::string& text, std::string& key);

char cipher_character_VignereCipher(char c_letter,char c_keyword);
char decipher_character_VignereCipher(char c_letter,char c_keyword);
void vignereCipher(std::string& text, std::string& key);
void vignereDecipher(std::string& text, std::string& key);

void xorCipher(std::string& text, char& key);
void xorDecipher(std::string& text, char& key);

void caesarCipher(std::string& text, int& n_shifts);
void caesarDecipher(std::string& text, int& n_shifts);
#endif // ALLCIPHERS_H
