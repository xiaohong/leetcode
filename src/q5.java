public class q5{
	public boolean isPalindrome(String s){
		int len = s.length();

		int i = 0;
		int j = len-1;
		for(; i<= j; ){
			if (s.charAt(i) != s.charAt(j)){
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

    public String longestPalindrome_(String s) {
    	int len = s.length();
    	int max =0;
    	int begin = 0, end = 0;
    	for(int i = 0; i<len; i++){
    		for(int j = i+1; j <= len; j++){
    			if(isPalindrome(s.substring(i,j))){
    				if (max < j-i){
    					max = j-i;
    					begin = i;
    					end= j;
    				}
    			}
    		}
    	}

    	return s.substring(begin, end);
    }

        public String longestPalindrome(String s) {
    	int len = s.length();
    	int max =0;
    	int begin = 0, end = 0;
    	for(int i = 0; i<len; i++){
    		char x = s.charAt(i);
    		for(int j = i+1; j <= len; j++){
    			if(x == s.charAt(j-1)&&isPalindrome(s.substring(i,j))){
    				if (max < j-i){
    					max = j-i;
    					begin = i;
    					end= j;
    				}
    			}
    		}
    	}

    	return s.substring(begin, end);
    }

	public static void main(String[] args){
		q5 q = new q5();
		System.out.println(q.longestPalindrome("XXabcbA"));
	}
}