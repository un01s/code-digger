/*
 * leetcode 27
 * double-pointer: fast and slow
 *
 * _ for something you do not need
 * 
 */

func removeElement(nums []int, val int) int {
    k := 0
    for _, num := range nums {
        if num != val {
            nums[k] = num
            k += 1
        }
    }
    return k    
}
