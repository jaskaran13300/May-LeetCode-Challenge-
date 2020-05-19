class StockSpanner {
public:
    int size;
    stack<int>st;
    int *array;
    StockSpanner() {
        array=new int[10000];
        size=0;
    }
    
    int next(int price) {
        if(size==0){
            array[size]=price;
            size++;
            st.push(0);
            return 1;
        }
        array[size]=price;
        while(!st.empty() && price>=array[st.top()]){
            st.pop();
        }
        
        if(st.empty()){
            st.push(size);
            size++;
            return size;
        }
        int ans=size-st.top();
        st.push(size);
        size++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
