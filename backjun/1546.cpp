#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    float scores[1000];
    float sum = 0;
    float max = 0;
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> scores[i];
        sum += scores[i];
        
        if(max < scores[i])
            max = scores[i];
    }
    
    cout << sum * 100 / max / N;
}
