Trước tiên, ta thử đánh giá xem dãy số này có đặc điểm gì. Nhìn vào công thức, ta thấy không có gì đặc biệt ngoài đảo chữ số. Tuy nhiên, việc đảo chữ số sẽ ảnh hưởng tới tính tăng của dãy số. Lý do là nếu như số hiện tại tồn tại chữ số 0, thì số tiếp theo sẽ giảm (bỏ số 0 ở đầu). Ta sẽ thử duyệt và liệt kê phần đầu tiên của dãy xem có gì đặc biệt về giá trị.

Nếu liệt kê vài chục số đầu:

$i$ | $F[i]$
:---: | :---:
1 | 1
2 | 2
3 | 4
4 | 8
5 | 16
6 | 23
7 | 46
8 | 29
9 | 58
10 | 116
11 | 223
12 | 446
13 | 289
14 | 578
15 | 1156
16 | 1223
17 | 2446
18 | 2489
19 | 4789
20 | 5789
21 | 11578
22 | 12356
23 | 12247
24 | 24449
25 | 48889
26 | 77789
27 | 155578
28 | 111356
29 | 122227
30 | 244445
31 | 48889
32 | 77789
33 | 155578
34 | 111356
35 | 122227
36 | 244445
... | ...
Thật may mắn, nhìn vào dãy số trên, ta thấy quy luật như sau:
- Nếu $i < 25$, ta sẽ tính theo công thức $F[i] = sort(F[i-1] * 2)$
- Bắt đầu từ $i = 25$, dãy số sẽ tuần hoàn với chu kỳ là: 48889, 77789, 155578, 111356, 122227, 244445. 

Quy luật trên tương đương với lời giải của bài toán