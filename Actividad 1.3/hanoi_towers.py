def TowerOfHanoi(n, from_rod, to_rod, aux_rod):
    if n == 0:
        return 0
    moves = (
        TowerOfHanoi(n-1, from_rod, aux_rod, to_rod) +
        1 +
        TowerOfHanoi(n-1, aux_rod, to_rod, from_rod)
    )
    return moves

# Driver code
N = int(input("Enter the number of disks: "))
total_moves = TowerOfHanoi(N, 'A', 'C', 'B')
print("Total movements:", total_moves)
