class Solution {
    public String decodeString(String s) {
        Stack<Integer> countStack = new Stack();
        Stack<StringBuilder> stringStack = new Stack();
        StringBuilder currentString = new StringBuilder();
        int k = 0;
        
        for(char ch : s.toCharArray()){
            if(Character.isDigit(ch)){
                k = k * 10 + ch-'0';
            }else if(ch == '['){
                //push the number k to countStack
                countStack.push(k);
                //push the currentString to stringStack
                stringStack.push(currentString);
                //reset the currentString and k
                currentString = new StringBuilder();
                k = 0;
            }else if(ch == ']'){
                StringBuilder decodedString = stringStack.pop();
                for(int i = countStack.pop(); i > 0; i--){
                    decodedString.append(currentString);
                }
                    currentString = decodedString;
            }else{
                currentString.append(ch);
            }
        }
        return currentString.toString();
    }
}