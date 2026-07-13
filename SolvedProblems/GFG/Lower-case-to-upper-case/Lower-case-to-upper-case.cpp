
string to_upper(string str) {
    int n=str.length();
   for(int i=0;i<n;i++){
       str[i]=str[i]-'a'+'A';
   }
   return str;
}