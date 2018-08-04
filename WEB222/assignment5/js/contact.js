/* Google Maps */
function initMap() {
    var seneca = {lat: 43.7713923, lng: -79.4987939};
    var map = new google.maps.Map(
        document.getElementById('map'), {zoom: 15, center: seneca});
        var marker = new google.maps.Marker({position: seneca, map: map});
}