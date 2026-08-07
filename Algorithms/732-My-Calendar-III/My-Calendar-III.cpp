class MyCalendarThree {
public:
    map<int,int>mpp;
    MyCalendarThree() {
        
    }
    
    int book(int st, int end) {
        mpp[st]++;
        mpp[end]--;
        int maxi = 0;
        int cnt = 0;
        for (auto it: mpp) {
            cnt += it.second;
            maxi = max(cnt, maxi);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */