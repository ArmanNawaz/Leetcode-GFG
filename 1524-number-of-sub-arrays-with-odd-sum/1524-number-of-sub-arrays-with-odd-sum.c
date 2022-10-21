

int numOfSubarrays(int* arr, int arrSize){
    int evenCount = 0, oddCount = 0;
    int mod = 1e9 + 7;
    
    if(arr[0] % 2 == 0)
        ++evenCount;
    else
        ++oddCount;
    int ans = oddCount;
    
    for(int i = 1; i < arrSize; ++i) {
        if(arr[i] % 2 == 0)
            ++evenCount;
        else {
            int tmp = oddCount;
            oddCount = evenCount + 1;
            evenCount = tmp;
        }
        ans = (ans + oddCount) % mod;
    }
    return ans;
}