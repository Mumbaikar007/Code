def calculate (N):
    # Write your code here

    ways = 0

    left = N // 10
    right = N % 10

    #i = 0
    tenpow = 1
    while left > tenpow:
    	
    	tenpow *= 10

    	if ( left % tenpow == right):
            print (left)
        

        
    tenpow = tenpow // 10

    



N =  int( input() )

out_ = calculate(N)
print (out_)