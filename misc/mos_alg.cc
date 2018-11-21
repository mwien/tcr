/* Mo's algorithm
 * Works for queries on intervals. Idea: Sort queries. Add and remove on borders has to work in O(1). Thus only usable when this is possible for the task.
 */

//START
// sort the querys [L,R] as follows: if L is in the same block (blocks have size sqrt n), sort by increasing R else sort by L
bool cmp(const pair<pair<int, int>, int> &i, const pair<pair<int, int>, int> &j) {
    if(i.first.first / BLOCK_SIZE != j.first.first / BLOCK_SIZE) {
        return i.first.first < j.first.first;
    }
    return i.first.second < j.first.second;
}

int main() {
    BLOCK_SIZE = static_cast<int>(sqrt(N));
    // store original index in queries
    vector<pair<pair<int, int>, int>> queries(M);
    vector<int> answers(M);
    //sort the queries into buckets
    sort(queries.begin(), queries.end(), cmp);
    //this is the essential part
    //for each querie we shift the previous borders one by one
    //careful analysis shows that the runtime is something like n*sqrtn + m*sqrt n (n elements and m queries)
    int mo_left = 0, mo_right = -1;
    for(int i = 0; i < M; ++i) {
        int left = queries[i].first.first;
        int right = queries[i].first.second;
        while(mo_right < right) {
            ++mo_right;
            // add can be any function as long as it is O(1)
            add(lmen[mo_right], lwomen[mo_right]);
        }
        while(mo_right > right) {
            // remove can be any function as long as it is O(1)
            remove(lmen[mo_right], lwomen[mo_right]);
            --mo_right;
        }
        while(mo_left < left) {
            remove(lmen[mo_left], lwomen[mo_left]);
            ++mo_left;
        }
        while(mo_left > left) {
            --mo_left;
            add(lmen[mo_left], lwomen[mo_left]);
        }
        answers[queries[i].second] = cur_answer;
    }
}
