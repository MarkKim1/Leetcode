class Solution {
    func longestPalindrome(_ s: String) -> String {
        var ans: String = ""
        var maxLength: Int = Int.min
        var array = Array(s)
        for (index, ch) in array.enumerated() {
            var right: Int = index
            var left: Int = index
            while right < array.count && left >= 0 && array[left] == array[right] {
                if right-left + 1 > maxLength {
                    ans = String(array[left..<right + 1])
                    maxLength = right-left + 1
                }
                right += 1
                left -= 1
            }
            left = index
            right = index + 1
            while right < array.count && left >= 0 && array[left] == array[right] {
                if right-left + 1 > maxLength {
                    ans = String(array[left..<right + 1])
                    maxLength = right-left + 1
                }
                right += 1
                left -= 1
            }
        }
        return ans
    }
}