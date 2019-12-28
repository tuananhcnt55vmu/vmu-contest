Tương tự như bài "Mật mã", mỗi vọng gác sẽ khống chế 4 đường thẳng đi qua vị trí được đặt. Như vậy, nếu ta đặt 1 vọng gác tại vị trí (r, c), thì các đường bị vọng gác này không chế là:
- Hàng (r) 
- Cột (c)
- Đường chéo loại 1 (r+c)
- Đường chéo loại 2 (r-c)

Ta có giải thuật sau: Duyệt từ vị trí nhỏ nhất tới vị trí lớn nhất, tại mỗi vị trí nếu có thể đặt vọng gác (không bị cấm và chưa bị không chế) thì ta sẽ đặt 1 vọng gác tại đây và đánh dấu 4 đường đi qua vị trí này đã bị khống chế. Tiếp tục cho tới khi duyệt hết bản đồ. Độ phức tạp là (8*8)

<!-- this css for latex -->
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });</script>