
# 
# func sum(x,y)
#      z=y+y
#      ret z
# 
# a=1
# b=3
# res=sum(a,b)


# subrutine 1
function sum
pop a
pop b
push sim a
push sim b
add
pop z
return sim z


function main
push const 5
push const 11
call sum  
pop res






