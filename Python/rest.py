# A REST api sample build in Python

import json
import requests
import urllib.parse

# Reading the JSON file
with open(‘requests.json’, ‘r’) as text_file_input:
    data=text_file_input.read()

#loading file as a JSON object
obj = json.loads(data)

API_ENDPOINT = ‘https://examplecom/{}``

#we pass on the arguments
for i in obj:
     r=requests.get(API_ENDPOINT.format(urllib.parse.quote(
i[‘userID’]),
i[‘userPassword’])
)
     print(r.text)#outside for loop
text_file_input.close()

r.json()

r.status_code

r.reason
