#include <iostream>
#include <string>
#include <vector> // Vector use karenge frequency array ke liye
#include <numeric> // Optional, but for std::accumulate (not strictly needed for this approach)

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // Step 1: Length check
        // Agar dono strings ki length alag hai, toh wo kabhi anagram nahi ho sakte.
        if (s.length() != t.length()) {
            return false;
        }

        // Step 2: Frequency array banate hain.
        // Kyunki sirf lowercase English letters hain ('a' se 'z'),
        // hum ek 26 size ka vector use kar sakte hain.
        // Sabko initially 0 se initialize kar denge.
        std::vector<int> char_counts(26, 0);

        // 's' string ke har character ki frequency count karte hain.
        // Jaise agar character 'c' hai, toh 'c' - 'a' = 2 hoga, toh char_counts[2] ko badhayenge.
        for (char c : s) {
            char_counts[c - 'a']++;
        }

        // 't' string ke har character ki frequency ko ghataate hain.
        // Agar 's' aur 't' anagram hain, toh ye operations ke baad sab counts 0 ho jaane chahiye.
        for (char c : t) {
            char_counts[c - 'a']--;
        }

        // Step 3: Final check
        // Ab char_counts vector ko iterate karte hain.
        // Agar koi bhi count non-zero hai, toh iska matlab frequencies match nahi hui.
        for (int count : char_counts) {
            if (count != 0) {
                return false; // Anagram nahi hai
            }
        }

        // Agar saare counts 0 hain, toh matlab strings anagram hain.
        return true;
    }
};

// Main function for testing (optional, usually LeetCode handles this)
int main() {
    Solution sol;

    // Test cases
    std::cout << "Is 'anagram' and 'nagaram' an anagram? "
              << (sol.isAnagram("anagram", "nagaram") ? "Yes" : "No") << std::endl; // Expected: Yes

    std::cout << "Is 'rat' and 'car' an anagram? "
              << (sol.isAnagram("rat", "car") ? "Yes" : "No") << std::endl;     // Expected: No

    std::cout << "Is 'listen' and 'silent' an anagram? "
              << (sol.isAnagram("listen", "silent") ? "Yes" : "No") << std::endl; // Expected: Yes

    std::cout << "Is 'hello' and 'world' an anagram? "
              << (sol.isAnagram("hello", "world") ? "Yes" : "No") << std::endl; // Expected: No

    std::cout << "Is 'a' and 'ab' an anagram? "
              << (sol.isAnagram("a", "ab") ? "Yes" : "No") << std::endl;     // Expected: No

    return 0;
}