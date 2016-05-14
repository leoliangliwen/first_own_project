#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

// *************************** Class 2 Binary Search ***************************
// *************************** Class 2 Binary Search ***************************
// *************************** Class 2 Binary Search ***************************

// Classical Binary Search
// http://www.lintcode.com/en/problem/classical-binary-search/#
int findPosition(vector<int>& A, int target) {
    if (A.size() == 0) return -1;

    int start = 0;
    int end = A.size() - 1;

    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] == target) return mid;
        else if (A[mid] > target) end = mid;
        else if (A[mid] < target) start = mid;
    }

    if (A[start] == target) return start;
    if (A[end] == target) return end;
    return -1;
}

// First Position of Target
// http://www.lintcode.com/submission/4406252/
int binarySearch(vector<int> &A, int target) {
    if (A.size() == 0) return -1;

    int start = 0;
    int end = A.size() - 1;

    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] == target) end = mid;
        else if (A[mid] > target) end = mid;
        else if (A[mid] < target) start = mid;
    }

    if (A[start] == target) return start;
    if (A[end] == target) return end;
    return -1;
}

// Last Position of Target
// http://www.lintcode.com/en/problem/last-position-of-target/#
int lastPosition(vector<int>& A, int target) {
    if (A.size() == 0) return -1;

    int start = 0;
    int end = A.size() - 1;

    while(start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] == target) start = mid;
        else if (A[mid] > target) end = mid;
        else if (A[mid] < target) start = mid;
    }

    if (A[end] == target) return end;
    if (A[start] == target) return start;
    return -1;
}

// Search a 2D Matrix (Last row that matrix[row][0] <= target)
// http://www.lintcode.com/en/problem/search-a-2d-matrix/#
bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return false;

    // search for row_index
    int start = 0;
    int end = matrix.size() - 1;
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (matrix[mid][0] == target) return true;
        else if (matrix[mid][0] > target) end = mid;
        else if (matrix[mid][0] < target) start = mid;
    }

    int row_index;
    if (matrix[end][0] <= target) row_index = end;
    else if (matrix[start][0] <= target) row_index = start;
    else return false;

    // search for column_index
    start = 0;
    end = matrix[row_index].size() - 1;
    while(start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (matrix[row_index][mid] == target) return true;
        else if (matrix[row_index][mid] > target) end = mid;
        else if (matrix[row_index][mid] < target) start = mid;
    }

    if (matrix[row_index][start] == target) return true;
    if (matrix[row_index][end] == target) return true;
    return false;
}

// Search Insert Position (First position >= target)
// http://www.lintcode.com/en/problem/search-insert-position/#
int searchInsert(vector<int> &A, int target) {
    if (A.size() == 0) return 0;

    int start = 0;
    int end = A.size() - 1;

    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] == target) end = mid;
        else if (A[mid] > target) end = mid;
        else if (A[mid] < target) start = mid;
    }

    if (A[start] >= target) return start;
    if (A[end] >= target) return end;
    return A.size();
}

// Search in a Big Sorted Array
// http://www.lintcode.com/en/problem/search-in-a-big-sorted-array/#
class ArrayReader {
    vector<int> long_array;
public:
    ArrayReader(vector<int> &input) {long_array = input;}
    int get(int index) {
        if (index < long_array.size())
            return long_array[index];
        else return -1;
    }
};

int searchBigSortedArray(ArrayReader *reader, int target) {
    int len = 1;
    while (reader->get(len - 1) != -1 && reader->get(len - 1) < target)
    {
        len *= 2;
    }

    int start = 0;
    int end = len - 1;
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (reader->get(mid) == -1) end = mid;
        else if (reader->get(mid) == target) end = mid;
        else if (reader->get(mid) > target) end = mid;
        else if (reader->get(mid) < target) start = mid;
    }

    if (reader->get(start) == target) return start;
    if (reader->get(end) == target) return end;
    return -1;
}

// Find Minimum in Rotated Sorted Array (First position <= Last Number)
// http://www.lintcode.com/en/problem/find-minimum-in-rotated-sorted-array/#
int findMin(vector<int> &A) {
    int start = 0;
    int end = A.size() - 1;
    int target = A[end];

    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] == target) ;// won't happen
        else if (A[mid] > target) start = mid;
        else if (A[mid] < target) end = mid;
    }

    if (A[start] <= target) return A[start];
    else return A[end];
}

// Search in Rotated Sorted Array
// http://www.lintcode.com/en/problem/search-in-rotated-sorted-array/#
int search(vector<int> &A, int target) {
    if (A.size() == 0) return -1;

    int start = 0;
    int end = A.size() - 1;

    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] == target) return mid;
        else if (A[mid] > A[end])   // before break point
        {
            if (A[end] < target && target < A[mid]) end = mid;
            else start = mid;
        }
        else   // after break point
        {
            if (A[mid] < target && target <= A[end]) start = mid;
            else end = mid;
        }
    }

    if (A[start] == target) return start;
    if (A[end] == target) return end;
    return -1;
}

// First Bad Version (First version that is bad version)
// http://www.lintcode.com/en/problem/first-bad-version/#
class SVNRepo {
public:
    static bool isBadVersion(int k) {return true;}
};

int findFirstBadVersion(int n) {
    int start = 1;
    int end = n;

    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (SVNRepo::isBadVersion(mid) == true) end = mid;
        else start = mid;
    }

    if (SVNRepo::isBadVersion(start) == true) return start;
    return end;
}

// Sqrt(x) (Last number that number^2 <= x)
// http://www.lintcode.com/en/problem/sqrtx/
int sqrt(int x) {
    long start = 0;
    long end = x;

    while (start + 1 < end)
    {
        long mid = start + (end - start) / 2;
        if (mid *mid == x) return mid;
        else if (mid * mid > x) end = mid;
        else if (mid * mid < x) start = mid;
    }

    if (end * end <= x) return end;
    return start;
}

// Wood Cut
// http://www.lintcode.com/en/problem/wood-cut/
int woodCut_helper(vector<int> &L, int size)
{
    int answer = 0;
    for (int i = 0; i < L.size(); i++)
    {
        answer += L[i] / size;
    }
    return answer;
}

int woodCut(vector<int> L, int k) {
    if (L.size() == 0) return 0;

    int start = 1;
    int end = L[0];
    for (int i = 0; i < L.size(); i++)
    {
        if (L[i] > end) end = L[i];
    }

    while(start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        //cout << "start<" << start << ">, end<" << end << ">, mid<" << mid << ">\n";
        if (woodCut_helper(L, mid) == k) start = mid;
        else if (woodCut_helper(L, mid) > k) start = mid;
        else if (woodCut_helper(L, mid) < k) end = mid;
    }

    if(woodCut_helper(L, end) >= k) return end;
    if(woodCut_helper(L, start) >= k) return start;
    return 0;
}

// Find Peak Element
// http://www.lintcode.com/en/problem/find-peak-element/#
int findPeak(vector<int> A) {
    int start = 0;
    int end = A.size() - 1;

    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) return mid;
        else if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1]) start = mid;
        else if (A[mid - 1] > A[mid] && A[mid] > A[mid + 1]) end = mid;
        else // (A[mid - 1] > A[mid] && A[mid] < A[mid + 1]) start = mid
        {
            start = mid;
            // end = mid;
        }
    }

    if (A[start - 1] < A[start] && A[start] > A[start + 1]) return start;
    if (A[end - 1] < A[end] && A[end] > A[end + 1]) return end;
    return -1;
}

// Search for a Range
// http://www.lintcode.com/en/problem/search-for-a-range/#
vector<int> searchRange(vector<int> &A, int target) {
    vector<int> answer = {-1, -1};
    if (A.size() == 0) return answer;

    // search for the first appearence
    int start = 0;
    int end = A.size() - 1;

    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] == target) end = mid;
        else if (A[mid] > target) end = mid;
        else if (A[mid] < target) start = mid;
    }

    if (A[start] == target) answer[0] = start;
    else if (A[end] == target) answer[0] = end;
    else return answer;

    // search for the last appearence
    start = answer[0];
    end = A.size() - 1;
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] == target) start = mid;
        else if (A[mid] > target) end = mid;
        else if (A[mid] < target) start = mid;
    }

    if (A[end] == target) answer[1] = end;
    else answer[1] = start;

    return answer;
}



int main()
{
    return 1;
}
