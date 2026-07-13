class MyCalendarTwo {
public:
map<int,int>events;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        events[start]+=1;
        events[end]-=1;

        int active=0;
        for(auto &event:events){
          active+=event.second;

          if(active>2){
            events[start]-=1;
            events[end]+=1;
if (events[start] == 0) events.erase(start);
if (events[end] == 0) events.erase(end);
            return false;
          }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */