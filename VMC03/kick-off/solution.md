Với giải thuật tự nhiên nhất, ta sẽ duyệt từ 1 tới $10^6$ để đếm. Với các số là bội của 3, 5 và 7 ta có để đếm trong O(1), còn lại đếm số lần xuất hiện của số 2. 
## Đếm số lần xuất hiện của chữ số 2
Cách đơn giản nhất là ta duyệt từng chữ số theo hàm sau:
```cpp
int count2(int n) {
    int cnt = 0;
    while(n) {
        if (n % 10 == 2) {
            cnt++;
        }
        n /= 10;
    }
    return cnt;
}
```
Do n không vượt quá $10^6$ nên số chữ số tối đa mà ta duyệt là 6. Do đó, nếu duyệt từ $1 \rarr 10^6$ và đếm từng số 1 thì độ phức tạp cho giải thuật này là **O(n)** với **$n = 10^6$**.
Để tránh phải tính lại các dữ liệu không cần thiết, ta có thể tính trước toàn bộ giá trị và lưu lại ở bước tiền xử lý, khi cần trả lời truy vấn ta chỉ cần đọc dữ liệu đã tính và ghi ra output
