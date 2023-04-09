#include<iostream>
#include<bits/stdc++.h>
#include<vector>

std::string next_smallest_palindrome(std::string input, int n) {
    // If no is all 9's
    bool is_all_nines = true;
    for (int i = 0; i < n; i++)
    {
        if (input[i] != '9'){
            is_all_nines = false;
        }
    }
    if(is_all_nines) {
        std::string res = "1";
        for (int i = 1; i < n;i++){
            std::string z = "0";
            res.append(z);
        }
        std::string o = "1";
        res.append(o);
        return res;
    }

    if (n % 2 != 0)
        {
            int mid = (n - 1 / 2);
            // Find the digits around middle digit
            input[mid - 1] > input[mid + 1] ? input[mid + 1] = input[mid - 1] : {
                if (input[mid]=='9'){
                    input[mid] == '0';
                    input[mid - 1] += 1;
                } else {
                    
                }
            }input[mid] += 1;
            std::cout << "starting odd\n";
            // Replace right half with mirror of left half
            for (int i = 0; i <= mid - 1; i++)
            {
                input[mid + i + 1] = input[mid - i - 1];
            }
            return input;
        }
        else
        {
            int midl = (n - 1) / 2;
            int midr = (n + 1) / 2;
            // Find the middle two digits
            input[midl] > input[midr] ? input[midr] = input[midl] : input[midl] += 1;
            // Replace right half with mirror of left half
            for (int i = 0; i <= midl; i++)
            {
                input[midr + i] = input[midl - i];
            }
            return input;
        }

    return "O-Oh! Something went wrong!";
}

int main(void){
    std::string input;
    int n;
    std::cin >> n;
    std::cin >> input;

    std::cout << next_smallest_palindrome(input, n);
    return 0;
}