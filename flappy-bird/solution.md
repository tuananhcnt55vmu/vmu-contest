Ta sẽ tính chi phí từng độ cao, sau đó tìm min của các chi phí đó. Nếu như tiếp cận theo cách tự nhiên nhất, ta có thể tìm min bằng cách duyệt qua toàn bộ các cột. Nhưng độ phức tạp sau khi tính chi phí của từng đô cao là O(H*N) ~ 10^12 => không khả thi. Ta sẽ tìm các tối ưu hơn, việc duyệt từng độ cao ko thể tối ưu hơn được vì vậy chỉ còn cách tối ưu cách tính chi phí.
Nhận thấy rằng vị trí của các cột không ảnh hưởng đến chi phí, cho nên ta có thể sắp xếp lại và dùng tìm kiếm nhị phân để giảm độ phức tạp. Nếu các cột đã được sắp xếp, ta có thể tính được chi phí với độ phức tạp log(N) hay vì N như cách duyệt tự nhiên. Do đó, độ phức tạp sẽ giảm xuống O(H*log(N)) với H, N = 10^6 (khả thi)