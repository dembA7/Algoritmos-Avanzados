def TowerOfHanoi(n, from_rod, to_rod, aux_rod, move_count):
    
    if n == 0:
        return
    
    TowerOfHanoi(n-1, from_rod, aux_rod, to_rod, move_count)

    move_count[0] += 1
    
    print("Move disk", n, "from rod", from_rod, "to rod", to_rod)
    
    TowerOfHanoi(n-1, aux_rod, to_rod, from_rod, move_count)

# Driver code
N = int(input("Enter the number of disks: "))

move_count = [0]  # Counter to store the number of movements

TowerOfHanoi(N, 'A', 'C', 'B', move_count)

print("Total movements:", move_count[0])
