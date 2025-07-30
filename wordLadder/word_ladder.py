import string
from util import *

def word_ladder_neighbors(current_word, valid_words):
    '''
    Given a word (current_word) as a string and a set of valid words,
    returns a list of words that are all one letter different 
    than current_word.
    '''
    alphabet = string.ascii_lowercase
    neighbor_words = []
    for i in range(len(current_word)):
        for letter in alphabet:
            new_word = current_word[:i] + letter + current_word[i+1:]
            if new_word in valid_words:
                neighbor_words.append(new_word)
    return neighbor_words

def word_ladder_search(valid_words, start_word, end_word):
    '''
    Given a list of valid words, a starting word (string), and an ending 
    word (string), returns the path of of strings representing the word ladder from
    start_word to end_word.
    '''

    queue = [[start_word]]
    visited = set()
    while queue:
        word_path = queue.pop(0)
        if word_path[-1] == end_word:
            return word_path, len(visited)
        if word_path[-1] not in visited:
            visited.add(word_path[-1])
            neighbors = word_ladder_neighbors(word_path[-1], valid_words)
            for other_word in neighbors:
                if other_word not in visited:
                    new_path = word_path + [other_word]
                    queue.append(new_path)

def better_word_ladder_search(valid_words, start_word, end_word):
    '''
    Given a list of valid words, a starting word (string), and an ending 
    word (string), returns the path of of strings representing the word ladder from
    start_word to end_word. This search should use heuristic_function to speed up
    the search.
    '''
    queue = PriorityQueue()
    queue.update([start_word], 0)
    visited = set()
    while not queue.isEmpty():
        word_path = queue.pop()
        if word_path[-1] == end_word:
            return word_path, len(visited)
        if word_path[-1] not in visited:
            visited.add(word_path[-1])
            neighbors = word_ladder_neighbors(word_path[-1], valid_words)
            for other_word in neighbors:
                if other_word not in visited:
                    new_path = word_path + [other_word]
                    heuristic_val = heuristic_function(other_word, end_word)
                    queue.update(new_path, heuristic_val)

def heuristic_function(state, end_word):
    incorrect_letters = 0
    for i in range(len(state)):
        if state[i] != end_word[i]:
            incorrect_letters += 1
    return incorrect_letters


if __name__=="__main__":
    # valid_words is a set containing all strings that should be considered valid
    # words (all in lower-case)
    with open('words_alpha.txt') as f:
        valid_words = {i.strip() for i in f}

    print("You have", len(valid_words), "words to work with.")

    start = "taker"
    end = "giver"

    path, num_visited = better_word_ladder_search(valid_words, start, end)

    for word in path:
        print(word)
    print(num_visited)