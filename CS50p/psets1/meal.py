'''
Suppose that you're in a country where it's customary to eat breakfast between 7:00 and 8:00, lunch between 12:00 and 13:00, and dinner between 18:00 and 19:00. Wouldn't it be nice if you had a program that could tell you what to eat when?

In meal.py, implement a program that prompts the user for a time and outputs whether it's breakfast time, lunch time, or dinner time. If it's not time for a meal, don't output anything at all. Assume that the user's input will be formatted in 24-hour time as #:## or ##:##. And assume that each meal's time range is inclusive. For instance, whether it's 7:00, 7:01, 7:59, or 8:00, or anytime in between, it's time for breakfast.

Structure your program per the below, wherein convert is a function (that can be called by main) that converts time, a str in 24-hour format, to the corresponding number of hours as a float. For instance, given a time like "7:30" (i.e., 7 hours and 30 minutes), convert should return 7.5 (i.e., 7.5 hours).
'''

def main():
    get_time: str = input("What time is it? ")
    if convert(get_time) >= 7 and convert(get_time) <= 8:
        print("breakfast time")
    elif convert(get_time) >= 12 and convert(get_time) <= 13:
        print("lunch time")
    elif convert(get_time) >= 18 and convert(get_time) <= 19:
        print("dinner time")
    else:
        return


def convert(time: str):
    hour, minute = time.split(":")
    formatted_time = float(hour) + (float(minute) / 60)
    return round(formatted_time,2)


if __name__ == "__main__":
    main()
