(reduce + (map (fn [i] (if (= (mod i 3) 0) i (if (= (mod i 5) 0) i 0))) (for [i (range 999)] (inc i)))))
