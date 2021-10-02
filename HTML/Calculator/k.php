<?php
$servername = "localhost";
$username = "root";
$password = "";
$databse ="information";
// Create connection
$conn = mysqli_connect($servername, $username, $password,$databse);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
echo "connected";
?>