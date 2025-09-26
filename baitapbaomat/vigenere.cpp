#include <bits/stdc++.h>
using namespace std;

// chuẩn hóa khóa: lặp lại cho đủ độ dài plaintext
string generateKey(string text, string key) {
    int x = text.size();
    for (int i = 0; ; i++) {
        if (x == (int)key.size())
            break;
        key.push_back(key[i % key.size()]);
    }
    return key;
}

string encryptVigenere(string text, string key) {
    string cipher = "";
    for (int i = 0; i < (int)text.size(); i++) {
        char c = ((text[i] - 'A') + (key[i] - 'A')) % 26 + 'A';
        cipher.push_back(c);
    }
    return cipher;
}

string decryptVigenere(string cipher, string key) {
    string orig = "";
    for (int i = 0; i < (int)cipher.size(); i++) {
        char c = ((cipher[i] - 'A') - (key[i] - 'A') + 26) % 26 + 'A';
        orig.push_back(c);
    }
    return orig;
}

int main() {
    string plaintext, keyword;
    cout << "=== Vigenere Cipher ===\n";
    cout << "Nhap plaintext (chu hoa, khong dau): ";
    cin >> plaintext;
    cout << "Nhap khoa (chu hoa, khong dau): ";
    cin >> keyword;

    string key = generateKey(plaintext, keyword);
    string encrypted = encryptVigenere(plaintext, key);
    string decrypted = decryptVigenere(encrypted, key);

    cout << "\n--- Ket qua ---\n";
    cout << "Ma hoa: " << encrypted << "\n";
    cout << "Giai ma: " << decrypted << "\n";
    return 0;
}
