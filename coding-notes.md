vector
    假設 vector<int> v = {10, 20, 30};
    [ 10 ] ← v.begin()  // 有資料
    [ 20 ]
    [ 30 ] ← v.back()
    [ ?? ] ← v.end()  // 沒有資料，禁止讀取

    「左閉右開」的設計有三個好處：
    計算數量：end - begin 直接等於元素的個數。
    迴圈判斷：while (it != indices.end())。如果 it 走到了 end，就代表剛剛那個（最後一個）已經處理完了。
    處理空陣列：當陣列是空的時候，begin() 會等於 end()，這讓所有演算法不用寫 if (empty) 就能直接相容。

    預先知道v的size時
    v.reserve(target.size());  // 預留空間優化
    只會改變 Capacity (容量)，不會改變 Size (大小)。

對應 long long 的極大值常數
    1. LLONG_MAX
    2. numeric_limits<long long>::max()

    // 無溢位風險
    3. 1e15 or 1e17

