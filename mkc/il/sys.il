
#header write 2
function write
pop o
pop w_data

open o
pop fd
push sim w_data
write fd
return const 0

