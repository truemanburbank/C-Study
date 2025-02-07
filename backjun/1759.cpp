#include <iostream>
#include <algorithm>
using namespace std;

// ��ȣ�� �ּ� �� ���� ����, �ּ� �� ���� �������� �����Ǿ�� ��

int L; // ��ȣ�� �� ����
int C; // �־��� ������ ����

// ����
int vowels[5] = { 'a', 'e', 'i', 'o', 'u' };

// ��ȣ�� ���� ���ڿ�
char picked[16];

// ���� ��� ������ ���ڵ�
char chars[16];

// �ߺ� ��� Ȯ�� �迭
bool isUsed[16];

// ����, ���� ������ ������ �����ϴ��� Ȯ��
int isVowle;
int isConsonant;

// k ��°�� ������ ���ڸ� Ž�� 
void Solve(int k)
{
    if (k == L)
    {
        // ����, ���� ������ ������ �����Ѵٸ�
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

        // ���� ���� ���ڰ� �����̸�
        if (find(vowels, vowels + 5, chars[i]) != std::end(vowels))
        {
            isVowle++;
        }
        // ���� ���� ���ڰ� �����̸�
        else
        {
            isConsonant++;
        }

        isUsed[i] = true;
        picked[k] = chars[i];
        Solve(k + 1);
        isUsed[i] = false;

        // ���� ���� ���ڰ� �����̸�
        if (find(vowels, vowels + 5, chars[i]) != std::end(vowels))
        {
            isVowle--;
        }
        // ���� ���� ���ڰ� �����̸�
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
