#!/usr/bin/env python3

"""

Get the list of integers for 'totalAuthored' and 'totalCompleted' of the nth ranker at Codewars Leaderboard.

(1 <= n <= 500)

See Example Test Cases for the expected data format.

(Note 1 : Mind the title of this kata as well as https://dev.codewars.com/ )

(Note 2 : It is recommended to finish Codewars Leaderboard [ https://www.codewars.com/kata/codewars-leaderboard/ ] before this kata. )

"""

import json, re
from urllib.request import urlopen

def get_code_challenges(n):
    html = urlopen('https://www.codewars.com/users/leaderboard').read().decode()
    matches = re.search(rf'#{n}\b.*?href="/users/([^"]+)"', html, re.S)
    user = matches.group(1)
    stream = urlopen(f'https://www.codewars.com/api/v1/users/{user}')
    data = stream.read().decode()
    challenges = json.loads(data)['codeChallenges']
    return [challenges['totalAuthored'], challenges['totalCompleted']]

def main():
    for i in range(10):
        try:
            print(i, get_code_challenges(i))
        except:
            pass

main()
