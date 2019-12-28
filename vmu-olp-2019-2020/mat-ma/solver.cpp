#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int MAXN = 101;
const int INF = 1E7+7;

struct Range {
  int r_min, r_max, c_min, c_max;
  Range() {
    r_min = c_min = INF;
    r_max = c_max = -INF;
  }
};

bool is_prime[INF];
int mat[MAXN][MAXN];
int R, C;
vector<Range> row, col, dia1, dia2;

void sieve (int lim) {
  memset(is_prime, 1, sizeof is_prime);
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; i * i < lim; ++i) {
    for (int j = i*i; j < lim; j += i) {
      is_prime[j] = false;
    }
  }
}

int eval_row(int r, Range & p) {
  return int(p.r_min < r and r < p.r_max);
}

int eval_col(int c, Range & p) {
  return int(p.c_min < c and c < p.c_max);
}

int eval (int r, int c, Range & p) {
  return eval_row(r, p) & eval_col(c, p);
}

int count (int r, int c) {
  return eval_row(r, col[c]) + eval_col(c, row[r]) + eval(r, c, dia1[r+c]) + eval(r, c, dia2[r-c+C]);
} 

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sieve(INF);
  
  cin >> R >> C;

  row.assign(R, Range());
  col.assign(C, Range());
  dia1.assign(R+C+1, Range());
  dia2.assign(R+C+1, Range());

  REP(r, 0, R) {
    REP(c, 0, C) { 
      cin >> mat[r][c];
    }
  }

  REP(r, 0, R) {
    REP(c, 0, C) { 
      if (is_prime[mat[r][c]]) {
        row[r].c_min = min(row[r].c_min, c);
        row[r].c_max = max(row[r].c_max, c);

        col[c].r_min = min(col[c].r_min, r);
        col[c].r_max = max(row[c].r_max, r);

        dia1[r+c].r_min = min(dia1[r+c].r_min, r);
        dia1[r+c].r_max = max(dia1[r+c].r_max, r);
        dia1[r+c].c_min = min(dia1[r+c].c_min, c);
        dia1[r+c].c_max = max(dia1[r+c].c_max, c);

        dia2[r-c+C].r_min = min(dia2[r-c+C].r_min, r);
        dia2[r-c+C].r_max = max(dia2[r-c+C].r_max, r);
        dia2[r-c+C].c_min = min(dia2[r-c+C].c_min, c);
        dia2[r-c+C].c_max = max(dia2[r-c+C].c_max, c);
      }
    }
  }

  REP(r, 0, R) {
    REP(c, 0, C) {
      if (!is_prime[mat[r][c]] && count(r, c) >= 2) {
        cout << mat[r][c] << endl;
      }
    }
  }
  
  return 0;
}