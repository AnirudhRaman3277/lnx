#!/bin/bash 
 
echo "Enter a string:" 
read str 
 
string_length() { 
 len=0 
 while [ -n "${str:len:1}" ]; do 
     ((len++)) 
 done 
 echo "Length of the string: $len" 
} 
 
 
reverse_string() { 
 echo "Reversed string: $(echo "$str" | rev)" 
} 
 
is_palindrome() 
{ 
 rev_str=$(echo "$str" | rev) 
 if [[ "$str" == "$rev_str" ]]; then 
     echo "It is a palindrome." 
 else 
     echo "Not a palindrome." 
 fi     
} 
 
to_uppercase() { 
 echo "Uppercase: $(echo "$str" | tr 'a-z' 'A-Z')" 
} 
 
to_lowercase() { 
 echo "Lowercase: $(echo "$str" | tr 'A-Z' 'a-z')" 
} 
 
word_count() { 
 echo "Word count: $(echo "$str" | wc -w)" 
} 
 
while true; do 
 echo -e "\nChoose an operation:" 
echo "1. Length of String" 
echo "2. Convert to Uppercase" 
echo "3. Convert to Lowercase" 
echo "4. Reverse String" 
echo "5. Check Palindrome" 
echo "6. Word Count" 
echo "7. Exit" 
read -p "Enter your choice: " choice 
case $choice in 
1) string_length ;; 
2) to_uppercase ;; 
3) to_lowercase ;; 
4) reverse_string ;; 
5) is_palindrome ;; 
6) word_count ;; 
7) echo "Exiting..."; exit 0 ;; 
*) echo "Invalid input." ;; 
esac 
done 
esac 
*) echo "Invalid option!" ;;