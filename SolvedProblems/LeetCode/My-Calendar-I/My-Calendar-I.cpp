class MyCalendar {
public:
    map<int,int> mp;

    MyCalendar() {
        // Empty constructor
    }

    bool book(int start, int end) {
        // Find the first interval whose start >= current start
        auto it = mp.lower_bound(start);

        // Check overlap with next interval
        if (it != mp.end() && it->first < end) {
            return false;
        }

        // Check overlap with previous interval
        if (it != mp.begin()) {
            auto previt = prev(it);
            if (previt->second > start) {
                return false;
            }
        }

        // Insert new booking
        mp[start] = end;
        return true;
    }
};