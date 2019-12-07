# Statement
Trong trò chơi dò mìn, cho một lưới ô vuông M hàng và N cột với mỗi ô trong lưới có thể chứa mìn hoặc không. Nhiệm vụ của bạn là phải tính toán xem mỗi ô không chứa mìn trong lưới kề với bao nhiêu ô có chứa mìn. Quan hệ liền kề ở đây là quan hệ 8 nghĩa là mỗi ô sẽ liền kề với 8 ô xung quanh.
# Input
Đầu vào sẽ bao gồm nhiều lưới (không lớn hơn 100) theo định dạng sau:
+ Mỗi lưới bắt đầu bằng hai số nguyên M và N ($0 < M, N \le 100$). Theo sau mỗi lưới là M hàng, trong đó mỗi hàng bao gồm N ký tự với ký tự dấu sao (*) là có mìn, ký tự dấu chấm (.) là không có mìn.
+ Kết thúc đầu vào khi M = N = 0 và không xử lý trường hợp này.
# Output
Với mỗi lưới đầu vào bạn phải in ra lưới kết quả theo định dạng sau:
+ Dòng đầu tiên ghi số thứ tự của lưới, ví dụ lưới đầu tiên là #1.
+ Theo sau là lưới kết quả, trong đó các ô chứa mìn giữ nguyên như lưới đầu vào còn ô không chứa mìn thì ghi số các ô có mìn liền kề nó. 

*Chú ý: Mỗi kết quả cách nhau bởi một dòng trống.*
# Example
Input | Output
--- | ---
4 4<br>\*...<br>....<br>.\*..<br>....<br>3 5<br>\*\*...<br>.....<br>.\*...<br>0 0<br> | #1<br>\*100<br>2210<br>1\*10<br>1110<br><br>#2<br>\*\*100<br>33200<br>1\*100<br>