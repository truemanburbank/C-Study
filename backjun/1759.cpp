#include <iostream>
#include <algorithm>
using namespace std;

// 암호는 최소 한 개의 모음, 최소 두 개의 자음으로 구성되어야 함

int L; // 암호의 총 길이
int C; // 주어진 문자의 개수

// 모음
int vowels[5] = { 'a', 'e', 'i', 'o', 'u' };

// 암호로 뽑은 문자열
char picked[16];

// 현재 사용 가능한 문자들
char chars[16];

// 중복 사용 확인 배열
bool isUsed[16];

// 모음, 자음 개수가 조건을 만족하는지 확인
int isVowle;
int isConsonant;

// k 번째로 지정할 문자를 탐색 
void Solve(int k)
{
    if (k == L)
    {
        // 모음, 자음 개수가 조건을 충족한다면
        if (isVowle >= 1 && isConsonant >= 2)
        {
            for (int i = 0; i < L; i++)
            {
                cout << (char)picked[i];
            }
            cout << '\n';
        }
        return;
    }

    for (int i = 0; i < C; i++)
    {
        if (isUsed[i] || (k > 0 && picked[k - 1] > chars[i])) continue;

        // 만약 현재 문자가 모음이면
        if (find(vowels, vowels + 5, chars[i]) != std::end(vowels))
        {
            isVowle++;
        }
        // 만약 현재 문자가 자음이면
        else
        {
            isConsonant++;
        }

        isUsed[i] = true;
        picked[k] = chars[i];
        Solve(k + 1);
        isUsed[i] = false;

        // 만약 현재 문자가 모음이면
        if (find(vowels, vowels + 5, chars[i]) != std::end(vowels))
        {
            isVowle--;
        }
        // 만약 현재 문자가 자음이면
        else
        {
            isConsonant--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        cin >> chars[i];
    }

    sort(chars, chars + C);

    Solve(0);

    return 0;
}
