# bai1_security
#  TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN
Caesar

Affine

Hoán vị

Vigenère

Playfair

#  Với mỗi phương pháp, hãy tìm hiểu:

Tên gọi

Thuật toán mã hoá, thuật toán giải mã

Không gian khóa

Cách phá mã (mà không cần khoá)

Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript

#  BÀI LÀM
## Caesar
### Tên gọi
Caesar cipher (mã Caesar, mã dịch chuyển)

### Thuật toán mã hoá, thuật toán giải mã
Khóa: một số nguyên k ∈ {0..25}.

Mã hóa: với ký tự chữ hoa P (A..Z) → C = (P + k) mod 26.

Giải mã: P = (C - k) mod 26.
### Không gian khóa
26 khả năng (k = 0..25). Nếu loại bỏ k=0 (không mã hóa) thì 25.
### Cách phá mã (mà không cần khoá)
Brute force: thử mọi k (26 thử) và đọc kết quả.

Phân tích tần suất: so sánh tần suất ký tự của bản mã với phân bố tiếng (ví dụ E, T, A, O...) để suy k.

### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b8cefd90-72cf-4db3-8597-90a92ec13d14" />

#### html+css+javascript
<img width="1492" height="809" alt="image" src="https://github.com/user-attachments/assets/c1418c0d-75a1-40fe-8c9a-1b1ddf20e237" />

## Affine
### Tên gọi
Affine cipher (mã Affine)

### Thuật toán mã hoá, thuật toán giải mã
Khóa: cặp (a, b) với 0 ≤ b ≤ 25 và a coprime với 26 (gcd(a,26)=1).

Mã hóa: C = (a * P + b) mod 26.

Giải mã: cần a^{-1} modular inverse modulo 26, P = a^{-1} * (C - b) mod 26.


### Không gian khóa
Số a khả dĩ = φ(26) = 12 (các a: 1,3,5,7,9,11,15,17,19,21,23,25). b có 26 giá trị → tổng 12 * 26 = 312 khóa.
### Cách phá mã (mà không cần khoá)
Brute force: thử mọi cặp (a,b) (312 thử) và chọn plaintext có nghĩa (hoặc dùng scoring / tần suất).

Phân tích tần suất: Affine là biến đổi tuyến tính trên alphabet nên tần suất tương tự Caesar sau biến đổi; tìm ánh xạ giữa hai ký tự thường nhất để ước lượng a,b (phân tích hai ký tự nóng nhất xác định a và b với điều kiện chưa bị trùng).

Known-plaintext: từ cặp plaintext-ciphertext suy a, b bằng hệ phương trình tuyến tính modulo 26.
### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++


#### html+css+javascript

## Hoán vị
### Tên gọi


### Thuật toán mã hoá, thuật toán giải mã

### Thuật toán giải mã

### Không gian khóa

### Cách phá mã (mà không cần khoá)

### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++


#### html+css+javascript

## Vigenère
### Tên gọi


### Thuật toán mã hoá, thuật toán giải mã

### Thuật toán giải mã

### Không gian khóa

### Cách phá mã (mà không cần khoá)


### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++

#### html+css+javascript

## Playfair
### Tên gọi


### Thuật toán mã hoá, thuật toán giải mã

### Thuật toán giải mã

### Không gian khóa

### Cách phá mã (mà không cần khoá)


### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++


#### html+css+javascript

