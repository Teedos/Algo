def countRangeSum(n,nums, low, up){
    long sum[n+1]
    for ( i = 0;i < n; ){
        sum[i+1] = sum[i] + nums[i];
    }
    return mergeSort(sum, 0, n, low, up);
}

def mergeSort(sum, start, end, low, up){
    if (start >= end)
        return 0;
    int middle = (end + 1 - start) / 2 + start;
    int count = mergeSort(sum, start, middle -1, low, up) + mergeSort(sum, middle, end, low, up);
    int startIndex = middle;
    int endIndex = middle;
    for(int i = start; i < middle; i++){
        while(startIndex <= end && sum[startIndex] - sum[i] < low){
            startIndex ++
        }
        while(endIndex <= end && sum[endIndex] - sum[i] <= up){
            endIndex ++
        }
        count += endIndex - startIndex;
    }
    merge(sum, start, middle -1, middle, end);
    return count;
}

def merge(sum,  start1,  end1,  start2,  end2){
    long temp[end2 - start1 +1];
    int index = 0;
    int index1 = start1;
    int index2 = start2;
    while(index1 <= end1 && index2 <= end2){
        if(sum[index1] <= sum[index2]){
            temp[index += 1] = sum[index1 += 1]
        }else{
            temp[index + = 1] = sum[index2 += 1]
        }
    }

    while(index1 <= end1){
        temp[index += 1] = sum[index1 += 1]
    }
    while(index2 <= end2){
        temp[index += 1] = sum[index2 += 1]
    }
}

n, lower, upper = input().split(" ")
nums = list(map(int, input().split()))
