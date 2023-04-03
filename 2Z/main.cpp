#include "modAlphaCipher.h"

void check(const string& Text, const string& key)
{
    try {
        string cipherText;
        string decryptedText;
        if (key.empty())
            throw cipher_error("Empty key");
        if (stoi(key) > 0) {
            modAlphaCipher cipher(stoi(key));
            cipherText = cipher.coder(Text);
            decryptedText = cipher.decoder(cipherText);
            cout<<"key="<<key<<endl;
            cout<<"Encrypted text: "<<cipherText<<endl;
            cout<<"Decrypted text: "<<decryptedText<<endl;
        } else
            throw cipher_error(std::string("Invalid key ")+key);
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
    cout<<""<<endl;
}

int main(int argc, char **argv)
{
    check("HELLO","0");
    check("HELLO","");
    check("HELLO","19");
    check("9876234321","19");
}
