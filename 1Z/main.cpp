#include <iostream>
#include <cctype>
#include  "modAlphaCipher.h"
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {//Чтобы программа не завершалась на обработке исключений вставим обработку исключений
 wstring cipherText;
 wstring decryptedText;
 modAlphaCipher cipher(key);
 cipherText = cipher.encrypt(Text);
        if (destructCipherText)
 cipherText.front() = towlower(cipherText.front());
 decryptedText = cipher.decrypt(cipherText);
 wcout<<L"key="<<key<<endl;
 wcout<<Text<<endl;
 wcout<<cipherText<<endl;
 wcout<<decryptedText<<endl;
 } catch (const cipher_error & e) {
 wcerr<<"Error:  "<<e.what()<<endl;
    }
    
}

int main()
{
 locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"СЛОВО",L"КЛЮЧИК");
    check(L"ТОЖЕСЛОВО",L"");
    check(L"ОПЯТЬСЛОВО",L"КЛЮЧИК1234567");
    check(L"КАКИЕ-ТО СЛОВА С ПРОБЕЛАМИ",L"КЛЮЧИК");
    check(L"123",L"КЛЮЧИК");
}
