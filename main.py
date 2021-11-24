import cppsort

import random
import datetime

def measure_time_decorator(method):
    def wrapper(*args):
        start = datetime.datetime.now()
        method(*args)
        end = datetime.datetime.now()
        print(end.microsecond - start.microsecond, "microsec", end="\n\n")
    
    return wrapper

@measure_time_decorator
def log_time(method, arr, language):
    print(language)
    method(arr)

if __name__ == "__main__":
    size = 10
    while size < 1000000:
        print("size:", size, '\n')

        arr = [random.randint(-100, 100) for _ in range(size)]

        cppsort.sort(arr)

        log_time(sorted, arr, "python")

        print("*********************************************")

        size *= 10
