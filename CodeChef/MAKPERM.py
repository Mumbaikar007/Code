t = int(input())
for t0 in range(t):
	n = int(input())
	a = list(map(int,input().strip().split()))
	c = 0
	# print()
	for i in range(n):
		# print("aaaaa",a[i])
		if(abs(a[i])-1 >= n):
			c += 1
		elif(a[abs(a[i])-1]-1 < 0):
			c += 1
		else:
			a[abs(a[i])-1] *= -1


	# print(a)
	print(c)