/******************************************************************************
 * WEB222 - Assignment 01
 * I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part of 
 * this assignment has been copied manually or electronically from any other source (including web sites)
 * or distributed to other students.
 * Name: Andrew Van Student ID: 141267179 Date: May 11, 2018
 *
******************************************************************************/ 
/*****************************
* Task 1
*****************************/
var studentName = "Andrew Van", numCourses = 4, program = "CPA", ptJob = false;

if (ptJob == true) {
  var have = "have";
}
else {
  var have = "don't have";
}
console.log("My name is " + studentName + " and I'm in " + program + " program. I'm taking " + numCourses + " course in this semester and I " + have + " a part-time job now.")
/*****************************
* Task 2
*****************************/
var cYear = 2018;
var age = prompt("Please enter your age: ");
var bYear = cYear - age;
console.log("You were born in the year of " + bYear);

var sYear = prompt("Enter the number of years you expect to study in the college: ");
var gYear = cYear + parseInt(sYear);
console.log("You will graduate from Seneca college in the year of " + gYear);
/*****************************
* Task 3
*****************************/
function toC(f) {
    return (5/9) * (f-32);
}

function toF(c) {
  return (1.8 * c) + 32;
}
var c = 0;
var f = toF(c);
console.log(c.toFixed(1) + "°C is " + f.toFixed(1) + "°F");
f = 100;
c = toC(f);
console.log(f.toFixed(1) + "°F is " + c.toFixed(1) + "°C");
/*****************************
* Task 4
*****************************/
for (var i = 0; i <= 10; i++) {
  if (i%2 != 0) {
    console.log(i + " is odd");
  }
  else {
    console.log(i + " is even");
  }
}
/*****************************
* Task 5
*****************************/
function largerNum(n1, n2) {
  if (n1 > n2) {
    return n1;
  }
  else {
    return n2;
  }
}
var n1 = 5, n2 = 12;
console.log("The larger number of " + n1 + " and " + n2 + " is " + largerNum(n1, n2));
n1 = 15;
n2 = 12;
console.log("The larger number of " + n1 + " and " + n2 + " is " + largerNum(n1, n2));

var greaterNum = function (n1, n2) {
  return Math.max(n1, n2);
}
console.log("The greater number of " + n1 + " and " + n2 + " is " + greaterNum(n1,n2));
n1 = 5
n2 = 12;
console.log("The greaer number of " + n1 + " and " + n2 + " is " + greaterNum(n1,n2));
/*****************************
* Task 6
*****************************/
function Evaluator() {
  var sum = 0;
  var avg = 0;
  for (var i=0; i < arguments.length; i++) {
    sum += arguments[i];
  }
  avg = sum/arguments.length;
  if (avg >= 50) {
    return true;
  }
  return false;
}
console.log("Average greater than equal to 50: " + Evaluator(20,30,40));
console.log("Average greater than equal to 50: " + Evaluator(60,70,80));
console.log("Average greater than equal to 50: " + Evaluator(30,60,90));
/*****************************
* Task 7
*****************************/
var grader = function(score) {
  if (score >= 80) {
    return "A";
  }
  else if (score >= 70) {
    return "B";
  }
  else if (score >= 60) {
    return "C";
  }  
  else if (score >= 50) {
    return "D";
  }
  else {
    return "F";
  }
}
var score = 82;
console.log(score + " is a letter grade of " + grader(score));
score = 66;
console.log(score + " is a letter grade of " + grader(score));
score = 41;
console.log(score + " is a letter grade of " + grader(score));
/*****************************
* Task 8
*****************************/
function showMultiples(num, numMultiples) {
   for (var i=1; i<= numMultiples; i++) {
      console.log(num + " x " + i + " = " + num*i);
   }
}

showMultiples(5,4);
showMultiples(2,5);
showMultiples(4,3);
