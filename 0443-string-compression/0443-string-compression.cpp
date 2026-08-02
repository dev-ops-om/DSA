class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int writeIdx=0;
       
        while(i<chars.size()){
            char ch=chars[i];
             int count=0;
            chars[writeIdx++]=ch;

            while(i<chars.size() && chars[i]==ch){
                count++;
                i++;

            }
            if(count>1){
                for(char dig:to_string(count)){
            chars[writeIdx++]=dig;

                }

            }
        }
        chars.resize(writeIdx);
        return writeIdx;
    }
};