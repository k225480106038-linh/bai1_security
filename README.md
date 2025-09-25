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
Giả sử bảng chữ cái có m ký tự (ví dụ với tiếng Anh là 26 ký tự: A..Z).

Gán đại số: gán mỗi ký tự thành số từ 0 đến m-1

Khóa k là một số nguyên giữa 0 và m−1.
Mã hóa: C=(P+k)modm

với 

P là giá trị plaintext, 

C là ciphertext.

Giải mã: P=(C−k+m)modm
### Không gian khóa
Khóa k có thể từ 0 đến m−1.

Với bảng 26 ký tự, có 26 khả năng khóa (trong thực tế khóa = 0 có thể coi là không mã hóa).

Nói cách khác, ∣K∣=m.
### Cách phá mã (mà không cần khoá)
Brute force: thử mọi k (26 thử) và đọc kết quả.

Phân tích tần suất: so sánh tần suất ký tự của bản mã với phân bố tiếng (ví dụ E, T, A, O...) để suy k.

### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b8cefd90-72cf-4db3-8597-90a92ec13d14" />

#### HTML+CSS+JAVACRIPT
<img width="937" height="720" alt="image" src="https://github.com/user-attachments/assets/e661b5fc-4aa3-4f10-83ca-8fb1f64d9ecf" />


## Affine
### Tên gọi
Affine cipher (mã Affine)

### Thuật toán mã hoá, thuật toán giải mã
Với bảng 26 chữ A..Z. Khóa là cặp (a, b) với gcd(a,26)=1.

Mã hoá: C = (a * P + b) mod 26.

Giải mã: cần a^{-1} (mod 26) là nghịch đảo của a: P = a^{-1} * (C - b) mod 26.

### Không gian khóa
Số a khả dĩ = φ(26) = 12 (các a: 1,3,5,7,9,11,15,17,19,21,23,25). b có 26 giá trị → tổng 12 * 26 = 312 khóa.
### Cách phá mã (mà không cần khoá)
Brute force: thử mọi cặp (a,b) (312 thử) và chọn plaintext có nghĩa (hoặc dùng scoring / tần suất).

Phân tích tần suất: Affine là biến đổi tuyến tính trên alphabet nên tần suất tương tự Caesar sau biến đổi; tìm ánh xạ giữa hai ký tự thường nhất để ước lượng a,b (phân tích hai ký tự nóng nhất xác định a và b với điều kiện chưa bị trùng).

Known-plaintext: từ cặp plaintext-ciphertext suy a, b bằng hệ phương trình tuyến tính modulo 26.
### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b27d5153-4afa-4020-8a90-291dad66a760" />


#### HTML+CSS+JAVACRIPT
<img width="1025" height="808" alt="image" src="https://github.com/user-attachments/assets/447b47e0-aabd-4775-9690-f3823927a7fe" />

## Hoán vị
### Tên gọi
Permutation cipher (hoán vị); phổ biến là Columnar transposition (đổi cột theo hoán vị của khóa)

### Thuật toán mã hoá, thuật toán giải mã
Chọn khóa là một hoán vị của n (hoặc chuỗi số dùng làm thứ tự cột).

Viết plaintext theo hàng vào ma trận có n cột; đọc ciphertext theo cột theo thứ tự khóa.

Giải mã: biết số cột và thứ tự; chia ciphertext theo độ dài cột, dựng lại ma trận rồi đọc theo hàng.


### Không gian khóa
Nếu độ dài khóa = n thì số hoán vị = n! (rất lớn khi n tăng). Nhưng khóa hay là một chuỗi số ngắn nên thực tế nhỏ hơn.
### Cách phá mã (mà không cần khoá)
Kasiski-like: thử các độ dài cột khác nhau, dùng heuristic để đo "độ giống tiếng" (số lượng cặp nguyên âm, từ hợp lệ).

Brute-force hoán vị: không khả thi nếu n lớn; nhưng nếu n nhỏ (5-8) có thể thử hết.
### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/3f6ddb52-c57e-4513-a7ba-941f47fff8d8" />

#### HTML+CSS+JAVACRIPT
<img width="887" height="478" alt="image" src="https://github.com/user-attachments/assets/f96fc699-8be3-4516-a86b-8bc91a7fb69a" />

## Vigenère
### Tên gọi
Vigenère cipher — gọi tiếng Việt: Mã Vigenère (một dạng polyalphabetic substitution cipher, dùng chuỗi khóa lặp để dịch từng ký tự).

### Thuật toán mã hoá, thuật toán giải ma
Tiền đề: xét bảng chữ cái A–Z (26 chữ). Ta sẽ chỉ dịch các chữ cái; ký tự không phải chữ để nguyên (tùy triển khai — mình cung cấp code giữ nguyên ký tự khác và bảo toàn chữ hoa/chữ thường).

Ký hiệu:

Plaintext ký tự thứ i: P_i (đại diện bằng số 0..25; ví dụ A=0, B=1, …)

Key ký tự thứ i (lặp theo plaintext): K_i (0..25)

Ciphertext ký tự thứ i: C_i

Mã hóa : C_i = (P_i + K_i) mod 26

Giải mã : P_i = (C_i - K_i + 26) mod 26

### Không gian khóa
Nếu key length = m thì keyspace = 26^m. Nếu m không biết, m thường nhỏ (ví dụ 3..10).

### Cách phá mã (mà không cần khoá)

Kasiski examination: tìm khoảng cách giữa các chuỗi lặp để ước lượng độ dài khóa.

Friedman test (index of coincidence) để ước lượng độ dài khóa.

Khi biết độ dài m, tách ciphertext thành m chuỗi con và áp dụng phân tích tần suất (giống Caesar) trên từng chuỗi để tìm shift.

Brute-force toàn bộ keyspace chỉ khả thi nếu m nhỏ.
### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/01591286-8c60-479e-bcc3-68d5bc93f4ae" />


#### HTML+CSS+JAVACRIPT
<img width="913" height="569" alt="image" src="https://github.com/user-attachments/assets/c2e7c7a7-dacd-4b95-83d5-eb6f4f6d5c1e" />

## Playfair
### Tên gọi
Playfair cipher (mã Playfair) — mã hoán vị digraph (2-chữ 1 cặp)

### Thuật toán mã hoá, thuật toán giải mã
Tạo ma trận 5×5 từ khóa (ký tự A..Z, thường gộp I/J thành một ô). Ví dụ fill bằng key (không trùng) rồi phần dư là alphabet còn lại.

Chia plaintext thành các digraph (cặp 2 chữ). Nếu cặp có hai chữ giống nhau thì chèn X giữa; nếu kết thúc lẻ thì thêm X để hoàn thành. (Một biến thể dùng Q hoặc khác)

Mã hoá một cặp (A,B):

Nếu A và B cùng hàng: thay mỗi chữ bằng chữ bên phải (vòng quanh).

Nếu cùng cột: thay bằng chữ bên dưới (vòng quanh).

Nếu khác hàng và khác cột: thay A bằng chữ cùng hàng với A nhưng cùng cột với B (nói cách khác: hoán đổi các cột — tạo thành hàng chéo chữ nhật).

Giải mã: tương tự nhưng quay trái/quay lên cho các trường hợp hàng/cột.

### Không gian khóa
Lý thuyết rất lớn (~25! khác), nhưng thực tế có cấu trúc—không dễ brute-force toàn diện. Playfair được phá bằng phân tích digraph (tần suất digram), tìm kiếm từ khả dĩ và tấn công heuristic.
### Cách phá mã (mà không cần khoá)
Phân tích tần suất digram (cặp 2 chữ), dùng thuật toán tối ưu/heuristic (simulated annealing, hill-climbing) để tìm ma trận phù hợp.

Với ciphertext dài, dễ dàng phục hồi plaintext bằng các phương pháp tối ưu hóa.

### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/78d33805-6c26-4ec5-9f1e-c2b6f61263a2" />


#### HTML+CSS+JAVACRIPT
<img width="869" height="551" alt="image" src="https://github.com/user-attachments/assets/9cdc1f95-fd52-4e6d-b140-1910130972a7" />

