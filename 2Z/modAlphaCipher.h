//modAlphaCipher.h
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <algorithm>
using namespace std;

class modAlphaCipher
{
private:
    int key;
    string getValidText(const std::string & s);
public:
    modAlphaCipher()=delete;
    modAlphaCipher(const int& newkey) :key(newkey) {};   // конструктор
    string coder(const string& open_st);   // зашифрование
    string decoder(const string& cipher_st); // расшифрование
};
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
