#
#
# What is the first term in the Fibonacci sequence to contain 1000 digits?
last = 1
current = 1
term = 2 
fib = 2
while fib < 10**999:
    fib = last + current
    last = current
    current = fib
    term += 1 
print term

