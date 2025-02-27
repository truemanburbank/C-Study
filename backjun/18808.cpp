#include <iostream>
#include <vector>
using namespace std;

struct StickerInfo
{
    int row;
    int col;
};

vector<vector<vector<int>>> stickers;
vector<StickerInfo> stickerInfo;

int N, M, K;
bool board[50][50];

// 스티커 붙이기
// k = 스티커 인덱스
bool Sticker(vector<vector<int>> sticker, int x, int y)
{
    // 붙일 자리에 다른 스티커 있는지 확인
    // 스티커 붙일 수 있는지 확인

    for (int i = 0; i < sticker.size(); i++)
    {
        for (int j = 0; j < sticker[0].size(); j++)
        {
            if (x + i >= N || y + j >= M) return false;
            if (board[x + i][y + j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }

    // 스티커 붙임
    for (int i = 0; i < sticker.size(); i++)
    {
        for (int j = 0; j < sticker[0].size(); j++)
        {
            board[x + i][y + j] += sticker[i][j] == 1;
        }
    }

    return true;
}

// 스티커 회전
vector<vector<int>> Rotate90(int k)
{
    vector<vector<int>> rotatedSticker(stickerInfo[k].col, vector<int>(stickerInfo[k].row, 0));

    for (int i = 0; i < stickerInfo[k].row; i++)
    {
        for (int j = 0; j < stickerInfo[k].col; j++)
        {
            rotatedSticker[j][stickerInfo[k].row - 1 - i] = stickers[k][i][j];
        }
    }

    return rotatedSticker;
}

vector<vector<int>> Rotate180(int k)
{
    vector<vector<int>> rotatedSticker(stickerInfo[k].row, vector<int>(stickerInfo[k].col, 0));

    for (int i = 0; i < stickerInfo[k].row; i++)
    {
        for (int j = 0; j < stickerInfo[k].col; j++)
        {
            rotatedSticker[stickerInfo[k].row - 1 - i][stickerInfo[k].col - 1 - j] = stickers[k][i][j];
        }
    }

    return rotatedSticker;
}


vector<vector<int>> Rotate270(int k)
{
    vector<vector<int>> rotatedSticker(stickerInfo[k].col, vector<int>(stickerInfo[k].row, 0));

    for (int i = 0; i < stickerInfo[k].row; i++)
    {
        for (int j = 0; j < stickerInfo[k].col; j++)
        {
            rotatedSticker[stickerInfo[k].col - 1 - j][i] = stickers[k][i][j];
        }
    }

    return rotatedSticker;
}

vector<vector<int>> Rotate(int n, int k)
{
    switch (n)
    {
    case 0:
        return Rotate90(k);
    case 1:
        return Rotate180(k);
    case 2:
        return Rotate270(k);
    }
}

int GetAnswer()
{
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j])
                ans++;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> K;

    // 스티커 입력 받음
    for (int i = 0; i < K; i++)
    {
        int c, r;
        cin >> c >> r;
        stickerInfo.push_back({ c, r});
        vector<vector<int>> sticker(c);
        for (int tmp_c = 0; tmp_c < c; tmp_c++)
        {
            for (int tmp_r = 0; tmp_r < r; tmp_r++)
            {
                int tmp = 0;
                cin >> tmp;
                sticker[tmp_c].push_back(tmp);
            }
        }

        stickers.push_back(sticker);
    }

    for (int k = 0; k < K; k++) {
        bool placed = false;
        for (int rot = 0; rot < 4 && !placed; rot++) {
            vector<vector<int>> curSticker;
            if (rot == 0)
                curSticker = stickers[k];
            else
                curSticker = Rotate(rot - 1, k);  // Rotate 함수가 회전한 스티커 반환

            int stickerRows = curSticker.size();
            int stickerCols = curSticker[0].size();

            // 가능한 모든 위치 (i, j)에서 시도
            for (int i = 0; i <= N - stickerRows && !placed; i++) {
                for (int j = 0; j <= M - stickerCols && !placed; j++) {
                    if (Sticker(curSticker, i, j)) {
                        placed = true;
                        break;
                    }
                }
            }
        }
        // 붙일 수 없으면 스티커는 건너뜁니다.
    }

    cout << GetAnswer();

    return 0;

    // 모르겠는 거
    // 왜 모든 자리에서 탐색?
    // 그리고 시간복잡도 ㅄ같은거 
}
