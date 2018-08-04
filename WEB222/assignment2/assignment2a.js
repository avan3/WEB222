/******************************************************************************* 
* WEB222 – Assignment 2 
* I declare that this assignment is my own work in accordance with Seneca 
* Academic Policy. No part of this assignment has been copied manually or 
* electronically from any other source (including web sites) or distributed to 
* other students. 
* 
* Name: _____Andrew Van______ Student ID: _141267179____ Date: __05-24-2018_____ 
* 
******************************************************************************/ 

/*****************************
* Step 1
*****************************/
var e1, e2, e3, e4, e5, e6, e7, str;

/*****************************
* Step 2
*****************************/
function capFirstLetter(string="Andrew") {
	var fString = string[0].toUpperCase();
  var lString = string.substring(1, string.length);
  fString += lString.toLowerCase();
  return fString;
}

var patt = /^[a-zA-Z]+$/
e1 = prompt("Please enter your first name: ");
var result = patt.test(e1);
if (result == false) {
	e1 = capFirstLetter();
}
else {
	e1 = capFirstLetter(e1);
}

/*****************************
* Step 3
*****************************/
var getAge = function(bYear = 1990) {
	var cYear = (new Date()).getFullYear();
	return cYear - bYear; 
}
var patt = /^[0-9]+$/
e2 = prompt("Please enter the year of your birthday: ");
var result = patt.test(e2);
if (result == false) {
	e2 = getAge();
}
else {
	e2 = getAge(e2);
}

/*****************************
* Step 4
*****************************/
function capCollegeName(college = "seneca college") {
	var words = college.split(" ");
  for (var i=0; i<words.length;i++) {
  	words[i] = capFirstLetter(words[i]);
  }
  return college = words.join(" ");
}

var patt = /^[a-zA-Z]+$/
e3 = prompt("Please enter the name of the college you are attending: ");
var result = patt.test(e3);
if (result == false) {
	e3 = capCollegeName();
}
else {
	e3 = capCollegeName(e3);
}

/*****************************
* Step 5
*****************************/
function favSports(sports = "hockey,football,basketball,tennis,golf") {
	sports = sports.replace("football", "soccer");
  var words = sports.split(",");
  return words;
}

var patt = /^(([a-zA-Z]{1,})[,]){4}[a-zA-Z]{1,}$/
e4 = prompt("Please enter your five favourite sports: ");
var result = patt.test(e4);
if (result == false) {
	e4 = favSports();
}
else {
	e4 = favSports(e4);
}

e5 = prompt("Please enter an extra favourite sport: ");
e4.push(e5);

/*****************************
* Step 6
*****************************/
for (var i=0; i<e4.length;i++) {
	e4[i] = e4[i].toUpperCase();
}
e4.sort();

/*****************************
* Step 7
*****************************/
function getDateString(date) {
	var year = date.getFullYear();
  var month = date.getMonth() + 1;
  var day = date.getDate();
  
  if (month < 10) {
  	month = "0" + month;
  }
  if (day < 10) {
  	day = "0" + day;
  }
  return year + "-" + month + "-" + day;
}

e6 = new Date();
e7 = getDateString(e6);

/*****************************
* Step 8
*****************************/
var sports = "";
for (var i=0; i<e4.length; i++) {
	sports += "\n\t" + e4[i];
}
var str = "User info:\n" + 
					"\nname (e1): " + e1 + 
          "\nage (e2): " + e2 + 
          "\nschool (e3): " + e3 + 
          "\nfavourite sports (e4): " +
          sports +
          "\ncurrent date (e7): " + e7;
          
console.log(str);