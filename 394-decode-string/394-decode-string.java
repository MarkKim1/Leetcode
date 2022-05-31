class Solution {
    public String decodeString(String s) {
        Stack<Integer> countStack = new Stack();
        Stack<String> stringStack = new Stack();
        int count = 0;
        String res = "";
        
        for(int i = 0; i < s.length(); i++){
            if(Character.isDigit(s.charAt(i))){
                count = count * 10 +(s.charAt(i) -'0');
            }else if(s.charAt(i) == '['){
                countStack.push(count);
                stringStack.push(res);
                res = "";
                count = 0;
            }else if (s.charAt(i) == ']'){
                StringBuilder temp = new StringBuilder(stringStack.pop());
                for(int j = 0; j < countStack.peek(); j++){
                    temp.append(res);
                }
                countStack.pop();
                res = temp.toString();
            }else{
                res+=s.charAt(i);
            }
        }
        return res;
    }
}