#include <string>
#include <vector>

using namespace std;

int get_rank(int n) {
    if (n <= 1) return 6;
    return 7 - n;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int hit = 0, zero = 0;
    bool win_num[46] = {};
    for (int n : win_nums)
        win_num[n] = true;
    for (int lotto : lottos) {
        if (!lotto) ++zero;
        if (win_num[lotto])
            ++hit;
    }
    return { get_rank(hit + zero), get_rank(hit) };
}

