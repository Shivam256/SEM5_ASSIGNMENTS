<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body bgcolor="87ceeb">
    <center><h2>Simple Library Management System</h2></center>
    <br>
 
    <?php
        include("DBConnection.php");
 
        $isbn=$_POST["isbn"];
        $title=$_POST["title"];
        $author=$_POST["author"];
        $edition=$_POST["edition"];
        $publication=$_POST["publication"];
 
        $query = "INSERT INTO `book_info`(`isbn`, `title`, `author`, `edition`, `publication`) VALUES ('$isbn','$title','$author','$edition','$publication')"; //Insert query to add book details into the book_info table
        $result = mysqli_query($db,$query);
    ?>
    <h3> Book information is inserted successfully </h3>
 
    <a href="SearchBooks.php"> To search for the Book information click here </a>
 
</body>
</html>