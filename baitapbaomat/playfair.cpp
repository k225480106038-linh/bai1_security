#include <bits/stdc++.h>
using namespace std;

// Tạo ma trận 5x5 từ khóa
vector<char> createMatrix(string key) {
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // J gộp I
    vector<char> matrix;
    set<char> used;

    // Đưa key vào trước
    for (char &c : key) {
        if (c == 'J') c = 'I';
        if (isalpha(c)) {
            c = toupper(c);
            if (!used.count(c)) {
                matrix.push_back(c);
                used.insert(c);
            }
        }
    }
    // Thêm các chữ cái còn lại
    for (char c : alphabet) {
        if (!used.count(c)) {
            matrix.push_back(c);
            used.insert(c);
        }
    }
    return matrix;
}

// Chia plaintext thành cặp
string prepareText(string text) {
    string result;
    for (char &c : text) {
        if (isalpha(c)) {
            char up = toupper(c);
            if (up == 'J') up = 'I';
            result.push_back(up);
        }
    }
    string fixed;
    for (int i = 0; i < result.size(); i++) {
        fixed.push_back(result[i]);
        if (i < result.size() - 1 && result[i] == result[i+1]) {
            fixed.push_back('X');
        }
    }
    if (fixed.size() % 2 == 1) fixed.push_back('X');
    return fixed;
}

pair<int,int> findPos(vector<char>& matrix, char ch) {
    int idx = find(matrix.begin(), matrix.end(), ch) - matrix.begin();
    return {idx/5, idx%5};
}

string encryptPair(vector<char>& matrix, char a, char b) {
    auto [r1,c1] = findPos(matrix,a);
    auto [r2,c2] = findPos(matrix,b);
    if (r1 == r2) {
        return string(1, matrix[r1*5 + (c1+1)%5]) + matrix[r2*5 + (c2+1)%5];
    } else if (c1 == c2) {
        return string(1, matrix[((r1+1)%5)*5 + c1]) + matrix[((r2+1)%5)*5 + c2];
    } else {
        return string(1, matrix[r1*5 + c2]) + matrix[r2*5 + c1];
    }
}

string decryptPair(vector<char>& matrix, char a, char b) {
    auto [r1,c1] = findPos(matrix,a);
    auto [r2,c2] = findPos(matrix,b);
    if (r1 == r2) {
        return string(1, matrix[r1*5 + (c1+4)%5]) + matrix[r2*5 + (c2+4)%5];
    } else if (c1 == c2) {
        return string(1, matrix[((r1+4)%5)*5 + c1]) + matrix[((r2+4)%5)*5 + c2];
    } else {
        return string(1, matrix[r1*5 + c2]) + matrix[r2*5 + c1];
    }
}

string encryptPlayfair(string text, string key) {
    vector<char> matrix = createMatrix(key);
    string prep = prepareText(text);
    string res;
    for (int i=0; i<prep.size(); i+=2) {
        res += encryptPair(matrix, prep[i], prep[i+1]);
    }
    return res;
}

string decryptPlayfair(string text, string key) {
    vector<char> matrix = createMatrix(key);
    string res;
    for (int i=0; i<text.size(); i+=2) {
        res += decryptPair(matrix, text[i], text[i+1]);
    }
    return res;
}

int main() {
    cout << "=== Playfair Cipher ===\n";
    cout << "Nhap plaintext (chu hoa/thuong, khong dau): ";
    string plaintext;
    getline(cin, plaintext);

    cout << "> Nhap khoa (chu hoa, khong dau): ";
    string key;
    getline(cin, key);

    string ct = encryptPlayfair(plaintext, key);
    string rt = decryptPlayfair(ct, key);

    cout << "\n--- Ket qua ---\n";
    cout << "Ma hoa: " << ct << "\n";
    cout << "Giai ma: " << rt << "\n";
}
