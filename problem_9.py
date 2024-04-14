def count_pythagorean_quadruplets(array):
    size_n = len(array)
    hashmap = {}
    count = 0


    # Hash the values of a^2 + b^2 for all possible pairs
    for i in range(size_n):
        for j in range(i+1, size_n):
            sum_square = array[i]*array[i] + array[j]*array[j]
            if sum_square in hashmap:
                hashmap[sum_square] = hashmap[sum_square] + 1
            else:
                hashmap[sum_square] = 1


    # Hash the values of d^2 - c^2 for all possible pairs
    for i in range(size_n):
        for j in range(i+1, size_n):
            diff_square = abs(array[i]*array[i] - array[j]*array[j])
            if diff_square in hashmap:
                count = count + hashmap[diff_square]


    # Divide the count by 2 because each quadruplet is counted twice
    return count // 2
