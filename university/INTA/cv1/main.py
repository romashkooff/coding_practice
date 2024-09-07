import requests
from duckduckgo_search import DDGS
from pprint import pprint

# url = 'https://duckduckgo.com/?t=h_&q=cat&iax=images&ia=images'
# r = requests.get(url)
# print(r.text)
# print("<img" in r.text.lower())

with DDGS() as ddgs:
    results = [r for r in ddgs.images("cat", max_results=5)]
    pprint(results)