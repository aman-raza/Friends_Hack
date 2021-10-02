import math
import itertools

D = 0
z = 0

N = int(input(''))

number = list(map(int, input("").split()[:N]))
number_list = ["zero","one","two","three","four","five","six","seven","eight","nine"]

for _ in number:
    x = number_list[_]
    vowel_counts = {}
    for vowels in 'aeiou':
        count = x.count(vowels)
        vowel_counts[vowels] = count
    counts = vowel_counts.values()
    total_vowels = sum(counts)
    D += total_vowels

integer_array = number
target = D
for numbers in itertools.combinations(integer_array,2):
    if sum(numbers) == target:
        z += 1    

co = number_list[z]
print(co)
