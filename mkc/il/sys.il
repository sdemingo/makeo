
#header write 2
function write
pop o
pop w_data

open o
pop fd
push sim w_data
write fd
return const 0


#header read 1
function read
pop i

open i
pop fd
read fd string
pop cad

close fd
return sim cad

