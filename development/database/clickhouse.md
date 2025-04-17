# Clickhouse
1. Install
    ```sh
    sudo apt-get install -y apt-transport-https ca-certificates dirmngr
    GNUPGHOME=$(mktemp -d)
    sudo GNUPGHOME="$GNUPGHOME" gpg --no-default-keyring --keyring /usr/share/keyrings/clickhouse-keyring.gpg --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 8919F6BD2B48D754
    sudo rm -r "$GNUPGHOME"
    sudo chmod +r /usr/share/keyrings/clickhouse-keyring.gpg

    echo "deb [signed-by=/usr/share/keyrings/clickhouse-keyring.gpg] https://packages.clickhouse.com/deb stable main" | sudo tee \
        /etc/apt/sources.list.d/clickhouse.list
    sudo apt-get update
    sudo apt install clickhouse-server clickhouse-client
    ```
2. Add service `/etc/systemd/system/clickhouse-server.service`
    ```sh
    [Unit]
    Description=ClickHouse Database Server
    After=network.target

    [Service]
    Type=simple
    User=clickhouse
    Group=clickhouse
    ExecStart=/usr/bin/clickhouse-server --config=/etc/clickhouse-server/config.xml
    Restart=on-failure

    [Install]
    WantedBy=multi-user.target
    ```
3. Add permission
    ```sh
    sudo chown -R  clickhouse /etc/clickhouse-server
    ```

4. [Create admin user](https://clickhouse.com/docs/en/operations/access-rights)