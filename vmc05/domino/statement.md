# Statement
Vào những năm 1980 người ta đã sáng tạo ra trò chơi sử dụng các quân domino để xếp liên tiếp nhau tạo ra các hiệu ứng và hình vẽ khi chúng đổ xuống. Một quân domino có thể bị đổ xuống nhiều lần để tạo ra các hướng đổ khác nhau. Hãy viết một chương trình để xác định độ dài của một dãy domino khi đổ xuống.

# Input
Dữ liệu của chương trình được cho trong một file text, có thể gồm nhiều test, mỗi test là mô tả về một sân bóng chuyền dùng để xếp các quân domino, dòng đầu tiên là hai số W và L (0 < W, L < 50) mô tả độ rộng và dài của bảng các quân domino. Tiếp theo là L dòng, mỗi dòng gồm W ký tự ASCII, ký tự ‘|’ nghĩa là một quân domino thẳng đứng (chưa đổ), ký tự ‘.’ nghĩa là không có quân domino nào, ký tự ‘-‘ tương ứng với 1 quân domino sẽ đổ xuống đầu tiên. File input kết thúc với W = L = 0.
# Output
Hãy tính thời gian để quân domino cuối cùng đổ xuống bằng giây (độ chính xác 1 chữ số sau dấu phẩy), có thể giả sử rằng tất cả các quân domino sẽ không đổ xuống hết. Tốc độ đổ của các quân domino là 10 quân 1 giây. Khi 1 quân domino đổ xuống, các quân domino cạnh đó (theo 8 hướng) sẽ đổ xuống tiếp theo.
# Test
- 40% số test có $1 \le W, L \le 10$
- 40% số test có $1 \le W, L \le 100$
- 20% số test có $1 \le W, L \le 1000$
# Example
Input | Output
--- | ---<!-- this css for latex -->
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });</script>