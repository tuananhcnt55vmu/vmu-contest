Tiếp cận từ cách tự nhiên nhất, ta sẽ khởi tạo mảng đánh dấu và duyệt từng tháp canh để đánh dấu lại các vị trí được bảo vệ. Tuy nhiên, bản đồ rất rộng (lên tới 10^9x10^9) nên việc lưu mảng đánh dấu không khả thi. Thử một cách tiếp cận khác, ta có thể tính được số các vị trí không an toàn bằng cách lấy tổng số vị trí trừ đi số vị trí an toàn. Cách này có vẻ tiếc kiệm hơn do số lượng tháp canh ít, đổi lại ta phải giải bài toán khác: Có bao nhiêu vị trí an toàn dựa vào vị trí các tháp canh? Việc lưu mảng đánh dấu lại không khả quan do kích cỡ bản đồ lớn, ta sẽ duy trì một tập các vị trí đã an toàn và đếm xem có bao nhiêu vị trí khác nhau. Để đơn giản, ta sẽ nén tọa độ lại thành 1 số nguyên bằng cách đánh chỉ số cho mỗi ô. Dưới đây là 2 cách:

1, Cho vào 1 mảng rồi sắp xếp, đếm khi giá trị thay đổi. Ví dụ: 1, 1, 2, 2, 3, 4 => 4

2, Cho vào 1 set
