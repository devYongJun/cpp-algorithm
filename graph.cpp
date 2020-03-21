/*
그래프 예시
     0       4
    / \     /
   1   2   3
  / \       \
 5   6       7 - 8

parents : [0, 0, 0, 3, 3, 0, 0, 3, 3]
*/


// 부모 가져오기
int getParent(const vector<int>& parents, int x)
{
    if(parents[x] == x)
    {
        return x;
    }
    return getParent(parents, parents[x]);
}

// 부모 합치기 (작은 숫자기준)
void unionParent(vector<int>& parents, int a, int b)
{
    int aParent = getParent(parents, a);
    int bParent = getParent(parents, b);
    if(aParent < bParent)
    {
        parents[b] = parents[bParent] = aParent;
    }
    else
    {
        parents[a] = parents[aParent] = bParent;
    }
}

// 부모가 같은지 검사
bool isEqualParent(const vector<int>& parents, int a, int b)
{
    return getParent(parents, a) == getParent(parents, b);
}
