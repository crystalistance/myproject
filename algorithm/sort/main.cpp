#include <iostream>
#include <vector>

using namespace std;

/*
 *冒泡排序
 *时间复杂度 平均O(n^2) 最坏O(n^2) 最好O(n)
 *比如12345，优化过的冒泡排序第一趟就发现，没有任何交换，则全部有序，相当于遍历一次
 * 稳定
 */

void BubbleSort(vector<int> &v) {
    int n = v.size();
    bool isExchange = true;

    for (int i = 0; i < n-1 && isExchange; i++) {
        isExchange = false;

        for (int j = 0; j < n-1-i; j++) {
            if (v[j] > v[j+1]) {
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;

                isExchange = true;
            }
        }
    }
}


/**
 *插入排序
 *时间复杂度 平均O(n^2) 最坏O(n^2) 最好O(n)
 *如12345，从小到大排序，则相当于只从头到尾遍历一次，没有作任何交换
 *稳定
 */

void InsertSort(vector<int> &v) {
    int n = v.size();

    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (v[j]< v[j-1]) {
                int tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
        }
    }
}


/**
 *选择排序
 *时间复杂度 平均O(n^2) 最坏O(n^2) 最好O(n^2)
 *不稳定
 * */

void SelectSort(vector<int> &v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            if (v[i] > v[j]) {
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}

/**
 *希尔排序
 *时间复杂度 平均O(n^1.3) 最坏O(n^2) 最好O(n) 
 *不稳定
 **/

void ShellSort(vector<int> &v) {
    
}


/**
 *快速排序
 **/

int Partition(vector<int> &v, int start, int end) {
    int i = start, j = end;
    int tmp = v[i];

    while (i < j) {
        while (i < j && tmp <= v[j]) {
            j--;
        } 

        if (i < j) {
            v[i++] = v[j];
        }

        while (i < j && tmp >= v[i]) {
            i++;
        }

        if (i < j) {
            v[j--] = v[i];
        }
    }

    v[i] = tmp;
    return i;
}

void QuickSort(vector<int> &v, int start, int end) {
    if (start < end) {
        int n = Partition(v, start, end);
        QuickSort(v, start, n-1);
        QuickSort(v, n+1, end);
    }
}

/**
 *快速排序 
 *时间复杂度 平均O(nlgn) 最坏O(n^2) 最好O(nlgn)
 *不稳定
 **/
void QuickSort(vector<int> &v) {
    int n = v.size();
    QuickSort(v, 0, n-1);
}

/**
 *堆排序
 *时间复杂度 平均O(nlgn) 最坏O(nlgn) 最好O(nlgn)
 *不稳定
 **/

//从小到大排序要建大根堆，每次把堆顶(最大)放到最后，然后前面的再建大根堆

void HeapAdjust(vector<int> &v, int start, int end) {
    int parent = start;
    int child = 2 * parent + 1;

    while (child <= end) {
        if (child + 1 <= end && v[child + 1] > v[child]) {
            child++;
        }

        if (v[parent] >= v[child]) {
            break;
        } else {
            int tmp = v[parent];
            v[parent] = v[child];
            v[child] = tmp;

            parent = child;
            child = 2 * parent + 1;
        }
    }
}

void HeapSort(vector<int> &v) {
    int n = v.size();

    //从最后一个父节点开始建堆
    for (int i = n/2 - 1; i >= 0; i--) {
        HeapAdjust(v, i, n-1);
    }

    for (int i = n-1; i > 0; i--) {
        int tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;

        HeapAdjust(v, 0, i-1);
    }
}

/**
 *归并排序
 *时间复杂度 平均O(nlgn) 最坏O(nlgn) 最好O(nlgn)
 *稳定
 **/

void MergeSort(vector<int> &v) {
    
}

/**
 *计数排序  O(n+k)  O(n+k)  O(n+k)   空间复杂度 O(n+k)
 *
 * 找出待排序的数组中最大和最小的元素；
 * 统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
 * 对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；
 *反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。
 *
 *
 * 桶排序   O(n+k)  O(n^2)  O(n)     空间复杂度 O(n+k)
 *
 * 桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。桶排序 (Bucket sort)的工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。
 *
 *
 * 基数排序 O(n*k)  O(n*k)  O(n*k)   空间复杂度 O(n+k)
 *
 * 基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。
 **/

void Show(vector<int> v) {
    for (auto item : v) {
        cout << item << ",";
    }
    cout << endl;
}

int main() {
    vector<int> v = {1,4,3,2,5,6,8,7};
//    BubbleSort(v);
//    InsertSort(v);
//    SelectSort(v);
//    QuickSort(v);
    HeapSort(v);
    Show(v);

}
