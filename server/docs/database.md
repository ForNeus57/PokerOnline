Used database: MySQL

Due to security conserves all the database connection details files are hidden from GitHub view.

Therefore, in order to establish connection between Sever module and your database you need to:
1.  Copy `DBConnectionDatalisSample.json` to a `../conf` directory:
    ```bash
    cp ./connection_details_sample.db.json ../conf
    ```
2. Edit the file contents so that it matches your database connection details.
3. Change the name of a file (`DBConnectionDatalisSample.json`) to `DBConnectionDatalis.json`:
    ```bash
    cd ../conf
    mv ./connection_details_sample.db.json ./connection_details.db.json
    ```
4.  Save this file.
TODO:
5. ... run custom exec........ to test connection.

Here I am using a bash command, but you can do it in any way you like, so long the same results will be achieved.

