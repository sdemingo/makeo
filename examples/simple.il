
# a=2
# b=4
# c=a+b

function main
push const 2
pop a
push const 4
pop b
push sim a
push sim b
add
pop c   