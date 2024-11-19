# task:
# In deep.py, implement a program that prompts the user for the answer to the Great Question of Life, the Universe and Everything, outputting Yes if the user inputs 42 or (case-insensitively) forty-two or forty two.
# Otherwise output No.
#
# output:
# What is the Answer to the Great Question of Life, the Universe, and Everything? 42                  
# Yes

def main():
    response: str = input("What is the Answer to the Great Question of Life, the Universe, and Everything? ").strip().casefold()

    match response:
        case '42' | 'forty-two' | 'forty two':
            print("Yes")
        case _:
            print("No")


main()