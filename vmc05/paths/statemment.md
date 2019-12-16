# Statement
Cho một bảng kích thước $R$ hàng và $C$ cột $(1 \le R, C \le 100)$, các hàng được đánh số từ
1 tới R theo chiều từ dưới lên trên, các cột được đánh số từ 1 tới C theo chiều từ trái sang phải. Tất cả các tọa độ trong bảng được cho theo định dạng (hàng, cột).

Cho một tập $P$ gôm có $K \le 1000$ ô nằm trong bảng đã cho, với mỗi số nguyên $0 \le i \le K$, hãy đếm số đường đi từ $(1, 1)$ tới $(R, C)$ đi qua đúng $i$ ô thuộc tập $P$. Các bước di chuyển chỉ được tiến hành từ **trái qua phải** hoặc từ **dưới lên trên**
# Input
Dòng đầu tiên là R, C và K cách nhau bởi khoảng trắng.

K dòng tiếp theo, mỗi dòng chứa 2 số nguyên là hoành độ và tung độ của ô thuộc P
# Output
Bao gồm K+1 dòng, dòng thứ i là số cách đi từ (1, 1) tới (R, C) và đi qua đúng i điểm thuộc P. 

Do kểt quả có thể rất lớn nên ta sẽ lấy theo mô đun $10^9 + 7$
# Test
- 20% số test có R+C <= 10
- 40% số test có R+C <= 16
- 40% số test có R+C > 16
# Example
| Input             | Output          |
| ----------------- | --------------- |
| 10 10 1 <br> 10 1 | 48619 1<br><br> |
| 10 10 1<br>10 10  | 0 48620<br><br> |

<!-- this css for latex -->
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });</script>