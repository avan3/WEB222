var errors = 0;
/* Javascript Validation */
function formValidation() {
    var result = false;
    clearErrors();
    result = validateUsername();
    result = validatePassword() && result;
    result = reenterPassword() && result;
    result = noDigits('#firstname') && result;
    result = noDigits('#lastname') && result;
    result = validateStreet() && result;
    result = noDigits('#city') && result;
    if (result == false) {
        document.getElementById('errorcolumn').style.display = "inline-block";
        document.querySelector(".content").style.width = "940px";
        document.getElementsByClassName("column")[0].style.width = "51%";
        document.getElementsByClassName("column")[1].style.width = "51%";
        //document.getElementById('username').addEventListener('focusout', validateUsername);
    }
    return result;
}

function clearErrors() {
    document.querySelector("#errors").innerHTML = "";
    errors = 0;
}

function showErrors(messages) {  
    errors++;
    if (errors < 9) {
        createImg('#errors', 'xicon.png');
        document.getElementById('errors').innerHTML += messages;
    } 
} 

/* Username Validation */
function validateUsername() {
    var valid = true;
    var loc = document.querySelector("#username");
    var inputValue = loc.value.trim();
    inputValue = inputValue.toUpperCase();
    if (inputValue.length == 0) {
        showErrors("<span>Username cannot be empty!</span><br>");
        valid = false;
    }
    else if (inputValue.length < 6) {
        showErrors("<span>Username must have at least 6 characters!</span><br>");
        valid = false;
    }
    /*if (valid) {
        var errors = document.querySelector("#errors");
        errors.removeChild(errors.childNodes[0]);
        createImg('xicon', 'cicon.png');
    } */
    if (inputValue[0] < "A" || inputValue[0] > "Z") {
        showErrors("<span>Username must start with a letter!</span><br>");
        valid = false;
    }
    return valid;
}

/* Password Validation */
function validatePassword() {
    var valid = true;
    var hasdigit = false;
    var alphString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    var loc = document.querySelector("#password");
    var inputValue = loc.value.trim();
    if (inputValue.length < 8 || inputValue.length == 0) {
        showErrors("<span>Password must be at least 8 characters long!</span><br>");
        valid = false;
    }
    for (var i = 0; i < inputValue.length; i++) {
        if (alphString.indexOf(inputValue.substr(i,1)) >= 0) { 
            valid = true;
            break;
        }
    }
    if (valid == false) {
        showErrors("<span>Password must contain at least one uppercase!</span><br>");
    }
    inputValue = inputValue.toUpperCase();
    if (inputValue[0] < "A" || inputValue[0] > "Z") {
        showErrors("<span>Password must start with a character!</span><br>");
        valid = false;
    }
    for (var i = 0; i < inputValue.length; i++) {
        if (parseInt(inputValue[i]) >= 0) { 
            hasdigit = true;
            break;
        }
    }
    if (hasdigit == false) {
        showErrors("<span>Password must contain at least one number!</span><br>");
    }
    return hasdigit && valid;
}

function reenterPassword() {
    var valid = false;
    var firstPassword = document.querySelector("#password").value.trim();
    var secondPassword = document.querySelector("#reenter").value.trim();
    if (firstPassword === secondPassword) {
        valid = true;
    }
    if (valid == false) {
        showErrors("<span>Passwords do not match!</span><br>");
    }
    return valid;
}

/* Street name validation */
function validateStreet() {
    var valid = true;
    var alphString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .";
    var loc = document.querySelector('#streetname');
    var inputValue = loc.value.trim();
    inputValue = inputValue.toUpperCase();
    if (inputValue.length == 0) {
        showErrors("<span>Street name cannot be empty!</span><br>");
        valid = false;
    }
    for (var i = 0; i < inputValue.length; i++) {
        if (alphString.indexOf(inputValue.substr(i,1)) < 0) {
            showErrors("<span>Street name must not contain numbers!</span><br>");
            valid = false;
            break;
        }
    }
    return valid;
}

/* First name, Last name, City validation */
function noDigits(id) {
    var valid = true;
    var loc = document.querySelector(id);
    var inputValue = loc.value.trim();
    inputValue = inputValue.toUpperCase();
    var field;
    switch (id) {
        case '#firstname':
            field = "First name";
            break;
        case '#lastname':
            field = "Last name";
            break;
        case '#city':
            field = "City";
            break;
    }
    if (inputValue.length == 0) {
        showErrors("<span>" + field + " cannot be empty!</span><br>");
        valid = false;
    }
    for (var i = 0; i < inputValue.length; i++) {
        if (inputValue.charAt(i) < "A" || inputValue.charAt(i) > "Z") {
            showErrors("<span>" + field + " must contain letters only!</span><br>");
            valid = false;
            break;
        }
    }
    return valid;
}

/* Creates the X icon beside the error message */
function createImg(loc, src) {
    var loc = document.querySelector(loc);
    var img = document.createElement("img");
    img.src = "css/" + src;
    img.className = "xicon";
    loc.appendChild(img);
}