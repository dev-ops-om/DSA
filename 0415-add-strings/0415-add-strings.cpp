class Solution {

    private:

    string add(string num1, string num2){
          int index1=num1.length()-1;
        int index2=num2.length()-1;
        string ans="";
int carry=0;
        while(index2>=0){
            int sum=(num1[index1]-'0')+(num2[index2]-'0')+carry;
          carry=sum/10;
            char c=(sum%10)+'0';
            ans=c+ans;
            index2--,index1--;

        }

        while(index1>=0){
            int sum=num1[index1]-'0'+carry;
            carry=sum/10;
            char c=(sum%10)+'0';

            ans=c+ans;
            index1--;
        }
        if(carry){
           ans='1'+ans;
        }
        return ans;
    }
public:
    string addStrings(string num1, string num2) {
      if(num1.length()>num2.length()){
            return add(num1,num2);
      }
      else{
        return add(num2,num1);
      }
    }
};