class Solution {
    func groupAnagrams(_ strs: [String]) -> [[String]] {
        var map = [String: [String]]()
        for str in strs {
            var sorted = String(str.sorted())
            map[sorted,default: []].append(str)
        }
        return Array(map.values)
    }
}

// class Solution {
//     func groupAnagrams(_ strs: [String]) -> [[String]] {
//         if strs.isEmpty { return [] }
        
//         var map = [String: [String]]()
//         for str in strs {
//             let sortedStr = String(str.sorted())
//             map[sortedStr, default: []] += [str]
//         }
                
//         return Array(map.values)
//     }
// }