Với bài này, cách đơn giản nhất là ta duyệt từ cặp đầu tiên cho đến cặp thứ T. Vì vậy, ta cần một thuật toán kiểm tra nguyên tố đủ nhanh. Sàng nguyên tố là lựa chọn tốt nhất trong trường hợp này.
Ta sẽ sàng trong khoảng lớn nhất có thể, nhưng thực tế chỉ cần sàng trong khoảng [1, 2*10^7]
Độ phức tạp: O(n*log(n)) với n = 2*10^7 (thời gian sàng nguyên tố)