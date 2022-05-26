#include<iostream>
#include<vector>
using namespace std;

//下沉
void down(vector<int>& nums,  int i, int n){
    if (i >= n) return;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int minIndex = i;
    if (left < n && nums[left] < nums[minIndex]) {
        minIndex = left;
    }
    if (right < n && nums[right] < nums[minIndex]) {
        minIndex = right;
    }
    if (minIndex != i) {
        swap(nums[minIndex], nums[i]);
        down(nums, minIndex, n);
    }
}

//初始化建堆
void build_heap(vector<int>& nums, int n) {
    int parent = (n - 1) / 2;
    for (int i = parent; i >= 0; i--) {
        down(nums, i, n);
    }
}

//上浮
void up(vector<int>& nums, int i) {
    if (i <= 0) return;
    int parent = i / 2;
    if (nums[i] < nums[parent]) {//交换
        swap(nums[i], nums[parent]);
        up(nums, parent);
    }
}
//向数组尾部添加一个结点，并将此结点进行上浮操作，使其符合堆的性质
void insert(vector<int>& nums, int val) {
    nums.push_back(val);
    up(nums, nums.size() - 1);
}

//先将堆顶结点与尾结点交换，再将新的堆点结点进行下沉操作，使其符合堆的性质
void Delete(vector<int>& nums) {
    swap(nums[0], nums[nums.size() - 1]);
    nums.pop_back();
    down(nums, 0, nums.size());
}

//进行排序
vector<int> sortArray(vector<int>& nums) {
    build_heap(nums, nums.size());//初始化大顶堆(从下往上headfy)
    for (int i = nums.size() - 1; i > 0; i--) {
        swap(nums[0], nums[i]);//交换一次后重新down
        down(nums, 0, i);
    }
    return nums;
}

int main() {
    vector<int> temp = { 3,2,5,6,1,4 };
    build_heap(temp, temp.size());
    insert(temp, 0);
    Delete(temp);
    for (const auto& a : temp) {
        cout << a << endl;
    }
    return -1;
}
