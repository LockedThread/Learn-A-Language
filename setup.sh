#!/bin/bash
problems=("Addition of Two Numbers" "Sum of 'N' Natural Numbers" "Area of Triangle" "Quadratic Formula" "Working Hours" "Greater of 3 Numbers" "Leap Year" "Palindrome" "Challenge 1")
languages=("C")

create_language_folders () {
	for lang in ${languages[@]}; do mkdir -p $lang; done
}

echo "Creating projects:"
for i in ${!problems[@]}; do
	name="$(($i+1))- ${problems[$i]}"
	if [[ ${problems[$i]:0:9} == "Challenge" ]] 
	then	
		mkdir -p "Challenges/${problems[$i]}"	
	else
		echo $name
		mkdir -p "$name" && cd "$_"	
		create_language_folders && cd ..
	fi
done
