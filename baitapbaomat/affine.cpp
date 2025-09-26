#include <iostream>
#include <string>
using namespace std;

// Tìm nghịch đảo modular của a mod m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // không tồn tại
}

// Hàm mã hóa Affine
string encryptAffine(const string& text, int a, int b) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            result += (char)(((a * (c - base) + b) % 26) + base);
        } else {
            result += c;
        }
    }
    return result;
}

// Hàm giải mã Affine
string decryptAffine(const string& cipher, int a, int b) {
    string result = "";
    int a_inv = modInverse(a, 26);
    for (char c : cipher) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int dec = a_inv * ((c - base) - b + 26);
            dec = (dec % 26 + 26) % 26;
            result += (char)(dec + base);
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text;
    int a, b;

    cout << "Nhap van ban: ";
    getline(cin, text);

    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;

    string cipher = encryptAffine(text, a, b);
    string decrypted = decryptAffine(cipher, a, b);

    cout << "Ma hoa: " << cipher << endl;
    cout << "Ma giai: " << decrypted << endl;

    return 0;
}
