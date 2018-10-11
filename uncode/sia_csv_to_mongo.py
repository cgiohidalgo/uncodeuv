import sys
import hashlib

lines = sys.stdin.readlines()

def tokens_to_mongo(tokens):
    names = tokens[0]
    last_names = tokens[1]
    full_name = names + " " + last_names

    email = tokens[2]
    username = email.split("@")[0]

    id = tokens[3]
    passwd_hash = hashlib.sha512(id.encode("utf-8")).hexdigest()

    print(
        'db.users.insert({' + 
            '"username" : "' + username + '", ' +
            '"realname" : "' + full_name + '", ' +
            '"language" : "en", ' +
            '"password" : "' + passwd_hash + '", ' + 
            '"email" : "' + email + '", ' +
            '"bindings" : {  } });'
    )
    #print(" {0} string: {1}".format("cool", "Hello there!"))

for line in lines:
    tokens = line.rstrip().split(",")
    tokens_to_mongo(tokens)
