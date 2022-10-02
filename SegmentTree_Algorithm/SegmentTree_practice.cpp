#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

long long build_tree(std::vector<long long> &seg_tree, long long *arr, int node, int start, int end)
{
    if (start == end)
    {
        return seg_tree.at(node) = arr[start];
    }

    else 
    {
        int mid = (start + end) / 2;

        return seg_tree.at(node) = build_tree(seg_tree, arr, 2*node, start, mid) + build_tree(seg_tree, arr, 2*node+1, mid+1, end);
    }

    return seg_tree.at(node);
    
}

long long query(std::vector<long long> &seg_tree, int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
    {
        return 0;
    }

    else if (start >= left && end <= right)
    {
        return seg_tree.at(node);
    }

    else 
    {
        int mid = (start + end) / 2;
        return query(seg_tree, 2*node, start, mid, left, right) + query(seg_tree, 2*node+1, mid+1, end, left, right);
    }
}

void update(std::vector<long long> &seg_tree, int changed_idx, long long diff, int index, int start, int end)
{
    if (changed_idx < start || changed_idx > end)
    {
        return;
    }

    seg_tree.at(index) += diff;

    if (start != end)
    {
        int mid = (start + end) / 2;
        update(seg_tree, changed_idx, diff, 2*index, start, mid);
        update(seg_tree, changed_idx, diff, 2*index+1, mid+1, end);
    }


}

int main()
{
    //Getting inputs of basic conditions of array
    int N, M, K;
    std::cin >> N >> M >> K;

    //Declaring and assigning memory to array and tree vector
    long long *arr = new long long [N];
    std::vector<long long> seg_tree;

    int tree_height = (int)ceil(log2(N));
    int tree_size = (1 << (tree_height + 1));

    seg_tree.resize(tree_size);

    //Getting inputs of array elements
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    //Calling build_tree function
    build_tree(seg_tree, arr, 1, 0, N-1);

    //Declaring result vector
    std::vector<long long> results;

    //Getting inputs
    for (int i = 0; i < M + K; i++)
    {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        if (a == 2)
        {
            results.push_back(query(seg_tree, 1, 0, N-1, b-1, c-1));
        }

        else if (a == 1)
        {
            long long diff = c - arr[b-1];
            arr[b-1] = c;
            update(seg_tree, b-1, diff, 1, 0, N-1);
        }
    }

    //Print result vector elements
    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results.at(i) << std::endl;
    }

    return 0;

}