Bài toán có thể phát biểu lại như sau:

- Cho 1 tập S gồm n số nguyên dương, hãy tìm số M nhỏ nhất sao cho phần dư với modulo M của mỗi phần tử trong S là khác nhau.

Ràng buộc:

- $1 \le |S| \le 300$
- $1 \le S_i \le 10^5$

Ta có vài nhật xét sau:

- M không nhỏ hơn số lượng phần tử của tập S (\*)
- M không lớn hơn $K = max(S) - min(S) + 1$ (\*\*)

=> $n \le M \le max(S) - min(S) + 1$

=> $1 \le M \le 10^5$

Với giới hạn này, ta hoàn toàn có thể duyệt M từ nhỏ tới lớn, với mỗi giá trị duyệt qua tập S để kiểm tra phần dư có trùng hay không. Giá trị đầu tiên là kết quả của bài toán

=> Độ phức tạp tính toán: O(max(S) \* N)

## Chứng minh (\*)

Giả sử M nhỏ hơn số phần tử của tập S thì tồn tại ít nhất 1 phần tử có phần dư lớn hơn M (vô lí)

## Chứng minh (\*\*)

Ta có: a % M == b % M thì (a - x) % m == (b - x) % M

Như vậy, để đơn giản ta trừ tất cả các phần tử trong S đi một lượng là $min(S_i) - 1$. Ta sẽ có tập $S' = \{1, S^{'}_1, S^{'}_2, ... S^{'}_n\}$. Việc tìm M trên tập S' cũng tương đương với tập S. Do đó ta có thể thấy rằng M không vượt quá $max(S^{'}) = max(S) - min(S) + 1$

<!-- this css for latex -->
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });</script>
