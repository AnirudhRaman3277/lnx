#!/bin/bash 
 
students_file="students.txt" 
> $students_file 
 
echo "How many students do you want to input?" 
read num_students 
 
for (( i=1; i<=$num_students; i++ )) 
do 
 echo "Enter PRN for student $i:" 
 read prn 
 echo "Enter first name for student $i:" 
 read first_name 
 echo "Enter surname for student $i:" 
 read surname 
 
 echo "$prn $first_name $surname" >> $students_file 
done 
 
echo "Student data input done successfully." 
 
for year in {1..4}; do 
 touch "${year}year.txt" 
done 
for division in A B C D; do 
 touch "division_${division}.txt" 
done 
 
while IFS=' ' read -r prn first_name surname; do 
 year=$(expr "$prn" : '\([0-9]\)') 
 
 case "$year" in 
     1) year="1";; 
     2) year="2";; 
     3) year="3";; 
     4) year="4";; 
     *) continue;; 
 esac 
 
 # Determine the division based on the surname's first letter 
case "${surname:0:1}" in 
[A-Fa-f]) division="A" ;; 
[G-Lg-l]) division="B" ;; 
[M-Rm-r]) division="C" ;; 
[S-Zs-z]) division="D" ;; 
*) division="D" ;;  # Default to Division D 
esac 
# Save PRN to the corresponding year and division files 
echo "$prn" >> "${year}year.txt" 
echo "$prn, $first_name, $surname" >> "division_${division}.txt" 
done < $students_file 
echo "Sorting complete! Students categorized by year and division."