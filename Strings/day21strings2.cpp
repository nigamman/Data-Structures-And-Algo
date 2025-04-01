// #include <iostream> 
// #include <vector>
// #include <string.h>
// using namespace std;

//     int findPairs(vector<int>& nums, int k) {
//         int count = 0;
//         int n = nums.size();
        
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (abs(nums[i] - nums[j]) == k) {
//                     //cout << i << " "<<j <<" "<< k << endl;;
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }

//  int main () {
//     vector<int> nums = {3,1,4,1,5};
//     int k = 2;
//     int ans = findPairs(nums,k);
//     cout << ans;
// }

#include <iostream>
#include <string>

using namespace std;

string removeDuplicates(string s) {
    int n = s.size();
    int slow = 0, fast = 0;

    while (fast < n) {
        // If adjacent characters are the same, move fast pointer to next non-duplicate character
        while (fast < n && s[fast] == s[slow]) {
            fast++;
        }
        
        // If adjacent characters are different, copy the non-duplicate character
        // to the appropriate position in the string
        if (fast < n && s[fast] != s[slow]) {
            slow++;
            s[slow] = s[fast];
        }
    }

    // Return the substring from the start pointer to the end pointer
    return s.substr(0,slow + 1);
}

int main() {
    string input = "abbacccaaa";
    cout << "Original string: " << input << endl;
    cout << "String after removing adjacent duplicates: "<< removeDuplicates(input) << endl;
    return 0;
}
