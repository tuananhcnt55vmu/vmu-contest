Nếu vẽ ra vài trường hợp đầu, ta có thể dễ dàng nhận ra diện tích của lần mở rộng thứ n là:
$S = F(n) * F(n+1)$
Trong đó, $F(n)$ là số fibonacci thứ n.

Số fibonacci được tính theo công thức sau

$F[1] = 1$
$F[2] = 1$
$F[3] = 2$
$F[4] = 3$
...
$F[n] = F[n-1] * F[n-2]$
# Thuật toán tính số fibonacci
Nhìn vào công thức trên, ta có thể dễ dàng tính được số fibonacci thứ n bằng cách duyệt từ 1 cho tới n. Như vậy, độ phức tạp sẽ là O(n). Tuy nhiên, với n lên tới $10^{18}$, việc duyệt tuyến tính không thể vượt qua được toàn bộ số test, ta phải dùng cách khác tối ưu hơn.
## Liên hệ giữa số fibonacci và ma trận
Dưới đây là công thức liên hệ giữa ma trận và số fibonacci, cụ thể hơn có thể tham khảo link (http://mathworld.wolfram.com/FibonacciQ-Matrix.html):

${\begin{bmatrix}1 & 1\\1 & 0\end{bmatrix}}^n = \begin{bmatrix}F(n+1) & F(n)\\F(n) & F(n-1)\end{bmatrix}$

Như vậy, ta còn 1 cách khác để tính số Fibonacci thứ n là tính lũy thừa n của ma trận $\begin{bmatrix}1 & 1\\1 & 0\end{bmatrix}$. 
## Tính lũy thừa trong O(log(n))
Ta sẽ không dùng cách thông thường là duyệt từ 1 cho tới n. Với bài toán tính lũy thừa, ta áp dụng chiến lược "chia để trị" để tính toán trong O(log(n)). Hãy xem cách tính sau:
 
$a^n = a^{(n/2)}.a^{(n/2)}$
$a^{n/2} = a^{(n/4)}.a^{(n/4)}$
$a^{n/4} = a^{(n/8)}.a^{(n/8)}$
...
$a^1 = a$
$a^0 = 1$

Như vậy, nếu tính theo cách trên ta chỉ cần $log_2^{n}$ bước để tính được $a^n$. Ta có thể cài đặt cách tính trên với độ phức tạp là O(log(n)) như sau:
```python
def power(a, n):
    if n == 0: return 1
    if n == 1: return a
    a_2 = power(a, floor(n/2))
    result = a_2 * a_2
    if n % 2 == 1:
        result *= a
    return result
```
Tương tự với cách tính lũy thừa của ma trận. 

Như vậy, ta có thể giải bài toán ban đầu với độ phức tạp là **O(log(n))**