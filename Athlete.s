.name "Athlete"
.comment "Keep running boy"

	sti r1, %:live, 1
	and r1, %0, r1
    live %1
    fork %:continue  

aliveloop:
   	live %1
	zjmp %:aliveloop

continue:
	sti r1, %:live, 1
	and r1, %0, r1
    live %1
    fork %:continue2  

aliveloop2:
   	live %1
	zjmp %:aliveloop2

continue2:
	sti r1, %:live, 1
	and r1, %0, r1
    live %1
    fork %:continue3  

aliveloop3:
   	live %1
	zjmp %:aliveloop3

continue3:
	sti r1, %:live, 1
	and r1, %0, r1
    live %1
    fork %:attack

aliveloop4:
   	live %1
	zjmp %:aliveloop4

attack: