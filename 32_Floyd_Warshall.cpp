#include <bits/stdc++.h>
using namespace std;

void floyd(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    // trying all via combination

    for (int via = 0; via < n; via++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
}

// =========== About floyd Warhsall ============

// represneted in NxN matrix  , and since its a inplace algo  , answer is stored in same
// to get min dist from src to dest -->
// matrix[src][dest]

// =========== rep of no edge ============

// no edge represneted by  1e8 ,,,, if there some other rep of no edge , first change it
// make sure not to make it INT_MAX , it can cause overflows , make sure value is greater than all possible values aswell
// first change all elements to (-1) to (1e8)
// apply transtivie realtion
// chagne all (1e8) to (-1)
// changing to max possible val

// ============ to detect negative cycle =============

// check all diagonal if any is < 0 (negative) then there's a negative cycle
// because path from x to x should be  0 .

// =========time complexity ====================
// O(n^3 )

int main()
{
    return 0;
}