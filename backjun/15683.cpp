#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int map[10][10];
vector<pair<int, int>> cctvs;
int N, M;
int ans = 987654321;
queue<pair<int, int>> q;
bool visited[10][10];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

struct Change {
    int x, y;
    int prev;
};

vector<Change> CaptureWithRecord(int dir, int x, int y) {
    vector<Change> changes;
    switch (dir) {
    case 0: // Up
        for (int i = x - 1; i >= 0; i--) {
            if (map[i][y] == 6) break;
            if (map[i][y] == 0) {
                changes.push_back({ i, y, map[i][y] });
                map[i][y] = '#';
            }
        }
        break;
    case 1: // Down
        for (int i = x + 1; i < N; i++) {
            if (map[i][y] == 6) break;
            if (map[i][y] == 0) {
                changes.push_back({ i, y, map[i][y] });
                map[i][y] = '#';
            }
        }
        break;
    case 2: // Left
        for (int j = y - 1; j >= 0; j--) {
            if (map[x][j] == 6) break;
            if (map[x][j] == 0) {
                changes.push_back({ x, j, map[x][j] });
                map[x][j] = '#';
            }
        }
        break;
    case 3: // Right
        for (int j = y + 1; j < M; j++) {
            if (map[x][j] == 6) break;
            if (map[x][j] == 0) {
                changes.push_back({ x, j, map[x][j] });
                map[x][j] = '#';
            }
        }
        break;
    }
    return changes;
}

void UndoChanges(const vector<Change>& changes) {
    for (const auto& ch : changes)
        map[ch.x][ch.y] = ch.prev;
}

// ����� 0�� ������ ���� ������� ������ ó�� (0�� �������� ����ε� ����)
int Solve() {
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map[i][j] == 0)
                cnt++;
    return cnt;
}

// �� CCTV ������ ȸ�� ��� (������ 0: Up, 1: Down, 2: Left, 3: Right)
vector<vector<vector<int>>> rotations(6);
void initRotations() {
    rotations[1] = { {0}, {1}, {2}, {3} };
    rotations[2] = { {0,1}, {2,3} };
    rotations[3] = { {0,3}, {3,1}, {1,2}, {2,0} };
    rotations[4] = { {2,0,3}, {0,3,1}, {3,1,2}, {1,2,0} };
    rotations[5] = { {0,1,2,3} };
}

// n��° CCTV�� ȸ�� ������ �����ϴ� ��Ʈ��ŷ �Լ�
void SearchAndRotate(int n) {
    if (n == cctvs.size()) {
        ans = min(ans, Solve());
        return;
    }

    int x = cctvs[n].first;
    int y = cctvs[n].second;
    int type = map[x][y]; // CCTV�� ���� (1~5)

    // �̸� ������ ȸ�� ������ ��ȸ
    for (auto& dirs : rotations[type]) {
        vector<Change> totalChanges;
        // �� ���⿡ ���� ����� ���� ����ϸ� ����
        for (int d : dirs) {
            vector<Change> changes = CaptureWithRecord(d, x, y);
            totalChanges.insert(totalChanges.end(), changes.begin(), changes.end());
        }
        SearchAndRotate(n + 1);
        UndoChanges(totalChanges);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] > 0 && map[i][j] < 6)
                cctvs.push_back({ i, j });
        }
    }

    rotations.resize(6);
    initRotations();
    SearchAndRotate(0);
    cout << ans;
    return 0;
}
