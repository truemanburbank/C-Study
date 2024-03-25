#include <iostream>
#include <vector>
using namespace std;

int S;
int P;
int check;
int required_DNA[4];
int my_DNA[4];
int result;
string str = "";

void Add(char);
void Delete(char);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S >> P;
    cin >> str;
    
    for(int i = 0; i < 4; i++)
    {
        cin >> required_DNA[i];
        if(required_DNA[i] == 0)
            check++;
    }
    
    for(int i = 0; i < P; i++)
    {
        Add(str[i]);
    }
    
    if(check == 4)
        result++;
    
    for(int i = P; i < S; i++)
    {
        int j = i - P;
        Add(str[i]);
        Delete(str[j]);
        if(check == 4)
            result++;
    }
    
    cout << result;
}

void Add(char c)
{
    switch (c) {
        case 'A':
            my_DNA[0]++;
            if(my_DNA[0] == required_DNA[0])
                check++;
            break;
        case 'C':
            my_DNA[1]++;
            if(my_DNA[1] == required_DNA[1])
                check++;
            break;
        case 'G':
            my_DNA[2]++;
            if(my_DNA[2] == required_DNA[2])
                check++;
            break;
        case 'T':
            my_DNA[3]++;
            if(my_DNA[3] == required_DNA[3])
                check++;
            break;
    }
}

void Delete(char c)
{
    switch (c) {
        case 'A':
            if(my_DNA[0] == required_DNA[0])
                check--;
            my_DNA[0]--;
            break;
        case 'C':
            if(my_DNA[1] == required_DNA[1])
                check--;
            my_DNA[1]--;
            break;
        case 'G':
            if(my_DNA[2] == required_DNA[2])
                check--;
            my_DNA[2]--;
            break;
        case 'T':
            if(my_DNA[3] == required_DNA[3])
                check--;
            my_DNA[3]--;
            break;
    }
}
