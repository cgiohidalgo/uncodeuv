import sys
import hashlib
import requests

def could_login(username, password):
    r = requests.post('http://localhost:8080/signin',
        data = {'login': username, 'password': password},
        allow_redirects=False
    )

    #print(r.status_code)
    return r.status_code == 303

def login_attempt(tokens):
    email = tokens[2]
    username = email.split("@")[0]

    id = tokens[3]

    print("Logging in as " + username)
    if not could_login(username, id):
        print("ERROR " + username + " " + id + " auth failed")


lines = sys.stdin.readlines()
for line in lines:
    tokens = line.rstrip().split(",")
    login_attempt(tokens)
