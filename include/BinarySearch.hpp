#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

int binary_search(int a[], int num, int target)
{
    int start, mid, end;
    start = 0;
    end = num - 1;

    while(start <= end)
    {
        mid = start + (end - start) / 2;
        
        if(a[mid] == target)
        {
            return mid;
        }
        else if(a[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }        
    }
    return -1;
}

int binary_search_first(int a[], int num, int target)
{
    int pos = binary_search(a, num, target);
    while((pos > 0) && (a[pos] == a[pos -1]))
    {
        pos--;
    }
    return pos;
}

int binary_search_last(int a[], int num, int target)
{
    int pos = binary_search(a, num, target);
    while((pos < num-1) && (a[pos] == a[pos + 1]))
    {
        pos++;
    }
    return pos;
}

int binary_search_first_greater_or_equal(int a[], int num, int target)
{
    int start, end, mid;
    start = 0;
    end = num - 1;

    while(start <= end)
    {
        mid = start + ((end - start)>>1);
        if(a[mid] >= target)
        {
            if(mid == 0 || a[mid-1] < target)
            {
                return mid;
            }
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int binary_search_last_less_or_equal(int a[], int num, int target)
{
    int start, end, mid;
    start = 0;
    end = num - 1;

    while(start <= end)
    {
        mid = start + ((end - start)>>1);
        if(a[mid] <= target)
        {
            if(mid == num-1 || a[mid+1] > target)
            {
                return mid;
            }
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

#endif