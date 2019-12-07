Thử cách tiếp cận brute-force (duyệt trâu bò), ta sẽ có thuật toán $O(N^6)$ ~ $10^{12}$. 
```python
ans = 0
for a in S:
    for b in S:
        for c in S:
            X = a * b + c
            for d in S:
                if d == 0:
                    continue
                for e in S:
                    for f in S:
                        Y = d * (e + f)
                        if X == Y:
                            ans += 1 
```
Thử đánh giá xem thuật toán này có thể tối ưu được không? Giá giử ta duyệt a, b, c được 1 giá trị X. Tiếp đó ta lại duyệt tất cả các giá trị d, e, f xem có khớp với X hay không. Như vậy, ta phải duyệt đi duyệt lại d, e, f ($N^3$) lần. Do đó, nếu ta tính trước và lưu lại các giá trị d, e, f vào 1 mảng (R) thì không cần phải duyệt $N^3$ nữa, khi duyệt được X ta chỉ cần tìm trong mảng R có bao nhiêu giá trị X và đếm thôi. Như vậy, độ phức tạp của ta chỉ còn $O(N^3)$ ~ $10^6$

Vì vậy, tiệc cần làm là ta sẽ tính trước Y và lưu vào 1 danh sách. 
```python
for d in S:
    if d != 0:
        for e in S:
            for f in S:
                R.add(d * (e + f))
```
Sau đó, ta sẽ duyệt X và tìm cách đếm xem với mỗi giá trị X xuất hiện bao nhiêu lần trong R. Cái này có 1 số cách, sử dụng một số cấu trúc dữ liệu (CTDL) khác nhau:
1. R là một mảng lưu số lần xuất hiện của index: Cách này không khả thi, vì giá trị của index có thể lên tới $3*10^4*(3*10^4 + 3*10^4) = 18*10^8$ (**không đủ bộ nhớ**)
2. R là một mảng lưu các giá trị của Y: Sắp xếp và tìm kiếm nhị phân trên Y. Việc đếm phải cẩn thận không gặp case trap duyệt toàn bộ Y là TLE (time limit exceeded). Tuy nhiên cách này vẫn quá phức tạp
3. R là một **hashtable**, **map**: Đây là dạng CTDL có dạng key: value tương tự như mảng. Tuy nhiên key ở đây không chỉ là số nguyên, mà còn có thể là 1 string. Đặc biệt, việc lưu trữ cũng ko liên tiếp nên ta có thể lưu được key rất lớn (khắc phục được nhược điểm của mảng). Độ phức tạp khi truy vấn hashtable là O(1), còn đối với map là O(log(n)). Tùy vào sự hỗ trợ của ngôn ngữ lập trình mà ta sử dụng hashtable hoặc map. Ví dụ, trong C++ không có built-in hashtable, ta sử dụng map, trong python hoặc java ta sử dụng hashtable

Như vậy, cách 3 tỏ ra phù hợp nhất trong trường hợp này. Đây là code mẫu C++, tôi lưu lại tập vế trái (left) thay vì tập vế phải
```cpp
#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> values(N);
    REP(i, 0, N) {
        cin >> values[i];
    }
    unordered_map<int, int> left;
    for(int a: values) {
        for (int b: values) {
            for (int c: values) {
                left[a * b + c]++;
            }
        }
    }
    int answer = 0;
    for(int d: values) {
        if (d == 0) continue;
        for (int e: values) {
            for (int f: values) {
                answer += left[d * (e + f)];
            }
        }
    }
    puts(answer);
    return 0;
}
```