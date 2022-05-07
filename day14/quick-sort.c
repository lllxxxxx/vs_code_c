int fun(int arr[], int low, int high);
void quick_sort(int arr[], int start, int end);

int fun(int arr[],int low,int high){
    int key;
    key = arr[low];
    while(low<high){
        while(low<high&&arr[high]>=key)
            high--;
        if(low<high)
            arr[low++] = arr[high];
        while(low<high&&arr[low]<=key)
            low++;
        if(low<high)
            arr[high--] = arr[low];
    }
    arr[low] = key;
    return low;
}

void quick_sort(int arr[],int start,int end){
    int pos;
    if(start<end){
        pos = fun(arr, start, end);
        quick_sort(arr, start, pos - 1);
        quick_sort(arr, pos + 1, end);
    }
}


