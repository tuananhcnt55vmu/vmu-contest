Ta sẽ đánh số bàn cờ từ ô trái trên xuống ô phải dưới theo thứ tự 0 -> 63. Dùng đệ quy để đặt từng ô từ nhỏ tới lớn, sau khi đặt tại 1 vị trí ta cần đánh dấu hàng, cột và hai đường chéo chứa ô đó bị bao phủ. Tiếp tục cho tới khi hết các vị trí, như vậy kết quả thu được luôn có thứ tự từ điển nhỏ nhất:

```python
def put (idx):
    if (idx == 63) {
        // print result
        return
    }
    row = idx / 8
    col = idx - row*8
    if not cover(row, col):
        mp[row][col] = 'Q'
        covered_row[row] = true
        covered_col[col] = true
        covered_dia1[row+col] = true
        covered_dia2[row-col+8] = true
    put(idx+1)
```<!-- this css for latex -->
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });</script>