import re
import string



def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v

# Generates list of every item followed by sales for each item type
def FullList():

    # Opens and reads file
    file = open('input.txt', 'r')
    read_data = file.read()
    per_word = read_data.split()

    # Empty dictionary
    item_types = {}

    # Counting and printing all items
    print('          Full Item List: \n')
    for word in per_word:
        if word not in item_types:
            item_types[word] = item_types.get(word, 1)
        else:
            item_types[word] += 1
    print('Total Items:', len(per_word))
    
    # Printing each item type with the amount of sales
    for item in item_types:
        print(item, item_types[item])
        

# Searches for item and reports its findings
def SpecificItem():

    # user input as all lower case
    search_word = input('Enter the word: ').lower()

    # opens and allows reading of given file
    file = open('input.txt', 'r')
    read_data = file.read()

    # searches through data as lower case entries
    # counts the occurrences of the search term in the data
    word_count = read_data.lower().count(search_word)

    # 
    print(f"The item '{search_word}' was purchased {word_count} times today.")


# Generates text-based histogram of sales
def PrintHistogram():
    # opens and reads file
    file = open('input.txt', 'r')
    read_data = file.read()
    per_word = read_data.split()

    # empty dictionary
    item_types = {}

    # populates dictionary with keys and values
    for word in per_word:
        if word not in item_types:
            item_types[word] = item_types.get(word, 1)
        else:
            item_types[word] += 1
    
    # Declaring variables for histogram
    item_1 = 0
    item_2 = 0
    item_3 = 0
    item_4 = 0
    item_5 = 0
    item_6 = 0
    item_7 = 0
    item_8 = 0
    item_9 = 0
    item_10 = 0
    item_11 = 0
    item_12plus = 0
      
    # Iterating through dictionary and incrementing
    # variables for histogram
    for item in item_types:
        if item_types[item] == 1:
            item_1 += 1
        if item_types[item] == 2:
            item_2 += 1
        if item_types[item] == 3:
            item_3 += 1
        if item_types[item] == 4:
            item_4 += 1
        if item_types[item] == 5:
            item_5 += 1
        if item_types[item] == 6:
            item_6 += 1
        if item_types[item] == 7:
            item_7 += 1
        if item_types[item] == 8:
            item_8 += 1
        if item_types[item] == 9:
            item_9 += 1
        if item_types[item] == 10:
            item_10 += 1
        if item_types[item] == 11:
            item_11 += 1
        else:
            item_12plus += 1

    # Printing histogram
    print("              Frequency of Items Purchase        \n")
    print("          0   " + "*"*0)
    print("          1   " + "*"*item_1)
    print("          2   " + "*"*item_2)
    print("          3   " + "*"*item_3)
    print("          4   " + "*"*item_4)
    print("Purchase  5   " + "*"*item_5)
    print("  Rate    6   " + "*"*item_6)
    print("          7   " + "*"*item_7)
    print("          8   " + "*"*item_8)
    print("          9   " + "*"*item_9)
    print("          10  " + "*"*item_10)
    print("          11  " + "*"*item_11)
    print("          12+ " + "*"*0 + "\n")


    

