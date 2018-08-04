var filterType = ""; // sets the filter type to "" (will later be dog, cat or bird)
var filterAgeMin = 0; // sets the filter age min to 0 (for no minimum age filter)
var filterAgeMax = Number.MAX_VALUE; // sets the filter age max to the largest number possible (for no maximum age filter)

window.onload = function() {
    loadTableWithFilters();
}

function loadTableWithFilters() {
    var loc = document.getElementById("main-table-body");
    loc.innerHTML = "";
    
    for (var i = 0; i < petData.length; i++) {
        if (petData[i].type == filterType || filterType == "") {
            if (petData[i].age >= filterAgeMin && petData[i].age <= filterAgeMax) {
                var row = document.createElement("tr");
                var cell1 = document.createElement("td");
                var cell2 = document.createElement("td");

                var img = document.createElement("img");
                img.src = petData[i].image.src;
                img.alt = petData[i].image.alt;
                img.height = petData[i].image.height;
                img.width = petData[i].image.width;

                cell1.appendChild(img);

                var h4 = document.createElement("h4");
                var text = document.createTextNode(petData[i].name);
                h4.appendChild(text);

                var p = document.createElement("p");
                p.innerHTML = petData[i].description;

                var age = document.createElement("span");
                var ageText = document.createTextNode("Age: " + petData[i].age + " years old.");
                age.appendChild(ageText);
                
                cell2.appendChild(h4);
                cell2.appendChild(p);
                cell2.appendChild(age);

                row.appendChild(cell1);
                row.appendChild(cell2);

                loc.appendChild(row);
            }
        }
    }
}

function filterAllPets() {
    filterType = "";
    filterAgeMin = 0;
    filterAgeMax = Number.MAX_VALUE;
    loadTableWithFilters();

}

function filterDog() {
    filterType = "dog";
    loadTableWithFilters();
}

function filterCat() {
    filterType = "cat";
    loadTableWithFilters();
}

function filterBird() {
    filterType = "bird";
    loadTableWithFilters();
}

function filter_zero_1() {
    filterAgeMin = 0;
    filterAgeMax = 1;
    loadTableWithFilters();
}

function filter_1_3() {
    filterAgeMin = 1;
    filterAgeMax = 3;
    loadTableWithFilters();
}

function filter_4_plus() {
    filterAgeMin = 4;
    filterAgeMax = Number.MAX_VALUE;
    loadTableWithFilters();
}