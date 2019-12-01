# Statement
Một vòng lớn được kết hợp bởi N (N chẵn) vòng tròn nhỏ mà bên trong đặt các số tự nhiên từ 1 đến N và tổng của hai số trong hai vòng liền kề phải là một số nguyên tố như thấy trong hình minh họa. Lưu ý, số đầu tiên của vòng phải là số 1.
<div align="center">
    <div>
        <image src="prime-circle.png" alt="prime-circle" />
    </div>
    <i>Vòng tròn nguyên tố</i>
</div>
# Input
Đầu vào bắt đầu bằng một dòng ghi số nguyên T $(0 < T \le 10)$ là số trường hợp cần kiểm tra.
Mỗi dòng trong T dòng tiếp theo ghi một số nguyên N $(N \le 14)$.
# Output
Với mỗi đầu vào in ra các kết quả theo định dạng sau:
- Dòng đầu tiên ghi số thứ tự của trường hợp, ví dụ trường hợp đầu tiên là #1.
- Mỗi hoán vị thỏa mãn điều kiện đề bài ghi trên một dòng như trong ví dụ minh họa bên dưới.

*Chú ý: Theo thứ tự từ điển và mỗi kết quả đầu vào cách nhau một dòng trống.*
# Example
Input | Output
--- | ---
2<br>2<br>4<br><br><br><br> | #1<br>1 2<br><br>#2<br>1 2 3 4<br>1 4 3 2<br>
