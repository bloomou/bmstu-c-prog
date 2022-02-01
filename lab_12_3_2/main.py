import arr as arr_lib

while True:
    print("Type:\n"
          "'0' to exit\n"
          "'1' to get first n prime numbers\n"
          "'2' to add number after even numbers of array\n"
          )
    input_str = input("Choice: ")
    if input_str == '0':
        break
    elif input_str == '1':
        n = int(input("Input number of prime numbers you want to get: "))
        if n <= 0:
            print("Number of prime numbers should be positive.")
            continue
        else:
            print(arr_lib.arr_prime_numbers(n))
    elif input_str == '2':
        input_str = input("Input array split by spaces: ")
        arr = list(map(int, input_str.split()))
        input_num = int(input("Input number to add after even ones: "))
        print(arr_lib.add_num_after_even(arr, len(arr), len(arr), input_num))
    else:
        continue
