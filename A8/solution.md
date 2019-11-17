Ở bài này, ta thấy rằng nếu có nhiều lựa chọn thì lựa chọn tốt nhất luôn là lựa chọn có kết thúc sớm nhất. CM: Lựa chọn kết thúc sớm nhất luôn bao gồm các lựa chọn của các cuộc họp kết thúc muộn hơn.
Vì vậy, ta sẽ có thuật toán như sau:
B1: Sắp xếp theo thời gian kết thúc
B2: Lấy cuộc họp có thời gian kết thúc sớm nhất
B3: Lấy cuộc họp bắt đầu ngay sau thời gian kết thúc của cuộc họp đã chọn trước đó (tất nhiên là thời gian kết thúc cũng sớm nhất do đã sắp xếp theo thời gian kết thúc)
B4: Lặp lại bước 3 cho tới khí duyệt hết các cuộc họp
Độ phức tạp: O(n*log(n)) với n = 10^6 (thời gian sắp xếp)