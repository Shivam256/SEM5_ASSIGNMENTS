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
 
    $search = $_REQUEST["search"];
 
    $query = "SELECT * FROM `book_info` WHERE title like '%$search%'"; //search with a book name in the table book_info
    $result = mysqli_query($db,$query);
 
    if(mysqli_num_rows($result)>0){
    ?>
    <table border="2" align="center" cellpadding="5" cellspacing="5">
        <tr>
            <th> ISBN </th>
            <th> Title </th>
            <th> Author </th>
            <th> Edition </th>
            <th> Publication </th>
        </tr>
 
        <?php while($row = mysqli_fetch_assoc($result))
        {
        ?>
        <tr>
            <td><?php echo $row["isbn"];?> </td>
            <td><?php echo $row["title"];?> </td>
            <td><?php echo $row["author"];?> </td>
            <td><?php echo $row["edition"];?> </td>
            <td><?php echo $row["publication"];?> </td>
        </tr>
        <?php
        }
        } else {echo "<center>No books found in the library by the name $search </center>" ;}
        ?>
    </table>
    </body>
</html>