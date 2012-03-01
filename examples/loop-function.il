
#
# func sum(x,y)
#      z=y+y
#      ret z
#
#
# func main
#      a=0
#      i=10
#      while (i>0)
#      	     a=sum(a,1)
#	     



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

push const 0
pop a

push const 10
pop i
# loop
label salto
push const 1
push sim a
call sum
pop a
push const 1
push sim i
sub
pop i
push sim i
goto-ifnz salto
# end loop

label fin