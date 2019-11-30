Tiếp cận theo hướng tự nhiên, ta sẽ dùng đệ quy để tạo ra các hoán vị của chuỗi S. Mỗi khi tạo được 1 chuỗi, ta sẽ lưu lại vào 1 mảng. Như vậy, độ phức tạp thời gian là $O(10!) = O(3628800)$ và độ phức tạp bộ nhớ là $O(10!*sizeof(S))$. Tuy độ phức tạp thời gian là đủ, nhưng việc bộ nhớ quá lớn khiến thuật toán này không khả thi.

Bài toán này vẫn có thể tối ưu thêm, dựa vào nhận xét sau:
1. Do các hoán vị sinh ra theo thứ tự từ điển, nên việc lưu lại chúng chỉ mang tính chất đếm. Liệu ta có thể tính được chính xác S có bao nhiêu hoán vị? Nếu tính được, ta sẽ tiết kiệm được rất nhiều bộ nhớ do không phải lưu lại các kết quả. Toán sẽ giúp ta tính được số hoán vị của S, gọi N là độ dài của S thì công thức tính số hoán vị của S là:

$number\_permutations(S) = \frac{N!}{\prod count(char)!}$

Ví dụ: Chuỗi $ABAB$ có $N = 4$, $char \in \{'A', 'B'\}$
=> $count('A') = count('B') = 2$
Như vậy, $ number\_permutations(S)  = 4!/(2!*2!) = 24 / (2 * 2) = 6$

2. C++ cũng cấp hàm next_permutation dùng để sinh hoán vị, như vậy ta không cần cài đặt hàm sinh hoán vị nữa. Chỉ cần sort lại chuỗi S và sinh thôi

