/* comparator in C++
 */

//START
bool myfunction (int i, int j) {return (i<j); }

int main() {
    vector<int> vec;
    sort(vec.begin(), vec.end(), myfunction);
    priority_queue<int, vector<int>, decltype(myfunction) *> pq(myfunction);
}
//END
