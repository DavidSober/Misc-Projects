# writes some text to a txt file REALLY GOOD FOR SPAMMING SHIT
# you need to make a txt called TESTLOL.txt in order for this to work

def textSpammer(str, num):

    # converts str to int for later loop
    number = int(num)

    # condition to clear the txt file
    if str == 'clear':
        with open('TESTLOL.txt', 'w') as f:
            f.write('')
    # if no condition then spam the str from user
    else:
        count = 0
        while count < number:
            with open('TESTLOL.txt', 'a') as f:
                f.writelines(str + '\n')

            count += 1


# script for user input
x = input("what do you want to spam? [TYPE 'clear' to clear txt]")
y = input("how many times to spam?")
textSpammer(x, y)


# clear the txt

