Với cách tiếp cận đơn giản nhất, ta sẽ sinh toàn bộ hoán vị độ dài N và kiểm tra xem từng hoán vị có là 1 vòng tròn nguyên tố hay không. Tuy nhiên, cách này thực sự là hạ sách và tất nhiên không thể pass được giới hạn đã cho. 
Ta sẽ phải dùng 1 phương pháp tối ưu gọi là "nhánh cận". Tức là trước khi đệ quy thêm 1 độ sâu, ta sẽ đánh giá nhánh bắt đầu từ vị trí đó có kết quả hay không, nếu không bỏ luôn và duyệt nhánh khác. Cách này sẽ loại bỏ được đa số các phép toán không cần thiết. Nếu càng ít đáp án, thì chương trình càng chạy nhanh. 