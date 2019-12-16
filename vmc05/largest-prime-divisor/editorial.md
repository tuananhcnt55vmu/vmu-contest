Ta có: $n = \prod_0^kp_i^{e_i}$ 
-   Trong đó: k+1 là số ước nguyên tố của n và $p_i$ là ước nguyên tố thứ i của n

Với n lên tới $10^{14}$, ta chỉ có thể duyệt được tối đa $sqrt(n)$. Nếu ta lọc các số nguyên tố từ $[1, sqrt(n)]$ thì có thể vẫn bỏ xót một ước lớn hơn $sqrt(n)$. Ví dụ: n = 2.2.31 = 124. Do sqrt(n) = 5 nên ta sẽ bỏ mất ước nguyên tố lớn nhất là 31

Vì vậy, ta phải duyệt theo cách khéo léo hơn, đó là rút gọn các ước nguyên tố từ nhỏ tới lớn, khi rút gọn hết các ước nhỏ hơn $sqrt(n)$, phần còn dư nếu có chắn chắn là ước nguyên tố lớn nhất. 


Ví du: n = 2.2.31 = 124
2.2.31 => 2.31 => 31

Đoạn mã sau sẽ mô phỏng thuật toán trên:
```python
def larget_prime_divisor(n):
    primes = get_prime(1, sqrt(n)) // get primes in range [1, sqrt(n)]
    p = n
    ans = -1
    for prime in primes:
        while p > 1 and p % prime == 0:
            p /= prime
            ans = max(ans, prime)
    
    if p > 1 and p != n:
        ans = p
    return p
```
<!-- this css for latex -->
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });</script>