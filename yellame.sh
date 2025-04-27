#!/bin/bash

# ===== Experiment 3: Basic Shell script for File operations =====

# Create and manipulate files
echo "===== File Operations ====="
echo "Enter filename:"
read filename
touch $filename
echo "Enter content for the file (Ctrl+D to end):"
cat > $filename
echo "Content of the file:"
cat $filename
echo "Word count:"
wc $filename
echo "Sorted content:"
sort $filename
echo "Uppercase content:"
tr '[:lower:]' '[:upper:]' < $filename
echo "Enter keyword to search:"
read keyword
grep $keyword $filename
echo "Renaming file..."
mv $filename "${filename}_new"
echo "Deleting file..."
rm "${filename}_new"

# ===== Experiment 4: Arithmetic Operations =====

echo -e "\n===== Arithmetic Operations ====="
echo "Enter two numbers:"
read a b
echo "Addition: $((a + b))"
echo "Subtraction: $((a - b))"
echo "Multiplication: $((a * b))"
echo "Division: $((a / b))"

echo "Enter radius for circle calculations:"
read radius
echo "Area: $(echo "3.14 * $radius * $radius" | bc)"
echo "Perimeter: $(echo "2 * 3.14 * $radius" | bc)"

echo "Enter basic salary:"
read salary
da=$(echo "$salary * 0.0165" | bc)
hra=$(echo "$salary * 0.003" | bc)
gross=$(echo "$salary + $da + $hra" | bc)
echo "Gross salary: $gross"

A=1200 B=1400 C=1350 D=1800
mean=$(echo "($A + $B + $C + $D)/4" | bc)
echo "Mean salary: $mean"

# ===== Experiment 5: Conditional Statements =====

echo -e "\n===== Conditional Statements ====="
echo "Enter number to check even/odd:"
read num
if [ $((num % 2)) -eq 0 ]; then
    echo "Even"
else
    echo "Odd"
fi

echo "Enter three numbers:"
read n1 n2 n3
if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]; then
    echo "$n1 is largest"
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ]; then
    echo "$n2 is largest"
else
    echo "$n3 is largest"
fi

echo "Enter year:"
read year
if [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]; then
    echo "Leap year"
else
    echo "Not leap year"
fi

echo "Enter account balance and withdrawal amount:"
read balance amount
if [ $amount -gt $balance ]; then
    echo "Insufficient balance"
else
    if [ $amount -lt 1500 ]; then
        tax=$(echo "$amount * 0.03" | bc)
    elif [ $amount -lt 3000 ]; then
        tax=$(echo "$amount * 0.04" | bc)
    else
        tax=$(echo "$amount * 0.05" | bc)
    fi
    echo "Tax: $tax"
    echo "New balance: $(echo "$balance - $amount - $tax" | bc)"
fi

# ===== Experiment 6: Loop Statements =====

echo -e "\n===== Loop Statements ====="
echo "Enter number for pattern:"
read n
for ((i=1; i<=n; i++)); do
    for ((j=1; j<=i; j++)); do
        echo -n "*"
    done
    echo
done
for ((i=n-1; i>=1; i--)); do
    for ((j=1; j<=i; j++)); do
        echo -n "*"
    done
    echo
done

echo "Factorial calculation - enter number:"
read num
fact=1
for ((i=1; i<=num; i++)); do
    fact=$((fact * i))
done
echo "Factorial: $fact"

# ===== Experiment 7: Case Statements =====

echo -e "\n===== Case Statements ====="
echo "Enter character:"
read char
case $char in
    [aeiouAEIOU]) echo "Vowel" ;;
    *) echo "Consonant" ;;
esac

echo "Enter number:"
read num
case ${#num} in
    1) echo "Single digit" ;;
    2) echo "Double digit" ;;
    3) echo "Triple digit" ;;
esac

echo "Enter month number (1-12):"
read month
case $month in
    1|2|12) echo "Winter" ;;
    3|4|5) echo "Spring" ;;
    6|7|8) echo "Summer" ;;
    9|10|11) echo "Autumn" ;;
esac