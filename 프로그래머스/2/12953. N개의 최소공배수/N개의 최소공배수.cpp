#include <string>
#include <vector>

using namespace std;

int lcm(int a,int b)
{
    int gcd=1;
    if(a>b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    for(int i=1;i<=a;i++)
    {
        if(a%i==0&&b%i==0)
            gcd=i;
    }
    return a*b/gcd;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i=1;i<arr.size();i++)
    {
        answer=lcm(answer,arr[i]);
    }
    return answer;
}