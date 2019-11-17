Ta thấy rằng luôn luôn chỉ có 1 cách di chuyển duy nhất, vì vậy số bước tối đa có thể đi là số ô trên bản đồ (R*C = 10^6).
Việc xác định hướng di chuyển có một số cách, một cách đơn giản là ta xác định vector hướng của đoàn dựa vào điểm trước đó và vị trí hiện tại.
Ta sẽ đi theo 2 cách từ vị trí đầu, sau đó tìm min và max độ dài của mỗi đường.
Độ phức tạp: O(n*log(n)) với n = 10^6
 
