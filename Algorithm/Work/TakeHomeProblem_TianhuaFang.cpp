#include <vector>
#include <iostream>

/*
Idea: 
1. Since the input array is sorted(non-decreasing order), binary search can be applied.
2. In order to find the target with smallest index, set the right boundry to middle idx when current value >= target value for next iteration.
*/

int Search(const std::vector<int> &src, int target){
    int len = src.size();

    if(len == 0){
        return 0;
    }

    // Do binary search
    int l = 0;
    int r = len - 1;

    const int *pSrc = src.data();

    while(l < r){
        int mid = l + (r - l) / 2;
        int curr = pSrc[mid];

        if(curr < target){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }

    if(pSrc[r] == target){
        return r;
    }

    return len;
}


/*
Test Plan
Equivalent classes by Input:

a. vector<int>: src
    1. size = odd number
    2. size = even number

b. int: target
    1. not found
    2. find
        1. repeated
        2. unique
        3. two boundries
            i. min
            ii. max

Special Cases:
1. size = 0
2. size = 1
3. all int in arraies are the same

*/

int RunTest(const std::vector<int>& in, int target, int reference, const std::string& caseName){
    int idx = Search(in, target);

    // pass
    if(idx == reference){
        return 0;
    }

    // failed, log details
    std::cout << "case [" << caseName << "] failed. Expected idx = " << reference << ", but actual = " << idx << std::endl; 
    return 1;
}

int main(int argc, char *argv[])
{
    int nFailed = 0;

    // test empty array
    std::vector<int> srcEmpty { };   // empty src
    nFailed += RunTest(srcEmpty, 1, 0, "size = 0");

    // test single item
    std::vector<int> srcSingle { 1 };
    nFailed += RunTest(srcSingle, 1, 0,  "size = 1, found");
    nFailed += RunTest(srcSingle, -1, 1, "size = 1, lt min");
    nFailed += RunTest(srcSingle, 9, 1,  "size = 1, gt max");

    // test odd size
    std::vector<int> srcOdd { 1, 2, 3, 3, 5, 6, 7 };
    nFailed += RunTest(srcOdd, 4, 7,   "odd size, not found");
    nFailed += RunTest(srcOdd, 5, 4,   "odd size, found unique");
    nFailed += RunTest(srcOdd, 3, 2,   "odd size, found repeated");
    nFailed += RunTest(srcOdd, 1, 0,   "odd size, found min");
    nFailed += RunTest(srcOdd, 7, 6,   "odd size, found max");

    // test even size
    std::vector<int> srcEven { 1, 2, 3, 4, 4, 6, 7, 8 };
    nFailed += RunTest(srcEven, 5, 8,   "odd size, not found");
    nFailed += RunTest(srcEven, 6, 5,   "odd size, found unique");
    nFailed += RunTest(srcEven, 4, 3,   "odd size, found repeated");
    nFailed += RunTest(srcEven, 1, 0,   "odd size, found min");
    nFailed += RunTest(srcEven, 8, 7,   "odd size, found max");

    // test special  
    std::vector<int> srcSame { 1, 1, 1, 1, 1, 1, 1 };
    nFailed += RunTest(srcSame, 1, 0, "all same, found");
    nFailed += RunTest(srcSame, 3, 7, "all same, not found");

    if(nFailed == 0){
        std::cout << "all test cases passed." << std::endl;
    }else{
        std::cout << nFailed << " test cases failed." << std::endl;
    }

    return 0;
}