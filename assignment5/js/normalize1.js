var user = {
    username: "",
    password: "",

}
/* Function to open and close menu and button transform */
function showMenu() {
    document.getElementsByClassName('menu')[0].classList.toggle('show');
    document.getElementById('1').classList.toggle('rotate45');
    document.getElementById('2').classList.toggle('hide');
    document.getElementById('3').classList.toggle('rotate-45');
}

/* Function to open and close sign in window and darker background */
function showLogin() {
    document.querySelector("#popupbg").style.visibility = 'visible';
    document.getElementsByClassName('form')[0].classList.add('show');
}

function closeLogin() {
    document.querySelector("#popupbg").style.visibility = 'hidden';
    document.getElementsByClassName('form')[0].classList.remove('show');
}

/* Functions to sign in and out */
function signin() {
    var inputValue = document.querySelector("#User");
    var username = inputValue.value.trim();
    var loc = document.querySelector("#welcome");
    if (username != "" && document.getElementsByClassName('signout')[0].style.display != "block") {
        var text = document.createTextNode("Welcome back, " + username + "!");
        loc.appendChild(text);
        document.getElementsByClassName('signin')[0].style.display = "none";
        document.getElementsByClassName('signout')[0].style.display = "block";
        closeLogin();
    }
    return false;
}

function logout() {
    var loc = document.querySelector("#welcome");
    loc.innerHTML = "";
    document.getElementsByClassName('signin')[0].style.display = "block";
    document.getElementsByClassName('signout')[0].style.display = "none";
}