.name "zork"
.comment "I'M ALIIIIVE"

l2:
	sti r1, :liv2, %1   
	and r1, :l2, r1 ; |:l2 / %0| as second
					;	or r1, r1, 15

liv2:
	live %1
	zjmp %:liv2
