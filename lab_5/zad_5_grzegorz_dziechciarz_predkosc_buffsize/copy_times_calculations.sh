for i in 0 1 2 3 4 5 6 7 8 9 10
do

    time ./copy_v2.o $((2**i)) random_bytes random_bytes_copy
done