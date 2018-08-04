// set a global httpRequest object

var httpRequest;
		
// TODO: when the page (window) has loaded, make a
// request for page 1

window.onload = function() {
	makeRequest(1);
}

function makeRequest(pageNum) {
	
    // TODO: create a variable "url" to store the request to 
	// the current pageNum, ie:
	// 		"https://reqres.in/api/users?page=1" // for page 1
	// 		"https://reqres.in/api/users?page=2" // for page 2
	// 		etc...
	var url = "https://reqres.in/api/users?page=" + pageNum;

	
	// make an HTTP request object
	
	httpRequest = new XMLHttpRequest();

	// execute the "showContents" function when
	// the httprequest.onreadystatechange event is fired
	
	httpRequest.onreadystatechange = showContents;
	
	// open a asynchronous HTTP (GET) request with the specified url
	
	httpRequest.open('GET', url, true);
	
	// send the request
	
	httpRequest.send();
}

// the function that handles the server response

function showContents() {

//  check for response state
//  0      The request is not initialized
//  1      The request has been set up
//  2      The request has been sent
//  3      The request is in process
//  4      The request is complete

	if (httpRequest.readyState === 4) {
		// check the response code
		if (httpRequest.status === 200) { // The request has succeeded
		    // Just for debugging. 
			console.log(httpRequest.responseText);
			
			// Javascript function JSON.parse to parse JSON data
			var jsData = JSON.parse(httpRequest.responseText);
			
			// TODO: use the jsData object to populate the correct
			// table cells, ie <tr><td>...</td></tr>
			// in the <tbody> element with id="data"
			var loc = document.querySelector('#data');
			loc.innerHTML = ""; // Clear the tbody element 
			for (var i = 0; i < jsData.data.length; i++) {
				var data = makeRow(jsData.data[i]); // Pass the data part of the object into function
				loc.appendChild(data); // Append row of data made from function to the tbody
			}
		} else {
			console.log('There was a problem with the request.');
		}
	}
}	

function makeRow(jsData) {
	var tr = document.createElement("tr");
	for (var key in jsData) { // For each key value pair in data
		var td = document.createElement("td");
		if (key == 'avatar') { 
			var img = document.createElement("img");
			img.src = jsData[key]; // Image src is the link
			img.alt = "Dunno bro";
			td.appendChild(img);
		}
		else {
			var text = document.createTextNode(jsData[key]); // Text is the value of the key
			td.appendChild(text);
		}
		tr.appendChild(td);
	}
	
	return tr; // Returns the row of data
}