
#include <bits/stdc++.h>
using namespace std;

string sanitize(const string &s) {
    string t;
    for(char c: s) if(isalpha((unsigned char)c)) t += toupper(c);
    return t;
}

string caesar_encrypt(const string &plain, int shift) {
    string p = sanitize(plain), out;
    for(char c: p) out += char('A' + (c - 'A' + shift) % 26);
    return out;
}

string caesar_decrypt(const string &cipher, int shift) {
    string c = sanitize(cipher), out;
    for(char ch: c) out += char('A' + (ch - 'A' - shift + 26) % 26);
    return out;
}

int main(){
    string text; cout<<"Plain: "; getline(cin, text);
    int s; cout<<"Shift (0-25): "; cin>>s;
    cout<<"Cipher: "<<caesar_encrypt(text, s)<<"\n";
    cout<<"Decrypt: "<<caesar_decrypt(caesar_encrypt(text,s), s)<<"\n";
}
