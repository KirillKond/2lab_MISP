//modAlphaCipher.cpp
#include "modAlphaCipher.h"

string modAlphaCipher::decoder(const std::string& cipher_st) // РАСШИФРОВАНИЕ
{
    string s = getValidText(cipher_st);
    string n_s = s;
    int dlina, nstrok, position, a; // dlina-длина строки ; nstrok-количество строк ; position-новая позиция символа, который меняем ;
    dlina = s.size(); // st-строка с текстом, который вводится пользователем
    nstrok = (dlina - 1) / key + 1; // key-количество столбцов в таблице
    a = 0;
    for (int colum_number = key; colum_number > 0; colum_number--) { // colum_number-номер столбца
        for (int line_number = 0; line_number < nstrok; line_number++) { // line_number-номер строки
            position = key*line_number+colum_number; //
            if (position-1 < dlina) {
                n_s[position-1] = s[a];
                a++;
            }
        }
    }
    return n_s;
}
string modAlphaCipher::coder(const string& open_st) // ЗАШИФРОВАНИЕ
{
    string s = getValidText(open_st);
    string n_s = s;
    int dlina, nstrok, position, a; // dlina-длина строки ; nstrok-количество строк ; position-новая позиция символа, который меняем ;
    dlina = s.size(); // st-строка с текстом, который вводится пользователем
    nstrok = (dlina - 1) / key + 1; //key-количество столбцов в таблице
    a = 0;
    for (int colum_number = key; colum_number > 0; colum_number--) { // colum_number-номер столбца
        for (int line_number = 0; line_number < nstrok; line_number++) { // line_number-номер строки
            position = colum_number+key*line_number;
            if (position-1 < dlina) {
                n_s[a] = open_st[position-1];
                a++;
            }
        }
    }
    return n_s;
}

inline std::string modAlphaCipher::getValidText(const std::string & s)
{
    string tmp;
    for (auto c:s) {
        if (isalpha (c)) {
            if (islower (c))
                tmp.push_back(toupper(c));
                else
                    tmp.push_back(c);
    }
}
if (tmp.empty())
    throw cipher_error ("Empty open text");
    return tmp;
}
