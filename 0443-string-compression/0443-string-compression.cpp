class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int writeIdx=0;
        while(i<chars.size()){

            char ch=chars[i];
            int count=0;
            chars[writeIdx++]=ch;

            while(i<chars.size()&& ch==chars[i]){
                count++;
                i++;
            }

            if(count>1){
                string dig=to_string(count);
                for(char ch:dig){
                    chars[writeIdx++]=ch;
                }
            }
        }
        return writeIdx;

    }
};