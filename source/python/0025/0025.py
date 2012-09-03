#
#
# What is the first term in the Fibonacci sequence to contain 1000 digits?
last = 1
current = 1
term = 3 
while True:
    fib = last + current
    if len( str( fib ) ) == 1000:
        break
    last = current
    current = fib
    term += 1 
print term

