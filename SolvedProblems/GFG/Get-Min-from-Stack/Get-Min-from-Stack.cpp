class SpecialStack {
     stack<int> st1, st2;

  public:
    SpecialStack() {
        
    }

    void push(int x) {
        if(st1.empty()){
            st1.push(x);
            st2.push(x);
        }
        else{
            st1.push(x);
            st2.push(min(st2.top(),x));
        }
    }

    int pop() {
        if(st1.empty())
        return -1;
        int element=st1.top();
        st1.pop();
        st2.pop();
        return element;
    }

    int peek() {
       if (st1.empty()) return -1;
        return st1.top();

    }

    bool isEmpty() {
       return st1.empty();

    }

    int getMin() {
        if(st2.empty()){
            return -1;
        }
        
        return st2.top();
    }
};