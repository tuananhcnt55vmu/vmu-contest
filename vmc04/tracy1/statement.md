# Statement
Trong một cuộc thi Robocon, robot Tracy được giao nhiệm vụ phải đến đích để đoạt cờ về cho đội tuyển của mình. VMU Racer - đội sở hữu Tracy, cần xác định được đường đi cụ thể để lập trình cho Tracy tới đích nhanh nhất có thể. 

Bản đồ là một hệ trục tọa độ dài vô tận, Tracy xuất phát tại vị trí trung tâm (0, 0) và cần đến vị trí (X, Y) để đoạt cờ. Mỗi bước, Tracy có thể di chuyển từ vị trí hiện tại tới 4 vị trí kề cạnh. Do thời gian thi đấu có hạn, BTC đã giới hạn 1 $\le |X|, |Y| \le 1000$ sao cho các robot không cần quá nhiều thời gian để hoàn thành phần thi của mình. 

Với điệu kiện không phát sinh hỏng hóc, bạn hãy giúp VMU Racer xác định tất cả các con đường ngắn nhất

# Input
- Một dòng duy nhất: X Y
# Output
- Dòng đầu là thời gian Tracy cần để về đích sớm nhất
- Dòng thứ 2 là số cách khác nhau để Tracy về đích sớm nhất
# Example
Input | Output
--- | ---
