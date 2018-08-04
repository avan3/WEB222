/*******************************************************************************
* WEB222 – Assignment 2
* I declare that this assignment is my own work in accordance with Seneca
* Academic Policy. No part of this assignment has been copied manually or
* electronically from any other source (including web sites) or distributed to
* other students.
*
* Name: _____Andrew Van______ Student ID: __141267179___ Date: __2018-05-25___
*
******************************************************************************/
// an array of course objects
var courses = [
    { code: 'APC100', name: 'Applied Professional Communications', hours: 3, url: 'http://www.senecacollege.ca/' },
    { code: 'IPC144', name: 'Introduction to Programming Using C', hours: 4, url: 'https://scs.senecac.on.ca/~ipc144/' },
    { code: 'ULI101', name: 'Introduction to Unix/Linux and the Internet', hours: 4, url: 'https://cs.senecac.on.ca/~fac/uli101/live/' },
    { code: 'IOS110', name: 'Introduction to Operating Systems Using Windows', hours: 4, url: 'https://cs.senecac.on.ca/~fac/ios110' },
    { code: 'EAC150', name: 'College English', hours: 3, url: null }
];

// prototype object for creating student objects
var student = { 
    name: "", 
    dob: new Date(),
    sid: "",
    program: "", 
    gpa: 4.0,
    toString: function () {
        return 'Student info for ' + this.name + ': born on ' + this.dob.toLocaleDateString() +
               ', student id ' + this.sid + ', progrem ' + this.program + ', current GPA ' + this.gpa; 
    }
};

/************************************************************
 * Start your Part B code here. Do not change the code above.
 ************************************************************/
// task 1

function addCourse(code, name, hours, url) {
	courses.push({
  	code: code, name: name, hours: hours, url: url
  });
}
// Remove last course
rmCourse = courses.pop();
// Add courses using function
addCourse('IBC233', 'iSERIES Business Computing', 4, 'https://scs.senecac.on.ca/~ibc233/');
addCourse('OOP244', 'Introduction to Object Oriented Programming', 4, 'https://scs.senecac.on.ca/~oop244/');
addCourse('WEB222', 'Internet I - Internet Fundamentals', 4, 'https://scs.senecac.on.ca/~web222/');
addCourse('DBS201', 'Introduction to Database Design and SQL', 4, 'https://scs.senecac.on.ca/~dbs201/');

// Display info
console.log("*** Task 1 ***\n\n");
console.log("Course",rmCourse['code'],"was deleted from the array (courses)");
console.log("Adding new course objects into the array (courses)\n\n");
console.log("Course objects in the array (courses):");
for (var i=0; i<courses.length; i++) {
	console.log('"' + courses[i]['code'] + ", " + 
  									courses[i]['name'] + ", " + 
              			courses[i]['hours'] + " hours/week, website: " + 
              			courses[i]['url'] + '"');
}

console.log("\n\n");

// task 2
student.set = function(name, dob, sid, program, gpa) {
  	this.name = name,
    this.dob = dob,
    this.sid = sid,
    this.program = program,
    this.gpa = gpa
}

student0 = Object.create(student);
student1 = Object.create(student);
student2 = Object.create(student);
student3 = Object.create(student);

student0.set('John Smith', new Date(1999,9,9), 010456101, 'CPA', 4);
student1.set('Jim Carrey', new Date(1992,0,17), 012345678, 'CPD', 3.5);
student2.set('Justin Bieber', new Date(1994,2,1), 0987654321, 'CAN', 3);
student3.set('Justin Trudeau', new Date(1992,0,12), 123456789, 'CAN', 4);

var students = [];
students.push(student0);
students.push(student1);
students.push(student2);
students.push(student3);

console.log("*** Task 2 ***\n\n");
console.log("Student objects in the array (students): ");

students.forEach(display);

function display(item, index) {
	console.log(index + ": " + item);
}