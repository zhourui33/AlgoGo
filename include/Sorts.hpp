#ifndef SORTS_HPP_20200922
#define SORTS_HPP_20200922

void merge_sort_inner(int a[], int start, int end);
void merge(int a[], int start, int mid, int end);
void quick_sort_inner(int a[], int start, int end);
int partition(int a[], int start, int end);

#define SWAP(lhs, rhs) do{                      \
                            int temp = lhs;     \
                            lhs = rhs;          \
                            rhs = temp;         \
                        }while(0);

void bubble_sort(int a[], int num)
{
    if(num <= 1) return;

    bool swaped = true;
    
    for(int i = 0; i < num && swaped; i++)
    {
        swaped = false;
        for(int j = 0; j < num-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                SWAP(a[j], a[j+1]);
                swaped = true;
            }
        }
    }
}

void insertion_sort(int a[], int num)
{
    if(num <= 1) return;

    for(int i = 1; i < num; ++i)
    {
        int value = a[i];
        int j = i-1;
        for(; j>=0; --j)
        {
            if(a[j] <= value)        //behind the value less or equal a[i] is the position to insert
            {
                break;
            }
            a[j+1] = a[j];          // value greater than a[i] move behind
        }
        a[j+1] = value;              // put the value on the find position
    }
}

void selection_sort(int a[], int num)
{
    if(num <= 1) return;

    for(int i = 0; i < num; ++i)
    {
        int min_index = i;
        for(int j = i; j < num; j++)
        {
            if(a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        SWAP(a[min_index], a[i]);
    }
}

void merge_sort(int a[], int num)
{
    merge_sort_inner(a, 0, num-1);
}

void merge_sort_inner(int a[], int start, int end)
{
    if(start >= end) return;

    int mid = start + (end - start) / 2;
    merge_sort_inner(a, start, mid);
    merge_sort_inner(a, mid+1, end);
    
    merge(a, start, mid, end);
}

void merge(int a[], int start, int mid, int end)
{
    int *temp = new int[end -start +1];
    
    int  i = start , 
            j = mid+1, 
            k = 0;
    while(i <= mid && j <= end)
    {
        if(a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    //将剩余部分赋给temp
    while(i <= mid)
    {
        temp[k++] = a[i++];
    }
    while(j <= end)
    {
        temp[k++] = a[j++];
    }

    for(int ii = 0; ii <= (end - start); ++ii)
    {
        a[start + ii] = temp[ii];
    }    
    delete[] temp;
}

void quick_sort(int a[], int num)
{
    if(num <= 1) return;

    quick_sort_inner(a, 0, num-1);
}

void quick_sort_inner(int a[], int start, int end)
{
    if(start >= end) return;

    int pivot = partition(a, start, end);
    quick_sort_inner(a, start, pivot - 1);
    quick_sort_inner(a, pivot + 1, end);
}

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int i = start; // i记录已排序取间，i前边都是小于Pivot的
    for(int j = start; j < end; ++j)
    {
        if(a[j] < pivot)
        {
            SWAP(a[i], a[j]);
            i++;
        }
    }
    SWAP(a[i], a[end]); // 把轴换到i的位置，i前边全是小于pivot的，后边全是大于的

    return i;
}

#endif
