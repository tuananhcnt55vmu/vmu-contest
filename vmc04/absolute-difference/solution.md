Dễ thấy rằng, nếu ta duyệt từng vùng chữ nhật với mỗi truy vấn thì độ phức tạp chương trình sẽ là $O(10^4*N^2) = O(10^{10})$. Vì vậy, để giải triệt để bài toán này ta cần phải tiếp cận theo cách khác

Trước tiên, ta sẽ đơn giản hóa bài toán. Thay vì tính độ chênh lệch, ta có thể quy về tính tổng bằng cách đảo dấu các ô trắng (hoặc đen). Như vậy, ta tính tổng lại và lấy giá trị tuyệt đối cũng tương đương với độ chênh lệch
# Giải thuật $O(N^2)$


Lý tưởng nhất, là ta có thể tính toán trước kết quả và mỗi truy vấn chỉ cần đọc dữ liệu đã tính và in ra kết quả. Tuy nhiên, nếu ta tiếp cận theo cách tự nhiên như ban đầu thì độ phức tạp vẫn không giảm đi được. Liệu ta có thể tính được tổng của 1 vùng dựa vào các vùng đã biết?

## Tính tổng của hình chữ nhật
Gọi $sum[i][j]$ là tổng của HCN $(1, 1) \rarr (i, j)$. Liệt kê một số trường hợp đầu tiên, ta có:
$sum[1][1] = a[1][1]$
$sum[1][2] = sum[1][1] + a[1][2]$
$sum[1][3] = sum[1][2] + a[1][3]$
...
$sum[2][1] = sum[1][1] + a[2][1]$
$sum[2][2] = a[2][2] + sum[1][2] + sum[2][1] - sum[1][1]$
$sum[2][3] = a[2][3] + sum[2][2] + sum[1][3] - sum[1][2]$
...
$sum[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1]$

Như vậy, ta có thể tính được tất cả các hình chữ nhật có điểm đầu là $(1, 1)$ với độ phức tạp $O(N^2)$. Vậy còn các hình chữ nhật khác? 

![hint](hint.png)

Giả sử ta cần tính vùng màu vàng, ta sẽ thử tính bằng cách dựa vào các vùng có điểm đầu là $(1, 1)$.

Đặt TOTAL = RED + BLUE + YELLOW + MAGENTA
$\rarr$ YELLOW = TOTAL - RED - BLUE - MAGENTA
Như vậy, để tính được YELLOW ta cần phải biết TOTAL, RED, BLUE, MAGENTA. TOTAL và MAGENTA có điểm đầu là (1, 1). Chỉ còn RED và BLUE, ta có thể bù vùng MAGENTA vào mỗi vùng để có được vùng có điểm đầu là (1, 1). Như vậy, ta có:
YELLOW = TOTAL - (RED + MAGENTA) - (BLUE + MAGENTA) + MAGENTA

Nói cách khác, gọi YELLOW = $S_{x_1,y_1,y_2,y_2}$ là tổng của vùng $(x_1, y_1) \rarr (x_2, y_2)$ thì:

$S_{x_1,y_1,y_2,y_2} = sum[x_2][y_2] - sum[x_1-1][y_2] - sum[x2][y_1-1] + sum[x_1-1][y_1-1]$

Vậy bài toán đã được giải quyết