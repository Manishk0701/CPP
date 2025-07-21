#include <string> // string class ke liye
#include <iostream>
#include<climits>
 // Output ke liye (optional, debugging mein kaam aata hai)

class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        // Step 1: Length Check (Lambai Check)
        // Agar dono strings ki lambai barabar nahi hai, toh woh rotate hoke
        // kabhi bhi same nahi ban sakte. Seedha false return karo.
        if (s.length() != goal.length()) {
            return false;
        }

        // Agar dono strings empty hain (yani lambai 0 hai), toh technically isomorphic hain.
        // Ye constraint ke hisaab se avoid ho jayega (1 <= s.length <= 100),
        // but it's a good edge case to consider in general.
        if (s.empty()) { // Ya s.length() == 0, jo upar wale check mein bhi cover ho jayega agar goal.length() bhi 0 hai
            return true;
        }

        // Step 2: Concatenation (Jodna)
        // 's' string ko do baar apne aap se jod do.
        // Example: s = "abcde" -> s_doubled = "abcdeabcde"
        std::string s_doubled = s + s;

        // Step 3: Search (Dhoondhna)
        // Ab check karo ki 'goal' string, 's_doubled' ka ek substring hai ya nahi.
        // std::string::find() method ka use karenge.
        // Agar find() method ko substring mil jata hai, toh woh uski starting index return karta hai.
        // Agar nahi milta, toh std::string::npos return karta hai (jo ki ek special value hai).
        if (s_doubled.find(goal) != std::string::npos) {
            // Agar goal, s_doubled mein mil gaya, toh true return karo.
            return true;
        } else {
            // Agar goal nahi mila, toh false return karo.
            return false;
        }
    }
};

//  Example Usage (Test karne ke liye main function)
int main() {
    Solution sol;

    std::cout << "Test 1: s = \"abcde\", goal = \"cdeab\" -> " << (sol.rotateString("abcde", "cdeab") ? "true" : "false") << std::endl; // Expected: true
    std::cout << "Test 2: s = \"abcde\", goal = \"abced\" -> " << (sol.rotateString("abcde", "abced") ? "true" : "false") << std::endl; // Expected: false
    std::cout << "Test 3: s = \"\", goal = \"\" -> " << (sol.rotateString("", "") ? "true" : "false") << std::endl; // Expected: true (edge case)
    std::cout << "Test 4: s = \"a\", goal = \"a\" -> " << (sol.rotateString("a", "a") ? "true" : "false") << std::endl; // Expected: true
    std::cout << "Test 5: s = \"abc\", goal = \"bca\" -> " << (sol.rotateString("abc", "bca") ? "true" : "false") << std::endl; // Expected: true

    return 0;
}
