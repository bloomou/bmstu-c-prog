import ctypes
from typing import List

lib = ctypes.CDLL("library/lib_arr.so")

_arr_prime_numbers = lib.arr_prime_numbers
_arr_prime_numbers.argtypes = (
    ctypes.POINTER(ctypes.c_int),
    ctypes.c_int,
)

_add_num_after_even = lib.add_num_after_even
_add_num_after_even.argtypes = (
    ctypes.POINTER(ctypes.c_int),
    ctypes.c_int,
    ctypes.POINTER(ctypes.c_int),
    ctypes.c_int,
    ctypes.c_int
)
_add_num_after_even.restype = ctypes.c_int


def arr_prime_numbers(n: int) -> List[int]:
    buffer = (ctypes.c_int * n)()
    _arr_prime_numbers(buffer, n)

    return list(buffer)


def add_num_after_even(src_arr, size_src_arr, size_dst_arr, num):
    src_arr = (ctypes.c_int * size_src_arr)(*src_arr)
    dst_arr = (ctypes.c_int * size_dst_arr)()

    num_elem = _add_num_after_even(src_arr, size_src_arr, dst_arr, size_dst_arr, num)

    if num_elem > size_dst_arr:
        dst_arr = (ctypes.c_int * num_elem)(*dst_arr)
        _add_num_after_even(src_arr, size_src_arr, dst_arr, num_elem, num)

    return list(dst_arr)
