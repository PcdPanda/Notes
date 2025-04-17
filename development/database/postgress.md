# Postgresql
1. Install
    ```sh
    sudo apt install postgresql
    sudo service postgresql start
    ```
2. Add user   
Switch to `postgres user` to add users 
    ```sql
    CREATE ROLE panda WITH SUPERUSER LOGIN PASSWORD 'pwd';
    ```
3. Create personal database
`createdb $(whoami)`   