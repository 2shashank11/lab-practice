N=9

def printing(arr):
	for i in range(N):
		for j in range(N):
			print(arr[i][j], end = " ")
		print()


def check(grid, row, col, n):
    for i in range(9):
        if(grid[row][i]==n):
            return False
    
    for i in range(9):
        if(grid[i][col]==n):
            return False
    
    r=row-row%3
    c=col-col%3

    for i in range(3):
        for j in range(3):
            if grid[r+i][c+j]==n:
               return False
    return True
    

def solveSudoku(grid, row, col):
	
    if(row==N-1 and col==N):
        return True
    
    if(col==N):
         row+=1
         col=0
	
    num=grid[row][col]

    if(num>0):
        return solveSudoku(grid, row, col+1)
    
    for i in range(1, N+1):
        if(check(grid, row, col, i)):
            grid[row][col]=i
            if solveSudoku(grid, row, col+1):
                return True
        grid[row][col]=0
    return False                    



grid = [[3, 0, 6, 5, 0, 8, 4, 0, 0],
		[5, 2, 0, 0, 0, 0, 0, 0, 0],
		[0, 8, 7, 0, 0, 0, 0, 3, 1],
		[0, 0, 3, 0, 1, 0, 0, 8, 0],
		[9, 0, 0, 8, 6, 3, 0, 0, 5],
		[0, 5, 0, 0, 9, 0, 6, 0, 0],
		[1, 3, 0, 0, 0, 0, 2, 5, 0],
		[0, 0, 0, 0, 0, 0, 0, 7, 4],
		[0, 0, 5, 2, 0, 6, 3, 0, 0]]

if (solveSudoku(grid, 0, 0)):
	printing(grid)
else:
	print("no solution exists ")
