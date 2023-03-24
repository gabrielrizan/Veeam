# Veeam Application Problem for Internal Development in QA

The project uses two vectors, file_source and file_destination and a boolean to check if there are changes made to the project.
The first for uses the directory iterator to go through the contents of the source directory and add the path of the files to the file_source vector.
We then change the file name from source to replica and then add this to the other vector called file_destination
The second for is used to delete all the files from the replica folder and to print a message for each file deleted.
We then make use of the boolean and check if there were any changes or not, displaying a message for each case.
The while loop copies the contents of each file in file_source to file_destination and displays in console a message for each copied file. It runs untill the file_source vector is empty.
