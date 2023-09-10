#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

// 세그먼트 트리의 노드 구조체
struct SegmentTreeNode {
    int start, end;
    long long mul; // 이 노드가 나타내는 범위의 곱

    SegmentTreeNode *left;
    SegmentTreeNode *right;

    SegmentTreeNode(int start, int end)
        : start(start), end(end), mul(1), left(nullptr), right(nullptr) {}
};

// 세그먼트 트리 클래스
class SegmentTree {
  public:
    SegmentTree(vector<int> &nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }

    // 범위 내의 곱을 구하는 함수
    long long query(int left, int right) { return query(root, left, right); }

    // 인덱스 i의 값을 업데이트하는 함수
    void update(int i, int val) { update(root, i, val); }

  private:
    SegmentTreeNode *root;

    // 세그먼트 트리를 생성하는 함수
    SegmentTreeNode *buildTree(vector<int> &nums, int start, int end) {
        if (start > end)
            return nullptr;

        SegmentTreeNode *root = new SegmentTreeNode(start, end);

        if (start == end) {
            root->mul = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            root->left = buildTree(nums, start, mid);
            root->right = buildTree(nums, mid + 1, end);
            root->mul = (root->left->mul * root->right->mul) % MOD;
        }

        return root;
    }

    // 범위 내의 곱을 구하는 재귀 함수
    long long query(SegmentTreeNode *root, int left, int right) {
        if (!root)
            return 1;
        if (left > root->end || right < root->start)
            return 1;

        if (left <= root->start && right >= root->end) {
            return root->mul;
        }

        int mid = root->start + (root->end - root->start) / 2;
        return (query(root->left, left, min(right, mid)) *
                query(root->right, max(left, mid + 1), right)) %
               MOD;
    }

    // 인덱스 i의 값을 업데이트하는 재귀 함수
    void update(SegmentTreeNode *root, int i, int val) {
        if (!root)
            return;

        if (root->start == root->end && root->start == i) {
            root->mul = val;
            return;
        }

        int mid = root->start + (root->end - root->start) / 2;
        if (i <= mid) {
            update(root->left, i, val);
        } else {
            update(root->right, i, val);
        }

        root->mul = (root->left->mul * root->right->mul) % MOD;
    }
};

vector<int> nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    nums.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    SegmentTree st(nums);

    for (int i = 0; i < M + K; i++) {
        int com;
        cin >> com;

        int b, c;
        cin >> b >> c;
        if (com == 1) {
            st.update(b - 1, c);
        } else if (com == 2) {
            cout << st.query(b - 1, c - 1) << '\n';
        }
    }

    return 0;
}
