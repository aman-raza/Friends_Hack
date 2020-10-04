import json
from difflib import get_close_matches

data = json.load(open("data.json"))


def translate(w):
    w = w.lower()
    if w in data:
        return data[word]
    elif len(get_close_matches(w, data.keys(), cutoff=0.8)) > 0:
        ans = input(f'Is the word you entered \'{get_close_matches(w, data.keys())[0]}\' (y/n)?')
        if ans == 'y' or ans == 'Y':
            return data[get_close_matches(w, data.keys())[0]]
        else:
            print("The word isn't understandable")
    else:
        print("The word may be misspelled. Please check the word.")


while True:
    word = input("Enter a word\n")
    meaning_list = translate(word)
    if type(meaning_list) == list:
        for item in meaning_list:
            print(item)
    else:
        print(meaning_list)
    ch = input("\nDo you want to search for another?(y/n)")
    if ch == 'n' or ch == 'N':
        break
