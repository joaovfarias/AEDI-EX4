typedef struct {
    int val;
    int index;
}pair;

pair *pairMerge(pair *leftArr, pair *rightArr, int n, int leftSize, int rightSize) {

    pair *output = malloc(sizeof(pair) * n);
    int i = 0, l = 0, r = 0;

    while (l < leftSize && r < rightSize) {
        if (leftArr[l].val < rightArr[r].val) {
            output[i] = leftArr[l];
            i++;
            l++;
        } else {
            output[i] = rightArr[r];
            i++;
            r++;
        }
    }
    while (l < leftSize) {
        output[i] = leftArr[l];
        i++;
        l++;
    }
    while (r < rightSize) {
        output[i] = rightArr[r];
        i++;
        r++;
    }

    return output;
}

pair *pairMergeSort(pair *array, int n) {

    if (n <= 1) {
        return array;
    }

    int mid = n / 2;
    pair *left = malloc(sizeof(pair) * mid);
    pair *right = malloc(sizeof(pair) * (n - mid));
    pair *resultado;
    int idx = 0;

    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }
    for (int j = mid; j < n; j++) {
        right[idx] = array[j];
        idx++;
    }

    left = pairMergeSort(left, mid);
    right = pairMergeSort(right, n - mid);
    resultado = pairMerge(left, right, n, mid, n - mid);

    return resultado;
}

int *merge(int *leftArr, int *rightArr, int n, int leftSize, int rightSize){

    int *output = malloc(sizeof(int) * n);
    int i = 0, l = 0, r = 0;

    while (l < leftSize && r < rightSize){
        if (leftArr[l] < rightArr[r]){
            output[i] = leftArr[l];
            i++;
            l++;
        }
        else{
            output[i] = rightArr[r];
            i++;
            r++;
        }
    }
    while (l < leftSize){
        output[i] = leftArr[l];
        i++;
        l++;
    }
    while (r < rightSize){
        output[i] = rightArr[r];
        i++;
        r++;
    }

    return output;
}

int *mergeSort(int *array, int n){

    if (n <= 1){
        return array;
    }

    int mid = n / 2;
    int *left = malloc(sizeof(int) * mid);
    int *right = malloc(sizeof(int) * (n - mid));
    int *resultado;
    int idx = 0;

    for (int i = 0; i < mid; i++){
        left[i] = array[i];
    }
    for (int j = mid; j < n; j++){
        right[idx] = array[j];
        idx++;
    }

    left = mergeSort(left, mid);
    right = mergeSort(right, n - mid);
    resultado = merge(left, right, n, mid, n - mid);

    return resultado;

}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize){

    pair *cpy = malloc(sizeof(pair) * numsSize);
    for (int i = 0; i < numsSize; i++){
        cpy[i].val = nums[i];
        cpy[i].index = i;
    }

    cpy = pairMergeSort(cpy, numsSize);
    
    int *indexes = malloc(sizeof(int) * k);
    int index = 0;
    for (int p = numsSize - k; p < numsSize; p++){
        indexes[index] = cpy[p].index;
        index++;
    }

    indexes = mergeSort(indexes, k);

    int *result = malloc(sizeof(int) * k);

    for (int l = 0; l < k; l++){
        result[l] = nums[indexes[l]];
    }

    *returnSize = k;
    return result;

}