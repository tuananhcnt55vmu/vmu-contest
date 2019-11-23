# Statement
Cho dãy số được xây dựng như sau:
- $F[1] = 1$
- $F[i] = sort(F[i-1] * 2)$

Trong đó, $sort(x)$ là hàm trả về giá trị sau khi sắp xếp các chữ số của $x$ tăng dần. Ví dụ: $sort(54321) = 12345$. Như vậy, ta có các số đầu tiên trong dãy là: 1, 2, 4, 8, 16, 23, 46, 29, 58, ...

Yêu cầu: Cho $n$ ($1 \le n \le 10^9)$, hãy tìm $F[n]$
# Input
Một dòng duy nhất chứa $n$
# Output
Một dòng duy nhất chứa $F[n]$
# Example
Input | Output
--- | ---
7 | 46
30 | 111356