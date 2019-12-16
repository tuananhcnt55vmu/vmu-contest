# Statement
Cho một bàn cờ vua kích thước 8x8, các hàng được đánh số từ 1 đến 8 và các cột được đánh số từ ký tự ‘A’ tới ký tự ‘H’ và bàn cờ này chỉ có 1 loại quân: Hậu. Trên bàn cờ có thể có một số ô bị hủy (không tính)

Hãy đặt số lượng tối thiểu các quân hậu lên bàn cờ sao cho tất cả các ô của bàn cờ đều bị khống chế bởi ít nhất một quân hậu và các quân hậu không khống chế lẫn nhau. Mỗi quân hậu không được đặt trên ô bị hủy và các ô này cũng không cần khống chế tuy nhiên một ô sẽ được tính là bị khống chế nếu như có một quân hậu nằm cùng hàng hoặc cột hoặc một trong các đường chéo tương ứng với ô đó.

# Input
Gồm 8 dòng, mỗi dòng gồm 8 ký tự, ký tự ‘.’ có nghĩa là ô trống trên bàn cờ, ký tự ‘#’ có nghĩa là ô hủy trên bàn cờ.
# Output
Gồm vị trí của các quân hậu thỏa mãn điều kiện đầu bài, mỗi vị trí được mô tả bằng chỉ số hàng và chỉ số cột viết liền nhau. Có thể có nhiều kết quả khác nhau, hãy lấy kết quả có thứ tự từ điểm nhỏ nhất.
# Example
Input | Output
--- | ---
<!-- this css for latex -->
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });</script>