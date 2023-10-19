func minSubArrayLen(target int, nums []int) int {
    i := 0
    l := len(nums)  // size of array nums
    sum := 0        // sum
    res := l + 1 // the goal is to make a choice when no subarray is found
    for j := 0; j < l; j++ {
        sum += nums[j]
        for sum >= target {
            width := j - i + 1
            if width < res {
                res = width
            }
            sum -= nums[i]
            i++
        }
    }
    if res == l+1 {
        return 0
    } else {
        return res
    }
}
