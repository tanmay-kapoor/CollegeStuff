#!/bin/bash
function accept() {
	echo -n "enter first number: "
	read num1
	echo -n "enter second number: "
	read num2
}

function string() {
	echo -n "enter string: "
	read str
}

function addition(){
		sum=`expr $num1 + $num2`
		echo "addition of two numbers is $sum"
}

function subtraction(){
		sub=`expr $num1 - $num2`
		echo "subtraction of two numbers is $sub"
} 

function multiplication(){
	mul=`expr $num1 \* $num2`
	echo "multiplication of two numbers is $mul"
}

function division(){
	div=`expr "scale=2; $num1 / $num2" |bc`
	echo "division of two numbers is $div"
}

function l2u(){
	str1=${str^^}
	echo "$str1"
}

function u2l(){
	str2=${str,,}
	echo "$str2"
}

echo "What do want to perform on these two numbers :- "
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication" 
echo "4. Division"
echo "5. lower to upper"
echo "6. upper to lower case"
read ch
case $ch in 
1)  accept
	addition;;
2)  accept
	subtraction;;
3)  accept
	multiplication;;
4)  accept 
	division;;
5)  string 
	l2u;;
6)  string 
	u2l;;
esac