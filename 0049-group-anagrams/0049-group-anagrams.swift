class Solution {
    func groupAnagrams(_ strs: [String]) -> [[String]] {
        var map:[String: [String]] = [:]
        for str in strs {
            var sorted = String(str.sorted())
            map[sorted,default:[String]()].append(str)
        }
        return Array(map.values)
    }
}