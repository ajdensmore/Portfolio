/*
Given an integer find the closed palindrome
   
there can only be 3 cases:
case1: the closest palindrome is one digit more. i.e., 9999 -> 10001
case2: the closest palindrome is one digit less. i.e., 10001 -> 9999
case3: the closest palindrome has the same length as the original palindrom:
       if the # of digits is even: i.e., 1234, then the left half is 12
            a. 1234 -> 1221, where left half of 1234: 12 is reversed and then duplicated to the right half
            b. 1234 -> 1331, where left half was increased by one and then reversely duplicated to the right half
            c. 1234 -> 1111, where left half was decreased by one and then reversely duplicated to the right half
       if the # of digits is odd: i.e., 12345, then the left half is 123
            a. no change to left half and reversely duplicate left half (except mid) to the right half: 12321
            b. increase left half by one (124) and then duplicate left half to right (except mid): 12421
            c. decrease left half by one (122) and then duplicate left half to right (except mid): 12221
*/

#define ll long long
class Solution {
public:
    //T(n) = O(1), because there are only 5 candids to determine at a time
    string nearestPalindromic(string n) {
        ll len = n.size();
        ///special case: if len is 1
        if(len == 1){
            return to_string(stol(n)-1);
        }
        ///////////////////////////////    
            
        vector<ll> candids;
        
        //case1
        candids.push_back(pow(10, len) + 1);
        //case2
        candids.push_back(pow(10, len-1) - 1);
        //case3 - even # digits
        if(len%2 == 0){
            string res = "";
            string leftS = "";
            string rightS = "";
            ll leftD = len/2;
            ll left = stol(n.substr(0,leftD));
            //subcase a
            leftS = to_string(left);
            rightS = leftS;
            reverse(rightS.begin(), rightS.end());
            res = leftS+rightS;
            candids.push_back(stol(res));
            //subcase b
            leftS = to_string(left+1);
            rightS = leftS;
            reverse(rightS.begin(), rightS.end());
            res = leftS+rightS;
            candids.push_back(stol(res));
            //subcase c
            leftS = to_string(left-1);
            rightS = leftS;
            reverse(rightS.begin(), rightS.end());
            res = leftS+rightS;
            candids.push_back(stol(res));            
        }
        //case3 - odd # digits
        else{
            string res = "";
            string leftS = "";
            string rightS = "";
            ll leftD = len/2 + 1;
            ll left = stol(n.substr(0,leftD));
            //subcase a
            leftS = to_string(left);
            rightS = leftS;
            rightS.pop_back();
            reverse(rightS.begin(), rightS.end());
            res = leftS+rightS;
            candids.push_back(stol(res));
            //subcase b
            leftS = to_string(left+1);
            rightS = leftS;
            rightS.pop_back();
            reverse(rightS.begin(), rightS.end());
            res = leftS+rightS;
            candids.push_back(stol(res));
            //subcase c
            leftS = to_string(left-1);
            rightS = leftS;
            rightS.pop_back();
            reverse(rightS.begin(), rightS.end());
            res = leftS+rightS;
            candids.push_back(stol(res));                      
        }
        //select the closest candid
        ll res = candids[0];
        ll MaxDist = LONG_MAX;
        ll org = stol(n);
        for(auto it : candids){
            /*
            1. make sure the candid does not equal to the original number
            2. if there is a tie, select the smaller one, i.e., input: 88; candids: 99, 77; then 77 is selected
            */
            if(MaxDist >= abs(it - org) && it != org){
                if(MaxDist > abs(it - org)){
                    MaxDist = abs(it - org);
                    res = it;
                }
                else if (MaxDist == abs(it - org)){
                    res = min(res,it);
                }
            }
        }
        return to_string(res);
    }
};
