int search(int* arr, int n, int key) {
    // Write your code here.
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key)
          return mid;
        if(arr[mid]>=arr[0])
        {
            if(arr[0]<=key && key<=arr[mid])
              high=mid-1;
            else
              low=mid+1;
        }
        else
        {
            if(arr[mid]<=key && key<=arr[n-1])
              low=mid+1;
            else
              high=mid-1;
        }
    }
    return -1;
}
