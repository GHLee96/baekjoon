#include <iostream>
#include <vector>

using namespace std;

struct SegmentTreeNode {
    int start, end;
    long long min_val;

    SegmentTreeNode *left;
    SegmentTreeNode *right;

    SegmentTreeNode(long long start, long long end)
        : start(start), end(end), min_val(0x7fffffff), left(nullptr),
          right(nullptr) {}
};

class SegmentTree {
  public:
    SegmentTree(vector<long long> &nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }

    long long query(int left, int right) { return query(root, left, right); }

  private:
    SegmentTreeNode *root;

    SegmentTreeNode *buildTree(vector<long long> &nums, long long start,
                               long long end) {
        if (start > end)
            return nullptr;

        SegmentTreeNode *root = new SegmentTreeNode(start, end);

        if (start == end) {
            root->min_val = nums[start];
        } else {
            long long mid = start + (end - start) / 2;
            root->left = buildTree(nums, start, mid);
            root->right = buildTree(nums, mid + 1, end);
            root->min_val = min(root->left->min_val, root->right->min_val);
        }

        return root;
    }

    long long query(SegmentTreeNode *root, int left, int right) {
        if (!root)
            return 0x7fffffff;
        if (left > root->end || right < root->start)
            return 0x7fffffff;

        if (left <= root->start && right >= root->end) {
            return root->min_val;
        }

        int mid = root->start + (root->end - root->start) / 2;
        return min(query(root->left, left, min(right, mid)),
                   query(root->right, max(left, mid + 1), right));
    }
};

vector<long long> nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M;
    cin >> N >> M;

    nums.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    SegmentTree st(nums);

    for (int i = 0; i < M; i++) {
        long long b, c;
        cin >> b >> c;

        cout << st.query(b - 1, c - 1) << '\n';
    }

    return 0;
}
