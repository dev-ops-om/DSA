class MyCalendarThree {
public:
    map<int,int> events;
    MyCalendarThree() {}

    int book(int start, int end) {
        events[start] += 1;
        events[end] -= 1;

        int active = 0, maxBooking = 0;
        for (auto &event : events) {
            active += event.second;
            maxBooking = max(maxBooking, active);
        }
        return maxBooking;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */