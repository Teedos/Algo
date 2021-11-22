#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int countRangeSum(int n, int nums[], int low, int up){
    long sum[n+1];
    for (int i = 0;i < n; i++){
        sum[i+1] = sum[i] + nums[i];
    }
    return mergeSort(sum, 0, n, low, up);
}

int mergeSort(long sum[], int start, int end, int low, int up){
    if (start >= end)
        return 0;
    int middle = (end + 1 - start) / 2 + start;
    int count = mergeSort(sum, start, middle -1, low, up) + mergeSort(sum, middle, end, low, up);
    int startIndex = middle;
    int endIndex = middle;
    for(int i = start; i < middle; i++){
        while(startIndex <= end && sum[startIndex] - sum[i] < low){
            startIndex ++;
        }
        while(endIndex <= end && sum[endIndex] - sum[i] <= up){
            endIndex ++;
        }
        count += endIndex - startIndex;
    }
    merge(sum, start, middle -1, middle, end);
    return count;
}
void merge(long sum[], int start1, int end1, int start2, int end2){
    long temp[end2 - start1 +1];
    int index = 0;
    int index1 = start1;
    int index2 = start2;
    while(index1 <= end1 && index2 <= end2){
        if(sum[index1] <= sum[index2]){
            temp[index++] = sum[index1++];
        }else{
            temp[index++] = sum[index2++];
        }
    }

    while(index1 <= end1){
        temp[index++] = sum[index1++];
    }
    while(index2 <= end2){
        temp[index++] = sum[index2++];
    }
}
int main()
{
    int n, low, up;
    cin >> n >> low >> up;
    int nums[n];
    for (int i= 0; i<n; i++){
        cin >> nums[i];
    }

    return 0;
}