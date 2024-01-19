before_alloc_swap=$(cat before_alloc100000.txt|awk '/Swap/ {print $3}')
after_alloc_swap=$(cat after_alloc100000.txt|awk '/Swap/ {print $3}')
before_alloc_mem_used=$(cat before_alloc100000.txt|awk '/Mem/ {print $3}')
after_alloc_mem_used=$(cat after_alloc100000.txt|awk '/Mem/ {print $3}')
echo swap before allocation:  "\t"$before_alloc_swap
echo swap after allocation:  "\t\t"$after_alloc_swap
echo memory before allocation: "\t"$before_alloc_mem_used
echo memory after allocation: "\t"$after_alloc_mem_used
echo ""

swap_diff=$after_alloc_swap
mem_diff=$(($after_alloc_mem_used-$before_alloc_mem_used))
echo difference between swap: "\t" $swap_diff
echo difference between mem: "\t" $mem_diff
echo ""

swap_mem_ratio=$(awk "BEGIN {print $swap_diff/$mem_diff}")
echo swap to mem ratio is: "\t\t" $swap_mem_ratio
