bool isPalindrome(char *s) {
     int left = 0; 
     int notleft = strlen(s) - 1;
      while (left < notleft) {
         
        while (left < notleft && !isalnum(s[left])) {
             left++;
              } 
        while (left < notleft && !isalnum(s[notleft])) {
            notleft--;
             } 
     if (tolower(s[left]) != tolower(s[notleft])) { 
        return false; 
        }
         left++;
          notleft--;
           }
            return true;
             }