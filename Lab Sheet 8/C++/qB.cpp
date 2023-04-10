#include <iostream>
#include <string>

using namespace std;

string getNextSmallestPalindrome(string num) {
    int n = num.length();
    int mid = n / 2;
    bool carry = true;
    
    // Compare the characters from the middle point towards the start and end of the string
    for(int i = mid - 1, j = (n % 2 == 0 ? mid : mid + 1); i >= 0 && j < n; i--, j++) {
        if(num[i] != num[j]) {
            carry = false;
            break;
        }
    }
    
    // If the input number is already a palindrome or if the left half is greater than the right half
    if(carry || num[mid] < '9') {
        // Copy the left half of the string to the right half, reversing it in the process
        for(int i = mid - 1, j = (n % 2 == 0 ? mid : mid + 1); i >= 0; i--, j++) {
            num[j] = num[i];
        }
        
        // If the resulting string is greater than the input number, we have found the next smallest palindrome
        if(num > num.substr(0, mid + (n % 2 == 0 ? 0 : 1))) {
            return num;
        }
    }
    
    // Add 1 to the middle character and propagate the carry to the left half of the string
    carry = true;
    for(int i = mid - 1, j = (n % 2 == 0 ? mid : mid + 1); i >= 0 && carry; i--, j++) {
        int digit = (num[i] - '0' + 1) % 10;
        num[i] = num[j] = digit + '0';
        carry = digit == 0;
    }
    
    // If there is a carry, we need to add an extra digit to the left half of the string
    if(carry) {
        num.insert(0, "1");
        num[n] = '1';
    }
    
    // Copy the left half of the string to the right half, reversing it in the process
    for(int i = mid - 1, j = (n % 2 == 0 ? mid : mid + 1); i >= 0; i--, j++) {
        num[j] = num[i];
    }
    return num;
}

int main(void){
    // Read the input number from the user
    string num;
    cout << "Enter a number: ";
    cin >> num;
    
    // Find the next smallest palindrome of the input number
    string nextPalindrome = getNextSmallestPalindrome(num);
    
    // Print the result
    cout << "The next smallest palindrome is: " << nextPalindrome << endl;
    return 0;
}