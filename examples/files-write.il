
# 
# func sum(x,y)
#      z=y+y
#      ret z
# 
# a=1
# b=3
# res=sum(a,b)
# f=open('/tmp/prueba.txt')
# write(f,res);
# close(f);



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

push const "Este es el resultado de sum:\n"
pop cad

#abro y escribo el fichero
push const "./tmp/prueba.txt"
pop file
open file
pop fd
push sim cad
write fd

# escribo el resultado de la funcion sum
push sim res
write fd

# escribo otro string y cierro el fichero
push const "\nCierro el fichero\n"
pop cad

push sim cad
write fd

close fd
