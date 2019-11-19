Tiếp cận với cách tự nhiên nhất, đó là ta duyệt từng số từ 1 tới N, sau đó đếm chữ số của từng số. 
### Đếm chữ số của một số
Ta sẽ đếm chữ số cuối, sau đó loại bỏ nó đi và tiếp tục làm cho tới khi không còn chữ số nào cả:
```python
while number > 0:
    digit[number % 10] += 1
    number /= 10
```
Theo cách này, độ phức tạp sẽ là O($T*N*K$) với K là độ phức tạp của hàm đếm chữ số. Do n không vượt quá 4 chữ số nên $T*N*K$ ~ $25 * 10^4 * 4 = 10^6$