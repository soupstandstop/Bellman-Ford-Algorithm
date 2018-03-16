# Bellman-Ford-Algorithm
令w[a][b]是a點到b點的距離（即是邊的權重）。
令d[a]是起點到a點的最短路徑長度，起點設為零，其他點都設為無限大。

# 重複下面這件事V-1次：
　甲、窮舉邊ab：d[a] + w[a][b] < d[b]。
　乙、以邊ab來修正起點到b點的最短路徑：d[b] = d[a] + w[a][b]。
　　　（即是圖上所有邊同時進行relaxation。）
